#!/usr/bin/env python3
"""
Simulador MIPS com trace especial para MEM[152]
Monitora todas as operações que afetam esse endereço crítico
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from mips_simulator import MIPSSimulator


class MemoryTraceMIPSSimulator(MIPSSimulator):
    def __init__(self, input_values=None, traced_address=152):
        super().__init__(input_values)
        self.traced_address = traced_address
        self.memory_trace = []
        self.detailed_log = []

        print(f"🔍 TRACE MODE: Monitorando MEM[{traced_address}]")

    def trace_memory_access(self, operation, address, value, instruction_info=""):
        """Registra operações de memória no endereço rastreado"""
        if address == self.traced_address:
            trace_entry = {
                "cycle": self.cycle_count,
                "pc": self.pc,
                "operation": operation,
                "address": address,
                "value": value,
                "instruction": instruction_info,
            }
            self.memory_trace.append(trace_entry)

            msg = f"🎯 TRACE MEM[{address}]: {operation} = {value} (CICLO {self.cycle_count}, PC={self.pc}) - {instruction_info}"
            print(msg)
            self.detailed_log.append(msg)

    def execute_instruction(self, instruction):
        """Override para interceptar operações de memória"""
        opcode = instruction["opcode"]
        args = instruction["args"]

        # Log antes da execução
        instr_str = f"{opcode} {', '.join(args)}"

        if opcode == "SW":
            # Interceptar SW para trace
            rs = self.get_register_number(args[1])  # base register
            rt = self.get_register_number(args[0])  # value register

            if "(" in args[1]:
                offset_str = args[1].split("(")[0]
                offset = int(offset_str) if offset_str else 0
            else:
                offset = self.get_immediate_value(args[1]) if len(args) > 1 else 0

            address = (self.registers[rs] + offset) & 0xFF
            value = self.registers[rt]

            # Trace antes da escrita
            self.trace_memory_access(
                "SW_BEFORE", address, self.memory[address], f"About to write {value}"
            )

            # Executar a operação original
            super().execute_instruction(instruction)

            # Trace após a escrita
            self.trace_memory_access(
                "SW_AFTER", address, self.memory[address], f"Written {value}"
            )

        elif opcode == "LW":
            # Interceptar LW para trace
            rs = (
                self.get_register_number(args[1].split("(")[1].rstrip(")"))
                if "(" in args[1]
                else self.get_register_number(args[1])
            )
            rt = self.get_register_number(args[0])

            if "(" in args[1]:
                offset_str = args[1].split("(")[0]
                offset = int(offset_str) if offset_str else 0
            else:
                offset = 0

            address = (self.registers[rs] + offset) & 0xFF

            # Trace antes da leitura
            old_value = self.memory[address]
            self.trace_memory_access(
                "LW_BEFORE", address, old_value, f"About to read to R{rt}"
            )

            # Executar a operação original
            super().execute_instruction(instruction)

            # Trace após a leitura
            self.trace_memory_access(
                "LW_AFTER", address, old_value, f"Read {old_value} to R{rt}"
            )

        else:
            # Operações normais
            super().execute_instruction(instruction)

    def print_memory_trace(self):
        """Imprime trace completo das operações de memória"""
        print(f"\n🔍 TRACE COMPLETO DE MEM[{self.traced_address}]:")
        print("=" * 80)

        for entry in self.memory_trace:
            print(
                f"CICLO {entry['cycle']:3d} | PC={entry['pc']:2d} | {entry['operation']:<10} | "
                f"MEM[{entry['address']}] = {entry['value']:3d} | {entry['instruction']}"
            )

        if not self.memory_trace:
            print("❌ Nenhuma operação detectada no endereço rastreado!")

        print("=" * 80)

    def run(self, max_cycles=1000):
        """Override do run para adicionar trace no final"""
        result = super().run(max_cycles)
        self.print_memory_trace()
        return result


def main():
    """Executa o simulador com trace"""
    if len(sys.argv) < 2:
        print("Uso: python trace_simulator.py <arquivo.asm> [endereço_trace]")
        return

    assembly_file = sys.argv[1]
    traced_address = int(sys.argv[2]) if len(sys.argv) > 2 else 152

    print("Simulador MIPS com Memory Trace")
    print("=" * 50)

    # Criar simulador com trace
    simulator = MemoryTraceMIPSSimulator(traced_address=traced_address)

    try:
        simulator.load_assembly(assembly_file)
        result = simulator.run()

        print(f"\n📊 RESULTADO FINAL: {result}")
        print(f"📋 TODAS AS SAÍDAS: {simulator.get_output_values()}")

    except Exception as e:
        print(f"Erro: {e}")


if __name__ == "__main__":
    main()

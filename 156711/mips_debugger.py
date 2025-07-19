#!/usr/bin/env python3
"""
Simulador/Debugger MIPS - Rastreamento de Escopo e Registradores
================================================================
Este algoritmo simula a execução do assembly gerado e registra:
- Mudanças de escopo (função main -> gcd -> recursões)
- Estado de todos os registradores a cada instrução
- Valores na memória (stack)
- Detecção de chamadas recursivas
- Fluxo de execução completo

Entradas de teste: x=4, y=6
Resultado esperado: GCD(4,6) = 2
"""

import re
from collections import defaultdict
from typing import Dict, List, Tuple, Optional


class MIPSDebugger:
    def __init__(self):
        # Estado do processador
        self.registers = {f"R{i}": 0 for i in range(32)}
        self.registers["R0"] = 0  # R0 sempre zero
        self.registers["R29"] = 1000  # Stack pointer inicial
        self.registers["R31"] = 0  # Return address

        # Memória (stack)
        self.memory = defaultdict(int)

        # Controle de execução
        self.pc = 0  # Program counter
        self.instructions = []
        self.labels = {}

        # Debug/rastreamento
        self.execution_log = []
        self.scope_stack = []
        self.current_scope = "BOOT"
        self.recursion_level = 0
        self.call_stack = []

        # Entradas do usuário
        self.input_values = [4, 6]  # x=4, y=6
        self.input_index = 0
        self.output_values = []

        # Estado HI/LO para divisão e multiplicação
        self.hi_register = 0
        self.lo_register = 0

    def load_assembly(self, filename: str):
        """Carrega o arquivo assembly e parseia as instruções"""
        with open(filename, "r", encoding="utf-8") as f:
            lines = f.readlines()

        # Criar um mapeamento de endereços para índices
        self.addr_to_index = {}

        for line in lines:
            line = line.strip()
            if not line or line.startswith("#"):
                continue

            # Detectar labels
            if ":" in line and not re.match(r"^\s*\d+:", line):
                label_match = re.match(r"^(\w+):", line)
                if label_match:
                    label_name = label_match.group(1)
                    # Próxima instrução após o label
                    continue

            # Parsear instrução
            instr_match = re.match(r"^\s*(\d+):\s*(\w+)\s*(.*)", line)
            if instr_match:
                addr = int(instr_match.group(1))
                opcode = instr_match.group(2)
                operands = instr_match.group(3).strip()

                index = len(self.instructions)
                self.addr_to_index[addr] = index

                self.instructions.append(
                    {
                        "addr": addr,
                        "opcode": opcode,
                        "operands": operands,
                        "original": line,
                    }
                )

        # Detectar labels após carregar instruções
        for line in lines:
            line = line.strip()
            if ":" in line and not re.match(r"^\s*\d+:", line):
                label_match = re.match(r"^(\w+):", line)
                if label_match:
                    label_name = label_match.group(1)
                    # Encontrar próxima instrução
                    found_next = False
                    for i, instruction in enumerate(self.instructions):
                        if not found_next:
                            # Procurar pela linha do label no texto
                            line_index = -1
                            with open(filename, "r", encoding="utf-8") as f:
                                file_lines = f.readlines()

                            for j, file_line in enumerate(file_lines):
                                if label_name + ":" in file_line:
                                    line_index = j
                                    break

                            if line_index >= 0:
                                # Encontrar próxima instrução após o label
                                for k in range(line_index + 1, len(file_lines)):
                                    next_line = file_lines[k].strip()
                                    instr_match = re.match(r"^\s*(\d+):", next_line)
                                    if instr_match:
                                        addr = int(instr_match.group(1))
                                        if addr in self.addr_to_index:
                                            self.labels[label_name] = (
                                                self.addr_to_index[addr]
                                            )
                                            found_next = True
                                            break
                                break

    def parse_operands(self, operands: str) -> List[str]:
        """Parseia operandos de uma instrução"""
        if not operands:
            return []

        # Remove espaços e divide por vírgulas
        parts = [part.strip() for part in operands.split(",")]
        return parts

    def get_register_value(self, reg_name: str) -> int:
        """Obtém valor de um registrador"""
        if reg_name.startswith("R"):
            return self.registers.get(reg_name, 0)
        return 0

    def set_register_value(self, reg_name: str, value: int):
        """Define valor de um registrador (R0 sempre permanece 0)"""
        if reg_name == "R0":
            return  # R0 sempre zero
        if reg_name.startswith("R"):
            old_value = self.registers.get(reg_name, 0)
            self.registers[reg_name] = value
            if old_value != value:
                self.log_register_change(reg_name, old_value, value)

    def log_register_change(self, reg_name: str, old_value: int, new_value: int):
        """Registra mudança em registrador"""
        self.execution_log.append(
            {
                "type": "register_change",
                "pc": self.pc,
                "scope": self.current_scope,
                "recursion_level": self.recursion_level,
                "register": reg_name,
                "old_value": old_value,
                "new_value": new_value,
            }
        )

    def log_memory_change(self, address: int, old_value: int, new_value: int):
        """Registra mudança na memória"""
        self.execution_log.append(
            {
                "type": "memory_change",
                "pc": self.pc,
                "scope": self.current_scope,
                "recursion_level": self.recursion_level,
                "address": address,
                "old_value": old_value,
                "new_value": new_value,
            }
        )

    def log_scope_change(self, new_scope: str, change_type: str):
        """Registra mudança de escopo"""
        old_scope = self.current_scope
        self.current_scope = new_scope

        self.execution_log.append(
            {
                "type": "scope_change",
                "pc": self.pc,
                "old_scope": old_scope,
                "new_scope": new_scope,
                "change_type": change_type,
                "recursion_level": self.recursion_level,
                "stack_state": dict(self.registers),
                "memory_snapshot": dict(self.memory),
            }
        )

    def execute_instruction(self, instruction: dict) -> bool:
        """Executa uma instrução e retorna False se deve parar"""
        opcode = instruction["opcode"]
        operands = self.parse_operands(instruction["operands"])

        self.execution_log.append(
            {
                "type": "instruction",
                "pc": self.pc,
                "scope": self.current_scope,
                "recursion_level": self.recursion_level,
                "instruction": instruction["original"],
                "registers_before": dict(self.registers),
            }
        )

        # Execução por tipo de instrução
        if opcode == "J":
            # Jump incondicional
            target = int(operands[0])
            self.pc = target
            return True

        elif opcode == "JAL":
            # Jump and Link (chamada de função)
            target = int(operands[0])
            self.set_register_value("R31", self.pc + 1)  # Return address

            # Detectar função sendo chamada
            target_func = None
            for label, addr in self.labels.items():
                if addr == target:
                    target_func = label
                    break

            if target_func:
                if target_func == "gcd" or target_func in self.call_stack:
                    self.recursion_level += 1
                    if target_func == "gcd":
                        self.log_scope_change(
                            f"gcd_recursion_{self.recursion_level}", "function_call"
                        )

                self.call_stack.append(target_func)

            self.pc = target
            return True

        elif opcode == "JR":
            # Jump Register (retorno de função)
            reg = operands[0]
            target = self.get_register_value(reg)

            if self.call_stack:
                returning_from = self.call_stack.pop()
                if returning_from == "gcd":
                    self.log_scope_change(
                        f"return_from_gcd_{self.recursion_level}", "function_return"
                    )
                    if self.recursion_level > 0:
                        self.recursion_level -= 1

            self.pc = target
            return True

        elif opcode == "BNE":
            # Branch Not Equal
            reg1, reg2, offset = operands[0], operands[1], int(operands[2])
            val1 = self.get_register_value(reg1)
            val2 = self.get_register_value(reg2)

            if val1 != val2:
                self.pc = offset
            else:
                self.pc += 1
            return True

        elif opcode == "BEQ":
            # Branch Equal
            reg1, reg2, offset = operands[0], operands[1], int(operands[2])
            val1 = self.get_register_value(reg1)
            val2 = self.get_register_value(reg2)

            if val1 == val2:
                self.pc = offset
            else:
                self.pc += 1
            return True

        elif opcode == "LW":
            # Load Word
            reg, offset_base = operands[0], operands[1]
            offset_match = re.match(r"(-?\d+)\((\w+)\)", offset_base)
            if offset_match:
                offset = int(offset_match.group(1))
                base_reg = offset_match.group(2)
                address = self.get_register_value(base_reg) + offset
                value = self.memory[address]
                self.set_register_value(reg, value)

        elif opcode == "SW":
            # Store Word
            reg, offset_base = operands[0], operands[1]
            offset_match = re.match(r"(-?\d+)\((\w+)\)", offset_base)
            if offset_match:
                offset = int(offset_match.group(1))
                base_reg = offset_match.group(2)
                address = self.get_register_value(base_reg) + offset
                value = self.get_register_value(reg)
                old_value = self.memory[address]
                self.memory[address] = value
                if old_value != value:
                    self.log_memory_change(address, old_value, value)

        elif opcode == "MOVE":
            # Move register
            dest, src = operands[0], operands[1]
            value = self.get_register_value(src)
            self.set_register_value(dest, value)

        elif opcode == "DIV":
            # Division
            reg1, reg2 = operands[0], operands[1]
            val1 = self.get_register_value(reg1)
            val2 = self.get_register_value(reg2)
            if val2 != 0:
                self.hi_register = val1 % val2  # Resto
                self.lo_register = val1 // val2  # Quociente

        elif opcode == "MFHI":
            # Move From HI
            reg = operands[0]
            self.set_register_value(reg, self.hi_register)

        elif opcode == "MFLO":
            # Move From LO
            reg = operands[0]
            self.set_register_value(reg, self.lo_register)

        elif opcode == "MULT":
            # Multiplication
            reg1, reg2 = operands[0], operands[1]
            val1 = self.get_register_value(reg1)
            val2 = self.get_register_value(reg2)
            result = val1 * val2
            self.lo_register = result & 0xFFFFFFFF
            self.hi_register = (result >> 32) & 0xFFFFFFFF

        elif opcode == "SUB":
            # Subtraction
            dest, src1, src2 = operands[0], operands[1], operands[2]
            val1 = self.get_register_value(src1)
            val2 = self.get_register_value(src2)
            result = val1 - val2
            self.set_register_value(dest, result)

        elif opcode == "INPUT":
            # Input
            reg = operands[0]
            if self.input_index < len(self.input_values):
                value = self.input_values[self.input_index]
                self.input_index += 1
                self.set_register_value(reg, value)
                self.execution_log.append(
                    {
                        "type": "input",
                        "pc": self.pc,
                        "scope": self.current_scope,
                        "value": value,
                        "register": reg,
                    }
                )

        elif opcode == "OUTPUTREG":
            # Output Register
            reg = operands[0]
            value = self.get_register_value(reg)
            self.output_values.append(value)
            self.execution_log.append(
                {
                    "type": "output",
                    "pc": self.pc,
                    "scope": self.current_scope,
                    "value": value,
                    "register": reg,
                }
            )

        elif opcode == "HALT":
            # Halt
            self.execution_log.append(
                {
                    "type": "halt",
                    "pc": self.pc,
                    "scope": self.current_scope,
                    "final_output": self.output_values,
                }
            )
            return False

        # Incrementar PC se não foi jump
        if opcode not in ["J", "JAL", "JR", "BNE", "BEQ"]:
            self.pc += 1

        return True

    def run_simulation(self):
        """Executa a simulação completa"""
        print("🚀 INICIANDO SIMULAÇÃO MIPS - DEBUG GCD(4,6)")
        print("=" * 60)

        # Começar na main (endereço 25 segundo o assembly)
        self.pc = 0  # Começa no J 21
        self.log_scope_change("main", "program_start")

        steps = 0
        max_steps = 1000  # Prevenir loop infinito

        while steps < max_steps:
            if self.pc >= len(self.instructions):
                break

            instruction = self.instructions[self.pc]
            should_continue = self.execute_instruction(instruction)

            steps += 1
            if not should_continue:
                break

        print(f"\n✅ Simulação concluída em {steps} passos")
        print(f"📤 Saídas: {self.output_values}")
        return self.output_values

    def print_detailed_log(self):
        """Imprime log detalhado da execução"""
        print("\n" + "=" * 80)
        print("📋 LOG DETALHADO DE EXECUÇÃO")
        print("=" * 80)

        scope_changes = 0
        register_changes = 0
        memory_changes = 0

        for i, entry in enumerate(self.execution_log):
            entry_type = entry["type"]

            if entry_type == "scope_change":
                scope_changes += 1
                print(f"\n🔄 MUDANÇA DE ESCOPO #{scope_changes}")
                print(f"   PC: {entry['pc']}")
                print(f"   {entry['old_scope']} → {entry['new_scope']}")
                print(f"   Tipo: {entry['change_type']}")
                print(f"   Nível de recursão: {entry['recursion_level']}")
                print(f"   Estado dos registradores:")
                for reg, val in sorted(entry["stack_state"].items()):
                    if val != 0:
                        print(f"      {reg}: {val}")

            elif entry_type == "register_change":
                register_changes += 1
                print(
                    f"📝 REG: {entry['register']} = {entry['old_value']} → {entry['new_value']} [PC:{entry['pc']}, {entry['scope']}]"
                )

            elif entry_type == "memory_change":
                memory_changes += 1
                print(
                    f"💾 MEM[{entry['address']}] = {entry['old_value']} → {entry['new_value']} [PC:{entry['pc']}, {entry['scope']}]"
                )

            elif entry_type == "input":
                print(
                    f"📥 INPUT: {entry['value']} → {entry['register']} [PC:{entry['pc']}, {entry['scope']}]"
                )

            elif entry_type == "output":
                print(
                    f"📤 OUTPUT: {entry['register']} = {entry['value']} [PC:{entry['pc']}, {entry['scope']}]"
                )

            elif entry_type == "halt":
                print(f"\n🛑 HALT [PC:{entry['pc']}, {entry['scope']}]")
                print(f"   Resultado final: {entry['final_output']}")

        print(f"\n📊 ESTATÍSTICAS:")
        print(f"   Mudanças de escopo: {scope_changes}")
        print(f"   Mudanças de registrador: {register_changes}")
        print(f"   Mudanças de memória: {memory_changes}")
        print(f"   Total de entradas no log: {len(self.execution_log)}")

    def print_gcd_trace(self):
        """Imprime trace específico das chamadas GCD"""
        print("\n" + "=" * 80)
        print("🔍 TRACE ESPECÍFICO DAS CHAMADAS GCD(4,6)")
        print("=" * 80)

        gcd_calls = []
        current_call = None

        for entry in self.execution_log:
            if entry["type"] == "scope_change":
                if "gcd" in entry["new_scope"]:
                    current_call = {
                        "scope": entry["new_scope"],
                        "level": entry["recursion_level"],
                        "parameters": {},
                        "return_value": None,
                    }
                    gcd_calls.append(current_call)
                elif entry["change_type"] == "function_return" and current_call:
                    # Capturar valor de retorno (R1)
                    if "stack_state" in entry:
                        current_call["return_value"] = entry["stack_state"].get(
                            "R1", "N/A"
                        )

        for i, call in enumerate(gcd_calls):
            print(f"\n📞 GCD Call #{i+1}: {call['scope']}")
            print(f"   Nível de recursão: {call['level']}")
            print(f"   Valor de retorno: {call['return_value']}")


def main():
    """Função principal"""
    debugger = MIPSDebugger()

    # Carregar assembly
    debugger.load_assembly("assembly_output.asm")
    print(f"📄 Assembly carregado: {len(debugger.instructions)} instruções")
    print(f"🏷️  Labels encontrados: {debugger.labels}")

    # Executar simulação
    results = debugger.run_simulation()

    # Imprimir resultados
    debugger.print_detailed_log()
    debugger.print_gcd_trace()

    print("\n" + "=" * 80)
    print("🎯 RESULTADO FINAL")
    print("=" * 80)
    print(f"Entradas: x=4, y=6")
    print(f"Resultado obtido: {results}")
    print(f"Resultado esperado: [2] (GCD(4,6) = 2)")

    if results == [2]:
        print("✅ TESTE PASSOU! O algoritmo GCD está funcionando corretamente.")
    else:
        print("❌ TESTE FALHOU! Há problemas na implementação.")


if __name__ == "__main__":
    main()

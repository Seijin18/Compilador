#!/usr/bin/env python3
"""
Simulador MIPS Simplificado - Debug GCD(4,6)
===========================================
"""

import re


class SimpleMIPSDebugger:
    def __init__(self):
        # Registradores
        self.regs = {f"R{i}": 0 for i in range(32)}
        self.regs["R0"] = 0
        self.regs["R29"] = 1000  # Stack pointer
        self.regs["R31"] = 0  # Return address

        # Memória
        self.memory = {}

        # Controle
        self.pc = 0
        self.instructions = []
        self.labels = {}

        # Estado especial
        self.hi = 0
        self.lo = 0

        # Debug
        self.step_count = 0
        self.scope = "BOOT"
        self.recursion_level = 0

        # I/O
        self.inputs = [4, 6]  # x=4, y=6
        self.input_idx = 0
        self.outputs = []

    def load_assembly(self, filename):
        """Carrega assembly e cria mapeamento direto"""
        with open(filename, "r") as f:
            lines = f.readlines()

        # Primeiro passo: coletar instruções
        for line in lines:
            line = line.strip()
            if re.match(r"^\s*\d+:", line):
                match = re.match(r"^\s*(\d+):\s*(\w+)\s*(.*)", line)
                if match:
                    addr = int(match.group(1))
                    op = match.group(2)
                    operands = match.group(3).strip()
                    self.instructions.append((addr, op, operands))

        # Segundo passo: mapear labels
        current_addr = 0
        for line in lines:
            line = line.strip()
            if line.endswith(":") and not re.match(r"^\s*\d+:", line):
                label = line[:-1]
                # Encontrar próxima instrução
                for i, (addr, op, operands) in enumerate(self.instructions):
                    if addr >= current_addr:
                        self.labels[label] = i
                        break
            elif re.match(r"^\s*\d+:", line):
                match = re.match(r"^\s*(\d+):", line)
                if match:
                    current_addr = int(match.group(1)) + 1

        print(f"🏷️  Labels: {self.labels}")
        print(f"📄 Instruções: {len(self.instructions)}")

    def addr_to_index(self, addr):
        """Converte endereço para índice na lista de instruções"""
        for i, (instr_addr, op, operands) in enumerate(self.instructions):
            if instr_addr == addr:
                return i
        return addr  # Fallback

    def run_debug(self):
        """Executa com debug detalhado"""
        print("🚀 EXECUTANDO GCD(4,6) COM DEBUG COMPLETO")
        print("=" * 60)

        # Começar no endereço 0 (J 21)
        self.pc = 0
        max_steps = 500

        while self.step_count < max_steps and self.pc < len(self.instructions):
            addr, op, operands = self.instructions[self.pc]

            print(f"\n📍 PASSO {self.step_count + 1}")
            print(f"   PC: {self.pc} (addr {addr})")
            print(f"   Instrução: {op} {operands}")
            print(f"   Escopo: {self.scope}")
            print(f"   Recursão: {self.recursion_level}")

            # Mostrar registradores não-zero
            non_zero_regs = {k: v for k, v in self.regs.items() if v != 0}
            if non_zero_regs:
                print(f"   Registradores: {non_zero_regs}")

            # Executar instrução
            should_continue = self.execute(op, operands)

            self.step_count += 1

            if not should_continue:
                break

            # Prevenir loop infinito
            if self.step_count >= max_steps:
                print("⚠️  Limite de passos atingido!")
                break

        print(f"\n✅ Execução finalizada")
        print(f"📤 Saídas: {self.outputs}")
        print(f"🎯 Resultado esperado: [2]")

        if self.outputs == [2]:
            print("✅ SUCESSO! GCD(4,6) = 2")
        else:
            print("❌ FALHA! Resultado incorreto")

    def execute(self, op, operands):
        """Executa uma instrução"""
        ops = [x.strip() for x in operands.split(",")] if operands else []

        if op == "J":
            # Jump
            target_addr = int(ops[0])
            self.pc = self.addr_to_index(target_addr)
            if target_addr == 25:  # main
                self.scope = "main"
                print(f"   🔄 Saltando para main")
            return True

        elif op == "JAL":
            # Jump and Link
            target_addr = int(ops[0])
            self.regs["R31"] = self.pc + 1  # Return address (próxima instrução)
            self.pc = self.addr_to_index(target_addr)

            if target_addr == 1:  # gcd
                self.recursion_level += 1
                self.scope = f"gcd_level_{self.recursion_level}"
                print(f"   📞 Chamando GCD (nível {self.recursion_level})")

                # Mostrar parâmetros
                u = self.memory.get(self.regs["R29"] + 0, "N/A")
                v = self.memory.get(self.regs["R29"] + 1, "N/A")
                print(f"      Parâmetros: u={u}, v={v}")
            return True

        elif op == "JR":
            # Jump Register
            reg = ops[0]
            target = self.regs[reg]

            if reg == "R31":  # Return
                if "gcd" in self.scope:
                    return_val = self.regs.get("R1", "N/A")
                    print(f"   🔙 Retornando de GCD com valor: {return_val}")
                    self.recursion_level = max(0, self.recursion_level - 1)
                    if self.recursion_level == 0:
                        self.scope = "main"
                    else:
                        self.scope = f"gcd_level_{self.recursion_level}"

            self.pc = target
            return True

        elif op == "BNE":
            # Branch Not Equal
            reg1, reg2, target_addr = ops[0], ops[1], int(ops[2])
            val1 = self.regs[reg1]
            val2 = self.regs[reg2]

            print(f"   🔍 BNE: {reg1}({val1}) != {reg2}({val2}) ?")

            if val1 != val2:
                self.pc = self.addr_to_index(target_addr)
                print(f"   ✅ Branch tomado para {target_addr}")
            else:
                self.pc += 1
                print(f"   ❌ Branch não tomado")
            return True

        elif op == "LW":
            # Load Word
            reg = ops[0]
            offset_base = ops[1]
            match = re.match(r"(-?\d+)\((\w+)\)", offset_base)
            if match:
                offset = int(match.group(1))
                base_reg = match.group(2)
                addr = self.regs[base_reg] + offset
                value = self.memory.get(addr, 0)
                old_val = self.regs[reg]
                self.regs[reg] = value
                print(f"   💾 LW: {reg} = MEM[{addr}] = {value} (era {old_val})")

        elif op == "SW":
            # Store Word
            reg = ops[0]
            offset_base = ops[1]
            match = re.match(r"(-?\d+)\((\w+)\)", offset_base)
            if match:
                offset = int(match.group(1))
                base_reg = match.group(2)
                addr = self.regs[base_reg] + offset
                value = self.regs[reg]
                old_val = self.memory.get(addr, 0)
                self.memory[addr] = value
                print(f"   💾 SW: MEM[{addr}] = {reg}({value}) (era {old_val})")

        elif op == "MOVE":
            # Move
            dest, src = ops[0], ops[1]
            old_val = self.regs[dest]
            self.regs[dest] = self.regs[src]
            print(f"   📝 MOVE: {dest} = {src}({self.regs[src]}) (era {old_val})")

        elif op == "DIV":
            # Division
            reg1, reg2 = ops[0], ops[1]
            val1, val2 = self.regs[reg1], self.regs[reg2]
            if val2 != 0:
                self.hi = val1 % val2  # Resto
                self.lo = val1 // val2  # Quociente
                print(f"   ➗ DIV: {val1} ÷ {val2} = Q:{self.lo}, R:{self.hi}")

        elif op == "MFHI":
            # Move From HI
            reg = ops[0]
            old_val = self.regs[reg]
            self.regs[reg] = self.hi
            print(f"   📤 MFHI: {reg} = HI({self.hi}) (era {old_val})")

        elif op == "MFLO":
            # Move From LO
            reg = ops[0]
            old_val = self.regs[reg]
            self.regs[reg] = self.lo
            print(f"   📤 MFLO: {reg} = LO({self.lo}) (era {old_val})")

        elif op == "MULT":
            # Multiplication
            reg1, reg2 = ops[0], ops[1]
            val1, val2 = self.regs[reg1], self.regs[reg2]
            result = val1 * val2
            self.lo = result & 0xFFFFFFFF
            self.hi = (result >> 32) & 0xFFFFFFFF
            print(
                f"   ✖️  MULT: {val1} × {val2} = {result} (LO:{self.lo}, HI:{self.hi})"
            )

        elif op == "SUB":
            # Subtraction
            dest, src1, src2 = ops[0], ops[1], ops[2]
            val1, val2 = self.regs[src1], self.regs[src2]
            result = val1 - val2
            old_val = self.regs[dest]
            self.regs[dest] = result
            print(f"   ➖ SUB: {dest} = {val1} - {val2} = {result} (era {old_val})")

        elif op == "INPUT":
            # Input
            reg = ops[0]
            if self.input_idx < len(self.inputs):
                value = self.inputs[self.input_idx]
                self.input_idx += 1
                old_val = self.regs[reg]
                self.regs[reg] = value
                print(f"   📥 INPUT: {reg} = {value} (era {old_val})")

        elif op == "OUTPUTREG":
            # Output
            reg = ops[0]
            value = self.regs[reg]
            self.outputs.append(value)
            print(f"   📤 OUTPUT: {reg}({value})")

        elif op == "HALT":
            # Halt
            print(f"   🛑 HALT - Fim da execução")
            return False

        # Incrementar PC para instruções normais
        if op not in ["J", "JAL", "JR", "BNE", "BEQ"]:
            self.pc += 1

        return True


def main():
    debugger = SimpleMIPSDebugger()
    debugger.load_assembly("assembly_output.asm")
    debugger.run_debug()


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Simulador do Processador MIPS Customizado
==========================================
Baseado na documentação instrucoes_processador.md
Simula a execução de código binário gerado pelo assembler
"""

import sys
import re
from typing import Dict, List, Optional, Tuple


class MIPSSimulator:
    def __init__(self, debug=False):
        """Inicializa o simulador"""
        self.debug = debug

        # Registradores (R0-R31)
        self.registers = [0] * 32

        # Registradores especiais HI e LO para multiplicação/divisão
        self.hi = 0
        self.lo = 0

        # Memória (256 posições de 32 bits)
        self.memory = [0] * 256

        # Program Counter
        self.pc = 0

        # Display (para saída)
        self.display_value = 0

        # Switches (para entrada)
        self.switches_value = 0

        # Flag de halt
        self.halted = False

        # Contador de instruções executadas
        self.instruction_count = 0

        # Histórico de execução
        self.execution_history = []

        # Definição dos opcodes
        self.opcodes = {
            0b000000: "ADD",
            0b000001: "SUB",
            0b000010: "MULT",
            0b000011: "DIV",
            0b000100: "AND",
            0b000101: "OR",
            0b000110: "SLL",
            0b000111: "SRL",
            0b001000: "SLT",
            0b001001: "MFHI",
            0b001010: "MFLO",
            0b001011: "MOVE",
            0b001100: "JR",
            0b001101: "JALR",
            0b001110: "LA",
            0b001111: "ADDI",
            0b010000: "SUBI",
            0b010001: "ANDI",
            0b010010: "ORI",
            0b010011: "BEQ",
            0b010100: "BNE",
            0b010101: "BGT",
            0b010110: "BGTE",
            0b010111: "BLT",
            0b011000: "BLTE",
            0b011001: "LW",
            0b011010: "SW",
            0b011011: "LI",
            0b011100: "J",
            0b011101: "JAL",
            0b011110: "HALT",
            0b011111: "OUTPUTMEM",
            0b100000: "OUTPUTREG",
            0b100001: "OUTPUTRESET",
            0b100010: "INPUT",
        }

    def reset(self):
        """Reset do simulador"""
        self.registers = [0] * 32
        # Inicializa Stack Pointer (R29) no topo da memória
        self.registers[29] = 255  # SP começa em 255
        self.hi = 0
        self.lo = 0
        self.memory = [0] * 256
        self.pc = 0
        self.display_value = 0
        self.switches_value = 0
        self.halted = False
        self.instruction_count = 0
        self.execution_history = []

    def load_binary_file(self, filename: str) -> List[int]:
        """Carrega arquivo binário e converte para lista de instruções"""
        instructions = []
        try:
            with open(filename, "r") as f:
                for line_num, line in enumerate(f, 1):
                    line = line.strip()
                    if line and not line.startswith("#"):
                        # Remove comentários da linha
                        if "#" in line:
                            line = line[: line.index("#")].strip()

                        # Verifica se é binário válido (32 bits)
                        if re.match(r"^[01]{32}$", line):
                            instruction = int(line, 2)
                            instructions.append(instruction)
                        elif line:  # Linha não vazia que não é binário válido
                            print(
                                f"Aviso: Linha {line_num} ignorada (formato inválido): {line}"
                            )
        except FileNotFoundError:
            print(f"Erro: Arquivo {filename} não encontrado")
            return []
        except Exception as e:
            print(f"Erro ao ler arquivo: {e}")
            return []

        return instructions

    def decode_instruction(self, instruction: int) -> Dict:
        """Decodifica uma instrução de 32 bits"""
        opcode = (instruction >> 26) & 0x3F  # bits 31-26
        rs = (instruction >> 20) & 0x3F  # bits 25-20
        rt = (instruction >> 14) & 0x3F  # bits 19-14
        rd = (instruction >> 8) & 0x3F  # bits 13-8
        immediate = instruction & 0xFF  # bits 7-0 (8 bits)
        immediate_14 = instruction & 0x3FFF  # bits 13-0 (14 bits)
        shamt = immediate & 0x1F  # bits 4-0 para shift

        return {
            "opcode": opcode,
            "rs": rs,
            "rt": rt,
            "rd": rd,
            "immediate": immediate,
            "immediate_14": immediate_14,
            "shamt": shamt,
            "instruction": instruction,
        }

    def sign_extend(self, value: int, bits: int) -> int:
        """Extensão de sinal para valores imediatos"""
        if value & (1 << (bits - 1)):
            return value | (0xFFFFFFFF << bits)
        return value

    def execute_instruction(self, instruction: int) -> bool:
        """Executa uma instrução. Retorna False se deve parar"""
        decoded = self.decode_instruction(instruction)
        opcode = decoded["opcode"]

        if opcode not in self.opcodes:
            print(
                f"Erro: Opcode desconhecido {opcode:06b} na instrução {instruction:032b}"
            )
            return False

        mnemonic = self.opcodes[opcode]

        if self.debug:
            self.log_instruction(decoded, mnemonic)

        # Executa a instrução baseada no opcode
        try:
            if mnemonic == "ADD":
                self.registers[decoded["rd"]] = (
                    self.registers[decoded["rs"]] + self.registers[decoded["rt"]]
                ) & 0xFFFFFFFF

            elif mnemonic == "SUB":
                self.registers[decoded["rd"]] = (
                    self.registers[decoded["rs"]] - self.registers[decoded["rt"]]
                ) & 0xFFFFFFFF

            elif mnemonic == "MULT":
                result = self.registers[decoded["rs"]] * self.registers[decoded["rt"]]
                self.hi = (result >> 32) & 0xFFFFFFFF
                self.lo = result & 0xFFFFFFFF

            elif mnemonic == "DIV":
                if self.registers[decoded["rt"]] != 0:
                    self.hi = (
                        self.registers[decoded["rs"]] // self.registers[decoded["rt"]]
                    )
                    self.lo = (
                        self.registers[decoded["rs"]] % self.registers[decoded["rt"]]
                    )
                else:
                    print("Erro: Divisão por zero")
                    return False

            elif mnemonic == "AND":
                self.registers[decoded["rd"]] = (
                    self.registers[decoded["rs"]] & self.registers[decoded["rt"]]
                )

            elif mnemonic == "OR":
                self.registers[decoded["rd"]] = (
                    self.registers[decoded["rs"]] | self.registers[decoded["rt"]]
                )

            elif mnemonic == "SLL":
                self.registers[decoded["rd"]] = (
                    self.registers[decoded["rs"]] << decoded["shamt"]
                ) & 0xFFFFFFFF

            elif mnemonic == "SRL":
                self.registers[decoded["rd"]] = (
                    self.registers[decoded["rs"]] >> decoded["shamt"]
                )

            elif mnemonic == "SLT":
                self.registers[decoded["rd"]] = (
                    1
                    if self.registers[decoded["rs"]] < self.registers[decoded["rt"]]
                    else 0
                )

            elif mnemonic == "MFHI":
                self.registers[decoded["rd"]] = self.hi

            elif mnemonic == "MFLO":
                self.registers[decoded["rd"]] = self.lo

            elif mnemonic == "MOVE":
                self.registers[decoded["rd"]] = self.registers[decoded["rs"]]

            elif mnemonic == "JR":
                self.pc = self.registers[decoded["rs"]]

            elif mnemonic == "JALR":
                self.registers[31] = self.pc + 1  # R31 = PC+1
                self.pc = self.registers[decoded["rs"]]

            elif mnemonic == "LA":
                self.registers[decoded["rd"]] = decoded["immediate"]

            elif mnemonic == "ADDI":
                imm = self.sign_extend(decoded["immediate"], 8)
                self.registers[decoded["rt"]] = (
                    self.registers[decoded["rs"]] + imm
                ) & 0xFFFFFFFF

            elif mnemonic == "SUBI":
                imm = self.sign_extend(decoded["immediate"], 8)
                self.registers[decoded["rt"]] = (
                    self.registers[decoded["rs"]] - imm
                ) & 0xFFFFFFFF

            elif mnemonic == "ANDI":
                self.registers[decoded["rt"]] = (
                    self.registers[decoded["rs"]] & decoded["immediate"]
                )

            elif mnemonic == "ORI":
                self.registers[decoded["rt"]] = (
                    self.registers[decoded["rs"]] | decoded["immediate"]
                )

            elif mnemonic == "LI":
                self.registers[decoded["rt"]] = decoded["immediate_14"]

            elif mnemonic == "BEQ":
                if self.registers[decoded["rs"]] == self.registers[decoded["rt"]]:
                    self.pc = decoded["immediate"]
                # Não precisa de else, PC será incrementado automaticamente

            elif mnemonic == "BNE":
                if self.registers[decoded["rs"]] != self.registers[decoded["rt"]]:
                    self.pc = decoded["immediate"]
                # Não precisa de else, PC será incrementado automaticamente

            elif mnemonic == "BGT":
                if self.registers[decoded["rs"]] > self.registers[decoded["rt"]]:
                    self.pc = decoded["immediate"]
                # Não precisa de else, PC será incrementado automaticamente

            elif mnemonic == "BGTE":
                if self.registers[decoded["rs"]] >= self.registers[decoded["rt"]]:
                    self.pc = decoded["immediate"]
                # Não precisa de else, PC será incrementado automaticamente

            elif mnemonic == "BLT":
                if self.registers[decoded["rs"]] < self.registers[decoded["rt"]]:
                    self.pc = decoded["immediate"]
                # Não precisa de else, PC será incrementado automaticamente

            elif mnemonic == "BLTE":
                if self.registers[decoded["rs"]] <= self.registers[decoded["rt"]]:
                    self.pc = decoded["immediate"]
                # Não precisa de else, PC será incrementado automaticamente

            elif mnemonic == "LW":
                addr = (
                    self.registers[decoded["rs"]] + decoded["immediate"]
                ) % 256  # Mod 256 para wraparound
                if addr < len(self.memory):
                    self.registers[decoded["rt"]] = self.memory[addr]
                else:
                    print(f"Erro: Acesso à memória fora dos limites: {addr}")
                    return False

            elif mnemonic == "SW":
                addr = (
                    self.registers[decoded["rs"]] + decoded["immediate"]
                ) % 256  # Mod 256 para wraparound
                if addr < len(self.memory):
                    self.memory[addr] = self.registers[decoded["rt"]]
                else:
                    print(f"Erro: Acesso à memória fora dos limites: {addr}")
                    return False

            elif mnemonic == "J":
                self.pc = decoded["immediate"]

            elif mnemonic == "JAL":
                self.registers[31] = self.pc + 1  # R31 = PC+1
                self.pc = decoded["immediate"]

            elif mnemonic == "OUTPUTMEM":
                addr = self.registers[decoded["rs"]] + decoded["immediate"]
                if addr < len(self.memory):
                    self.display_value = self.memory[addr]
                    print(f"DISPLAY: {self.display_value}")

            elif mnemonic == "OUTPUTREG":
                self.display_value = self.registers[decoded["rs"]]
                print(f"DISPLAY: {self.display_value}")

            elif mnemonic == "OUTPUTRESET":
                self.display_value = 0
                print("DISPLAY: RESET")

            elif mnemonic == "INPUT":
                if hasattr(self, "input_values") and self.input_values:
                    value = self.input_values.pop(0)
                    self.registers[decoded["rd"]] = value & 0xFFFFFFFF
                    if self.debug:
                        print(f"INPUT R{decoded['rd']} = {value}")
                else:
                    value = input(f"INPUT para R{decoded['rd']}: ")
                    try:
                        self.registers[decoded["rd"]] = int(value) & 0xFFFFFFFF
                    except ValueError:
                        print("Valor inválido, usando 0")
                        self.registers[decoded["rd"]] = 0

            elif mnemonic == "HALT":
                self.halted = True
                print("PROCESSADOR PARADO (HALT)")
                return False

            # Garante que R0 sempre seja 0
            self.registers[0] = 0

        except Exception as e:
            print(f"Erro na execução da instrução {mnemonic}: {e}")
            return False

        return True

    def log_instruction(self, decoded: Dict, mnemonic: str):
        """Log da instrução executada"""
        entry = {
            "pc": self.pc,
            "instruction": decoded["instruction"],
            "mnemonic": mnemonic,
            "opcode": decoded["opcode"],
            "rs": decoded["rs"],
            "rt": decoded["rt"],
            "rd": decoded["rd"],
            "immediate": decoded["immediate"],
        }
        self.execution_history.append(entry)

        if self.debug:
            print(f"PC={self.pc:3d}: {mnemonic:10s} | {decoded['instruction']:032b}")

    def run(
        self,
        instructions: List[int],
        max_cycles: int = 10000,
        input_values: List[int] = None,
    ) -> Dict:
        """Executa o programa"""
        if input_values:
            self.input_values = input_values.copy()

        self.reset()

        print(f"Iniciando simulação com {len(instructions)} instruções...")
        print("=" * 60)

        while not self.halted and self.instruction_count < max_cycles:
            if self.pc >= len(instructions):
                print(f"Erro: PC ({self.pc}) fora do range de instruções")
                break

            instruction = instructions[self.pc]
            old_pc = self.pc  # Salva PC antes da execução

            # Incrementa contador antes da execução
            self.instruction_count += 1

            # Executa instrução
            continue_execution = self.execute_instruction(instruction)

            if not continue_execution:
                break

            # Incrementa PC automaticamente se a instrução não mudou o PC
            if self.pc == old_pc:
                self.pc += 1

        return self.get_execution_summary()

    def is_jump_instruction(self, instruction: int) -> bool:
        """Verifica se é uma instrução de salto"""
        opcode = (instruction >> 26) & 0x3F
        jump_opcodes = [
            0b001100,
            0b001101,
            0b011100,
            0b011101,  # JR, JALR, J, JAL
            0b010011,
            0b010100,
            0b010101,
            0b010110,  # BEQ, BNE, BGT, BGTE
            0b010111,
            0b011000,
        ]  # BLT, BLTE
        return opcode in jump_opcodes

    def get_execution_summary(self) -> Dict:
        """Retorna resumo da execução"""
        return {
            "instructions_executed": self.instruction_count,
            "final_pc": self.pc,
            "registers": self.registers.copy(),
            "hi": self.hi,
            "lo": self.lo,
            "memory": [
                val for val in self.memory if val != 0
            ],  # Apenas posições não-zero
            "display_value": self.display_value,
            "halted": self.halted,
            "execution_history": self.execution_history,
        }

    def print_state(self):
        """Imprime estado atual do processador"""
        print("\n" + "=" * 60)
        print("ESTADO DO PROCESSADOR")
        print("=" * 60)
        print(f"PC: {self.pc}")
        print(f"Instruções executadas: {self.instruction_count}")
        print(f"HI: {self.hi}, LO: {self.lo}")
        print(f"Display: {self.display_value}")
        print(f"Halted: {self.halted}")

        print("\nREGISTRADORES:")
        for i in range(0, 32, 4):
            reg_str = ""
            for j in range(4):
                if i + j < 32:
                    reg_str += f"R{i+j:2d}={self.registers[i+j]:8d} "
            print(reg_str)

        print("\nMEMÓRIA (posições não-zero):")
        for i, val in enumerate(self.memory):
            if val != 0:
                print(f"MEM[{i:3d}] = {val}")
        print("=" * 60)


def main():
    """Função principal"""
    if len(sys.argv) < 2:
        print("Uso: python simulator_mips.py <arquivo_binario> [valores_input...]")
        print("Exemplo: python simulator_mips.py binary_output.txt 15 25")
        return

    binary_file = sys.argv[1]
    input_values = []

    # Parse dos valores de entrada
    if len(sys.argv) > 2:
        try:
            input_values = [int(x) for x in sys.argv[2:]]
        except ValueError:
            print("Erro: Valores de entrada devem ser números inteiros")
            return

    # Cria e executa simulador
    simulator = MIPSSimulator(debug=True)
    instructions = simulator.load_binary_file(binary_file)

    if not instructions:
        print("Nenhuma instrução carregada")
        return

    print(f"Carregadas {len(instructions)} instruções")
    if input_values:
        print(f"Valores de entrada: {input_values}")

    # Executa simulação
    summary = simulator.run(instructions, input_values=input_values)

    # Mostra resultado
    simulator.print_state()

    print(f"\nSimulação concluída em {summary['instructions_executed']} ciclos")


if __name__ == "__main__":
    main()

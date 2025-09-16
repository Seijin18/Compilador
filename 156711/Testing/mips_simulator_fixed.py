#!/usr/bin/env python3
"""
Simulador do Processador MIPS Customizado
Executa o código assembly gerado pelo compilador
"""


class MIPSSimulator:
    def __init__(self, input_values=None, architecture_bits=32):
        # Configuração flexível de arquitetura
        self.architecture_bits = architecture_bits
        self.max_value = (1 << architecture_bits) - 1  # Máximo valor para registradores

        # Banco de registradores (32 registradores)
        self.registers = [0] * 32

        # Memória RAM (256 bytes)
        self.memory = [0] * 256

        # Program Counter
        self.pc = 0

        # Registradores especiais
        self.GP = 28  # Global Pointer
        self.SP = 29  # Stack Pointer
        self.FP = 30  # Frame Pointer
        self.RA = 31  # Return Address

        # Registradores especiais para multiplicação/divisão
        self.hi_register = 0
        self.lo_register = 0

        # Instruções carregadas
        self.instructions = []
        self.labels = {}

        # Valores de entrada configuráveis (simulando INPUT)
        self.input_values = input_values if input_values is not None else []
        self.input_index = 0

        # Histórico de saídas (para programas que fazem múltiplos outputs)
        self.output_values = []
        self.output_value = None  # Última saída (para compatibilidade)

        # Flag de halt
        self.halted = False

        # Contador de ciclos para debug
        self.cycle_count = 0

        # Contador de vezes que voltou ao PC=0 (para detectar loop infinito)
        self.pc_zero_count = 0

        # LOG DE DEBUG: arquivo para transcrever execução
        self.debug_log = []
        self.debug_file = None

        print(f"🔧 Simulador MIPS inicializado")
        print(f"📊 Memória: {len(self.memory)} bytes")
        print(f"📋 Registradores: {len(self.registers)} de {architecture_bits} bits")
        print(f"🔢 Entradas programadas: {self.input_values}")

    def start_debug_log(self, filename="execution_debug.txt"):
        """Inicia o arquivo de log de debug"""
        self.debug_file = open(filename, "w", encoding="utf-8")
        self.debug_file.write("=== LOG DE EXECUÇÃO DETALHADO - MIPS SIMULATOR ===\n")
        self.debug_file.write(f"Arquivo gerado automaticamente para debug\n")
        self.debug_file.write(f"Arquitetura: {self.architecture_bits} bits\n")
        self.debug_file.write(f"Entradas programadas: {self.input_values}\n")
        self.debug_file.write("=" * 60 + "\n\n")
        print(f"📝 Log de debug iniciado: {filename}")

    def log_debug(self, message):
        """Adiciona uma mensagem ao log de debug"""
        if self.debug_file:
            self.debug_file.write(f"{message}\n")
            self.debug_file.flush()  # Força escrita imediata

    def log_instruction(self, pc, instruction, details=""):
        """Registra execução de uma instrução no log"""
        self.cycle_count += 1
        log_entry = (
            f"CICLO {self.cycle_count:3d}: PC={pc:2d} | {instruction:<20} | {details}"
        )
        self.log_debug(log_entry)

        # Adicionar estado dos registradores importantes a cada 10 ciclos
        if self.cycle_count % 10 == 0:
            self.log_register_state()

    def log_register_state(self):
        """Registra estado atual dos registradores no log"""
        important_regs = []
        for i in range(32):
            if self.registers[i] != 0:
                reg_name = self.get_register_name(i)
                important_regs.append(f"{reg_name}={self.registers[i]}")

        if important_regs:
            self.log_debug(f"    ESTADO: {', '.join(important_regs)}")
        else:
            self.log_debug(f"    ESTADO: Todos registradores zerados")
        self.log_debug("")  # Linha em branco para separar

    def get_register_name(self, reg_num):
        """Retorna nome amigável do registrador"""
        special_regs = {28: "GP", 29: "SP", 30: "FP", 31: "RA"}
        return special_regs.get(reg_num, f"R{reg_num}")

    def close_debug_log(self):
        """Fecha o arquivo de log de debug"""
        if self.debug_file:
            self.debug_file.write(f"\n=== FIM DA EXECUÇÃO ===\n")
            self.debug_file.write(f"Total de ciclos: {self.cycle_count}\n")
            self.debug_file.write(f"Saídas geradas: {self.output_values}\n")
            self.debug_file.write(f"Resultado final: {self.output_value}\n")
            self.debug_file.close()
            self.debug_file = None
            print(f"📝 Log de debug salvo com {self.cycle_count} ciclos registrados")

    def load_assembly(self, filename):
        """Carrega o arquivo assembly e converte para instruções"""
        print(f"\n📂 Carregando assembly: {filename}")

        with open(filename, "r", encoding="utf-8") as file:
            lines = file.readlines()

        for line_num, line in enumerate(lines):
            line = line.strip()

            # Ignorar comentários e linhas vazias
            if line.startswith("#") or not line:
                continue

            # Processar labels
            if line.endswith(":"):
                label = line[:-1]
                self.labels[label] = len(self.instructions)
                print(
                    f"🏷️  Label encontrado: {label} -> posição {len(self.instructions)}"
                )
                continue

            # Processar instruções numeradas
            if ":" in line and line.split(":", 1)[0].strip().isdigit():
                parts = line.split(":", 1)
                addr = int(parts[0].strip())
                instruction_text = parts[1].strip()

                # Parse da instrução
                instruction = self.parse_instruction(instruction_text)
                if instruction:
                    self.instructions.append(instruction)
                    print(f"📋 [{addr:2d}] {instruction}")

        print(f"OK Carregadas {len(self.instructions)} instrucoes")
        print(f"🏷️  Labels: {self.labels}")

    def parse_instruction(self, text):
        """Converte texto da instrução para dicionário"""
        parts = text.split()
        if not parts:
            return None

        opcode = parts[0]

        instruction = {"opcode": opcode, "args": []}

        if len(parts) > 1:
            # Juntar argumentos e fazer parse
            args_text = " ".join(parts[1:])
            args = [arg.strip() for arg in args_text.split(",")]
            instruction["args"] = args

        return instruction

    def get_register_number(self, reg_str):
        """Converte nome de registrador para número"""
        reg_str = reg_str.strip()

        # Registradores especiais
        if reg_str == "GP":
            return self.GP
        elif reg_str == "SP":
            return self.SP
        elif reg_str == "FP":
            return self.FP
        elif reg_str == "RA":
            return self.RA
        elif reg_str.startswith("R") and len(reg_str) > 1:
            return int(reg_str[1:])
        else:
            # Tentar converter diretamente para número
            try:
                return int(reg_str)
            except ValueError:
                print(f"❌ Registrador inválido: {reg_str}")
                return 0

    def get_immediate_value(self, value_str):
        """Extrai valor imediato de string"""
        value_str = value_str.strip()

        # Remover parênteses se houver (para offset addressing)
        if "(" in value_str:
            # Formato: offset(reg)
            offset_str = value_str.split("(")[0]
            return int(offset_str)

        return int(value_str)

    def execute_instruction(self, instruction):
        """Executa uma única instrução"""
        opcode = instruction["opcode"]
        args = instruction["args"]

        # Formatar instrução para display e log
        instr_str = f"{opcode} {', '.join(args)}"
        print(f"PC={self.pc:2d}: {instr_str}")

        # LOG: Registrar início da execução da instrução
        self.log_instruction(self.pc, instr_str, "INICIANDO")

        if opcode == "LI":
            # Load Immediate: LI rt, immediate
            rt = self.get_register_number(args[0])
            immediate = self.get_immediate_value(args[1])
            self.registers[rt] = (
                immediate & self.max_value
            )  # Aplicar máscara da arquitetura
            result_msg = f"R{rt} = {self.registers[rt]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "J":
            # Jump: J target
            target = self.get_immediate_value(args[0])
            self.pc = target
            result_msg = f"Jump to {target}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)
            return  # Não incrementar PC

        elif opcode == "MOVE":
            # Move: MOVE rd, rs
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            old_value = self.registers[rd]
            self.registers[rd] = self.registers[rs]
            result_msg = f"R{rd} = R{rs} = {self.registers[rd]} (era {old_value})"
            print(f"   R{rd} = R{rs} = {self.registers[rd]}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "SUBI":
            # Subtract Immediate: SUBI rt, rs, immediate
            rt = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            immediate = self.get_immediate_value(args[2])
            old_value = self.registers[rt]
            self.registers[rt] = (self.registers[rs] - immediate) & self.max_value
            result_msg = f"R{rt} = R{rs}({self.registers[rs]}) - {immediate} = {self.registers[rt]} (era {old_value})"
            print(f"   R{rt} = R{rs} - {immediate} = {self.registers[rt]}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "ADDI":
            # Add Immediate: ADDI rt, rs, immediate
            rt = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            immediate = self.get_immediate_value(args[2])
            old_value = self.registers[rt]
            self.registers[rt] = (self.registers[rs] + immediate) & self.max_value
            result_msg = f"R{rt} = R{rs}({self.registers[rs]}) + {immediate} = {self.registers[rt]} (era {old_value})"
            print(f"   R{rt} = R{rs} + {immediate} = {self.registers[rt]}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "SW":
            # Store Word: SW rt, offset(rs)
            rt = self.get_register_number(args[0])
            offset_str = args[1]

            if "(" in offset_str:
                offset = self.get_immediate_value(offset_str)
                rs = self.get_register_number(offset_str.split("(")[1].replace(")", ""))
                address = (self.registers[rs] + offset) & 0xFF
            else:
                address = self.get_immediate_value(offset_str) & 0xFF

            self.memory[address] = (
                self.registers[rt] & 0xFF
            )  # Garantir que cabe na memória
            result_msg = f"MEM[{address}] = R{rt} = {self.registers[rt]}"
            print(f"   MEM[{address}] = R{rt} = {self.registers[rt]}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "LW":
            # Load Word: LW rt, offset(rs)
            rt = self.get_register_number(args[0])
            offset_str = args[1]

            if "(" in offset_str:
                offset = self.get_immediate_value(offset_str)
                rs = self.get_register_number(offset_str.split("(")[1].replace(")", ""))
                address = (self.registers[rs] + offset) & 0xFF
            else:
                address = self.get_immediate_value(offset_str) & 0xFF

            self.registers[rt] = self.memory[address] & self.max_value
            result_msg = f"R{rt} = MEM[{address}] = {self.registers[rt]}"
            print(f"   R{rt} = MEM[{address}] = {self.registers[rt]}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "BNE":
            # Branch Not Equal: BNE rs, rt, target
            rs = self.get_register_number(args[0])
            rt = self.get_register_number(args[1])
            target = self.get_immediate_value(args[2])

            result_msg = f"R{rs}({self.registers[rs]}) != R{rt}({self.registers[rt]})"
            if self.registers[rs] != self.registers[rt]:
                self.pc = target
                result_msg += f" -> Jump to {target}"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)
                return  # Não incrementar PC
            else:
                result_msg += " -> Continue"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "BEQ":
            # Branch Equal: BEQ rs, rt, target
            rs = self.get_register_number(args[0])
            rt = self.get_register_number(args[1])
            target = self.get_immediate_value(args[2])

            result_msg = f"R{rs}({self.registers[rs]}) == R{rt}({self.registers[rt]})"
            if self.registers[rs] == self.registers[rt]:
                self.pc = target
                result_msg += f" -> Jump to {target}"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)
                return  # Não incrementar PC
            else:
                result_msg += " -> Continue"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "JAL":
            # Jump and Link: JAL target
            target = self.get_immediate_value(args[0])
            self.registers[self.RA] = self.pc + 1  # Salvar endereço de retorno
            self.pc = target
            result_msg = f"RA = {self.registers[self.RA]}, Jump to {target}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)
            return  # Não incrementar PC

        elif opcode == "JR":
            # Jump Register: JR rs
            rs = self.get_register_number(args[0])
            self.pc = self.registers[rs]
            result_msg = f"Jump to R{rs} = {self.registers[rs]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)
            return  # Não incrementar PC

        elif opcode == "DIV":
            # Divide: DIV rs, rt
            rs = self.get_register_number(args[0])
            rt = self.get_register_number(args[1])

            if self.registers[rt] != 0:
                quotient = self.registers[rs] // self.registers[rt]
                remainder = self.registers[rs] % self.registers[rt]
                # Conforme especificação: HI = quociente, LO = resto
                self.hi_register = quotient & self.max_value
                self.lo_register = remainder & self.max_value
                result_msg = f"{self.registers[rs]} / {self.registers[rt]} = Q:{quotient}, R:{remainder}"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)
            else:
                result_msg = "Divisão por zero!"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)
                self.hi_register = 0
                self.lo_register = 0

        elif opcode == "MULT":
            # Multiply: MULT rs, rt
            rs = self.get_register_number(args[0])
            rt = self.get_register_number(args[1])

            result = self.registers[rs] * self.registers[rt]
            # Para arquitetura flexível
            low_bits = self.architecture_bits // 2 if self.architecture_bits > 8 else 8
            self.lo_register = result & ((1 << low_bits) - 1)  # Bits baixos
            self.hi_register = (result >> low_bits) & (
                (1 << low_bits) - 1
            )  # Bits altos
            result_msg = f"{self.registers[rs]} * {self.registers[rt]} = {result} (HI:{self.hi_register}, LO:{self.lo_register})"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "MFLO":
            # Move From LO: MFLO rd
            rd = self.get_register_number(args[0])
            self.registers[rd] = self.lo_register & self.max_value
            result_msg = f"R{rd} = LO = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "MFHI":
            # Move From HI: MFHI rd
            rd = self.get_register_number(args[0])
            self.registers[rd] = self.hi_register & self.max_value
            result_msg = f"R{rd} = HI = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "SUB":
            # Subtract: SUB rd, rs, rt
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            rt = self.get_register_number(args[2])
            self.registers[rd] = (
                self.registers[rs] - self.registers[rt]
            ) & self.max_value
            result_msg = f"R{rd} = R{rs} - R{rt} = {self.registers[rs]} - {self.registers[rt]} = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "ADD":
            # Add: ADD rd, rs, rt
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            rt = self.get_register_number(args[2])
            self.registers[rd] = (
                self.registers[rs] + self.registers[rt]
            ) & self.max_value
            result_msg = f"R{rd} = R{rs} + R{rt} = {self.registers[rs]} + {self.registers[rt]} = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        # Instruções de comparação e branch adicionais
        elif opcode in ["BGT", "BLT", "BGTE", "BLTE"]:
            # Branch Greater Than, Less Than, etc.
            rs = self.get_register_number(args[0])
            rt = self.get_register_number(args[1])
            target = self.get_immediate_value(args[2])

            condition_met = False
            if opcode == "BGT":
                condition_met = self.registers[rs] > self.registers[rt]
                condition_str = ">"
            elif opcode == "BLT":
                condition_met = self.registers[rs] < self.registers[rt]
                condition_str = "<"
            elif opcode == "BGTE":
                condition_met = self.registers[rs] >= self.registers[rt]
                condition_str = ">="
            elif opcode == "BLTE":
                condition_met = self.registers[rs] <= self.registers[rt]
                condition_str = "<="

            result_msg = f"R{rs}({self.registers[rs]}) {condition_str} R{rt}({self.registers[rt]})"
            if condition_met:
                self.pc = target
                result_msg += f" -> Jump to {target}"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)
                return  # Não incrementar PC
            else:
                result_msg += " -> Continue"
                print(f"   {result_msg}")
                self.log_instruction(self.pc, instr_str, result_msg)

        # Instruções lógicas
        elif opcode == "AND":
            # Logical AND: AND rd, rs, rt
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            rt = self.get_register_number(args[2])
            self.registers[rd] = (
                self.registers[rs] & self.registers[rt]
            ) & self.max_value
            result_msg = f"R{rd} = R{rs} & R{rt} = {self.registers[rs]} & {self.registers[rt]} = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "OR":
            # Logical OR: OR rd, rs, rt
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            rt = self.get_register_number(args[2])
            self.registers[rd] = (
                self.registers[rs] | self.registers[rt]
            ) & self.max_value
            result_msg = f"R{rd} = R{rs} | R{rt} = {self.registers[rs]} | {self.registers[rt]} = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        # Instruções de shift
        elif opcode == "SLL":
            # Shift Left Logical: SLL rd, rs, shamt
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            shamt = self.get_immediate_value(args[2])
            self.registers[rd] = (self.registers[rs] << shamt) & self.max_value
            result_msg = f"R{rd} = R{rs} << {shamt} = {self.registers[rs]} << {shamt} = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "SRL":
            # Shift Right Logical: SRL rd, rs, shamt
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            shamt = self.get_immediate_value(args[2])
            self.registers[rd] = (self.registers[rs] >> shamt) & self.max_value
            result_msg = f"R{rd} = R{rs} >> {shamt} = {self.registers[rs]} >> {shamt} = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        # Set Less Than
        elif opcode == "SLT":
            # Set Less Than: SLT rd, rs, rt
            rd = self.get_register_number(args[0])
            rs = self.get_register_number(args[1])
            rt = self.get_register_number(args[2])
            self.registers[rd] = 1 if self.registers[rs] < self.registers[rt] else 0
            result_msg = f"R{rd} = (R{rs} < R{rt}) = ({self.registers[rs]} < {self.registers[rt]}) = {self.registers[rd]}"
            print(f"   {result_msg}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "INPUT":
            # Input: INPUT rd
            rd = self.get_register_number(args[0])
            if self.input_index < len(self.input_values):
                old_value = self.registers[rd]
                self.registers[rd] = (
                    self.input_values[self.input_index] & self.max_value
                )
                result_msg = f"INPUT[{self.input_index}]: R{rd} = {self.registers[rd]} (era {old_value})"
                print(f"   📥 INPUT: R{rd} = {self.registers[rd]}")
                self.log_instruction(self.pc, instr_str, result_msg)
                self.input_index += 1
            else:
                old_value = self.registers[rd]
                self.registers[rd] = 0
                result_msg = f"INPUT[SEM MAIS VALORES]: R{rd} = 0 (era {old_value})"
                print(f"   📥 INPUT: Sem mais valores, R{rd} = 0")
                self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "OUTPUTREG":
            # Output Register: OUTPUTREG rs
            rs = self.get_register_number(args[0])
            output_val = self.registers[rs] & self.max_value
            self.output_values.append(output_val)  # Adicionar ao histórico
            self.output_value = output_val  # Manter última saída
            result_msg = f"OUTPUT: {output_val} (de R{rs})"
            print(f"   OUTPUT: {output_val}")
            self.log_instruction(self.pc, instr_str, result_msg)

        elif opcode == "HALT":
            # Halt
            self.halted = True
            result_msg = f"PROGRAMA FINALIZADO - Saídas: {self.output_values}"
            print(f"   HALT - Programa finalizado")
            self.log_instruction(self.pc, instr_str, result_msg)
            return

        else:
            print(f"   ⚠️  Instrução não implementada: {opcode}")

        # Incrementar PC para próxima instrução
        self.pc += 1

    def run(self, max_cycles=1000):
        """Executa o programa carregado"""
        # INICIALIZAR LOG DE DEBUG
        self.start_debug_log("execution_debug.txt")

        print(f"\nIniciando execucao...")
        print(f"PC inicial: {self.pc}")
        print(f"Limite de ciclos: {max_cycles}")

        cycle = 0

        while not self.halted and cycle < max_cycles:
            if self.pc >= len(self.instructions):
                print(f"❌ PC fora dos limites: {self.pc} >= {len(self.instructions)}")
                self.log_debug(
                    f"ERRO: PC fora dos limites: {self.pc} >= {len(self.instructions)}"
                )
                break

            # Detectar possível loop infinito ao voltar ao PC=0 muitas vezes
            if self.pc == 0:
                self.pc_zero_count += 1
                if self.pc_zero_count > 3:  # Permitir algumas voltas ao PC=0
                    print(
                        f"🔄 Possível loop infinito: voltou ao PC=0 {self.pc_zero_count} vezes"
                    )
                    print(f"🛑 Interrompendo execução para evitar loop infinito")
                    self.log_debug(
                        f"LOOP INFINITO DETECTADO: PC=0 visitado {self.pc_zero_count} vezes"
                    )
                    break

            instruction = self.instructions[self.pc]
            self.execute_instruction(instruction)

            # Se HALT foi executado, parar imediatamente
            if self.halted:
                print(f"🛑 HALT detectado - programa finalizado!")
                break

            cycle += 1

            # Debug: mostrar estado dos registradores importantes periodicamente
            if cycle % 50 == 0:
                self.print_register_state()

        if cycle >= max_cycles:
            print(f"⚠️  Execução interrompida após {max_cycles} ciclos")
            self.log_debug(f"AVISO: Execução interrompida após {max_cycles} ciclos")
            if self.output_values:
                print(f"📤 Saídas obtidas até agora: {self.output_values}")

        print(f"\n✅ Execução finalizada após {cycle} ciclos")
        print(f"📤 Saídas geradas: {self.output_values}")
        print(f"🎯 Última saída: {self.output_value}")

        # FECHAR LOG DE DEBUG
        self.close_debug_log()

        return self.output_value

    def print_register_state(self):
        """Imprime estado dos registradores importantes"""
        print(
            f"   📊 Registradores: R1={self.registers[1]}, SP={self.registers[self.SP]}, "
            + f"FP={self.registers[self.FP]}, RA={self.registers[self.RA]}"
        )

    def print_final_state(self):
        """Imprime estado final do simulador"""
        print(f"\nEstado Final:")
        print(f"Saidas geradas: {self.output_values}")
        print(f"Ultima saida: {self.output_value}")
        print(f"PC final: {self.pc}")
        print(f"Entradas processadas: {self.input_index}/{len(self.input_values)}")

        # Mostrar registradores não-zero
        non_zero_regs = []
        for i, val in enumerate(self.registers):
            if val != 0:
                name = self.get_register_name(i)
                non_zero_regs.append(f"{name}={val}")

        if non_zero_regs:
            print(f"📋 Registradores não-zero: {', '.join(non_zero_regs)}")
        else:
            print(f"📋 Todos os registradores estão zerados")

    def set_input_values(self, values):
        """Define os valores de entrada para o programa"""
        self.input_values = values if values is not None else []
        self.input_index = 0
        print(f"🔢 Valores de entrada definidos: {self.input_values}")

    def get_output_values(self):
        """Retorna todas as saídas geradas"""
        return self.output_values

    def get_last_output(self):
        """Retorna a última saída gerada"""
        return self.output_value

    def reset(self):
        """Reseta o estado do simulador"""
        self.registers = [0] * 32
        self.memory = [0] * 256
        self.pc = 0
        self.input_index = 0
        self.output_values = []
        self.output_value = None
        self.halted = False
        self.cycle_count = 0
        self.pc_zero_count = 0
        self.hi_register = 0
        self.lo_register = 0
        print("🔄 Simulador resetado")


def main():
    """Função principal"""
    import sys
    import os

    print("Simulador MIPS Customizado - Versao Generica")
    print("=" * 60)

    # Permitir argumentos da linha de comando
    assembly_file = "assembly_output.asm"  # Padrão
    input_values = []
    expected_output = None

    if len(sys.argv) > 1:
        assembly_file = sys.argv[1]
    if len(sys.argv) > 2:
        # Valores de entrada separados por vírgula
        input_str = sys.argv[2]
        input_values = [int(x.strip()) for x in input_str.split(",")]
    if len(sys.argv) > 3:
        expected_output = int(sys.argv[3])

    # Se não há argumentos, usar interface interativa
    if len(sys.argv) == 1:
        print("📋 Modo interativo:")
        assembly_file = input(
            "Digite o nome do arquivo assembly (ou Enter para 'assembly_output.asm'): "
        ).strip()
        if not assembly_file:
            assembly_file = "assembly_output.asm"

        input_str = input(
            "Digite os valores de entrada separados por vírgula (ou Enter para nenhum): "
        ).strip()
        if input_str:
            try:
                input_values = [int(x.strip()) for x in input_str.split(",")]
            except ValueError:
                print("⚠️  Valores inválidos, usando entrada vazia")
                input_values = []

        expected_str = input(
            "Digite o resultado esperado (ou Enter para pular verificação): "
        ).strip()
        if expected_str:
            try:
                expected_output = int(expected_str)
            except ValueError:
                print("⚠️  Resultado esperado inválido, pulando verificação")

    print(f"\n🔧 Configuração:")
    print(f"📂 Arquivo: {assembly_file}")
    print(f"📥 Entradas: {input_values}")
    print(f"🎯 Resultado esperado: {expected_output}")

    # Criar simulador
    simulator = MIPSSimulator(input_values=input_values)

    # Carregar assembly
    try:
        if not os.path.exists(assembly_file):
            print(f"❌ Arquivo não encontrado: {assembly_file}")
            print("💡 Certifique-se de que o arquivo existe no diretório atual")
            return

        simulator.load_assembly(assembly_file)
    except FileNotFoundError:
        print(f"❌ Arquivo não encontrado: {assembly_file}")
        return
    except Exception as e:
        print(f"❌ Erro ao carregar arquivo: {e}")
        return

    # Executar programa
    print(f"\n{'='*50}")
    result = simulator.run()
    print(f"{'='*50}")

    # Mostrar estado final
    simulator.print_final_state()

    # Verificar resultado se especificado
    if expected_output is not None:
        if result == expected_output:
            print(f"\n✅ Teste PASSOU! Resultado correto: {result}")
        else:
            print(f"\n❌ Teste FALHOU! Esperado: {expected_output}, Obtido: {result}")
    else:
        print(f"\n🏁 Execução concluída. Resultado final: {result}")

    # Mostrar todas as saídas se houver múltiplas
    all_outputs = simulator.get_output_values()
    if len(all_outputs) > 1:
        print(f"📤 Todas as saídas: {all_outputs}")


def test_algorithms():
    """Testa algoritmos específicos"""
    print("🧪 Testando algoritmos conhecidos...")

    test_cases = [
        {
            "name": "GCD (48, 18)",
            "file": "gcd_assembly.asm",
            "inputs": [48, 18],
            "expected": 6,
        },
        {
            "name": "Fatorial de 5",
            "file": "factorial_assembly.asm",
            "inputs": [5],
            "expected": 120,
        },
        {
            "name": "Soma (10 + 15)",
            "file": "sum_assembly.asm",
            "inputs": [10, 15],
            "expected": 25,
        },
    ]

    for test in test_cases:
        print(f"\n🔬 Testando: {test['name']}")
        simulator = MIPSSimulator(input_values=test["inputs"])

        try:
            simulator.load_assembly(test["file"])
            result = simulator.run()

            if result == test["expected"]:
                print(f"✅ {test['name']}: PASSOU")
            else:
                print(
                    f"❌ {test['name']}: FALHOU (esperado {test['expected']}, obtido {result})"
                )

        except FileNotFoundError:
            print(f"⏭️  {test['name']}: Arquivo não encontrado, pulando")
        except Exception as e:
            print(f"❌ {test['name']}: Erro - {e}")


if __name__ == "__main__":
    main()

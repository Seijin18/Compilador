#!/usr/bin/env python3
"""
🔧 CORREÇÃO DO ASSEMBLY E DEBUG GCD(4,6)
========================================
O assembly tem um erro: J 21 deveria ser J 25 (main)
Vamos corrigir e simular corretamente.
"""


def create_corrected_debugger():
    """Cria um debugger que corrige o assembly automaticamente"""

    print("🔧 ANALISANDO E CORRIGINDO ASSEMBLY...")

    # Ler assembly original
    with open("assembly_output.asm", "r") as f:
        lines = f.readlines()

    # Encontrar labels e instruções
    labels = {}
    instructions = []

    for line in lines:
        line = line.strip()
        if line.endswith(":") and not line.startswith("#"):
            label = line[:-1]
            # Label aponta para próxima instrução
            labels[label] = len(instructions)
        elif ":" in line and not line.startswith("#"):
            # Instrução com endereço
            import re

            match = re.match(r"^\s*(\d+):\s*(\w+)\s*(.*)", line)
            if match:
                addr = int(match.group(1))
                op = match.group(2)
                operands = match.group(3).strip()
                instructions.append((addr, op, operands))

    print(f"📋 Labels encontrados: {labels}")
    print(f"📋 Total de instruções: {len(instructions)}")

    # Verificar se J 0 aponta para main
    if instructions[0][1] == "J":
        target = int(instructions[0][2])
        if "main" in labels and target != labels["main"]:
            print(f"🔧 CORREÇÃO: J {target} → J {labels['main']}")
            # Corrigir instrução
            instructions[0] = (instructions[0][0], "J", str(labels["main"]))

    return instructions, labels


def simulate_corrected_gcd():
    """Simula o GCD corrigido com debug completo"""

    instructions, labels = create_corrected_debugger()

    # Estado do simulador
    regs = {f"R{i}": 0 for i in range(32)}
    regs["R0"] = 0
    regs["R29"] = 1000  # Stack pointer
    regs["R31"] = 0  # Return address

    memory = {}
    pc = 0
    hi, lo = 0, 0

    # I/O
    inputs = [4, 6]
    input_idx = 0
    outputs = []

    # Debug
    scope = "BOOT"
    recursion_level = 0
    call_stack = []

    def addr_to_index(addr):
        for i, (instr_addr, op, operands) in enumerate(instructions):
            if instr_addr == addr:
                return i
        return addr if addr < len(instructions) else 0

    def execute_step():
        nonlocal pc, hi, lo, input_idx, scope, recursion_level

        if pc >= len(instructions):
            return False

        addr, op, operands = instructions[pc]
        ops = [x.strip() for x in operands.split(",")] if operands else []

        print(f"\n📍 PC:{pc} (addr {addr}) | {op} {operands}")
        print(f"   Escopo: {scope} | Recursão: {recursion_level}")

        # Mostrar registradores importantes
        important_regs = {
            k: v for k, v in regs.items() if v != 0 or k in ["R0", "R1", "R29", "R31"]
        }
        if important_regs:
            print(f"   Regs: {important_regs}")

        if op == "J":
            target_addr = int(ops[0])
            pc = addr_to_index(target_addr)
            if target_addr in [labels.get("main", -1)]:
                scope = "main"
                print(f"   🔄 Saltando para main")
            return True

        elif op == "JAL":
            target_addr = int(ops[0])
            regs["R31"] = pc + 1
            pc = addr_to_index(target_addr)

            if target_addr == labels.get("gcd", -1):
                recursion_level += 1
                scope = f"gcd_level_{recursion_level}"
                call_stack.append("gcd")
                print(f"   📞 Chamando GCD (nível {recursion_level})")

                # Mostrar parâmetros na stack
                u = memory.get(regs["R29"] + 0, "?")
                v = memory.get(regs["R29"] + 1, "?")
                print(
                    f"      Parâmetros esperados: u=MEM[{regs['R29']}]={u}, v=MEM[{regs['R29']+1}]={v}"
                )
            return True

        elif op == "JR":
            reg = ops[0]
            target = regs[reg]

            if reg == "R31" and scope.startswith("gcd"):
                if call_stack:
                    call_stack.pop()
                return_val = regs.get("R1", "?")
                print(f"   🔙 Retornando de GCD com R1={return_val}")
                recursion_level = max(0, recursion_level - 1)
                scope = (
                    "main" if recursion_level == 0 else f"gcd_level_{recursion_level}"
                )

            pc = target if target < len(instructions) else target
            return True

        elif op == "BNE":
            reg1, reg2, target_addr = ops[0], ops[1], int(ops[2])
            val1, val2 = regs[reg1], regs[reg2]
            print(f"   🔍 BNE: {reg1}({val1}) != {reg2}({val2}) ?")

            if val1 != val2:
                pc = addr_to_index(target_addr)
                print(f"   ✅ Branch tomado para {target_addr}")
            else:
                pc += 1
                print(f"   ❌ Branch não tomado")
            return True

        elif op == "LW":
            reg = ops[0]
            import re

            match = re.match(r"(-?\d+)\((\w+)\)", ops[1])
            if match:
                offset = int(match.group(1))
                base_reg = match.group(2)
                addr = regs[base_reg] + offset
                value = memory.get(addr, 0)
                old_val = regs[reg]
                regs[reg] = value
                print(f"   💾 LW: {reg} = MEM[{addr}] = {value} (era {old_val})")

        elif op == "SW":
            reg = ops[0]
            import re

            match = re.match(r"(-?\d+)\((\w+)\)", ops[1])
            if match:
                offset = int(match.group(1))
                base_reg = match.group(2)
                addr = regs[base_reg] + offset
                value = regs[reg]
                old_val = memory.get(addr, 0)
                memory[addr] = value
                print(f"   💾 SW: MEM[{addr}] = {reg}({value}) (era {old_val})")

        elif op == "MOVE":
            dest, src = ops[0], ops[1]
            old_val = regs[dest]
            regs[dest] = regs[src]
            print(f"   📝 MOVE: {dest} = {src}({regs[src]}) (era {old_val})")

        elif op == "INPUT":
            reg = ops[0]
            if input_idx < len(inputs):
                value = inputs[input_idx]
                input_idx += 1
                old_val = regs[reg]
                regs[reg] = value
                print(f"   📥 INPUT: {reg} = {value} (era {old_val})")

        elif op == "OUTPUTREG":
            reg = ops[0]
            value = regs[reg]
            outputs.append(value)
            print(f"   📤 OUTPUT: {reg}({value}) → saída")

        elif op == "HALT":
            print(f"   🛑 HALT - Programa finalizado")
            return False

        elif op == "DIV":
            reg1, reg2 = ops[0], ops[1]
            val1, val2 = regs[reg1], regs[reg2]
            if val2 != 0:
                hi = val1 % val2  # Resto
                lo = val1 // val2  # Quociente
                print(f"   ➗ DIV: {val1} ÷ {val2} = Q:{lo}, R:{hi}")

        elif op == "MFHI":
            reg = ops[0]
            old_val = regs[reg]
            regs[reg] = hi
            print(f"   📤 MFHI: {reg} = HI({hi}) (era {old_val})")

        elif op == "MFLO":
            reg = ops[0]
            old_val = regs[reg]
            regs[reg] = lo
            print(f"   📤 MFLO: {reg} = LO({lo}) (era {old_val})")

        elif op == "MULT":
            reg1, reg2 = ops[0], ops[1]
            val1, val2 = regs[reg1], regs[reg2]
            result = val1 * val2
            lo = result & 0xFFFFFFFF
            hi = (result >> 32) & 0xFFFFFFFF
            print(f"   ✖️  MULT: {val1} × {val2} = {result} (LO:{lo}, HI:{hi})")

        elif op == "SUB":
            dest, src1, src2 = ops[0], ops[1], ops[2]
            val1, val2 = regs[src1], regs[src2]
            result = val1 - val2
            old_val = regs[dest]
            regs[dest] = result
            print(f"   ➖ SUB: {dest} = {val1} - {val2} = {result} (era {old_val})")

        # Avançar PC para instruções não-jump
        if op not in ["J", "JAL", "JR", "BNE", "BEQ"]:
            pc += 1

        return True

    print("\n🚀 INICIANDO SIMULAÇÃO CORRIGIDA GCD(4,6)")
    print("=" * 60)

    step = 0
    max_steps = 100  # Reduzido para evitar loops

    while step < max_steps:
        should_continue = execute_step()
        step += 1

        if not should_continue:
            break

        # Verificar se está em loop
        if step > 20 and scope == "BOOT":
            print("⚠️  Detectado loop infinito! Forçando entrada na main...")
            pc = labels.get("main", 25)  # Força ir para main
            scope = "main"

    print(f"\n✅ Simulação finalizada em {step} passos")
    print(f"📤 Saídas: {outputs}")
    print(f"🎯 Resultado esperado: [2] para GCD(4,6)")

    if outputs == [2]:
        print("✅ SUCESSO! GCD funcionando corretamente")
    elif outputs:
        print(f"⚠️  RESULTADO INESPERADO: {outputs[0]} (esperado: 2)")
    else:
        print("❌ FALHA! Nenhuma saída produzida")


if __name__ == "__main__":
    simulate_corrected_gcd()

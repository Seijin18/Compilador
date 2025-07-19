#!/usr/bin/env python3
"""
Teste específico das correções de gerenciamento de memória
Foca na análise das instruções de memória e stack
"""

def test_memory_management():
    print("=== TESTE DE GERENCIAMENTO DE MEMÓRIA ===")
    print("Analisando assembly_output.asm para verificar correções...")
    
    with open('assembly_output.asm', 'r') as f:
        lines = f.readlines()
    
    # Extrair instruções numéricas
    instructions = []
    for line in lines:
        line = line.strip()
        if ':' in line and not line.startswith('#'):
            parts = line.split(':')
            if len(parts) == 2 and parts[0].strip().isdigit():
                addr = int(parts[0].strip())
                inst = parts[1].strip()
                if inst and inst not in ['gcd', 'L0', 'L1', 'main']:
                    instructions.append((addr, inst))
    
    print(f"\n📋 INSTRUÇÕES EXTRAÍDAS ({len(instructions)} total):")
    for addr, inst in instructions:
        print(f"  {addr:2d}: {inst}")
    
    print("\n🔍 ANÁLISE DE CORREÇÕES:")
    
    # 1. Verificar sequência de call
    print("\n1️⃣ SEQUÊNCIA DE CALL (instruções 15-19):")
    call_sequence = [inst for addr, inst in instructions if 15 <= addr <= 19]
    for i, inst in enumerate(call_sequence, 15):
        print(f"  {i:2d}: {inst}")
    
    # Analisar se a sequência está correta
    expected_pattern = [
        "LW",      # 15: Carrega parâmetro
        "SUBI",    # 16: Ajusta stack  
        "SW",      # 17: Salva primeiro parâmetro
        "SW",      # 18: Salva segundo parâmetro
        "SW"       # 19: Salva RA
    ]
    
    actual_pattern = []
    for inst in call_sequence:
        op = inst.split()[0]
        actual_pattern.append(op)
    
    print(f"\n   Padrão esperado: {expected_pattern}")
    print(f"   Padrão obtido:   {actual_pattern}")
    
    if actual_pattern == expected_pattern:
        print("   ✅ SEQUÊNCIA CORRETA: Parâmetros carregados antes de ajustar stack")
    else:
        print("   ❌ SEQUÊNCIA INCORRETA")
    
    # 2. Verificar se eliminou LW redundante
    print("\n2️⃣ VERIFICAÇÃO DE LW REDUNDANTE:")
    lw_instructions = [(addr, inst) for addr, inst in instructions if inst.startswith('LW')]
    
    print("   Instruções LW encontradas:")
    for addr, inst in lw_instructions:
        print(f"     {addr:2d}: {inst}")
    
    # Procurar por LW consecutivos com mesmo registrador
    consecutive_lw = []
    for i in range(len(lw_instructions) - 1):
        curr_addr, curr_inst = lw_instructions[i]
        next_addr, next_inst = lw_instructions[i + 1]
        
        # Extrair registrador destino
        curr_reg = curr_inst.split()[1].rstrip(',')
        next_reg = next_inst.split()[1].rstrip(',')
        
        if curr_reg == next_reg and next_addr == curr_addr + 1:
            consecutive_lw.append((curr_addr, curr_inst, next_addr, next_inst))
    
    if consecutive_lw:
        print("   ❌ LW REDUNDANTES encontrados:")
        for curr_addr, curr_inst, next_addr, next_inst in consecutive_lw:
            print(f"     {curr_addr}: {curr_inst}")
            print(f"     {next_addr}: {next_inst}")
    else:
        print("   ✅ NENHUM LW REDUNDANTE encontrado")
    
    # 3. Verificar operações de stack
    print("\n3️⃣ OPERAÇÕES DE STACK:")
    stack_ops = [(addr, inst) for addr, inst in instructions if any(op in inst for op in ['SUBI R29', 'ADDI R29', 'SW', 'LW'])]
    
    print("   Operações relacionadas ao stack:")
    for addr, inst in stack_ops:
        print(f"     {addr:2d}: {inst}")
    
    # 4. Análise de padrões problemáticos antigos
    print("\n4️⃣ VERIFICAÇÃO DE PADRÕES PROBLEMÁTICOS:")
    
    # Procurar padrão antigo problemático: SW seguido de LW imediato do mesmo local
    problematic_patterns = []
    sw_instructions = [(addr, inst) for addr, inst in instructions if inst.startswith('SW')]
    
    for addr, sw_inst in sw_instructions:
        # Procurar LW na próxima instrução
        next_instructions = [(a, i) for a, i in instructions if a == addr + 1]
        if next_instructions:
            next_addr, next_inst = next_instructions[0]
            if next_inst.startswith('LW'):
                # Verificar se é o mesmo endereço de memória
                sw_parts = sw_inst.split()
                lw_parts = next_inst.split()
                if len(sw_parts) >= 3 and len(lw_parts) >= 3:
                    sw_addr = sw_parts[2]  # offset(Rs)
                    lw_addr = lw_parts[2]  # offset(Rs)
                    if sw_addr == lw_addr:
                        problematic_patterns.append((addr, sw_inst, next_addr, next_inst))
    
    if problematic_patterns:
        print("   ❌ PADRÕES PROBLEMÁTICOS encontrados:")
        for sw_addr, sw_inst, lw_addr, lw_inst in problematic_patterns:
            print(f"     {sw_addr}: {sw_inst}")
            print(f"     {lw_addr}: {lw_inst} (carrega o que acabou de salvar)")
    else:
        print("   ✅ NENHUM PADRÃO PROBLEMÁTICO encontrado")
    
    # 5. Resumo da análise
    print("\n📊 RESUMO DA ANÁLISE:")
    print("=" * 50)
    
    corrections = []
    issues = []
    
    if actual_pattern == expected_pattern:
        corrections.append("Sequência de call corrigida")
    else:
        issues.append("Sequência de call ainda incorreta")
    
    if not consecutive_lw:
        corrections.append("LW redundantes eliminados")
    else:
        issues.append("LW redundantes ainda presentes")
    
    if not problematic_patterns:
        corrections.append("Padrões SW->LW problemáticos eliminados")
    else:
        issues.append("Padrões SW->LW problemáticos ainda presentes")
    
    print(f"✅ CORREÇÕES APLICADAS ({len(corrections)}):")
    for correction in corrections:
        print(f"   • {correction}")
    
    if issues:
        print(f"\n❌ PROBLEMAS RESTANTES ({len(issues)}):")
        for issue in issues:
            print(f"   • {issue}")
    else:
        print(f"\n🎉 TODOS OS PROBLEMAS DE MEMÓRIA FORAM CORRIGIDOS!")
    
    return len(issues) == 0

if __name__ == "__main__":
    success = test_memory_management()
    exit(0 if success else 1)

#!/usr/bin/env python3
"""
Analisador de Problemas no Assembly MIPS
Identifica redundâncias e problemas de lógica
"""

def analyze_assembly_problems(filename):
    """Analisa o arquivo assembly e identifica problemas"""
    problems = []
    
    with open(filename, 'r', encoding='utf-8') as file:
        lines = file.readlines()
    
    print("🔍 Analisando problemas no assembly...")
    
    for line_num, line in enumerate(lines, 1):
        line = line.strip()
        
        # Ignorar comentários e linhas vazias
        if line.startswith('#') or not line or line.endswith(':'):
            continue
        
        # Extrair instrução
        if ':' in line and line.split(':', 1)[0].strip().isdigit():
            parts = line.split(':', 1)
            addr = int(parts[0].strip())
            instruction = parts[1].strip()
            
            # Verificar problemas específicos
            
            # 1. Comparações com registradores iguais
            if 'BNE' in instruction or 'BEQ' in instruction:
                args = instruction.split()[1:]
                if len(args) >= 2:
                    reg1 = args[0].rstrip(',')
                    reg2 = args[1].rstrip(',')
                    if reg1 == reg2:
                        problems.append({
                            'line': line_num,
                            'addr': addr,
                            'type': 'REDUNDANT_BRANCH',
                            'description': f'Comparação redundante: {reg1} com {reg2}',
                            'instruction': instruction,
                            'severity': 'CRITICAL'
                        })
            
            # 2. MOVEs redundantes
            if 'MOVE' in instruction:
                args = instruction.split()[1:]
                if len(args) >= 2:
                    reg1 = args[0].rstrip(',')
                    reg2 = args[1].rstrip(',')
                    if reg1 == reg2:
                        problems.append({
                            'line': line_num,
                            'addr': addr,
                            'type': 'REDUNDANT_MOVE',
                            'description': f'MOVE redundante: {reg1} para {reg2}',
                            'instruction': instruction,
                            'severity': 'WARNING'
                        })
            
            # 3. Operações aritméticas com operandos iguais
            if 'DIV' in instruction or 'SUB' in instruction or 'MULT' in instruction:
                args = instruction.split()[1:]
                if len(args) >= 2:
                    reg1 = args[0].rstrip(',')
                    reg2 = args[1].rstrip(',')
                    if reg1 == reg2:
                        op = instruction.split()[0]
                        result = "desconhecido"
                        if op == 'DIV':
                            result = "sempre 1"
                        elif op == 'SUB':
                            result = "sempre 0"
                        elif op == 'MULT':
                            result = "quadrado do valor"
                        
                        problems.append({
                            'line': line_num,
                            'addr': addr,
                            'type': 'REDUNDANT_ARITHMETIC',
                            'description': f'{op} com operandos iguais ({reg1}), resultado {result}',
                            'instruction': instruction,
                            'severity': 'WARNING'
                        })
            
            # 4. Offsets inconsistentes
            if 'SW' in instruction and 'FP' in instruction:
                if '4(FP)' in instruction:
                    problems.append({
                        'line': line_num,
                        'addr': addr,
                        'type': 'INCONSISTENT_OFFSET',
                        'description': 'Offset 4(FP) inconsistente com arquitetura 8-bit',
                        'instruction': instruction,
                        'severity': 'ERROR'
                    })
    
    return problems

def print_problems_report(problems):
    """Imprime relatório de problemas"""
    print(f"\n📋 Relatório de Problemas ({len(problems)} encontrados)")
    print("=" * 60)
    
    # Agrupar por severidade
    critical = [p for p in problems if p['severity'] == 'CRITICAL']
    errors = [p for p in problems if p['severity'] == 'ERROR']
    warnings = [p for p in problems if p['severity'] == 'WARNING']
    
    if critical:
        print(f"\n🚨 CRÍTICOS ({len(critical)}):")
        for p in critical:
            print(f"  [{p['addr']:2d}] {p['description']}")
            print(f"      {p['instruction']}")
    
    if errors:
        print(f"\n❌ ERROS ({len(errors)}):")
        for p in errors:
            print(f"  [{p['addr']:2d}] {p['description']}")
            print(f"      {p['instruction']}")
    
    if warnings:
        print(f"\n⚠️  AVISOS ({len(warnings)}):")
        for p in warnings:
            print(f"  [{p['addr']:2d}] {p['description']}")
            print(f"      {p['instruction']}")

def suggest_fixes(problems):
    """Sugere correções para os problemas"""
    print(f"\n💡 Sugestões de Correção:")
    print("=" * 30)
    
    for p in problems:
        if p['type'] == 'REDUNDANT_BRANCH':
            print(f"🔧 Linha {p['addr']}: Corrigir comparação para usar registradores diferentes")
            print(f"   Atual: {p['instruction']}")
            print(f"   Sugerido: BNE R2, R0, 15  (comparar com zero)")
        
        elif p['type'] == 'REDUNDANT_MOVE':
            print(f"🔧 Linha {p['addr']}: Remover MOVE redundante")
            print(f"   Remover: {p['instruction']}")
        
        elif p['type'] == 'REDUNDANT_ARITHMETIC':
            op = p['instruction'].split()[0]
            if op == 'SUB':
                print(f"🔧 Linha {p['addr']}: Substituir por LI rd, 0")
            elif op == 'DIV':
                print(f"🔧 Linha {p['addr']}: Substituir por LI rd, 1")
        
        elif p['type'] == 'INCONSISTENT_OFFSET':
            print(f"🔧 Linha {p['addr']}: Corrigir offset para arquitetura 8-bit")
            print(f"   Trocar: 4(FP) por 2(FP)")

def main():
    """Função principal"""
    print("🔍 Analisador de Problemas do Assembly MIPS")
    print("=" * 50)
    
    filename = "assembly_output_corrected.asm"
    
    try:
        problems = analyze_assembly_problems(filename)
        print_problems_report(problems)
        suggest_fixes(problems)
        
        # Estatísticas finais
        critical_count = len([p for p in problems if p['severity'] == 'CRITICAL'])
        error_count = len([p for p in problems if p['severity'] == 'ERROR'])
        warning_count = len([p for p in problems if p['severity'] == 'WARNING'])
        
        print(f"\n📊 Resumo:")
        print(f"   🚨 Críticos: {critical_count}")
        print(f"   ❌ Erros: {error_count}")
        print(f"   ⚠️  Avisos: {warning_count}")
        print(f"   📋 Total: {len(problems)}")
        
        if critical_count > 0:
            print(f"\n❗ ATENÇÃO: {critical_count} problema(s) crítico(s) impedem execução correta!")
        
    except FileNotFoundError:
        print(f"❌ Arquivo não encontrado: {filename}")

if __name__ == "__main__":
    main()

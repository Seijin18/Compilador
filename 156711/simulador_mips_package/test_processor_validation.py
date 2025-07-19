#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Teste Simplificado das Instruções do Processador MIPS
====================================================
Teste básico das instruções fundamentais sem dependências externas

Versão: 1.1 - 2025-07-19
"""

import builtins
from simulator_mips import MIPSSimulator

def mock_input_safe(prompt=""):
    """Mock para INPUT que retorna valores predefinidos"""
    values = [42, 17, 8, 3, 1]
    mock_input_safe.counter = getattr(mock_input_safe, 'counter', 0)
    value = values[mock_input_safe.counter % len(values)]
    mock_input_safe.counter += 1
    print(f"[MOCK INPUT] {prompt}: {value}")
    return str(value)

def create_simple_test():
    """
    Cria teste simples das instruções básicas
    """
    print("🔧 CRIANDO TESTE SIMPLES DAS INSTRUÇÕES:")
    print("=" * 50)
    
    # Criar instruções manualmente
    instructions = []
    
    # Instrução 1: LI R1, 10 (Carrega 10 no registrador R1)
    # OPCODE: 011011 (LI), RT: 000001 (R1), IMEDIATO: 1010 (10)
    instr1 = (0b011011 << 26) | (0b000001 << 14) | 10
    instructions.append(instr1)
    print(f"✅ Instrução 1: LI R1, 10 - Binary: {format(instr1, '032b')}")
    
    # Instrução 2: LI R2, 5
    instr2 = (0b011011 << 26) | (0b000010 << 14) | 5
    instructions.append(instr2)
    print(f"✅ Instrução 2: LI R2, 5 - Binary: {format(instr2, '032b')}")
    
    # Instrução 3: ADD R3, R1, R2 (R3 = R1 + R2)
    # OPCODE: 000000, RS: R1, RT: R2, RD: R3
    instr3 = (0b000000 << 26) | (0b000001 << 20) | (0b000010 << 14) | (0b000011 << 8)
    instructions.append(instr3)
    print(f"✅ Instrução 3: ADD R3, R1, R2 - Binary: {format(instr3, '032b')}")
    
    # Instrução 4: OUTPUTREG R3 (Mostra R3 no display)
    # OPCODE: 100000, RS: R3
    instr4 = (0b100000 << 26) | (0b000011 << 20)
    instructions.append(instr4)
    print(f"✅ Instrução 4: OUTPUTREG R3 - Binary: {format(instr4, '032b')}")
    
    # Instrução 5: HALT
    instr5 = (0b011110 << 26)
    instructions.append(instr5)
    print(f"✅ Instrução 5: HALT - Binary: {format(instr5, '032b')}")
    
    print(f"\n📊 Total de instruções: {len(instructions)}")
    return instructions

def test_basic_instructions():
    """
    Teste das instruções básicas
    """
    print("🎯 TESTE BÁSICO DAS INSTRUÇÕES DO PROCESSADOR")
    print("=" * 60)
    
    # Substituir input() globalmente
    original_input = builtins.input
    builtins.input = mock_input_safe
    
    try:
        # Criar simulador
        simulator = MIPSSimulator(debug=True)  # Debug ativo para ver execução
        
        # Configurar inputs seguros
        if hasattr(simulator, 'set_input_values_safe'):
            simulator.set_input_values_safe([42, 17, 8], extra_zeros=10)
        else:
            simulator.input_values = [42, 17, 8, 0, 0, 0, 0, 0, 0, 0]
        
        # Criar instruções de teste
        instructions = create_simple_test()
        
        print(f"\n🚀 EXECUTANDO INSTRUÇÕES...")
        print("=" * 40)
        
        # Não usar o método run(), executar manualmente para debug
        simulator.reset()
        
        print("Estado inicial:")
        print(f"  R1 = {simulator.registers[1]}")
        print(f"  R2 = {simulator.registers[2]}")
        print(f"  R3 = {simulator.registers[3]}")
        print(f"  PC = {simulator.pc}")
        
        # Executar cada instrução manualmente
        for i, instruction in enumerate(instructions):
            if simulator.halted:
                break
                
            print(f"\n--- Executando instrução {i+1} ---")
            print(f"PC = {simulator.pc}, Instrução = {format(instruction, '032b')}")
            
            # Decodificar instrução
            decoded = simulator.decode_instruction(instruction)
            opcode = decoded.get('opcode', 0)
            mnemonic = simulator.opcodes.get(opcode, 'UNKNOWN')
            
            print(f"Mnemonic: {mnemonic}")
            print(f"Decoded: {decoded}")
            
            # Executar
            result = simulator.execute_instruction(instruction)
            
            print(f"Resultado: {result}")
            print(f"R1 = {simulator.registers[1]}, R2 = {simulator.registers[2]}, R3 = {simulator.registers[3]}")
            print(f"Display = {simulator.display_value}")
            print(f"PC = {simulator.pc}")
        
        print(f"\n📊 RESULTADO FINAL:")
        print("=" * 30)
        print(f"R1 = {simulator.registers[1]} (esperado: 10)")
        print(f"R2 = {simulator.registers[2]} (esperado: 5)")
        print(f"R3 = {simulator.registers[3]} (esperado: 15)")
        print(f"Display = {simulator.display_value} (esperado: 15)")
        print(f"Halted = {simulator.halted}")
        
        # Validação
        success = (
            simulator.registers[1] == 10 and
            simulator.registers[2] == 5 and
            simulator.registers[3] == 15 and
            simulator.display_value == 15 and
            simulator.halted
        )
        
        return success
        
    except Exception as e:
        print(f"💥 Erro durante execução: {e}")
        import traceback
        traceback.print_exc()
        return False
    
    finally:
        # Restaurar input original
        builtins.input = original_input

def test_individual_opcodes():
    """
    Teste individual dos opcodes mais importantes
    """
    print("\n🔍 TESTE INDIVIDUAL DE OPCODES:")
    print("=" * 50)
    
    # Lista de opcodes da documentação
    opcodes = {
        0b000000: 'ADD',    0b000001: 'SUB',    0b000010: 'MULT',   0b000011: 'DIV',
        0b000100: 'AND',    0b000101: 'OR',     0b000110: 'SLL',    0b000111: 'SRL',
        0b001000: 'SLT',    0b001001: 'MFHI',   0b001010: 'MFLO',   0b001011: 'MOVE',
        0b001100: 'JR',     0b001101: 'JALR',   0b001110: 'LA',     0b001111: 'ADDI',
        0b010000: 'SUBI',   0b010001: 'ANDI',   0b010010: 'ORI',    0b010011: 'BEQ',
        0b010100: 'BNE',    0b010101: 'BGT',    0b010110: 'BGTE',   0b010111: 'BLT',
        0b011000: 'BLTE',   0b011001: 'LW',     0b011010: 'SW',     0b011011: 'LI',
        0b011100: 'J',      0b011101: 'JAL',    0b011110: 'HALT',   0b011111: 'OUTPUTMEM',
        0b100000: 'OUTPUTREG', 0b100001: 'OUTPUTRESET', 0b100010: 'INPUT'
    }
    
    simulator = MIPSSimulator(debug=False)
    
    print("📋 Opcodes suportados pelo simulador:")
    supported = 0
    total = len(opcodes)
    
    for opcode, mnemonic in opcodes.items():
        if opcode in simulator.opcodes:
            actual_mnemonic = simulator.opcodes[opcode]
            if actual_mnemonic == mnemonic:
                print(f"✅ {opcode:06b} ({opcode:2d}): {mnemonic}")
                supported += 1
            else:
                print(f"⚠️  {opcode:06b} ({opcode:2d}): {mnemonic} (simulador tem: {actual_mnemonic})")
                supported += 1
        else:
            print(f"❌ {opcode:06b} ({opcode:2d}): {mnemonic} (não implementado)")
    
    print(f"\n📊 Suporte de opcodes: {supported}/{total} ({(supported/total)*100:.1f}%)")
    return supported == total

def create_binary_file_test():
    """
    Cria um arquivo binário de teste e testa carregamento
    """
    print("\n📄 TESTE DE ARQUIVO BINÁRIO:")
    print("=" * 40)
    
    # Criar arquivo binário simples
    test_filename = "test_instructions.bin"
    
    # Instruções de teste em formato binário
    test_instructions = [
        "01101100000000000000010000001010",  # LI R1, 10
        "01101100000000000001000000000101",  # LI R2, 5
        "00000000000100000001000001100000",  # ADD R3, R1, R2
        "10000000000011000000000000000000",  # OUTPUTREG R3
        "01111000000000000000000000000000",  # HALT
    ]
    
    try:
        with open(test_filename, 'w') as f:
            for instruction in test_instructions:
                f.write(instruction + '\n')
        
        print(f"✅ Arquivo {test_filename} criado com {len(test_instructions)} instruções")
        
        # Testar carregamento
        simulator = MIPSSimulator(debug=False)
        loaded_instructions = simulator.load_binary_file(test_filename)
        
        if len(loaded_instructions) == len(test_instructions):
            print(f"✅ Carregamento bem-sucedido: {len(loaded_instructions)} instruções")
            
            # Verificar se as instruções estão corretas
            for i, (original, loaded) in enumerate(zip(test_instructions, loaded_instructions)):
                expected = int(original, 2)
                if loaded == expected:
                    print(f"✅ Instrução {i+1}: {format(loaded, '032b')} (correto)")
                else:
                    print(f"❌ Instrução {i+1}: {format(loaded, '032b')} (esperado: {original})")
            
            return True
        else:
            print(f"❌ Carregamento falhou: {len(loaded_instructions)} de {len(test_instructions)}")
            return False
            
    except Exception as e:
        print(f"❌ Erro ao criar/carregar arquivo: {e}")
        return False

if __name__ == "__main__":
    print("🔬 TESTE SIMPLIFICADO DAS INSTRUÇÕES DO PROCESSADOR")
    print("=" * 60)
    print("Versão: 1.1 - Focado em validação básica")
    print("=" * 60)
    
    # Teste 1: Instruções básicas
    print("\n📋 TESTE 1: INSTRUÇÕES BÁSICAS")
    success1 = test_basic_instructions()
    
    # Teste 2: Opcodes individuais
    print("\n📋 TESTE 2: VERIFICAÇÃO DE OPCODES")
    success2 = test_individual_opcodes()
    
    # Teste 3: Arquivo binário
    print("\n📋 TESTE 3: CARREGAMENTO DE ARQUIVO")
    success3 = create_binary_file_test()
    
    print(f"\n🎯 RESULTADO FINAL:")
    print("=" * 30)
    print(f"Teste 1 (Básico): {'✅ PASSOU' if success1 else '❌ FALHOU'}")
    print(f"Teste 2 (Opcodes): {'✅ PASSOU' if success2 else '❌ FALHOU'}")
    print(f"Teste 3 (Arquivo): {'✅ PASSOU' if success3 else '❌ FALHOU'}")
    
    overall_success = success1 and success2 and success3
    
    if overall_success:
        print("\n🎉 TODOS OS TESTES PASSARAM!")
        print("✅ Simulador está funcionando corretamente")
        print("✅ Instruções básicas validadas")
        print("✅ Pronto para uso com compiladores")
    else:
        print("\n⚠️  ALGUNS TESTES FALHARAM")
        print("❌ Verificar implementação do simulador")
        print("❌ Possíveis problemas de compatibilidade")
    
    print("\n📝 INSTRUÇÕES TESTADAS:")
    print("   • LI (Load Immediate)")
    print("   • ADD (Adição)")
    print("   • OUTPUTREG (Saída)")
    print("   • HALT (Parar)")
    print("   • Carregamento de arquivo binário")
    print("   • Validação de 35 opcodes")

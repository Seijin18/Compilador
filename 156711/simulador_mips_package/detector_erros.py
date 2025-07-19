#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Identificação de Erros no Assembly - Análise Detalhada
Usar o simulador para mapear exatamente onde está o problema
"""

from simulator_mips import MIPSSimulator

class AssemblyErrorDetector(MIPSSimulator):
    def __init__(self):
        super().__init__(debug=False)
        self.stack_operations = []
        self.gcd_calls = []
        
    def execute_instruction(self, instruction: int) -> bool:
        decoded = self.decode_instruction(instruction)
        opcode = decoded['opcode']
        mnemonic = self.opcodes.get(opcode, 'UNKNOWN')
        
        # Rastrear todas as operações de stack
        if mnemonic in ['SW', 'LW'] and decoded['rs'] == 29:
            addr = (self.registers[decoded['rs']] + decoded['immediate']) % 256
            
            if mnemonic == 'SW':
                val = self.registers[decoded['rt']]
                operation = {
                    'pc': self.pc,
                    'type': 'SW',
                    'reg': f"R{decoded['rt']}",
                    'addr': addr,
                    'offset': decoded['immediate'],
                    'value': val,
                    'sp': self.registers[29]
                }
                self.stack_operations.append(operation)
                
            else:  # LW
                old_val = self.registers[decoded['rt']]
                result = super().execute_instruction(instruction)
                new_val = self.registers[decoded['rt']]
                
                operation = {
                    'pc': self.pc,
                    'type': 'LW',
                    'reg': f"R{decoded['rt']}",
                    'addr': addr,
                    'offset': decoded['immediate'],
                    'value': new_val,
                    'sp': self.registers[29]
                }
                self.stack_operations.append(operation)
                return result
                
        # Rastrear chamadas GCD
        elif mnemonic == 'JAL' and decoded['immediate'] == 1:
            # Captura parâmetros antes da chamada
            param1_addr = 255  # MEM[255] based on previous analysis
            param2_addr = 0    # MEM[0] based on previous analysis
            
            call_info = {
                'call_num': len(self.gcd_calls) + 1,
                'pc': self.pc,
                'sp': self.registers[29],
                'param1': self.memory[param1_addr] if param1_addr < len(self.memory) else 0,
                'param2': self.memory[param2_addr] if param2_addr < len(self.memory) else 0,
                'stack_state': dict(enumerate(self.memory[:10]))
            }
            self.gcd_calls.append(call_info)
        
        return super().execute_instruction(instruction)
    
    def analyze_errors(self):
        print("\n" + "=" * 60)
        print("ANÁLISE DE ERROS NO ASSEMBLY")
        print("=" * 60)
        
        print("\n1. OPERAÇÕES DE STACK:")
        print("-" * 30)
        for i, op in enumerate(self.stack_operations[:15]):  # Primeiras 15 operações
            print(f"{i+1:2d}. PC={op['pc']:2d} {op['type']} {op['reg']} offset={op['offset']} addr={op['addr']} value={op['value']} SP={op['sp']}")
        
        print("\n2. CHAMADAS GCD:")
        print("-" * 30)
        for call in self.gcd_calls:
            print(f"Call #{call['call_num']}: GCD({call['param1']}, {call['param2']}) at PC={call['pc']} SP={call['sp']}")
        
        print("\n3. IDENTIFICAÇÃO DE PROBLEMAS:")
        print("-" * 30)
        
        # Análise dos padrões
        problems = []
        
        # Verificar se os parâmetros estão sendo lidos corretamente
        main_stores = [op for op in self.stack_operations if op['pc'] in [40, 43]]
        gcd_loads = [op for op in self.stack_operations if op['pc'] in [6, 8]]
        
        if main_stores:
            print("PARÂMETROS SALVOS NO MAIN:")
            for store in main_stores:
                print(f"  PC={store['pc']}: {store['reg']} -> MEM[{store['addr']}] = {store['value']}")
        
        if gcd_loads:
            print("PARÂMETROS LIDOS NO GCD:")
            for load in gcd_loads:
                print(f"  PC={load['pc']}: {load['reg']} <- MEM[{load['addr']}] = {load['value']}")
                
        # Identificar problemas específicos
        if any(call['param2'] == 0 for call in self.gcd_calls):
            problems.append("❌ ERRO: Segundo parâmetro sendo lido como 0")
            
        if len(set(call['param1'] for call in self.gcd_calls)) <= 1:
            problems.append("❌ ERRO: Parâmetros não estão sendo atualizados nas chamadas recursivas")
            
        if not problems:
            problems.append("✅ Nenhum problema óbvio detectado")
            
        for problem in problems:
            print(problem)
        
        return problems

def main():
    print("DETECTOR DE ERROS NO ASSEMBLY")
    print("=" * 40)
    
    detector = AssemblyErrorDetector()
    instructions = detector.load_binary_file("binary_output.txt")
    
    if not instructions:
        print("❌ Erro: Não foi possível carregar as instruções")
        return
    
    # Executa com valores 4 e 6
    detector.input_values = [4, 6]
    summary = detector.run(instructions, max_cycles=50)  # Limite para não entrar em loop infinito
    
    # Analisa os erros encontrados
    problems = detector.analyze_errors()
    
    print("\n" + "=" * 60)
    print("RECOMENDAÇÕES DE CORREÇÃO:")
    print("=" * 60)
    
    if "❌ ERRO: Segundo parâmetro sendo lido como 0" in problems:
        print("\n🔧 CORREÇÃO 1: Fixing convention")
        print("O assembly está tentando ler os parâmetros das posições erradas.")
        print("Solução: Ajustar os offsets nas instruções LW na função gcd.")
        
    if "❌ ERRO: Parâmetros não estão sendo atualizados" in problems:
        print("\n🔧 CORREÇÃO 2: Stack parameter updates")
        print("Os parâmetros não estão sendo atualizados corretamente para chamadas recursivas.")
        print("Solução: Revisar as instruções SW que preparam os novos parâmetros.")
    
    print("\n📝 PRÓXIMOS PASSOS:")
    print("1. Identificar as instruções específicas que precisam ser corrigidas")
    print("2. Modificar o assembler para gerar código correto")
    print("3. Testar novamente com o simulador")

if __name__ == "__main__":
    main()

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Teste simples das instruções INPUT
"""

from simulator_mips import MIPSSimulator

def main():
    print("Teste de INPUT com valores 4 e 6")
    print("=" * 40)
    
    simulator = MIPSSimulator(debug=True)
    instructions = simulator.load_binary_file("binary_output.txt")
    
    if not instructions:
        print("Erro: Não foi possível carregar as instruções")
        return
    
    # Executa apenas até ler os dois inputs
    simulator.input_values = [4, 6]
    
    # Executa limitado
    simulator.reset()
    cycle = 0
    
    print("Executando até JAL...")
    while not simulator.halted and cycle < 15:
        if simulator.pc >= len(instructions):
            break
            
        instruction = instructions[simulator.pc]
        decoded = simulator.decode_instruction(instruction)
        mnemonic = simulator.opcodes.get(decoded['opcode'], 'UNKNOWN')
        
        print(f"PC={simulator.pc:2d}: {mnemonic:10s}", end="")
        
        if mnemonic == 'INPUT':
            before = simulator.registers[decoded['rd']]
            
        simulator.execute_instruction(instruction)
        
        if mnemonic == 'INPUT':
            after = simulator.registers[decoded['rd']]
            print(f" R{decoded['rd']}: {before} -> {after}")
        elif mnemonic in ['MOVE', 'SW']:
            if mnemonic == 'MOVE':
                print(f" R{decoded['rd']} = R{decoded['rs']} = {simulator.registers[decoded['rs']]}")
            else:
                addr = (simulator.registers[decoded['rs']] + decoded['immediate']) & 0xFF
                val = simulator.registers[decoded['rt']]
                print(f" MEM[{addr}] = {val}")
        else:
            print()
            
        if mnemonic == 'JAL':
            break
            
        if simulator.pc == cycle:  # Prevent infinite loop
            simulator.pc += 1
        cycle += 1
    
    print("\n" + "=" * 40)
    print("RESULTADO:")
    print(f"R8 (primeiro input): {simulator.registers[8]}")
    print(f"R9 (cópia): {simulator.registers[9]}")
    print(f"R10 (segundo input): {simulator.registers[10]}")
    print(f"R11 (cópia): {simulator.registers[11]}")
    
    print("\nStack:")
    print(f"MEM[0] = {simulator.memory[0]} (deveria ser 4)")
    print(f"MEM[1] = {simulator.memory[1]} (deveria ser 6)")

if __name__ == "__main__":
    main()

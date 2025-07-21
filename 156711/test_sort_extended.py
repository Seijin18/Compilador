#!/usr/bin/env python3
"""
Teste estendido do algoritmo de sort com mais ciclos
Salva execução linha por linha igual ao terminal
"""

from mips_simulator import MIPSSimulator
import datetime
import io
import sys

def test_sort_extended():
    # Criar arquivo de log com timestamp
    timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    log_filename = f"debug_sort_execution_{timestamp}.txt"
    
    # Abrir arquivo de log
    with open(log_filename, 'w', encoding='utf-8') as log_file:
        # Classe para capturar tanto stdout quanto salvar no arquivo
        class TeeOutput:
            def __init__(self, file):
                self.file = file
                self.original_stdout = sys.stdout
                
            def write(self, message):
                self.original_stdout.write(message)  # Escrever no console
                self.file.write(message)             # Escrever no arquivo
                self.file.flush()                    # Garantir que seja salvo imediatamente
                
            def flush(self):
                self.original_stdout.flush()
                self.file.flush()
        
        # Configurar interceptação da saída
        tee = TeeOutput(log_file)
        
        def log_print(message):
            """Função para escrever tanto no console quanto no arquivo"""
            print(message)
            tee.write(message + '\n')
            # Separador visual apenas para linhas de execução do simulador
            if message.startswith('🔄 PC=') or message.startswith('🎯 Executando OUTPUTREG') or message.startswith('📊 Registradores:'):
                print('────────────────────────────────────────────────────────')
                tee.write('────────────────────────────────────────────────────────\n')
        
        log_print("🔢 Testando algoritmo de Sort (versão estendida)")
        log_print("=" * 50)
        log_print(f"📅 Timestamp: {datetime.datetime.now()}")
        log_print(f"📝 Log sendo salvo em: {log_filename}")
        log_print("")
        
        # Array de entrada
        array_input = [5, 2, 8, 1, 9, 3, 7, 4, 6, 0]
        log_print(f"🔢 Array de entrada: {array_input}")
        
        # Array esperado (ordenado)
        expected = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        
        # Criar simulador
        simulator = MIPSSimulator()
        log_print("🔧 Simulador MIPS inicializado")
        log_print(f"📊 Memória: {len(simulator.memory)} bytes")
        log_print(f"📋 Registradores: {len(simulator.registers)}")
        
        # Configurar entradas para o array
        simulator.input_values = array_input
        simulator.input_index = 0
        log_print(f"🔢 Array programado como entrada: {array_input}")
        
        # Carregar assembly
        log_print("📂 Carregando assembly: assembly_output.asm")
        try:
            simulator.load_assembly("assembly_output.asm")
            log_print(f"✅ Carregado assembly com {len(simulator.instructions)} instruções")
        except Exception as e:
            log_print(f"❌ Erro ao carregar assembly: {e}")
            return False
        
        # Configurar debug do simulador para usar o mesmo arquivo
        debug_simulator_filename = f"debug_simulator_{timestamp}.txt"
        simulator.start_debug_log(debug_simulator_filename)
        log_print(f"📝 Debug do simulador sendo salvo em: {debug_simulator_filename}")
        
        # Executar com interceptação da saída
        log_print("🚀 Iniciando execução...")
        log_print("=" * 60)
        
        # Interceptar stdout durante a execução
        sys.stdout = tee
        try:
            result = simulator.run()
        finally:
            sys.stdout = tee.original_stdout  # Restaurar stdout original
        
        log_print("=" * 60)
        
        log_print(f"🎯 Execução finalizada com resultado: {result}")
        
        # Verificar estado final da memória do array
        log_print("📊 Estado final do array vet (GP+0 até GP+9):")
        final_array = []
        for i in range(10):
            addr = simulator.registers[28] + i  # GP + offset
            value = simulator.memory[addr] if addr < len(simulator.memory) else 0
            final_array.append(value)
            log_print(f"   vet[{i}] = {value}")
        
        # Verificar se está ordenado
        is_sorted = final_array == expected
        
        log_print("\n🎯 Resultado do teste:")
        if is_sorted:
            log_print("✅ SUCESSO: Array foi ordenado corretamente!")
            log_print(f"   Entrada: {array_input}")
            log_print(f"   Saída:   {final_array}")
            log_print(f"   Esperado: {expected}")
        else:
            log_print("❌ FALHA: Array não foi ordenado corretamente")
            log_print(f"   Entrada: {array_input}")
            log_print(f"   Saída:   {final_array}")
            log_print(f"   Esperado: {expected}")
        
        log_print(f"\n📊 Estatísticas:")
        log_print(f"   Ciclos executados: {simulator.cycle_count}")
        log_print(f"   Instruções processadas: {simulator.pc if hasattr(simulator, 'pc') else 'N/A'}")
        
        # Informações adicionais de debug
        log_print(f"\n🔍 Estado final dos registradores:")
        for i, value in enumerate(simulator.registers):
            if value != 0:  # Só mostrar registradores não-zero
                log_print(f"   R{i}: {value}")
        
        log_print(f"\n📝 Log completo salvo em: {log_filename}")
        log_print(f"📝 Debug detalhado do simulador salvo em: {debug_simulator_filename}")
        return is_sorted

if __name__ == "__main__":
    success = test_sort_extended()
    exit(0 if success else 1)

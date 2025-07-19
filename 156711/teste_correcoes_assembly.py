#!/usr/bin/env python3
"""
Teste das Correções de Assembly
Compara o assembly original com o corrigido usando o simulador
"""

import sys
import builtins
import os

# Usar o simulador atualizado da pasta package
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "simulador_mips_package"))
from simulator_mips import MIPSSimulator


def mock_input_safe(prompt=""):
    """Mock para INPUT que retorna valores predefinidos"""
    valores = [48, 18]  # GCD(48,18) = 6
    if not hasattr(mock_input_safe, "index"):
        mock_input_safe.index = 0

    if mock_input_safe.index < len(valores):
        valor = valores[mock_input_safe.index]
        mock_input_safe.index += 1
        return str(valor)
    return "0"


def executar_assembly(arquivo_assembly, descricao):
    """
    Executa um arquivo assembly e retorna o resultado
    """
    print(f"\n🔧 TESTANDO: {descricao}")
    print("-" * 50)

    try:
        # Configurar mock de input
        builtins.input = mock_input_safe
        mock_input_safe.index = 0  # Reset index

        # Criar simulador
        simulator = MIPSSimulator(debug=False)
        simulator.set_input_values_safe([48, 18], extra_zeros=5)

        # Converter assembly para binary usando assembler
        print("🔄 Convertendo assembly para binary...")
        os.system(f"assembler_final.exe {arquivo_assembly} binary_temp.txt")

        # Carregar instruções binárias
        try:
            instructions = simulator.load_binary_file("binary_temp.txt")
            print(f"📝 Carregadas {len(instructions)} instruções")
        except:
            print("❌ Erro ao carregar binary, tentando parsing manual...")
            # Fallback: parse manual básico
            instructions = []
            with open(arquivo_assembly, "r", encoding="utf-8") as f:
                lines = f.readlines()
                for line in lines:
                    line = line.strip()
                    if line and not line.startswith("#") and not line.endswith(":"):
                        parts = line.split()
                        if len(parts) >= 2 and parts[0].isdigit():
                            # Formato "0: INSTRUCAO ..."
                            instructions.append(0)  # Placeholder
            print(f"📝 Preparadas {len(instructions)} instruções (placeholder)")

        # Executar
        print("▶️  Executando...")
        result = simulator.run(instructions, max_cycles=100)

        print(f"✅ Execução concluída!")
        print(f"📊 Ciclos executados: {result.get('cycles', 'N/A')}")
        print(f"🎯 Status: {result.get('status', 'N/A')}")

        # Verificar resultado
        if hasattr(simulator, "output_values") and simulator.output_values:
            print(f"📤 Output: {simulator.output_values}")
            result["output"] = simulator.output_values
        else:
            print("📤 Output: (vazio ou não capturado)")

        # Mostrar registradores importantes
        print("🔍 Registradores importantes:")
        for i in [1, 3, 4, 5, 6, 8, 9, 12]:
            valor = simulator.registers.get(i, 0)
            print(f"   R{i}: {valor}")

        return result

    except Exception as e:
        print(f"❌ Erro na execução: {e}")
        import traceback

        traceback.print_exc()
        return None


def comparar_resultados(resultado_original, resultado_corrigido):
    """
    Compara os resultados das duas versões
    """
    print("\n📊 COMPARAÇÃO DE RESULTADOS")
    print("=" * 60)

    if not resultado_original or not resultado_corrigido:
        print("❌ Não foi possível comparar - alguma execução falhou")
        return

    print("🔍 ANÁLISE:")

    # Comparar outputs
    output_orig = resultado_original.get("output", [])
    output_corr = resultado_corrigido.get("output", [])

    print(f"   📤 Output Original:  {output_orig}")
    print(f"   📤 Output Corrigido: {output_corr}")

    # Comparar ciclos
    ciclos_orig = resultado_original.get("cycles", 0)
    ciclos_corr = resultado_corrigido.get("cycles", 0)

    print(f"   ⏱️  Ciclos Original:  {ciclos_orig}")
    print(f"   ⏱️  Ciclos Corrigido: {ciclos_corr}")

    # Comparar status
    status_orig = resultado_original.get("status", "unknown")
    status_corr = resultado_corrigido.get("status", "unknown")

    print(f"   📊 Status Original:  {status_orig}")
    print(f"   📊 Status Corrigido: {status_corr}")

    # Avaliar se as correções funcionaram
    print("\n🎯 AVALIAÇÃO DAS CORREÇÕES:")

    if output_corr and len(output_corr) > 0:
        resultado_gcd = output_corr[0] if output_corr else None
        if resultado_gcd == 6:  # GCD(48,18) = 6
            print("   ✅ SUCESSO: GCD calculado corretamente!")
            print("   ✅ Correções resolveram os problemas")
        else:
            print(f"   ⚠️  Resultado inesperado: {resultado_gcd} (esperado: 6)")
    else:
        print("   ❌ Nenhum output produzido")


def criar_relatorio_correcoes():
    """
    Cria um relatório detalhado das correções
    """
    print("\n📋 RELATÓRIO DE CORREÇÕES APLICADAS")
    print("=" * 60)

    print("\n🔧 CORREÇÃO 1: BEQ → BNE")
    print("   📍 Localização: Linha 2")
    print("   ❌ Original:  BEQ R1, R0, 5")
    print("   ✅ Corrigido: BNE R1, R0, 6")
    print("   🎯 Motivo:")
    print("      - Quadrupla if_f(v==0) significa 'se v≠0 pule'")
    print("      - BNE implementa corretamente esta lógica")
    print("      - Endereço 6 corresponde ao label L0")

    print("\n🔧 CORREÇÃO 2: MFLO → MFHI")
    print("   📍 Localização: Linha 9")
    print("   ❌ Original:  MFLO R4")
    print("   ✅ Corrigido: MFHI R4")
    print("   🎯 Motivo:")
    print("      - Quadrupla (/) solicita quociente da divisão")
    print("      - MFHI recupera o quociente, MFLO recupera o resto")
    print("      - Algoritmo GCD precisa calcular u%v = u - (u/v)*v")

    print("\n📈 IMPACTO ESPERADO DAS CORREÇÕES:")
    print("   ✅ Lógica condicional correta (v==0 vs v≠0)")
    print("   ✅ Cálculo correto do resto da divisão")
    print("   ✅ Algoritmo GCD funcionando adequadamente")
    print("   ✅ Resultado correto para GCD(48,18) = 6")


def main():
    """
    Função principal de teste
    """
    print("🧪 TESTE DAS CORREÇÕES DE ASSEMBLY")
    print("🎯 Objetivo: Validar as correções de BEQ→BNE e MFLO→MFHI")
    print("📊 Entrada de teste: GCD(48, 18) = 6")
    print("")

    # Executar versão original
    resultado_original = executar_assembly(
        "assembly_output.asm", "Assembly Original (com bugs)"
    )

    # Executar versão corrigida
    resultado_corrigido = executar_assembly(
        "assembly_output_corrigido.asm", "Assembly Corrigido"
    )

    # Comparar resultados
    comparar_resultados(resultado_original, resultado_corrigido)

    # Criar relatório
    criar_relatorio_correcoes()

    print("\n" + "=" * 60)
    print("🎉 TESTE DAS CORREÇÕES CONCLUÍDO!")
    print("🔍 Verifique os resultados acima para validar as correções")


if __name__ == "__main__":
    main()

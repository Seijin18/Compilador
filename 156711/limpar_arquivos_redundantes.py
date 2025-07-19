#!/usr/bin/env python3
"""
Script para identificar e excluir arquivos redundantes e inúteis na pasta 156711
"""

import os
import shutil

# Diretório base
BASE_DIR = r"c:\Users\marco\Projetinhos\Compilador\156711"

# Arquivos redundantes identificados - classificados por categoria

ARQUIVOS_DEBUG_REDUNDANTES = [
    "debug_gcd.py",  # Redundante com debug_gcd_simple.py e debug_gcd_detailed.py
    "debug_gcd_algorithm.py",  # Redundante com debug_gcd_detailed.py
    "debug_gcd_params.py",  # Redundante com debug_params.py
    "debug_params.py",  # Redundante com debug_gcd_params.py
    "debug_input.py",  # Já resolvido - problema de input
    "debug_stack.py",  # Debug específico já concluído
    "debug_jump.py",  # Debug específico já concluído
    "decode_main.py",  # Debug específico já concluído
]

ARQUIVOS_TESTE_REDUNDANTES = [
    "test_input_fix.py",  # Redundante com test_gcd_no_loop.py
    "test_complete_gcd.py",  # Redundante com test_gcd_final.py
    "test_gcd_corrected.py",  # Redundante com test_gcd_final.py
    "test_final_simple.py",  # Redundante com test_final_validation.py
    "test_minimal.py",  # Redundante com testes mais completos
    "test_gcd_no_loop.py",  # Redundante com test_gcd_final.py
    "test_processor_instructions.py",  # Redundante com test_final_validation.py
    "test_processor_simple.py",  # Redundante com test_final_validation.py
    "test_complete_validation.py",  # Redundante com test_final_validation.py (este é melhor)
]

ARQUIVOS_ANALISE_REDUNDANTES = [
    "analise_critica.py",  # Análise já concluída
    "analyze_bne.py",  # Análise específica já concluída
    "analyze_compilation.py",  # Análise já concluída
    "analyze_gcd_logic.py",  # Redundante com analyze_gcd_safe.py
    "analyze_gcd_safe.py",  # Análise já concluída
]

ARQUIVOS_VALIDACAO_REDUNDANTES = [
    "validacao_final.py",  # Redundante com test_final_validation.py
    "validacao_completa.py",  # Redundante com test_final_validation.py
    "diagnostico_final.py",  # Diagnóstico já concluído
    "detector_erros.py",  # Já incorporado no simulador principal
    "simulador_corrigido.py",  # Redundante com simulator_mips.py atualizado
]

ARQUIVOS_UTILITARIOS_REDUNDANTES = [
    "check_opcodes.py",  # Verificação já concluída
    "generate_beq.py",  # Geração específica já concluída
    "verify_opcodes.py",  # Redundante com check_opcodes.py
    "full_verify.py",  # Redundante com test_final_validation.py
]

ARQUIVOS_EXECUTAVEIS_DESNECESSARIOS = [
    "assembler_corrected.exe",  # Versão antiga
    "assembler_updated.exe",  # Versão duplicada
    "test_encoding.exe",  # Executável de teste
]

ARQUIVOS_TEMPORARIOS_E_CACHE = [
    "__pycache__",  # Cache do Python
]

# Todos os arquivos a serem excluídos
TODOS_ARQUIVOS_PARA_EXCLUIR = (
    ARQUIVOS_DEBUG_REDUNDANTES
    + ARQUIVOS_TESTE_REDUNDANTES
    + ARQUIVOS_ANALISE_REDUNDANTES
    + ARQUIVOS_VALIDACAO_REDUNDANTES
    + ARQUIVOS_UTILITARIOS_REDUNDANTES
    + ARQUIVOS_EXECUTAVEIS_DESNECESSARIOS
    + ARQUIVOS_TEMPORARIOS_E_CACHE
)


def excluir_arquivos_redundantes():
    """
    Exclui arquivos redundantes e inúteis da pasta 156711
    """
    print("🗂️  LIMPEZA DA PASTA 156711")
    print("=" * 50)

    total_excluidos = 0
    espaco_liberado = 0

    for arquivo in TODOS_ARQUIVOS_PARA_EXCLUIR:
        caminho_completo = os.path.join(BASE_DIR, arquivo)

        try:
            if os.path.isfile(caminho_completo):
                # Calcular tamanho do arquivo
                tamanho = os.path.getsize(caminho_completo)

                # Excluir arquivo
                os.remove(caminho_completo)
                print(f"🗑️  Excluído: {arquivo} ({tamanho} bytes)")

                total_excluidos += 1
                espaco_liberado += tamanho

            elif os.path.isdir(caminho_completo):
                # Excluir diretório e todo seu conteúdo
                tamanho_dir = sum(
                    os.path.getsize(os.path.join(dirpath, filename))
                    for dirpath, dirnames, filenames in os.walk(caminho_completo)
                    for filename in filenames
                )

                shutil.rmtree(caminho_completo)
                print(f"📁🗑️  Excluído diretório: {arquivo} ({tamanho_dir} bytes)")

                total_excluidos += 1
                espaco_liberado += tamanho_dir

            else:
                print(f"⚠️  Não encontrado: {arquivo}")

        except Exception as e:
            print(f"❌ Erro ao excluir {arquivo}: {e}")

    print("=" * 50)
    print(f"✅ Limpeza concluída!")
    print(f"📊 Total de itens excluídos: {total_excluidos}")
    print(
        f"💾 Espaço liberado: {espaco_liberado:,} bytes ({espaco_liberado/1024:.1f} KB)"
    )

    return total_excluidos, espaco_liberado


def listar_arquivos_importantes():
    """
    Lista os arquivos importantes que devem ser mantidos
    """
    print("\n📋 ARQUIVOS IMPORTANTES MANTIDOS:")
    print("=" * 50)

    arquivos_importantes = [
        "simulator_mips.py",  # Simulador principal atualizado
        "test_final_validation.py",  # Teste de validação oficial
        "simulador_mips_package/",  # Pacote de distribuição completo
        "assembler_final.c",  # Assemblador final
        "assembler_final.exe",  # Executável do assemblador
        "compilador_final.exe",  # Compilador final
        "binary_output.txt",  # Output binário de testes
        "assembly_output.asm",  # Output assembly
        "intermediate.txt",  # Código intermediário
        "funcs.c",
        "funcs.h",  # Funções do projeto
        "bison.y",
        "bison.tab.c",
        "bison.tab.h",  # Parser
        "README.md",  # Documentação principal
        "STATUS_FINAL.md",  # Status do projeto
        "*.md",  # Toda documentação markdown
    ]

    for arquivo in arquivos_importantes:
        print(f"📌 {arquivo}")

    print("=" * 50)


def main():
    """
    Função principal
    """
    print("🧹 SCRIPT DE LIMPEZA - PASTA 156711")
    print("🎯 Objetivo: Remover arquivos redundantes e desnecessários")
    print("")

    # Listar arquivos importantes que serão mantidos
    listar_arquivos_importantes()

    # Executar limpeza
    total, espaco = excluir_arquivos_redundantes()

    print(f"\n🎉 LIMPEZA CONCLUÍDA COM SUCESSO!")
    print(f"📦 Projeto mais organizado e otimizado")
    print(f"🚀 Arquivos essenciais preservados")


if __name__ == "__main__":
    main()

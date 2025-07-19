#!/usr/bin/env python3
"""
Análise dos Arquivos Assembler para Identificar o Correto
"""


def analisar_arquivos_assembler():
    """
    Analisa os arquivos assembler disponíveis
    """
    print("🔍 ANÁLISE DOS ARQUIVOS ASSEMBLER")
    print("=" * 60)

    print("\n📂 ARQUIVOS ENCONTRADOS:")
    print("   1. assembler_final.c      (1155 linhas)")
    print("   2. assembler_corrected.c  (1177 linhas)")
    print("   3. debug_assembler.c      (55 linhas - apenas debug)")
    print("   4. assembler_final.exe    (executável atual)")

    print("\n🔍 ANÁLISE DE FUNCIONALIDADES:")

    print("\n1️⃣ ASSEMBLER_FINAL.C:")
    print("   ✅ Divisão '/' usa MFHI (CORRIGIDO)")
    print("   ✅ Modulo '%' usa MFLO (correto)")
    print("   ✅ Lógica if_f → BNE implementada")
    print("   ✅ Comentário indica 'CORREÇÃO: MFHI para quociente'")
    print("   📊 Status: CORRIGIDO e MAIS ATUAL")

    print("\n2️⃣ ASSEMBLER_CORRECTED.C:")
    print("   ✅ Divisão '/' usa MFHI")
    print("   ✅ Modulo '%' usa MFLO")
    print("   ✅ Lógica if_f → BNE implementada")
    print("   ✅ Mais casos de otimização (casos 7-12)")
    print("   📊 Status: MAIS COMPLETO mas possivelmente MAIS ANTIGO")

    print("\n3️⃣ DEBUG_ASSEMBLER.C:")
    print("   📋 Apenas para debug/análise")
    print("   📊 Status: UTILITÁRIO (manter)")

    print("\n🎯 QUAL É O ARQUIVO CORRETO?")
    print("-" * 40)

    print("\n📊 EVIDÊNCIAS:")
    print("   • Makefile aponta para assembler_final.c")
    print("   • assembler_final.exe existe (compilado de assembler_final.c)")
    print("   • assembler_final.c tem correção de divisão aplicada")
    print("   • assembler_corrected.c é mais completo mas mais antigo")
    print("   • Assembly gerado atual usa MFHI (indica correção funcionando)")

    print("\n✅ CONCLUSÃO:")
    print("   📌 assembler_final.c é o ARQUIVO CORRETO ATUAL")
    print("   📌 assembler_corrected.c é REDUNDANTE")
    print("   📌 debug_assembler.c é UTILITÁRIO (manter)")


def criar_plano_limpeza():
    """
    Cria plano de limpeza dos arquivos redundantes
    """
    print("\n🗑️ PLANO DE LIMPEZA:")
    print("=" * 60)

    print("\n🚮 ARQUIVOS A REMOVER:")
    print("   ❌ assembler_corrected.c  - Versão redundante")

    print("\n✅ ARQUIVOS A MANTER:")
    print("   📌 assembler_final.c      - Versão atual e corrigida")
    print("   📌 assembler_final.exe    - Executável atual")
    print("   📌 debug_assembler.c      - Utilitário de debug")

    print("\n🔧 JUSTIFICATIVAS:")
    print("   • assembler_final.c é a versão em uso (Makefile)")
    print("   • assembler_final.c tem correções mais recentes")
    print("   • assembler_corrected.c é versão anterior")
    print("   • Manter apenas uma versão evita confusão")


def executar_limpeza():
    """
    Recomendações para execução da limpeza
    """
    print("\n🚀 EXECUÇÃO DA LIMPEZA:")
    print("=" * 60)

    print("\n📋 COMANDOS RECOMENDADOS:")
    print("   1. Backup (opcional):")
    print("      copy assembler_corrected.c assembler_corrected.c.bak")
    print("")
    print("   2. Remover arquivo redundante:")
    print("      del assembler_corrected.c")
    print("")
    print("   3. Verificar se tudo ainda funciona:")
    print("      assembler_final.exe intermediate.txt")

    print("\n⚠️  PRECAUÇÕES:")
    print("   • Verificar se não há referências no Makefile")
    print("   • Confirmar que assembler_final.exe funciona")
    print("   • Manter backup se necessário")


def main():
    """
    Análise principal
    """
    print("🔍 ANÁLISE DE ARQUIVOS ASSEMBLER - DIRETÓRIO 156711")
    print("🎯 Objetivo: Identificar o arquivo correto e remover redundantes")
    print("")

    analisar_arquivos_assembler()
    criar_plano_limpeza()
    executar_limpeza()

    print("\n" + "=" * 60)
    print("🎉 ANÁLISE CONCLUÍDA!")
    print("📌 assembler_final.c é o arquivo correto")
    print("🗑️ assembler_corrected.c deve ser removido")
    print("🔧 debug_assembler.c deve ser mantido como utilitário")


if __name__ == "__main__":
    main()

#!/bin/bash
# Script de Build do Compilador 156711
# Compila o sistema completo: Compilador + Assembler

echo "=== Build do Compilador 156711 ==="
echo ""

# Compilar o compilador principal
echo "1. Compilando o compilador principal..."
gcc -o compilador_final.exe bison.tab.c funcs.c intermediate.c -I.
if [ $? -eq 0 ]; then
    echo "✅ Compilador compilado com sucesso!"
else
    echo "❌ Erro ao compilar o compilador!"
    exit 1
fi

# Compilar o assembler
echo ""
echo "2. Compilando o assembler..."
gcc -o assembler_corrected.exe assembler_corrected.c
if [ $? -eq 0 ]; then
    echo "✅ Assembler compilado com sucesso!"
else
    echo "❌ Erro ao compilar o assembler!"
    exit 1
fi

echo ""
echo "=== Build Concluído! ==="
echo "Arquivos gerados:"
echo "- compilador_final.exe"
echo "- assembler_corrected.exe"
echo ""
echo "Uso:"
echo "1. ./compilador_final.exe <arquivo.c> > intermediate.txt"
echo "2. ./assembler_corrected.exe intermediate.txt"
echo "3. Resultado em: assembly_output.asm e binary_output.txt"

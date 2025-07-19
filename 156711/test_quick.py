#!/usr/bin/env python3

# Script para recompilar e executar com debug simples
import subprocess
import os

# Ir para o diretório
os.chdir(r"c:\Users\marco\Projetinhos\Compilador\156711")

print("🔄 Executando todo o processo...")

# 1. Compilador
result = subprocess.run(
    ["compilador_final.exe", "gcd.c"], capture_output=True, text=True
)
if result.returncode != 0:
    print(f"❌ Erro no compilador: {result.stderr}")
    exit(1)
print("✅ Compilador executado")

# 2. Assembler
result = subprocess.run(
    ["assembler_final.exe", "intermediate_output.txt"], capture_output=True, text=True
)
print(f"📄 Saída do assembler:")
print(result.stdout)
print(f"📄 Erros do assembler:")
print(result.stderr)

# 3. Verificar assembly gerado
print("\n📋 Assembly gerado (primeiras 10 linhas):")
with open("assembly_output.asm", "r") as f:
    lines = f.readlines()
    for i, line in enumerate(lines[:10]):
        print(f"  {i}: {line.strip()}")

print("\n🎯 Verificando linha 2 especificamente:")
if len(lines) > 2:
    line2 = lines[2].strip()
    print(f"  Linha 2: {line2}")
    if "BNE" in line2 and "R2" in line2:
        print("  ❌ AINDA USA R2!")
    elif "BNE" in line2 and "R0" in line2:
        print("  ✅ AGORA USA R0!")

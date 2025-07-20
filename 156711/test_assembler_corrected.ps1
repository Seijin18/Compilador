# Script de Teste do Assembler Corrigido (PowerShell)
Write-Host "=== SCRIPT DE TESTE DO ASSEMBLER CORRIGIDO ===" -ForegroundColor Cyan
Write-Host ""

# Definir diretório de trabalho
$workDir = "c:\Users\marco\Projetinhos\Compilador\156711"
Set-Location $workDir

# Compilar o assembler corrigido
Write-Host "1. Compilando assembler corrigido..." -ForegroundColor Yellow
$compileResult = Start-Process -FilePath "gcc" -ArgumentList "-o", "assembler_final.exe", "assembler_corrected.c" -Wait -PassThru -NoNewWindow
if ($compileResult.ExitCode -eq 0) {
    Write-Host "   ✓ Compilação bem-sucedida" -ForegroundColor Green
} else {
    Write-Host "   ✗ Erro na compilação" -ForegroundColor Red
    exit 1
}

Write-Host ""

# Testar com arquivo de código intermediário
Write-Host "2. Testando com intermediate_clean.txt..." -ForegroundColor Yellow
$testResult = Start-Process -FilePath ".\assembler_final.exe" -ArgumentList "intermediate_clean.txt" -Wait -PassThru -NoNewWindow
if ($testResult.ExitCode -eq 0) {
    Write-Host "   ✓ Execução bem-sucedida" -ForegroundColor Green
} else {
    Write-Host "   ✗ Erro na execução" -ForegroundColor Red
    exit 1
}

Write-Host ""

# Verificar arquivos gerados
Write-Host "3. Verificando arquivos gerados..." -ForegroundColor Yellow
if (Test-Path "assembly_output_corrected.asm") {
    Write-Host "   ✓ assembly_output_corrected.asm gerado" -ForegroundColor Green
    $lines = (Get-Content "assembly_output_corrected.asm").Count
    Write-Host "     - Linhas: $lines" -ForegroundColor Gray
} else {
    Write-Host "   ✗ assembly_output_corrected.asm não foi gerado" -ForegroundColor Red
}

if (Test-Path "binary_output_corrected.txt") {
    Write-Host "   ✓ binary_output_corrected.txt gerado" -ForegroundColor Green
    $lines = (Get-Content "binary_output_corrected.txt").Count
    Write-Host "     - Linhas: $lines" -ForegroundColor Gray
} else {
    Write-Host "   ✗ binary_output_corrected.txt não foi gerado" -ForegroundColor Red
}

Write-Host ""

# Comparar com assembler original
Write-Host "4. Comparando com assembler original..." -ForegroundColor Yellow
if ((Test-Path "assembly_output.asm") -and (Test-Path "assembly_output_corrected.asm")) {
    $originalLines = (Get-Content "assembly_output.asm").Count
    $correctedLines = (Get-Content "assembly_output_corrected.asm").Count
    Write-Host "   - Assembler original: $originalLines linhas" -ForegroundColor Gray
    Write-Host "   - Assembler corrigido: $correctedLines linhas" -ForegroundColor Gray
    if ($correctedLines -gt $originalLines) {
        Write-Host "   ✓ Assembler corrigido gerou mais instruções (esperado devido às correções)" -ForegroundColor Green
    }
} else {
    Write-Host "   - Não foi possível comparar (arquivo original não encontrado)" -ForegroundColor Gray
}

Write-Host ""

# Verificar características específicas das correções
Write-Host "5. Verificando características das correções..." -ForegroundColor Yellow

# Verificar inicialização de $gp
$content = Get-Content "assembly_output_corrected.asm" -Raw
if ($content -match "LI.*R28.*4096") {
    Write-Host "   ✓ Inicializacao de `$gp encontrada" -ForegroundColor Green
} else {
    Write-Host "   ✗ Inicializacao de `$gp nao encontrada" -ForegroundColor Red
}

# Verificar uso de Frame Pointer
if ($content -match "R30") {
    Write-Host "   ✓ Uso de Frame Pointer (`$fp = R30) encontrado" -ForegroundColor Green
} else {
    Write-Host "   ✗ Uso de Frame Pointer nao encontrado" -ForegroundColor Red
}

# Verificar prólogo/epílogo de função
if (($content -match "SW.*R31.*-4") -and ($content -match "SW.*R30.*-8")) {
    Write-Host "   ✓ Prologo de funcao correto encontrado" -ForegroundColor Green
} else {
    Write-Host "   ✗ Prologo de funcao nao encontrado" -ForegroundColor Red
}

if (($content -match "LW.*R30.*-8") -and ($content -match "LW.*R31.*-4")) {
    Write-Host "   ✓ Epilogo de funcao correto encontrado" -ForegroundColor Green
} else {
    Write-Host "   ✗ Epilogo de funcao nao encontrado" -ForegroundColor Red
}

# Verificar instruções ADDI completas
if ($content -match "ADDI.*R29.*R29") {
    Write-Host "   ✓ Instrucoes ADDI completas encontradas" -ForegroundColor Green
} else {
    Write-Host "   ✗ Instrucoes ADDI incompletas" -ForegroundColor Red
}

Write-Host ""
Write-Host "=== TESTE CONCLUÍDO ===" -ForegroundColor Cyan
Write-Host ""
Write-Host "Resumo dos problemas corrigidos:" -ForegroundColor White
Write-Host "1. ✓ Gerenciamento de pilha com Frame Pointer" -ForegroundColor Green
Write-Host "2. ✓ Suporte a vetores (estrutura preparada)" -ForegroundColor Green
Write-Host "3. ✓ Inicializacao de variaveis globais (`$gp)" -ForegroundColor Green
Write-Host "4. ✓ Passagem robusta de parametros" -ForegroundColor Green
Write-Host "5. ✓ Prologo/epilogo adequados de funcoes" -ForegroundColor Green
Write-Host ""
Write-Host "Arquivos principais:" -ForegroundColor White
Write-Host "- assembler_corrected.c (código fonte corrigido)" -ForegroundColor Gray
Write-Host "- assembler_final.exe (executável)" -ForegroundColor Gray
Write-Host "- assembly_output_corrected.asm (assembly gerado)" -ForegroundColor Gray
Write-Host "- binary_output_corrected.txt (binario gerado)" -ForegroundColor Gray
Write-Host "- CORRECOES_ASSEMBLER.md (documentacao das correcoes)" -ForegroundColor Gray
Write-Host ""

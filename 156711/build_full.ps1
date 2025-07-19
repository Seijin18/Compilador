# Build Script para Pipeline Completo - Compilador + Assembler
# ============================================================

param(
    [string]$Action = "help",
    [string]$SourceFile = ""
)

# Configurações
$COMPILER = "compilador_final.exe"
$ASSEMBLER = "assembler_corrected.exe"
$DEFAULT_SOURCE = "gcd.c"

# Cores para saída
$Color = @{
    Header = "Magenta"
    Success = "Green"
    Warning = "Yellow"
    Error = "Red"
    Info = "Cyan"
    Gray = "Gray"
}

function Write-Header {
    param([string]$Text)
    Write-Host "=" * 60 -ForegroundColor $Color.Header
    Write-Host $Text -ForegroundColor $Color.Header
    Write-Host "=" * 60 -ForegroundColor $Color.Header
}

function Write-Step {
    param([string]$Text)
    Write-Host "`n$Text" -ForegroundColor $Color.Info
    Write-Host "-" * $Text.Length -ForegroundColor $Color.Gray
}

function Test-Prerequisites {
    Write-Step "Verificando pré-requisitos"
    
    if (-not (Test-Path $COMPILER)) {
        Write-Host "❌ Compilador não encontrado: $COMPILER" -ForegroundColor $Color.Error
        Write-Host "   Execute primeiro: gcc -o $COMPILER *.c" -ForegroundColor $Color.Warning
        return $false
    }
    
    if (-not (Test-Path $ASSEMBLER)) {
        Write-Host "❌ Assembler não encontrado: $ASSEMBLER" -ForegroundColor $Color.Error
        Write-Host "   Execute primeiro: gcc -o $ASSEMBLER assembler_corrected.c" -ForegroundColor $Color.Warning
        return $false
    }
    
    Write-Host "✅ Pré-requisitos atendidos!" -ForegroundColor $Color.Success
    return $true
}

function Build-Compiler {
    Write-Step "Compilando o compilador"
    
    $sourceFiles = @("bison.tab.c", "funcs.c", "intermediate.c")
    $missingFiles = $sourceFiles | Where-Object { -not (Test-Path $_) }
    
    if ($missingFiles.Count -gt 0) {
        Write-Host "❌ Arquivos fonte não encontrados:" -ForegroundColor $Color.Error
        $missingFiles | ForEach-Object { Write-Host "   - $_" -ForegroundColor $Color.Error }
        return $false
    }
    
    Write-Host "Compilando: gcc -o $COMPILER $($sourceFiles -join ' ')" -ForegroundColor $Color.Info
    & gcc -o $COMPILER $sourceFiles
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✅ Compilador construído com sucesso!" -ForegroundColor $Color.Success
        return $true
    } else {
        Write-Host "❌ Erro na compilação do compilador!" -ForegroundColor $Color.Error
        return $false
    }
}

function Build-Assembler {
    Write-Step "Compilando o assembler"
    
    if (-not (Test-Path "assembler_corrected.c")) {
        Write-Host "❌ Arquivo fonte não encontrado: assembler_corrected.c" -ForegroundColor $Color.Error
        return $false
    }
    
    Write-Host "Compilando: gcc -o $ASSEMBLER assembler_corrected.c" -ForegroundColor $Color.Info
    & gcc -o $ASSEMBLER assembler_corrected.c
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✅ Assembler construído com sucesso!" -ForegroundColor $Color.Success
        return $true
    } else {
        Write-Host "❌ Erro na compilação do assembler!" -ForegroundColor $Color.Error
        return $false
    }
}

function Compile-Source {
    param([string]$InputFile)
    
    if (-not (Test-Path $InputFile)) {
        Write-Host "❌ Arquivo fonte não encontrado: $InputFile" -ForegroundColor $Color.Error
        return $false
    }
    
    Write-Step "Compilando arquivo fonte: $InputFile"
    
    $intermediateFile = "intermediate_output.txt"
    
    Write-Host "Executando: .\$COMPILER $InputFile" -ForegroundColor $Color.Info
    
    # Usar PowerShell pipeline para garantir encoding correto
    & ".\$COMPILER" $InputFile | Out-File -Encoding ASCII $intermediateFile
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✅ Compilação bem-sucedida!" -ForegroundColor $Color.Success
        Write-Host "   Código intermediário salvo em: $intermediateFile" -ForegroundColor $Color.Gray
        return $intermediateFile
    } else {
        Write-Host "❌ Erro na compilação!" -ForegroundColor $Color.Error
        return $false
    }
}

function Assemble-Code {
    param([string]$IntermediateFile)
    
    if (-not (Test-Path $IntermediateFile)) {
        Write-Host "❌ Arquivo intermediário não encontrado: $IntermediateFile" -ForegroundColor $Color.Error
        return $false
    }
    
    Write-Step "Gerando assembly: $IntermediateFile"
    
    Write-Host "Executando: .\$ASSEMBLER $IntermediateFile" -ForegroundColor $Color.Info
    & ".\$ASSEMBLER" $IntermediateFile
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✅ Assembly gerado com sucesso!" -ForegroundColor $Color.Success
        return $true
    } else {
        Write-Host "❌ Erro na geração do assembly!" -ForegroundColor $Color.Error
        return $false
    }
}

function Show-Results {
    Write-Step "Resultados da compilação"
    
    if (Test-Path "assembly_output.asm") {
        Write-Host "`n=== Assembly Gerado (primeiras 20 linhas) ===" -ForegroundColor $Color.Info
        Get-Content "assembly_output.asm" | Select-Object -First 20 | ForEach-Object { 
            Write-Host $_ -ForegroundColor White 
        }
        Write-Host "..." -ForegroundColor $Color.Gray
        Write-Host "📄 Arquivo completo: assembly_output.asm" -ForegroundColor $Color.Gray
    }
    
    if (Test-Path "binary_output.txt") {
        Write-Host "`n=== Código Binário (primeiras 10 linhas) ===" -ForegroundColor $Color.Info
        Get-Content "binary_output.txt" | Select-Object -First 10 | ForEach-Object { 
            Write-Host $_ -ForegroundColor White 
        }
        Write-Host "..." -ForegroundColor $Color.Gray
        Write-Host "📄 Arquivo completo: binary_output.txt" -ForegroundColor $Color.Gray
    }
}

function Run-FullPipeline {
    param([string]$InputFile = $DEFAULT_SOURCE)
    
    Write-Header "PIPELINE COMPLETO - COMPILADOR + ASSEMBLER"
    
    if (-not (Test-Prerequisites)) { return }
    
    $intermediateFile = Compile-Source $InputFile
    if (-not $intermediateFile) { return }
    
    $success = Assemble-Code $intermediateFile
    if (-not $success) { return }
    
    Show-Results
    
    Write-Host "`n✅ Pipeline executado com sucesso!" -ForegroundColor $Color.Success
}

function Clean-All {
    Write-Step "Limpando arquivos gerados"
    
    $filesToRemove = @(
        "intermediate_output.txt",
        "assembly_output.asm", 
        "binary_output.txt",
        "tree.txt",
        "symbol_table.txt",
        "intermediate.txt"
    )
    
    foreach ($file in $filesToRemove) {
        if (Test-Path $file) {
            Remove-Item $file
            Write-Host "Removido: $file" -ForegroundColor $Color.Gray
        }
    }
    Write-Host "✅ Limpeza concluída!" -ForegroundColor $Color.Success
}

function Show-Help {
    Write-Header "SISTEMA DE BUILD - COMPILADOR MIPS CUSTOMIZADO"
    
    Write-Host "Uso: .\build_full.ps1 [ação] [arquivo]" -ForegroundColor White
    Write-Host ""
    Write-Host "Ações disponíveis:" -ForegroundColor $Color.Warning
    Write-Host "  build-compiler  - Compila o compilador" -ForegroundColor White
    Write-Host "  build-assembler - Compila o assembler" -ForegroundColor White
    Write-Host "  build-all       - Compila compilador + assembler" -ForegroundColor White
    Write-Host "  run            - Executa pipeline completo (padrão: $DEFAULT_SOURCE)" -ForegroundColor White
    Write-Host "  clean          - Remove arquivos gerados" -ForegroundColor White
    Write-Host "  help           - Mostra esta ajuda" -ForegroundColor White
    Write-Host ""
    Write-Host "Exemplos:" -ForegroundColor $Color.Warning
    Write-Host "  .\build_full.ps1 build-all" -ForegroundColor $Color.Gray
    Write-Host "  .\build_full.ps1 run" -ForegroundColor $Color.Gray
    Write-Host "  .\build_full.ps1 run sort.c" -ForegroundColor $Color.Gray
    Write-Host "  .\build_full.ps1 clean" -ForegroundColor $Color.Gray
}

# Execução baseada na ação
switch ($Action.ToLower()) {
    "build-compiler" {
        Write-Header "COMPILANDO COMPILADOR"
        Build-Compiler
    }
    "build-assembler" {
        Write-Header "COMPILANDO ASSEMBLER"
        Build-Assembler  
    }
    "build-all" {
        Write-Header "COMPILANDO TODOS OS COMPONENTES"
        $compilerSuccess = Build-Compiler
        $assemblerSuccess = Build-Assembler
        if ($compilerSuccess -and $assemblerSuccess) {
            Write-Host "`n✅ Todos os componentes compilados com sucesso!" -ForegroundColor $Color.Success
        }
    }
    "run" {
        $targetFile = if ($SourceFile) { $SourceFile } else { $DEFAULT_SOURCE }
        Run-FullPipeline $targetFile
    }
    "clean" {
        Write-Header "LIMPEZA DE ARQUIVOS"
        Clean-All
    }
    "help" {
        Show-Help
    }
    default {
        if ($Action -ne "help") {
            Write-Host "Ação desconhecida: $Action" -ForegroundColor $Color.Error
            Write-Host ""
        }
        Show-Help
    }
}

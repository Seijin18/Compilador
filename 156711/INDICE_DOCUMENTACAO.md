# 📚 Índice de Documentação - Compilador 156711

## 📋 Documentos Principais

### 1. 🎯 **DOCUMENTACAO_SINTESE.md** - **DOCUMENTO PRINCIPAL**
**Documentação unificada e completa da parte de síntese do compilador**
- Gerador de código intermediário
- Assembler (tradutor de quadruplas) - **ATUALIZADO**
- Gerador de código binário
- Exemplos detalhados e especificações técnicas

### 2. � **ATUALIZACAO_MEMORIA.md** - **NOVO**
**Detalhes das melhorias no gerenciamento de memória**
- Sistema de Frame Pointer implementado
- Prólogo/epílogo estruturado
- Comparação antes vs. depois
- Validação e benefícios alcançados

### 3. �📖 **README.md**
Guia de uso geral do sistema
- Como compilar e executar
- Pipeline completo
- Exemplos básicos

### 4. ✅ **STATUS_FINAL.md**
Status do projeto e objetivos alcançados
- Resumo de funcionalidades
- Métricas de performance
- Validação e testes

### 5. 🔧 **memory_management_req.txt**
Requisitos específicos de gerenciamento de memória
- Resumo dos requisitos atendidos
- Referência à implementação

### 6. 📐 **memory_ref.txt**
Arquivo de referência usado para as melhorias
- Template de função estruturado
- Layout de activation record
- Estratégia de gerenciamento

## 📁 Arquivos de Saída e Exemplos

### Arquivos Gerados pelo Sistema
- `intermediate.txt` - Código intermediário (quadruplas)
- `assembly_output.asm` - Assembly legível com labels
- `binary_output.txt` - Código binário hexadecimal
- `symbol_table.txt` - Tabela de símbolos
- `tree.txt` - Árvore sintática

### Exemplos de Código
- `gcd.c` - Algoritmo de Euclides (exemplo principal)
- `test_if_return.c` - Teste de estruturas condicionais
- `sort.c` - Algoritmo de ordenação

## 🚀 Scripts de Automação

### Scripts Principais
- `build_full.ps1` - Pipeline completo (Windows)
- `build.ps1` - Compilação rápida (Windows)
- `build.sh` - Compilação (Linux/Mac)

### Como Usar
```powershell
# Pipeline completo
.\build_full.ps1 run programa.c

# Compilação manual
.\compilador_final.exe programa.c | Out-File -Encoding ASCII intermediate.txt
.\assembler_corrected.exe intermediate.txt
```

## 🔍 Navegação Rápida

- **Para entender o sistema completo**: Leia [`DOCUMENTACAO_SINTESE.md`](./DOCUMENTACAO_SINTESE.md)
- **Para ver as melhorias recentes**: Consulte [`ATUALIZACAO_MEMORIA.md`](./ATUALIZACAO_MEMORIA.md) 
- **Para usar o compilador**: Consulte [`README.md`](./README.md)
- **Para verificar status**: Veja [`STATUS_FINAL.md`](./STATUS_FINAL.md)
- **Para executar**: Use scripts `build_full.ps1` ou `build.ps1`

---

> **📌 Nota**: A documentação foi unificada em `DOCUMENTACAO_SINTESE.md` para fornecer uma visão completa e detalhada do sistema de síntese do compilador 156711. As melhorias recentes no gerenciamento de memória estão documentadas em `ATUALIZACAO_MEMORIA.md`.

# RESOLUÇÃO FINAL DO PROBLEMA DE GERAÇÃO DE CÓDIGO INTERMEDIÁRIO

## Problema Identificado
Durante os testes do pipeline completo do compilador, foi identificado que o código intermediário não estava sendo gerado corretamente. O compilador exibia a mensagem "Could not write intermediate code" em vez de gerar as quadruplas esperadas.

## Diagnóstico
O problema estava relacionado à linkagem durante a compilação do `compilador_final.exe`. A tentativa inicial de compilar com a flag `-ly` (biblioteca yacc) falhou:

```bash
gcc -o compilador_final.exe bison.tab.c funcs.c intermediate.c -ly
# Erro: cannot find -ly
```

## Solução Implementada
1. **Recompilação sem biblioteca yacc**: O compilador foi recompilado sem a dependência da biblioteca yacc:
   ```bash
   gcc -o compilador_final.exe bison.tab.c funcs.c intermediate.c
   ```

2. **Verificação do pipeline**: Após a recompilação, o pipeline completo foi testado:
   ```bash
   .\compilador_final.exe gcd.c; .\assembler_corrected.exe intermediate.txt
   ```

## Resultado Final
O pipeline completo agora funciona corretamente:

### Código Intermediário Gerado (30 quadruplas):
```
(goto,main, , )
(fun,gcd, , )
(alloc,u,1, )
(alloc,v,1, )
(immed,0, ,t0)
(==,v,t0,t1)
(if_f,t1,L0, )
(ret,u, , )
(label,L0, , )
(/,u,v,t2)
(*,t2,v,t3)
(-,u,t3,t4)
(param,v, , )
(param,t4, , )
(call,gcd,v,t5)
(ret,t5, , )
(label,L1, , )
(endfun, , , )
(fun,main, , )
(alloc,x,1, )
(alloc,y,1, )
(input, , ,t6)
(asn,t6, ,x)
(input, , ,t7)
(asn,t7, ,y)
(param,x, , )
(param,y, , )
(call,gcd,x,t8)
(output,t8,0, )
(endfun, , , )
```

### Estatísticas do Assembler:
- **Quadruplas processadas**: 30
- **Instruções assembly geradas**: 58
- **Labels encontrados**: 4
- **Símbolos na tabela**: 4

### Validação Final:
- **Instruções analisadas**: 54
- **Total de erros**: 0
- **Status**: ✅ **TODAS AS INSTRUÇÕES CODIFICADAS CORRETAMENTE**

## Melhorias Implementadas
1. **Sistema de Frame Pointer**: Implementado com R30 (FP), R29 (SP), R31 (RA)
2. **Correção de formatos de instrução**: ADDI/SUBI agora usam campo RT corretamente
3. **Substituição de ADDI negativo por SUBI**: Conforme solicitado
4. **Validação completa**: 0 erros detectados pelo sistema de verificação

## Conclusão
O compilador está agora funcionando completamente, gerando código correto e validado para o processador MIPS customizado. O pipeline completo (C → código intermediário → assembly → binário) opera sem erros.

**Data**: 19/07/2025
**Status**: ✅ CONCLUÍDO COM SUCESSO

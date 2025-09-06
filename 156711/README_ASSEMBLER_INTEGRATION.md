# Assembler Integration into Bison.y Compiler

## Overview
Successfully integrated the assembler functionality from `assembler_corrected.c` into the main compiler (`bison.y`). The compiler now supports full compilation pipeline from source code to binary machine code.

## Features Added

### 1. Integrated Assembler Structures
- Added all necessary data structures from the assembler:
  - `AssemblerQuad` for intermediate code representation
  - `Instruction` for assembly instructions
  - `LabelMap` for label address mapping
  - `AssemblerSymbol` for symbol table management
  - `RegisterInfo` for register allocation
  - `FunctionContext` for function management
  - Opcode enumerations for all processor instructions

### 2. Enhanced Command Line Interface
```bash
Usage: compiler_with_assembler <filename> [-l|-p|-s|-a]
  -l: Análise léxica apenas
  -p: Análise sintática apenas  
  -s: Análise semântica apenas
  -a: Executar assembler (requer intermediate.txt)
  Sem flags: Executa compilação completa + assembler
```

### 3. Assembly Code Generation
The integrated assembler handles the following intermediate code operations:

#### Arithmetic Operations
- `+` → `ADD` instruction
- `-` → `SUB` instruction  
- `*` → `MULT` instruction
- `/` → `DIV` instruction

#### Control Flow
- `goto` → `J` (Jump) instruction
- `label` → Assembly labels
- `fun` → Function labels
- `call` → `JAL` (Jump and Link) instruction
- `ret` → `JR` (Jump Register) instruction
- `bne` → `BNE` (Branch Not Equal) instruction
- `beq` → `BEQ` (Branch Equal) instruction

#### Data Movement
- `asn` → `MOVE` instruction
- `immed` → `LI` (Load Immediate) instruction
- `param` → Parameter passing setup

#### I/O Operations
- `input` → `INPUT` instruction
- `output` → `OUTPUTREG` instruction

#### Memory Management
- `alloc` → Stack allocation with `ADDI`
- Function prologue/epilogue management

### 4. Output Files Generated
When running the full compilation pipeline:

1. **tree.txt** - Abstract Syntax Tree
2. **symbol_table.txt** - Symbol table information
3. **intermediate.txt** - Intermediate code (quadruples)
4. **assembly_output_integrated.asm** - Assembly code
5. **binary_output_integrated.txt** - Binary machine code

### 5. Example Usage

#### Full Compilation (Source → Binary)
```bash
.\compiler_with_assembler.exe gcd.c
```

#### Assembler Only (Intermediate → Binary)
```bash
.\compiler_with_assembler.exe dummy.txt -a
```

#### Individual Phases
```bash
.\compiler_with_assembler.exe gcd.c -p  # Syntax analysis only
.\compiler_with_assembler.exe gcd.c -s  # Semantic analysis only
```

## Test Results

Tested with `gcd.c` (Euclidean GCD algorithm):
- **Input**: 29 quadruples from intermediate code
- **Output**: 32 assembly instructions
- **Generated**: Complete assembly with function calls, branching, I/O operations

## Benefits

1. **Unified Pipeline**: Single executable handles complete compilation
2. **Consistent Output**: Maintains compatibility with existing processor design
3. **Enhanced Debugging**: All intermediate stages available for inspection
4. **Flexible Usage**: Can run individual phases or complete pipeline
5. **Robust Assembly**: Handles complex control flow and function calls

## Technical Implementation

### Key Functions Added
- `run_assembler_on_intermediate()` - Main assembler driver
- `parse_assembler_quadruple()` - Parse intermediate code format
- `read_intermediate_for_assembler()` - File I/O for intermediate code
- `add_instruction()` - Assembly instruction generation
- `write_assembly_file()` - Human-readable assembly output
- `write_binary_file()` - Machine code binary output

### Integration Points
- Modified main() function to call assembler after intermediate code generation
- Added command-line option parsing for assembler-only mode
- Integrated error handling and status reporting

## Compatibility
- Maintains full backward compatibility with existing compiler phases
- Compatible with the custom MIPS processor design
- Supports all existing intermediate code operations
- Preserves original assembler correction features

This integration successfully bridges the gap between high-level compilation and machine code generation, providing a complete toolchain for the custom processor architecture.

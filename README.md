# Virtual Machine (VM) in C++

A simple **stack-based virtual machine** written in C++ with a custom assembly language, assembler, and execution engine.

---

## Features

- Stack-based VM architecture
- Custom bytecode instruction set
- Arithmetic operations (ADD, SUB, MUL, DIV)
- Control flow (JMP, JZ, JNZ, JE, JNE, JGE, JLE)
- Simple assembler (text → bytecode)
- Parser for mini assembly language
- Runtime error handling (stack underflow, invalid jumps, etc.)
- Modular code structure
---

## Architecture

```txt
Assembly Code
     ↓
Parser
     ↓
Assembler
     ↓
Bytecode (Instructions)
     ↓
Virtual Machine
     ↓
Execution
```

---

## Project Structure
```
project/
│
├── main.cpp
│
├── vm/
│   ├── vm.h
│   ├── vm.cpp
│
├── assembler/
│   ├── assembler.h
│   ├── assembler.cpp
│   ├── parser.h
│   ├── parser.cpp
│
├── core/
│   ├── opcode.h
│   ├── instruction.h

```

## Example
```
PUSH 5
PUSH 3
ADD

PUSH 2
MUL

PRINT
HLT
```
## Output
```
Top of stack: 16.
Result: 16.
```


## Build

```
g++ main.cpp \
vm/vm.cpp \
assembler/assembler.cpp \
assembler/parser.cpp \
-o vm
```



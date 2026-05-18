#include "vm.h"
#include "opcode.h"
#include <stdexcept>
#include <iostream>

VM::VM(const std::vector<Instruction>& program) : program(program), ip(0), running(true) {}

void VM::run(){

    while(running){
        std::cout << "Executing instruction at IP: " << ip << std::endl;
        if(ip >= program.size()){
            running = false;
            throw std::runtime_error("Instruction pointer out of bounds");
        }

        Instruction instr = program[ip++];

        switch (instr.op)
        {
        case opcode::PUSH:
            stack.push(instr.operand);
            break;
        case opcode::POP:
            stack.pop();
            break;
        case opcode::ADD:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(a + b);
            break;
        }
        case opcode::SUB:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            stack.push(a - b);
            break;
        }
        case opcode::MUL:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            stack.push(a * b);
            break;
        }
        case opcode::DIV:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if(b == 0){
                running = false;
                throw std::runtime_error("Division by zero");
            }

            stack.push(a / b);
            break;
        }
        case opcode::HLT:
            running = false;
            break;
        case opcode::PRINT:
            std::cout << "Top of stack: " << stack.top() << std::endl;
            break;
        case opcode::JMP:
            ip = instr.operand;
            break;
        case opcode::JZ:{
            int value = stack.top(); stack.pop();
            if(value == 0){
                ip = instr.operand;
            }
            break;
        }
        case opcode::JNZ:{
            int value = stack.top(); stack.pop();
            if(value != 0){
                ip = instr.operand;
            }
            break;
        }
        case opcode::JE:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if(a == b){
                ip = instr.operand;
            }
            break;
        }
        case opcode::JNE:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if(a != b){
                ip = instr.operand;
            }
            break;
        }
        case opcode::JGE:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if(a >= b){
                ip = instr.operand;
            }
            break;
        }
        case opcode::JLE:{
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if(a <= b){
                ip = instr.operand;
            }
            break;
        }
        
        default:
            break;
        }
    }
    
    std::cout<< "Result: " << stack.top() << std::endl;

}
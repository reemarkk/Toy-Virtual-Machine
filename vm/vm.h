#pragma once 
#include <vector>
#include <stack>
#include "../core/instruction.h"
#include "../core/opcode.h"

class VM{
        public:
        std::stack<int> stack;
        std::vector<Instruction> program;
        int ip; // instruction pointer or program counter
        bool running;
        
        VM(const std::vector<Instruction>& program);
        void run();
        void jump(int address);
        int pop();
        
};
#include "vm.h"
#include <vector>
#include <iostream>

int main(){
   std::vector<Instruction> program =
   {
    {PUSH, 5},
    {PUSH, 3},
    {ADD, 0},
    {PUSH, 2},
    {MUL, 0},
    {HLT, 0}
   };

    VM vm(program);
    std::cout<<"Running VM..."<<std::endl;
    vm.run();
}
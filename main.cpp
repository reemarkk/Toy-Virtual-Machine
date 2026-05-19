#include <iostream>

#include "assembler/assembler.h"
#include "vm/vm.h"

int main() {

    std::string code = R"(

        PUSH 5
        PUSH 3
        ADD

        PUSH 2
        MUL

        HLT

    )";

    try {

        std::vector<Instruction> program = assemble(code);

        VM vm(program);

        vm.run();
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
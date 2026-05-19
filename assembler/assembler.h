#include <vector>
#include <stack>
#include "../core/instruction.h"

// text to bytecode assembler
std::vector<Instruction> assemble(const std::string& source);
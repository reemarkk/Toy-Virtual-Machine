#include "assembler.h"
#include "parser.h"
#include "../core/opcode.h"

#include <unordered_map>
#include <stdexcept>

static opcode toOpcode(const std::string& s) {

    static std::unordered_map<std::string, opcode> map = {
        {"PUSH", opcode::PUSH},
        {"POP",  opcode::POP},
        {"ADD",  opcode::ADD},
        {"SUB",  opcode::SUB},
        {"MUL",  opcode::MUL},
        {"DIV",  opcode::DIV},
        {"HLT",  opcode::HLT},
        {"PRINT", opcode::PRINT},
        {"JMP", opcode::JMP},
        {"JZ", opcode::JZ},
        {"JNZ", opcode::JNZ},
        {"JE", opcode::JE},
        {"JNE", opcode::JNE},
        {"JGE", opcode::JGE},
        {"JLE", opcode::JLE},
    };

    auto it = map.find(s);

    if (it == map.end())
        throw std::runtime_error("Unknown opcode: " + s);

    return it->second;
}

std::vector<Instruction> assemble(const std::string& source) {
    std::vector<Instruction> program;
    auto lines = parse(source);

    for (const auto& line : lines) {
        opcode op = toOpcode(line.op);

        if (line.hasOperand)
            program.emplace_back(op, line.operand);
        else
            program.emplace_back(op, 0);
    }
    return program;
}

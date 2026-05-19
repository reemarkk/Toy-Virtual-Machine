#pragma once

#include "opcode.h"

struct Instruction{
    opcode op; // operation code
    int operand; // operand value

    Instruction(opcode op, int operand = 0) : op(op), operand(operand) {}
};
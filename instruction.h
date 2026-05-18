#pragma once

#include "opcode.h"

struct Instruction{
    opcode op;
    int operand;

    Instruction(opcode op, int operand = 0) : op(op), operand(operand) {}
};
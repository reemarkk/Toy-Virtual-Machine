#include <vector>
#include <string>

struct TokenLine{
    std::string op; // operation
    bool hasOperand; // whether the line has an operand
    int operand; // operand value if hasOperand is true
};

std::vector<TokenLine> parse(const std::string& source);
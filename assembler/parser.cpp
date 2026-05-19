#include "parser.h"

#include <sstream>

std::vector<TokenLine> parse(const std::string& source) {
    std::vector<TokenLine> lines;
    std::stringstream ss(source);
    std::string line;

    while (std::getline(ss, line)) {
        std::stringstream ls(line);
        TokenLine t;
        t.hasOperand = false;
        ls >> t.op;

        // skip empty lines
        if (t.op.empty())
            continue;

        if (ls >> t.operand) {
            t.hasOperand = true;
        }

        lines.push_back(t);
    }

    return lines;
}
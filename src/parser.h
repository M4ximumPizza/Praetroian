#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class Parser {
public:
    Parser(Lexer& lexer);
    void parse();

private:
    Lexer& lexer;
};

#endif // PARSER_H

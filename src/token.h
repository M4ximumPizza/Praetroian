#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    IDENTIFIER,
    KEYWORD,
    SEMICOLON,
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PAREN,
    CLOSE_PAREN,
    EQUALS,
    INT_LITERAL,
    STRING_LITERAL,
    OPERATOR,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string lexeme;
};

#endif // TOKEN_H


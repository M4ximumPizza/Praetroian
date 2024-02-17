#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>
#include <vector>
#include <regex>

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

class Lexer {
public:
    Lexer(const std::string& sourceCode);
    Token getNextToken();

private:
    const std::string sourceCode;
    size_t currentPosition;
    const std::vector<std::pair<std::string, TokenType>> regexTokens;
    void skipWhitespace();
};

#endif // LEXER_H

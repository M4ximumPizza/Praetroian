#include "Parser.h"

Parser::Parser(Lexer& lexer) : lexer(lexer) {}

void Parser::parse() {
    Token token;
    do {
        token = lexer.getNextToken();
        std::cout << "Token: " << token.lexeme << " Type: " << token.type << std::endl;
    } while (token.type != END_OF_FILE);
}


#include "Lexer.h"

Lexer::Lexer(const std::string& sourceCode) : sourceCode(sourceCode), currentPosition(0),
    regexTokens {
        {"\\b[a-zA-Z_]\\w*\\b", IDENTIFIER},
        {"\\b(int|float|double|boolean|char|void)\\b", KEYWORD},
        {"\\;", SEMICOLON},
        {"\\{", OPEN_BRACE},
        {"\\}", CLOSE_BRACE},
        {"\\(", OPEN_PAREN},
        {"\\)", CLOSE_PAREN},
        {"\\=", EQUALS},
        {"\\d+", INT_LITERAL},
        {"\"(\\\\.|[^\\\\\"])*\"", STRING_LITERAL},
        {"[\\+\\-\\*/]", OPERATOR}
    }
{}

Token Lexer::getNextToken() {
    skipWhitespace();

    if (currentPosition >= sourceCode.length()) {
        return Token{END_OF_FILE, ""};
    }

    for (const auto& regexToken : regexTokens) {
        std::regex regex(regexToken.first);
        std::smatch match;

        if (std::regex_search(sourceCode.begin() + currentPosition, sourceCode.end(), match, regex, std::regex_constants::match_continuous)) {
            currentPosition += match.position() + match.length();
            return Token{regexToken.second, match.str()};
        }
    }

    std::cerr << "Unknown token at position " << currentPosition << std::endl;
    return Token{END_OF_FILE, ""};
}

void Lexer::skipWhitespace() {
    while (std::isspace(sourceCode[currentPosition])) {
        ++currentPosition;
    }
}


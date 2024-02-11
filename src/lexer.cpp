#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

// Define token types
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

// Token structure
struct Token {
    TokenType type;
    std::string lexeme;
};

// Java Lexer
class Lexer {
public:
    Lexer(const std::string& sourceCode) : sourceCode(sourceCode), currentPosition(0) {}

    // Get next token
    Token getNextToken() {
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

        // Unknown token
        std::cerr << "Unknown token at position " << currentPosition << std::endl;
        return Token{END_OF_FILE, ""};
    }

private:
    const std::string sourceCode;
    size_t currentPosition;
    const std::vector<std::pair<std::string, TokenType>> regexTokens {
        {"\\b[a-zA-Z_]\\w*\\b", IDENTIFIER},
        {"\\b(int|float|double|boolean|char|void)\\b", KEYWORD},
        {"\\;", SEMICOLON},
        {"\\{", OPEN_BRACE},
        {"\\}", CLOSE_BRACE},
        {"\\(", OPEN_PAREN},
        {"\\)", CLOSE_PAREN},
        {"\\=", EQUALS},
        {"\\d+", INT_LITERAL},
        {"\"(?:\\\\.|[^\"])*\"", STRING_LITERAL},
        {"[\\+\\-\\*/]", OPERATOR},
        {"\\b(if|else|while|for|return)\\b", KEYWORD} // Add control flow keywords
    };

    // Skip whitespaces
    void skipWhitespace() {
        while (std::isspace(sourceCode[currentPosition])) {
            ++currentPosition;
        }
    }
};

// Java Parser
class Parser {
public:
    Parser(Lexer& lexer) : lexer(lexer) {}

    void parse() {
        Token token;
        do {
            token = lexer.getNextToken();
            // You can implement parsing logic here
            // For demonstration, just print the tokens
            std::cout << "Token: " << token.lexeme << " Type: " << token.type << std::endl;
        } while (token.type != END_OF_FILE);
    }

private:
    Lexer& lexer;
};

int main() {
    // Read source code from file
    std::ifstream file("src/javatest/Main.java");
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open source file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sourceCode = buffer.str();

    Lexer lexer(sourceCode);
    Parser parser(lexer);
    parser.parse();

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

// All the token types for the lexer.
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
    size_t position;
};

// AST Node types
enum class NodeType {
    Program,
    Declaration,
    Statement,
    Expression
};

// AST Node base class
class Node {
public:
    Node(NodeType type) : type(type) {}
    virtual ~Node() {}

    NodeType getType() const { return type; }

private:
    NodeType type;
};

// AST Program Node
class ProgramNode : public Node {
public:
    ProgramNode() : Node(NodeType::Program) {}
    std::vector<Node*> declarations;
};

// AST Declaration Node
class DeclarationNode : public Node {
public:
    DeclarationNode(TokenType keywordType, const std::string& identifier)
        : Node(NodeType::Declaration), keywordType(keywordType), identifier(identifier) {}

    TokenType keywordType;
    std::string identifier;
};

// AST Statement Node
class StatementNode : public Node {
public:
    StatementNode() : Node(NodeType::Statement) {}
    // For simplicity, let's assume a statement can only be an expression
    Node* expression;
};

// AST Expression Node
class ExpressionNode : public Node {
public:
    ExpressionNode() : Node(NodeType::Expression) {}
    // For simplicity, let's assume expression is just an identifier
    std::string identifier;
};

class Lexer {
public:
    Lexer(const std::string& sourceCode) : sourceCode(sourceCode), currentPosition(0) {}

    // Get next token
    Token getNextToken() {
        skipWhitespace();

        if (currentPosition >= sourceCode.length()) {
            return Token{END_OF_FILE, "", currentPosition};
        }

        for (const auto& regexToken : regexTokens) {
            std::regex regex(regexToken.first);
            std::smatch match;

            if (std::regex_search(sourceCode.begin() + currentPosition, sourceCode.end(), match, regex, std::regex_constants::match_continuous)) {
                currentPosition += match.position() + match.length();
                return Token{regexToken.second, match.str(), currentPosition};
            }
        }

        // Unknown token
        std::string unidentifiedToken = sourceCode.substr(currentPosition, 10); // Extract the unidentified token
        std::cerr << "Unknown token at position " << currentPosition << ": " << unidentifiedToken << std::endl;
        return Token{END_OF_FILE, "", currentPosition};
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
        {"\\b(if|else|while|for|return)\\b", KEYWORD},
        {"\\b(package)\\b", KEYWORD},
        {"\\[\\]", OPERATOR},
        {"System\\.out\\.print", IDENTIFIER}
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
            //TODO: Implement parsing logic here
            // For demonstration, just print the tokens
            std::cout << "Token: " << token.lexeme << " Type: " << token.type << std::endl;
        } while (token.type != END_OF_FILE);
    }

private:
    Lexer& lexer;

    // Parse declaration
    DeclarationNode* parseDeclaration(const Token& keywordToken) {
        Token identifierToken = lexer.getNextToken();
        if (identifierToken.type != IDENTIFIER) {
        //TODO: Make a way to handle errors
        }
        return new DeclarationNode(keywordToken.type, identifierToken.lexeme);
    }
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

#include <iostream>
#include <fstream>
#include "lexer.h"
#include "parser.h"
#include "terminal.h"

int main() {
    // Open the file
    std::ifstream file("javatest/Main.java");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Read the content of the file into a string
    std::string sourceCode((std::istreambuf_iterator<char>(file)),
                       (std::istreambuf_iterator<char>()));

    // Close the file
    file.close();

    // Process the source code
    Lexer lexer(sourceCode);
    Parser parser(lexer);
    parser.parse();

    return terminal_main();
}

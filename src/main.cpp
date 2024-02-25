#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "terminal.h"

int main() {
    std::string sourceCode = "public class Main {\n\tpublic static void main(String[] args) {\n\t\tSystem.out.println(\"Hello, World!\");\n\t}\n}";

    Lexer lexer(sourceCode);
    Parser parser(lexer);
    parser.parse();

    return terminal_main();
}

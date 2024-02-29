![Praetorian Logo](pictures/logo.jpg)

# Praetorian - Java to Machine Code Compiler

Praetorian is a project in development aiming to create a Java to machine code compiler. Currently in its nascent stage, it is not yet suitable for practical use. The primary objective is to devise a compiler capable of translating Java code directly into machine code, thereby eliminating the dependency on the Java Virtual Machine (JVM).

Similar to the 'javac' command which compiles Java code into bytecode, Praetorian will generate machine code instead of bytecode.

## Goals:
- [ ] Develop a lexer
- [ ] Implement a parser
- [ ] Construct an Abstract Syntax Tree (AST)
- [ ] Make a custom terminal
- [ ] Make it attached to default OS terminal
- [ ] Establish an intermediate representation
- [ ] Produce comprehensive documentation
- [ ] Ensure compatibility with multiple Java versions (JDK11-Current)
- [ ] Enable compilation via command line and integration with external programs

If you want to look at the in depth goals. Look [here](GOALS.md)

## Getting Started
To initiate involvement with this project, the repository needs to be cloned followed by building the project. Written in C++, the project supports compilation using various methods. You can utilize [Clang](https://clang.llvm.org) or [GCC](https://gcc.gnu.org/) for compiling.

## Contributors
<img src="https://github.com/m4ximumpizza.png" alt="Logan Abernathy" height="100" style="height: 100px;" /> <img src="https://github.com/shabman.png" alt="Shabman" height="100" style="height: 100px;" />

## License
This project is licensed under the GNU General Public License v3.0. Refer to the [LICENSE](LICENSE.txt) file for further details.

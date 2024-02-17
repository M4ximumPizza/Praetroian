<img src="pictures/logo.jpg" alt="Praetorian Logo" width="200" height="200" />

# Praetorian - Java to Machine Code Compiler

Praetorian is in development to be a Java to machine code compiler. This
project is in its early stages and is not yet ready for use. The goal is to
create a compiler that can take Java code and compile it into machine code.
It will work without the need of the Java Virtual Machine (JVM). 

There will be a command similar to the 'javac' command that compiles into 
bytecode. Instead of bytecode, its machine code. 

## Goals:
- [X] Create a lexer
- [X] Create a parser
- [X] Abstract Syntax Tree (AST):
- [ ] Create an intermediate representation
- [ ] Create proper Documentation
- [ ] Add support for most Java versions (JDK11-Current)
- [ ] Make this useable compilable by the command line and a external program

## Getting Started
To get started with this project, you will need to clone the repository and
build the project. This project is written in CPP and can compile in a number
of ways. You can download [Clang](https://clang.llvm.org) or [GCC](https://gcc.gnu.org/)
to compile the project.

## License
This project is licensed under the GNU General Public License v3.0 - see the
[LICENSE](LICENSE.txt) file for details.

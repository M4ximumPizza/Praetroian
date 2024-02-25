#include "terminal.h"

// Include necessary headers
#include <iostream>
#include <string>
#include <chrono>

void displayHelp() {
    std::cout << "Available commands:\n";
    std::cout << "- help: Display available commands\n";
    std::cout << "- greet: Say hello\n";
    std::cout << "- time: Display current time\n";
    std::cout << "- exit: Exit the program\n";
}

void displayCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current time is: " << std::ctime(&currentTime);
}

int terminal_main() {
    std::string input;

    // ASCII art welcome message
    std::cout << " _    _ ____ __   ___ _____ __  __ ____    ____ _____    ____ ____   __   ____ ____ _____ ____ ____   __   _  _ \n";
    std::cout << "( \\/\\/ ( ___(  ) / __(  _  (  \\/  ( ___)  (_  _(  _  )  (  _ (  _ \\ /__\\ ( ___(_  _(  _  (  _ (_  _) /__\\ ( \\( )\n";
    std::cout << " )    ( )__) )(_( (__ )(_)( )    ( )__)     )(  )(_)(    )___/)   //(__)\\ )__)  )(  )(_)( )   /_)(_ /(__)\\ )  ( \n";
    std::cout << "(__/\\__(____(____\\___(_____(_/\\/\\_(____)   (__)(_____)  (__) (_)_)(__)(__(____)(__)(_____(_)_\\(____(__)(__(_)_)\n";
    std::cout << "\n";

    while (true) {
        // Print the prompt
        std::cout << "> ";

        // Get input from the user
        std::getline(std::cin, input);

        // Check for exit command
        if (input == "exit") {
            std::cout << "Exiting...\n";
            break;
        }

        // Check for help command
        if (input == "help") {
            displayHelp();
            continue;
        }

        // Check for time command
        if (input == "time") {
            displayCurrentTime();
            continue;
        }

        // Check for greet command
        if (input == "greet") {
            std::cout << "Hello! Welcome to my program!\n";
            continue;
        }

        // Unknown command
        std::cout << "Unknown command. Type 'help' for available commands.\n";
    }

    return 0;
}

#include <iostream>

int main() {
    char input;

    std::cout << "Choices for Breakfast:\n"
              << "  A. Two Bananas\n"
              << "  B. Three Bananas\n"
              << "  C. Four Bananas\n"
              << "What would you like for breakfast today?\n";
    std::cin >> input;

    switch (input) {
        case 'A':
            std::cout << "You chose two bananas!\n";
            break;
        case 'B':
            std::cout << "You chose three bananas!\n";
            break;
        case 'C':
            std::cout << "You chose four bananas!\n";
            break;
        default:
            std::cout << "Please choose from the options\n";
    }

    return 0;
}


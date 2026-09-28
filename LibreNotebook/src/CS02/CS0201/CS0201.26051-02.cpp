#include <iostream>

int main() {
    std::string password = "password";
    std::string input;

    std::cout << "Enter your password: ";
    std::cin >> input;

    bool correct = (input == password);

    if (correct) {
        std::cout << "Correct!\n";
    } else {
        std::cout << "Incorrect!\n";
    }

    return 0;
}


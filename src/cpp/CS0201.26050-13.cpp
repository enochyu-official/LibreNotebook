#include <iostream>

int main() {
    int birthdayYear = 9999;
    int input;
    bool wrong = true;

    while (wrong) {
        std::cout << "Guess which year I was born in!\n";
        std::cin >> input;

        if (input == birthdayYear) {
            wrong = false;
            std::cout << "Correct!\n";
        } else {
            std::cout << ":(\n";
        }
    }

    return 0;
}


#include <iostream>

int main() {
    int a;

    std::cout << "Enter a number: ";
    std::cin >> a;

    if (a > 10) {
        std::cout << "Your number is greater than ten!\n";
    } else if (a == 10) {
        std::cout << "Your number is ten!\n";
    } else {
        std::cout << "Your number is smaller than ten!\n";
    }

    return 0;
}



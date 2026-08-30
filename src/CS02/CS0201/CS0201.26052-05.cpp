#include <iostream>

int main() {
    int a = 5;
    int& ref = a; // reference to a

    std::cout << "ref: " << ref << "\n";
    std::cout << "a:   " << a   << "\n";
    ref++;
    std::cout << "After adding 1 to ref\n";
    std::cout << "ref: " << ref << "\n";
    std::cout << "a:   " << a   << "\n";

    return 0;
}


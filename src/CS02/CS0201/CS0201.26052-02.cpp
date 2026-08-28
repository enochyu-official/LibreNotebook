#include <iostream>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int mod(int a, int b) {
    return a % b;
}

int main() {
    std::cout << "1 + 2 = "    << add(1, 2)      << std::endl;
    std::cout << "3 - 4 = "    << subtract(3, 4) << std::endl;
    std::cout << "5 * 6 = "    << multiply(5, 6) << std::endl;
    std::cout << "7 / 8 = "    << divide(7, 8)   << std::endl;
    std::cout << "10 mod 9 = " << mod(10, 9)     << std::endl;

    std::cout << "((1 + 2) * 4) mod 10 = "
              << mod(multiply(add(1, 2), 4), 10) << std::endl;

    return 0;
}


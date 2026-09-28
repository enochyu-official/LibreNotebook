#include <iostream>

void increment1(int a) {
    a++;
}

void increment2(int& a) {
    a++;
}

int main() {
    int x = 5;
    increment1(x);
    std::cout << x << "\n";

    x = 5;
    increment2(x);
    std::cout << x << "\n";

    return 0;
}


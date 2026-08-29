#include <iostream>

void increment1(int a) {
    a++;
    std::cout << a << "\n";
}

void increment2(int& a) {
    a++;
    std::cout << a << "\n";
}

int main() {
    int x = 5;
    increment1(x);
    x = 5;
    increment2(x);

    return 0;
}


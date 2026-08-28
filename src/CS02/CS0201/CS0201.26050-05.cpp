#include <iostream>

int main() {
    const int a = 5;
    int b;

    std::cout << "Type a number: ";
    std::cin >> b;
    std::cout << b << " + 5 = " << a + b << std::endl;
    
    return 0;
}


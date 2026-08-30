#include <iostream>

int sum(int n) {
    if (n > 0) {
        return n + sum(n-1);
    } else {
        return 0;
    }
}

int main() {
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::cout << "Sum: " << sum(n) << "\n";

    return 0;
}


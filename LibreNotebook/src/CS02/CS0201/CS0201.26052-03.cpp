#include <iostream>

int main() {
    int n;
    int sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    std::cout << "Sum: " << sum << "\n";

    return 0;
}


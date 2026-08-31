/**
 * Enoch Yu
 * Codeforces
 * Problem 231A. Team
 *
 * First two -> Y, N
 * 0 1 -> 0 1 1, 0 1 0
 * 1 0 -> 1 0 1, 1 0 0
 * or just take sum
 */

#include <iostream>

int main() {
    int n;
    int counter = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (a + b + c >= 2) {
            counter++;
        }
    }
    std::cout << counter << "\n";

    return 0;
}



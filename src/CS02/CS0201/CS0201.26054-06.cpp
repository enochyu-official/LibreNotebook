/***
 * Enoch Yu
 * Codeforces
 * Problem 4A. Watermelon
 *
 * 2a + 2b = total
 * 2 | total
 */

#include <iostream>

int main() {
    int w;
    std::cin >> w;

    if (w % 2 == 1) {
        std::cout << "NO\n";
    } else if (w == 2) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }

    return 0;
}


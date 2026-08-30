/***
 * Enoch Yu
 * Codeforces
 * Problem 546A. Soldier and Bananas
 *
 * k + 2k + 3k + ... + wk = k(1 + ... + w)
 */

#include <iostream>

int main() {
    int k, n, w;
    std::cin >> k >> n >> w;

    int sum1w = 0;
    for (int i = 1; i <= w; i++) {
        sum1w += i;
    }
    
    int total = k * sum1w;
    int need;
    if (total > n) {
        need = total - n;
    } else {
        need = 0;
    }
    std::cout << need << "\n";

    return 0;
}


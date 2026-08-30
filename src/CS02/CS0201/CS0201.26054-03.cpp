/***
 * Enoch Yu
 * USACO 2020 December (Bronze)
 * Problem 1. Do You Know Your ABCs?
 *
 * (A + B) + (B + C) - (A + B + C) = B
 * A, B, (C, A + B), A + C, B + C, A + B + C
 * A, B, (A + B + C) - (A + B)
 */

#include <iostream>

int main() {
    long long int a, b, c, d, e, f, g;
    std::cin >> a >> b >> c >> d >> e >> f >> g;
    long long int list[7] = {a, b, c, d, e, f, g};

    long long int A = list[0];
    long long int B = list[0];
    long long int sum = list[0];
    
    for (int i = 0; i < 7; i++) {
        if (list[i] >= sum) {
            sum = list[i];
            B = list[i];
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (list[i] <= A) {
                A = list[i];
                if (A <= list[j] && list[j] <= B && i != j) {
                    B = list[j];
                }
            }
        }
    }

    std::cout << A << " " << B << " " << sum - A - B << "\n";

    return 0;
}



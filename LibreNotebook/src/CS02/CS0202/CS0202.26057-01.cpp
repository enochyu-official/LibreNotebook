/**
 * Enoch Yu
 * 2018 USACO First Bronze
 * Problem 1. Mixing Milk
 *
 * 12 3 / 11 4 / 10 5
 * 3 4 5
 * 0 7 5
 * 0 2 10
 * 10 2 0
 * 1 11 0
 * 1 1 10
 * 11 1 0
 * 10 11 0
 * 10 1 10
 * 12 1 8
 * Conditions?
 */

#include <cstdio>
#include <iostream>
using namespace std;

void mix(int& a, int& b, int& x) {
    if (a + b <= x) {
        b = a + b;
        a = 0;
    } else {
        a = a + b - x;
        b = x;
    }
}

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c1, c2, c3, m1, m2, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int i = 0; i < 33; i++) {
        mix(m1, m2, c2);
        mix(m2, m3, c3);
        mix(m3, m1, c1);
    }
    mix(m1, m2, c2);

    cout << m1 << "\n" << m2 << "\n" << m3 << "\n";

    return 0;
}


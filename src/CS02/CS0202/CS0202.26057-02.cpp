/**
 * Enoch Yu
 * 2017 USACO Open Bronze
 * Problem 1. The Lost Cow
 *
 * x -> x + 1 -> x - 2 -> x + 4 -> x - 8 -> ...
 * 1 + 2 + 4 + ... + 2^n - |x pm 2^n mp y|
 * Shift by x -> z = y - x
 */

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;
    int z = y - x;

    int n = 0;
    if (z > 0) {
        while (pow(2,2*n) < z) {
            n++;
        }
        cout << 2*(pow(2,2*n) - 1) + z << "\n";
    } else if (z < 0) {
        while (pow(2,2*n+1) < -z) {
            n++;
        }
        cout << 2*(pow(2,2*n) - 1) - z << "\n";
    }

    return 0;
}


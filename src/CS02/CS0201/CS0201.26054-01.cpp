/**
 * Enoch Yu
 * 2018 USACO Third Bronze
 * Problem 1. Teleportation
 *
 * a b x y
 * |a - b| or
 * |a - x| + |b - y| or
 * |a - y| + |b - x|
 */

#include <cstdio>
#include <iostream>

int absDiff(int a, int b) {
    if (a > b) {
        return a - b;
    } else {
        return b - a;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    std::cin >> a >> b >> x >> y;

    int minD1 = absDiff(a, b);
    int minD2 = absDiff(a, x) + absDiff(b, y);
    int minD3 = absDiff(a, y) + absDiff(b, x);
    int minD  = min(minD1, min(minD2, minD3));

    std::cout << minD << "\n";

    return 0;
}


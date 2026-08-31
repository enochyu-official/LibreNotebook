/**
 * Enoch Yu
 * 2019 USACO US Open Bronze
 * Problem 1. Bucket Brigade
 *
 * min = |x2 - x1| + |y2 - y1| - 1
 * Holds even if rock since total same
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
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void findCoor(int& a, int& b, int& c, int& d, int& e, int& f,
              char arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == 'B') {
                a = i;
                b = j;
            } else if (arr[i][j] == 'L') {
                c = i;
                d = j;
            } else if (arr[i][j] == 'R') {
                e = i;
                f = j;
            }
        }
    }
}

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    char farm[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cin >> farm[i][j];
        }
    }

    int x1, x2, x3, y1, y2, y3;
    findCoor(x1, y1, x2, y2, x3, y3, farm);

    if ((x1 == x2 && x2 == x3 &&
        min(y1, y2) < y3 && y3 < max(y1, y2)) ||
        (y1 == y2 && y2 == y3) &&
        min(x1, x2) < x3 && x3 < max(x1, x2)) {
        std::cout << absDiff(x2, x1) + absDiff(y2, y1) + 1 << "\n";
    } else {
        std::cout << absDiff(x2, x1) + absDiff(y2, y1) - 1 << "\n";
    }

    return 0;
}


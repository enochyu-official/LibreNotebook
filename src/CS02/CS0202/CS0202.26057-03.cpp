/**
 * Enoch Yu
 * 2016 USACO Third Bronze
 * Problem 2. Circular Barn
 *
 * Try all cases from 1,...,n
 * Print the minimum
 * (n-1) r_k + (n-2) r_{k-1} + ... + r_{k+1}
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> config(n);
    for (int i = 0; i < n; i++) {
        cin >> config[i];
    }

    vector<int> SUM(n);
    for (int i = 0; i < n; i++) {
        SUM[i] = 0;
        for (int j = 1; j < n; j++) {
            if (j + i < n) {
                SUM[i] += j * config[j+i];
            } else {
                SUM[i] += j * config[j+i-n];
            }
        }
    }

    int min = SUM[0];
    for (int i = 0; i < n; i++) {
        if (min >= SUM[i]) {
            min = SUM[i];
        }
    }
    cout << min << "\n";

    return 0;
}


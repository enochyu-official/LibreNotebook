/** IN PROGRESS
 * Enoch Yu
 * 2015 USACO First Bronze
 * Problem 2. Speeding Ticket
 *
 * Cummulative stops for actual and bessie
 * Compare actual stops with bessie speed
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    int MAX = 0;
    cin >> N >> M;

    vector<array<int, 2>> actual(N), bessie(M);
    for (int i = 0; i < N; i++) {
        cin >> actual[i][0] >> actual[i][1];
        if (i > 0) {
            actual[i][0] += actual[i-1][0];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> bessie[i][0] >> bessie[i][1];
        if (i > 0) {
            bessie[i][0] += bessie[i-1][0];
        }
    }

    int counter = 0;
    for (int i = 0; i < M; i++) {
        for (int j = counter; j < N; j++) {
            if (bessie[i][0] >= actual[j][0]) {
                if (MAX < bessie[i][1] - actual[j][1]) {
                    MAX = bessie[i][1] - actual[j][1];
                }
                counter++;
            } else {
                break;
            }
        }
    }

    cout << MAX << "\n";

    return 0;
}


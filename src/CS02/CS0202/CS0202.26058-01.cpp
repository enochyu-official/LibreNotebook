/**
 * Enoch Yu
 * 2019 USACO Second Bronze
 * Problem 1. Shell Game
 *
 * Case I:   Answer in 1
 * Case II:  Answer in 2
 * Case III: Answer in 3
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int N;
    cin >> N;

    vector<array<int,3>> game(N);
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> game[i][j];
        }
    }


    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (game[i][0] == ans) {
            ans = game[i][1];
            if (game[i][2] == ans) {
                score1++;
            }
        } else if (game[i][1] == ans) {
            ans = game[i][0];
            if (game[i][2] == ans) {
                score1++;
            }
        } else if (game[i][2] == ans) {
            score1++;
        }
    }

    ans = 2;
    for (int i = 0; i < N; i++) {
        if (game[i][0] == ans) {
            ans = game[i][1];
            if (game[i][2] == ans) {
                score2++;
            }
        } else if (game[i][1] == ans) {
            ans = game[i][0];
            if (game[i][2] == ans) {
                score2++;
            }
        } else if (game[i][2] == ans) {
            score2++;
        }
    }

    ans = 3;
    for (int i = 0; i < N; i++) {
        if (game[i][0] == ans) {
            ans = game[i][1];
            if (game[i][2] == ans) {
                score3++;
            }
        } else if (game[i][1] == ans) {
            ans = game[i][0];
            if (game[i][2] == ans) {
                score3++;
            }
        } else if (game[i][2] == ans) {
            score3++;
        }
    }

    cout << max({score1, score2, score3}) << "\n";

    return 0;
}


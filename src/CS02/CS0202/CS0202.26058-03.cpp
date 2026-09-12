/**
 * Enoch Yu
 * 2017 USACO First Bronze
 * Problem 2. The Bovine Shuffle
 *
 * Loop through, find the first mismatch,
 * move the mismatch -> mismatch -> mismatch...
 * If loop stop, find the first mismatch again
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int findMis(int N, vector<int> row) {
    int pos = N + 1;
    for (int i = 0; i < N; i++) {
        if (row[i] != i + 1) {
            pos = i;
            break;
        }
    }
    return pos;
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int N;
    cin >> N;
    vector<int> row(N);
    for (int i = 0; i < N; i++) {
        cin >> row[i];
    }
    vector<int> ID(N);
    for (int i = 0; i < N; i++) {
        cin >> ID[i];
    }

    /*
    vector<int> row2;
    for (int i = 0; i < 3; i++) {
        row2 = row;

        for (int j = 0; j < N; j++) {
            int index1 = findMis(N, row2);

            if (findMis(N, row2) != N + 1) {
                int index2 = row2[index1] - 1;
                int a = ID[index2];
                ID[index2] = ID[index1];
                ID[index1] = a;

                int b = row2[index2];
                row2[index2] = row2[index1];
                row2[index1] = b;
            } else {
                break;
            }
        }
    }
    */
    vector<int> IDbak = ID;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            ID[j] = IDbak[row[j]-1];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ID[i] << "\n";
    }

    return 0;
}


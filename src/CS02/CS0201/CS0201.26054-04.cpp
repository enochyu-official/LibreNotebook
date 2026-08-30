/*** IN PROGRESS
 * Enoch Yu
 * USACO 2020 January (Bronze)
 * Problem 1. Word Processor
 *
 * .size() for num char
 * Recursion
 *
 * counter for indices
 *   0, 1 pass -> returns 2
 * void function to print them with line break
 */

#include <cstdio>
#include <iostream>

int sumChar(int& numChar, int a, int N, int K,
            std::string sentence[]) {
    while (numChar <= K) {
        if (a < N-1) {
            numChar += sentence[a].size();
            a++;
        }
    }

    return a;
}

void wordProcessor(int a, int N, int K, std::string sentence[]) {
    int numChar = 0;
    int b = sumChar(numChar, a, N, K, sentence) - 1;

    for (int i = a; i < b; i++) {
        if (i != b-1) {
            std::cout << sentence[i] << " ";
        } else {
            std::cout << sentence[i];
        }
    }
    std::cout << "\n";

    if (b < N) {
        wordProcessor(b, N, K, sentence);
    } else {
        std::cout << sentence[b] << "\n";
    }
}

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int N, K;
    std::cin >> N >> K;

    std::string sentence[N];
    for (int i = 0; i < N; i++) {
        std::cin >> sentence[i];
    }

    wordProcessor(0, N, K, sentence);

    return 0;
}



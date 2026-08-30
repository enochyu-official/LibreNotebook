/***
 * Enoch Yu
 * USACO 2016 January (Bronze)
 * Problem 1. Promoting Counting
 *
 * Detailed Thought Process Below the Program
 * promo2s = new + bi - bf
 * promo2g = promo2s + si - sf
 * promo2p = promo2g + gi - gf = pf - pi
 * Stops if get neg diff
 * B2S = promo2s
 * S2G = promo2g
 * G2P = promo2p
 */

#include <cstdio>
#include <iostream>

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int bi, bf, si, sf, gi, gf, pi, pf;
    std::cin >> bi >> bf >> si >> sf >> gi >> gf >> pi >> pf;

    int newCow = bf + sf + gf + pf - (bi + si + gi + pi);
    int B2S = newCow + bi - bf;
    int S2G = B2S + si - sf;
    int G2P = pf - pi;

    if (B2S > 0) {
        std::cout << B2S << "\n";
        if (S2G > 0) {
            std::cout << S2G << "\n";
            if (G2P > 0) {
                std::cout << G2P << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        } else {
            std::cout << 0 << "\n"
                      << 0 << "\n";
        }
    } else {
        std::cout << 0 << "\n"
                  << 0 << "\n"
                  << 0 << "\n";
    }

    return 0;
}



/***
 * final = original + new - leave
 * pf = pi + pn (includes bronze, silver, gold)
 * gf = gi + gn (includes bronze to gold) -
 *           gl (only G2P)
 * sf = si + sn - sl
 *
 * b2b, B2S, b2g, b2p
 * s2s, S2G, s2p
 * g2g, G2P,
 * p2p
 *
 * bi = b2b + B2S + b2g + b2p
 * si =       s2s + S2G + s2p
 * gi =             g2g + G2P
 * pi = p2p
 *
 * pf = p2p + G2P + s2p + b2p
 * gf = g2g + S2G + b2g
 * sf = s2s + B2S
 * bf = b2b + new2b
 * new = sumF - sumI
 *
 * Promotion need not be distinct
 * Output: B2S, B2G + S2G, B2P + S2P + G2P
 * Need: s2s, g2g
 * 
 * Wait... This is a simple problem
 * promo2s = new + bi - bf
 * promo2g = promo2s + si - sf
 * promo2p = promo2g + gi - gf = pf - pi
 * Stops if get neg diff
 * B2S = promo2s
 * S2G = promo2g
 * G2P = promo2p
 */


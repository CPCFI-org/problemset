//c++ TwoKnights.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);

void solve() {
    int len; 
    si(len)
    for (int i=1; i<=len; i++){ 
        /*
        The number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.
        */
        long long combinations = ((pow(i,4))-(pow(i,2)))/2; //All posible combinations
        // print(combinations)
        long long attack_combinations = 2*(2*((i-1)*(i-2))); //All posible combinations where they have 3x2 o 2x3
        long long posibilities = combinations - attack_combinations;
        pll(posibilities)
    }
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
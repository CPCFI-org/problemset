//c++ WeirdAlgorithm.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define sl(x)           scanf("%lld", &x);

void solve() {
    long long n; sl(n) //1 ≤ n ≤10^6
    while (n > 1){ // The algorithm repeats this, until n is one.
        printf("%lld ",n);
        if (n%2 == 0){ //If n is even, the algorithm divides it by two
            n = n/2;
        } else {
            n = n*3 + 1; // If n is odd, the algorithm multiplies it by three and adds one
        }
    }
    printf("%lld",n);
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
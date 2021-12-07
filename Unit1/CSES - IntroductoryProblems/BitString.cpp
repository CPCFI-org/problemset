//c++ BitString.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);

#define mod (long long)(1e9 + 7)

void solve() {
    int bit; si(bit);
    long long res = 1; 
    for (int i=0; i<bit; i++){ //Your task is to calculate the number of bit strings of length n.
        // pll(res)
        res = (res*2)%mod; 
        // pll(res)
    }
    pll(res)
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
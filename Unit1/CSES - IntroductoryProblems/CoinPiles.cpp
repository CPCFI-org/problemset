//c++ CoinPiles.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);

void solve() {
    int cases; 
    si(cases)
    for (int i=0; i<cases; i++){
        long long a; long long b; 
        sl(a) sl(b)
        /* 
        On each move, you can either remove one coin from the left pile and two coins from the right pile, 
        or two coins from the left pile and one coin from the right pile.
        */
        if ( ((a+b)%3 != 0) || (a>(2*b)) || (b>(2*a)) ){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
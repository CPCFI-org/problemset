//c++ TrailingZeros.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define print(x)        printf("%d\n", x);
#define prints(x)       printf("%s\n", x);
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define all(x)          x.begin(), x.end()

void solve() {
    int num;
    si(num)
    int zeros=0; 
    while(num>0){
        /*
        Your task is to calculate the number of trailing zeros in the factorial n!.
        */
        num /= 5; 
        zeros += num; 
    }
    print(zeros)
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
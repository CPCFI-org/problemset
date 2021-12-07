//c++ DigitQueries.cpp -o test.o; ./test.o < test.in
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

long long pow10(int x){
    long long value = 1;
    for(int i = 0; i < x; i++)
        value *= 10;
    return value;
}

void solve() {
    int cases; 
    si(cases)
    for (int i=0; i<cases; i++){
        long long q; sl(q)
        if (q<9){ //0 1 2 3 4 5 6 7 8 9 
            pll(q)
        } else {
            int maxValue = 1; 
            while(9 * pow10(maxValue-1) * maxValue < q){ 
                
            }
        }
    }
    // vector<long long> power_of_ten(19,1); 
    // for(int i=1; i<power_of_ten.size();i++){
    //     power_of_ten[i] = power_of_ten[i-1] * 10;
    // }

    // for (int i=0; i<cases; i++){
    //     long long q; sl(q)

    //     // if (q<9){
    //     //     pll(q);
    //     //     return;
    //     // }

    //     printf("Intentando con %lld \n", q);
    //     long long digitSoFar = 0; 
    //     long long digitBefore = 0; 
    //     int numberOfDigits = 0; 
    //     for(int i=1; i<power_of_ten.size();i++){
    //         digitSoFar += (power_of_ten[i]-power_of_ten[i-1])*i;
    //         pll(digitSoFar)
    //         if (digitSoFar >= q){
    //             numberOfDigits = i;
    //             break;
    //         }
    //         digitBefore += (power_of_ten[i]-power_of_ten[i-1])*i; 
    //         pll(digitBefore)
    //     }

    //     long long smallValue = power_of_ten[i-1];
    //     long long largeValue = power_of_ten[i]-1; 
    //     long long bestValue = 0; 

    //     while(smallValue<=largeValue){

    //     }
    // }

    // for(int i=0; i<power_of_ten.size();i++){
    //     pll(power_of_ten[i])
    // }
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
//c++ AppleDivision.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);

const long long INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int apples; 
    si(apples)
    
    vector <int> weights; 

    for (int i=0; i<apples; i++){
        int weight; 
        si(weight)
        weights.push_back(weight);
    }

    long long best_combination = INF;

    for (int i=0; i<(1<<apples); i++){
        //All posible combinations
        long long sumA = 0;
        long long sumB = 0; 
        for (int j=0; j<apples; j++){
            //Getting the values from the combinations
            if(i&(1<<j)) {
                sumA += weights[j]; //With 0
            } else {
                sumB += weights[j]; //With 1
            }
        }

        /*
        Divide the apples into two groups so that the difference between the weights of the groups is minimal 
        */
        // if (abs(sumA-sumB) < best_combination){
        //     best_combination = abs(sumA-sumB);
        // }
        best_combination = min(best_combination,  abs(sumA-sumB));
    }

    pll(best_combination)
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
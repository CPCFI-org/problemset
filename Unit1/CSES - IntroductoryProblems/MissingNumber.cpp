//c++ MissingNumber.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define print(x)        printf("%d\n", x);
#define sl(x)           scanf("%lld", &x);

void solve() {
    long long n;  //2≤n≤2⋅105
    sl(n)
    bool values[n+1]; 

    memset(values, false, sizeof(values));


    for (int i=1; i<n; i++){ //The second line contains n−1 numbers. Each number is distinct and between 1 and n
        long long newValue; 
        sl(newValue)
        values[newValue] = true;
    }

    for (int i=1; i<n+1; i++){
        if (!values[i]){
            print(i)
            return;
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
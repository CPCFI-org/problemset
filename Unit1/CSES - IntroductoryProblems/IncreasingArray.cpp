//c++ IncreasingArray.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);

void solve() {
    int n; 
    si(n)

    long long moves = 0; 

    long long currentNumber;
    sl(currentNumber)

    for (int i=0; i<n-1; i++){
        long long newNumber; 
        sl(newNumber)

        /*  You want to modify the array so that it is increasing, i.e., 
        every element is at least as large as the previous element. */

        if (currentNumber>newNumber){ 
            long long difference = currentNumber-newNumber;
            moves += difference;
            newNumber = newNumber+difference;
        }

        // while (currentNumber>newNumber){
        //     newNumber+=1;
        //     moves+=1;
        // }

        currentNumber = newNumber;
    }
    pll(moves)
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
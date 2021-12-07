//c++ Permutations.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define print(x)        printf("%d ", x);


void solve() {
    int len; 
    si(len)

    if(len == 1) { //Just one options
        print(len)
    } else if(len <= 3) { //No posilbe permutations
        printf("NO SOLUTION\n");
    } else {    
        /*
        A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.
        */
        for(int i = 2; i <= len; i += 2){
            printf("%d ", i);
        }
        for(int i = 1; i <= len; i += 2) {
            printf("%d ", i);
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
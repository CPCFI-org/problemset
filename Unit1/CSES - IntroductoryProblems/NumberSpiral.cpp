//c++ NumberSpiral.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);

bool even(int value){
    return value % 2 == 0;
}
bool odd(int value){
    return value % 2 != 0;
}

void solve() {
    int cases; 
    si(cases)

    /* A number spiral is an infinite grid whose upper-left square has number 1. */
    for (int i=0; i<cases; i++){
        long long x,y; 
        sl(x) sl(y)

        long long value = 0;
        if (even(x)){ 
            if (y<=x){
                value = (x*x)+1-y;
            } else if ((y>x) && odd(y)){
                value = (y*y)-(x-1);
            }  else if ((y>x) && even(y)){
                value = ((y-1)*(y-1))+x;
            }
        } else if (odd(x)){
            if (y>=x && odd(y)){
                value = (y*y)-(x-1);
            } else if (y>=x && even(y)){
                value = ((y-1)*(y-1))+x;
            } else if (y<x) {
                value = (x*x) - (((x-y)-1)+x);
            }
        }
        pll(value)
    }
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
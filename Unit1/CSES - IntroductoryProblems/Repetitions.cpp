//gcc Repetitions.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define print(x)        printf("%d\n", x);

const int INF = 1000000;

void solve() {
    char sequence[INF];
    scanf("%s",sequence);
    int size = (int) strlen(sequence);

    int maxSequence = 1; 
    int currentSequence = 1;

    for (int i=1; i<size; i++){
        /* Your task is to find the longest repetition in the sequence. 
        This is a maximum-length substring containing only one type of character. */
        if (sequence[i-1]==sequence[i]){ 
            currentSequence+=1; 
        } else {
            currentSequence = 1;
        }
        maxSequence = fmax(maxSequence,currentSequence);
    }

    print(maxSequence);
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
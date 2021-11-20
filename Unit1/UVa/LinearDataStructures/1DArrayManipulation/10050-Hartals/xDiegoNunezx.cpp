#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases, days, parties, party, suma;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &days);
        scanf("%d", &parties);
        int hartals[parties];
        suma = 0;
        for(int i=0; i<parties; i++){
            scanf("%d", &party);
            hartals[i] = party;
        }
        for(int i = 1; i<=days; i++){
            if (i % 7 != 6 && i % 7 != 0){ 
                for (int j = 0; j < parties; j++){
                    if(i % hartals[j] == 0){
                        suma++;   
                        break;
                    }
                }
            }
        }
        printf("%d\n", suma);
    }
    return 0;
}
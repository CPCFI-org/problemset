#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int cases, sum, res, x, y;
    bool b;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &sum, &res);
        if((res-sum)%2==0){
            y = (res - sum)/-2;
            x = sum - y;
            if (x<0 || y<0) printf("impossible\n");
            else printf("%d %d\n", x, y);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}


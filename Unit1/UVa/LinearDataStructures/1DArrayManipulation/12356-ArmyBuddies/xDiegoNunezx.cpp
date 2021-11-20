#include <stdio.h>
using namespace std;

int main() {
    int s, b, l, r;
    while(true){
        scanf("%d %d", &s, &b);
        if (s==0 && b==0) break;
        int lbuddie[s+1];
        int rbuddie[s+1];
        
        for (int i = 1; i <= s; i++) {
			lbuddie[i] = i - 1;
			rbuddie[i] = i + 1;
		}
		rbuddie[s] = -1;
		lbuddie[1] = -1;
        
        while(b--){
            scanf("%d %d", &l, &r);
            
            lbuddie[rbuddie[r]] = lbuddie[l];
            lbuddie[l] == -1 ? printf("* ") : printf("%d ", lbuddie[l]);

            rbuddie[lbuddie[l]] = rbuddie[r];
            rbuddie[r] == -1 ? printf("*\n") : printf("%d\n", rbuddie[r]);
        }
        printf("-\n");
    }
    return 0;
}
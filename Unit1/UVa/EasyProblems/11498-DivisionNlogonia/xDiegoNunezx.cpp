#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int queries, n, m, x, y;
    while(true) {
        scanf("%d", &queries);
        if (queries==0) break;
        scanf("%d %d", &n, &m);
        for(int i=0; i < queries; i++){
            scanf("%d %d", &x, &y);
            if(x==n || y==m) printf("divisa\n");
            else if(x>n && y>m) printf("NE\n");
            else if(x<n && y>m) printf("NO\n");
            else if(x>n && y<m) printf("SE\n");
            else printf("SO\n");
        }
    }
    return 0;
}
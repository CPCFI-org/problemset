#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int w,h;
    scanf("%d %d",&w, &h);
    int res[w+1][h+1];
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(j==i)
                res[i][j]=0;
            else
                res[i][j]=INT_MAX-1;
        }
    }
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            for(int x=1;x<i;x++){
                res[i][j]=min(res[i][j],res[x][j]+res[i-x][j]+1);
            }
            for(int x=1;x<j;x++){
                res[i][j]=min(res[i][j],res[i][x]+res[i][j-x]+1);
            }
        }
    }
    printf("%d",res[w][h]);
    
    return 0;
}

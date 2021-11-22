#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long int mod =1e9+7;
    int n,x,temp;
    char c;
    scanf("%d\n",&n);
    int map[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&c);
            if(c=='.')
                map[i][j]=0;
            else
                map[i][j]=1;
        }
        scanf("\n");
    }
    vector<long long int> ans((n*n)+1,0);
    if(map[0][0]!=1)
    	ans[1]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j-1]!=1){
               if (map[i-1][j-1]!=1 && i > 0)
                    ans[(i*n)+j] =(ans[(i*n)+j] + ans[((i-1)*n)+j])%mod;
                if(map[i][j-2] !=1 && j > 1)
                    ans[(i*n)+j] =(ans[(i*n)+j] + ans[(i*n)+j-1])%mod;
            }
                
        }
        
    }
    printf("%lld",ans[n*n]);
}

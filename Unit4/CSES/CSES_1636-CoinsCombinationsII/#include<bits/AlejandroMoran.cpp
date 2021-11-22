#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    long int mod = 1e9 + 7;
    scanf("%d %d",&n,&x);
    int coins[n];
    vector<long long int> ans(x+1,0);
    ans[0]=1;
    for(int i=0;i<n;i++)
        scanf("%d",&coins[i]);
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
                if(j-coins[i]>=0)
                    ans[j]=(ans[j]+ans[j-coins[i]])%mod;
        }
    }
    printf("%lld",ans[x]);
}

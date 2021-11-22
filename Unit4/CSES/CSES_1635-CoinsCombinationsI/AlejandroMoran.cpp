#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    const int mod = 1e9+7;
    scanf("%d %d",&n,&x);
    int coins[n];
    vector<long long> ans(x+1,0);
    ans[0]=1;
    for(int i=0;i<n;i++)
        scanf("%d",&coins[i]);
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
                if(i-coins[j]>=0)
                    ans[i]=(ans[i]+ans[i-coins[j]])%mod;
        }
    }
    printf("%lld",ans[x]);
}

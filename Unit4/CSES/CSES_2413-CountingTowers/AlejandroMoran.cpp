#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,tc,temp=1;
    long long ans[1000001][2]={0};
    long int mod=1e9+7;
    ans[1][0]=1;
    ans[1][1]=1;
    scanf("%d\n",&tc);
    for(int i=0;i<tc;i++){
        scanf("%d\n",&n);
        if(n>temp){
            for(int i=temp;i<n;i++){
                ans[i][0]%=mod;
                ans[i][1]%=mod;
                ans[i+1][0]+=2*ans[i][0];
                ans[i+1][1]+=ans[i][0];
                ans[i+1][0]+=ans[i][1];
                ans[i+1][1]+=4*ans[i][1];
            }
            temp=n;
            printf("%lld\n",(ans[n][0]+ans[n][1])%mod);
        }
        else
            printf("%lld\n",(ans[n][0]+ans[n][1])%mod);
    }
    return 0;
}

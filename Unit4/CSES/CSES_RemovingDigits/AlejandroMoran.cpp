#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x,temp;
    scanf("%d",&n);
    
    vector<long long int> ans(n+1,INT_MAX-1);
    ans[0]=0;
    for(int i=1;i<=n;i++){
        temp=i;
        while(temp>0){
            ans[i]=min(ans[i],ans[i-temp%10]+1);
            temp=temp/10;
        }
    }
    printf("%lld",ans[n]);
}

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int coins[n];
    vector<int> ans(x+2,1000001);
    ans[0]=0;
    for(int i=0;i<n;i++)
        scanf("%d",&coins[i]);
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0)
                ans[i]=min(ans[i],ans[i-coins[j]]+1);
        }
    }
    if(ans[x]==1000001)
        ans[x]=-1;
    printf("%d",ans[x]);
}

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m=0;
    scanf("%d",&n);
    int coin[n];
    for(int i=0;i<n;i++){
        scanf("%d",&coin[i]);
        m=m+coin[i];
    }
    int res[m+1]={0};
    res[0]=1;
    for(int i=0;i<n;i++){
        for(int j=m;j>=coin[i];j--){
            if(res[j-coin[i]]==0&&res[j]==0)
                res[j]=0;
            else
                res[j]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(res[i]!=0)
            ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=m;i++){
        if(res[i]!=0)
            printf("%d ",i);
    }
    return 0;
}
    

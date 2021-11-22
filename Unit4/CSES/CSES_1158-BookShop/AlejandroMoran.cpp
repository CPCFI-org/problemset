#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int price[n];
    int pages[n];
    for(int i=0;i<n;i++)
        scanf("%d",&price[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]); 
    vector< vector<int> > ans(n+1, vector<int>(x+1,0)); 
    for(int i=0;i<n;i++){
        for(int p=0;p<=x;p++){
            ans[i+1][p]=ans[i][p];
            if(p>=price[i])
                ans[i+1][p]=max(ans[i+1][p],pages[i]+ans[i][p-price[i]]);
        }
    }
    printf("%d",ans[n][x]);
}

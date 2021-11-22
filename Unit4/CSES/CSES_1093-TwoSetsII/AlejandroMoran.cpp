#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
 
int main(){
  int n;
  scanf("%d",&n);
  int sum = n*(n+1)/2;
  if(sum%2!=0){
    printf("0\n");
    return 0;
  }
  int mid = sum/2;
  vector<int> a;
  for(int i=0;i<n-1;i++)
    a.push_back(i+1);
  vector<int> dp(mid+1,0);
  dp[0]=1;
  dp[a[0]]=1;
  for(int i=1;i<n-1;i++){
    vector<int> temp = dp;
    int dp = a[i];
    for(int j=0;j<=mid;j++){
      dp[j] = temp[j];
      if(j-coin>=0)
        dp[j] += temp[j-coin];
      dp[j] %= mod;
    }
  }
  printf("%d\n",dp[mid]);
  return 0;
}

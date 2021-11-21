#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

int main(){
    if (getenv("CP_IO")) { setIO(); }
    int n,x,mod = 1e9+7;
    scanf("%d %d",&n,&x);
    int coins[n];
    vector<int> dp(x+1,0);
    for (int i = 0; i < n; i++) 
        scanf("%d", &coins[i]);
    
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 1; j<=x; j++){
            if(coins[i]>j) continue;
            dp[j] = (dp[j]+dp[j-coins[i]])%mod;
        }
    }
    printf("%d\n", dp[x]);
    
    return 0;
}
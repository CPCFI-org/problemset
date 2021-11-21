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
#define max 1e9
int main(){
    if (getenv("CP_IO")) { setIO(); }
    int n,x;
    scanf("%d %d",&n,&x);
    int coins[n];
    vector<int> dp(x+1,max);
    for (int i = 0; i < n; i++) 
        scanf("%d", &coins[i]);

    dp[0] = 0; 
    for (int i=1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if(i-coins[j]>=0){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }

    if(dp[x]!=max){
        printf("%d\n",dp[x]);
    } else {
        printf("-1\n");
    }
    return 0;
}
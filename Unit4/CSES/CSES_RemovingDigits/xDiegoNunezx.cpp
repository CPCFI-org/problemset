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

#define MAX 1e9
int main(){
    if (getenv("CP_IO")) { setIO(); }
    int n;
    scanf("%d", &n);
    
    vector<int> dp(n+1,MAX);
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        int temp = i;
        while(temp>0){
            dp[i] = min(dp[i],dp[i-temp%10]+1);
            temp /= 10;
        }
    }
    printf("%d\n", dp[n]);
    
    return 0;
}
#include <iostream>
#include <vector>
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
    int mod = 1e9+7;
    int n, sum;
    scanf("%d",&n);

    sum = n*(n+1)/2;

    if(sum % 2){
        printf("0");
        return 0;
    }

    sum /= 2;
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    dp[0][0] = 1;
    for(int i=1; i <n; i++){
        for(int j=0; j <= sum; j++){
            dp[i][j] = ((j<i) ? dp[i-1][j] : dp[i-1][j-i] + dp[i-1][j]) % mod;
        }
    }

    for(int i=0; i <n; i++){
        for(int j=0; j <= sum; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    printf("%d", dp[n-1][sum]);
    return 0;
}
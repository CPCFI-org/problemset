#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x)
#define pll(x)          printf("%lld\n", x)
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define all(x)          x.begin(), x.end()

typedef vector<int> vi;
typedef vector<long long> vll;





// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------
void setIO(){
    string file = __FILE__;
    file = string(file.begin(),file.end()-3);
    string input_file = file+"in";
    string output_file =file+"out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

void solve() {
    int a,b;
    si(a);
    si(b);
   
    
    vector<vector<int>> dp(b+1,vector<int>(a+1,1e9));
    

    for(int i=0; i<=b;i++){
        for(int j=0;j<=a;j++){
            if(i==0 || j==0 || i==j) dp[i][j]=0;
            else{
                int p1,p2;     
                for(int k = 1; k<i;k++){
                    p1=k;
                    p2=i-p1;
                    dp[i][j] = min(dp[i][j],dp[p1][j]+dp[p2][j]+1);
                }
                for(int k = 1; k<j;k++){
                    p1=k;
                    p2=j-p1;
                    dp[i][j] = min(dp[i][j],dp[i][p1]+dp[i][p2]+1);
                }       
            }
        }
    }
    
     cout<<dp[b][a]<<endl;
    // for(int i=0; i<=b;i++){
    //     for(int j=0;j<=a;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
//11917
#include <bits/stdc++.h>
using namespace std;

#define fastIO          cin.tie(0); cout.tie(0);
#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x);
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define all(x)          x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

void solve(int tc) {
    tc++;
    map<string, int> mapper;
    int N, D;
    string subject;
    si(N);
    FO(i,N){
        cin >> subject >> D;
        mapper[subject] = D;
    }
    cin >> D >> subject;
    if(mapper[subject] == 0 || mapper[subject] > D+5){ 
        printf("Case %d: Do your own homework!\n", tc);
    } else if(mapper[subject] <= D){
        printf("Case %d: Yesss\n", tc);
    } else if (mapper[subject]<= D+5){
        printf("Case %d: Late\n", tc);
    }
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    int T; si(T);
    int i = 0;
    FO(tc, T){
        solve(i++);
    }
    return 0;
}
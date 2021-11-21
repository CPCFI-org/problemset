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

// push, top, empty, pop

int vagones, vagon;
stack<int> tren;

void solve() {    
    while(true) {
        while(!tren.empty()) tren.pop();
        int j = 0;
        FO(i, vagones){
            si(vagon);
            if(vagon == 0) return;

            while(j < vagones && j != vagon){
                if(!tren.empty() && tren.top() == vagon) break;
                j++;
                tren.push(j);
            }
            if(tren.top() == vagon) tren.pop();
        }
        tren.empty() ? printf("Yes\n") : printf("No\n");
    }
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    int T=1;
    while(T){
        si(vagones);
        if(vagones == 0) break;
        solve();
        printf("\n");
    }
    return 0;
}
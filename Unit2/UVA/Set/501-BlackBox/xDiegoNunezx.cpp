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

void solve() {
    multiset<int> bb;
    multiset<int>::iterator currentElement;
    int n,m;
    int p = 0;
    int add[30001], get[30001];
    
    scanf("%d %d",&m,&n);

    FO(i,m){ scanf("%d", &add[i]); }
    FO(i,n){ scanf("%d", &get[i]); }
    
    bb.insert(add[0]);
    currentElement = bb.begin();
    
    FOR(i,1,m){
        while(get[p] == i && p < n){
            printf("%d\n", *currentElement);
            p++;        
            currentElement++;
        }
        bb.insert(add[i]);
        if (currentElement == bb.end() || add[i] < *currentElement){
                --currentElement;
        }
    }
    
    while (p < n && get[p] == m){
                ++p;
                printf("%d\n", *currentElement);
                ++currentElement;
    }
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    int T; scanf("%d\n", &T);
    FO(tc, T){
        solve();
        printf("\n");
    }
    return 0;
}
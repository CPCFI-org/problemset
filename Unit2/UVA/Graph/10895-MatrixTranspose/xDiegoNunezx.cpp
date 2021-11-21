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

vector<vii> matriz, matrizT;

void solve() {
    int m, n;
    int pos[1001], num[1001];

    while(scanf("%d %d", &m, &n) != EOF) {
        matriz.assign(m, vii());
		matrizT.assign(n, vii());
        FO(j, m){
            int nfilas;     si(nfilas);
            FO(i, nfilas)   si(pos[i]);
            FO(i, nfilas)   si(num[i]);
            FO(i, nfilas)   matriz[j].push_back(ii(pos[i]-1, num[i]));
        }

        FO(i, m)
            FO(j, matriz[i].size())
                matrizT[matriz[i][j].first].push_back(ii(i , matriz[i][j].second));

        printf("%d %d\n", n, m);
        FO(i, n){
            printf("%d", (int) matrizT[i].size());
            FO(j, matrizT[i].size())
                printf(" %d", matrizT[i][j].first+1);
            printf("\n");
            FO(j, matrizT[i].size()){
                printf("%d", matrizT[i][j].second);
                if (j < (int) matrizT[i].size() - 1)
					printf(" ");
            }
            printf("\n");
        }
    }
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
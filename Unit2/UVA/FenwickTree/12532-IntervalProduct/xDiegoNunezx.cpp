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

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
    vi ft;
public:
    FenwickTree() {}
    // initialization: n + 1 zeroes, ignore index 0
    FenwickTree(int n) { ft.assign(n + 1, 0); }
    int rsq(int b) {                                     // returns RSQ(1, b)
        int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

    int rsq(int a, int b) {                              // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v) {                    // note: n = ft.size() - 1
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

void solve() {
    int x[100005];
    int n, k, d1, d2;
	char q;

	while (scanf("%d %d", &n, &k) != EOF) {
		FenwickTree ftNeg(n), ftZero(n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
			if (x[i] < 0)
				ftNeg.adjust(i, 1);
			if (x[i] == 0)
				ftZero.adjust(i, 1);
		}

		for (int i = 0; i < k; i++) {
			scanf("%c", &q);
			while (q != 'P' && q != 'C')
				scanf("%c", &q);
			scanf("%d %d", &d1, &d2);

			if (q == 'P') {
				if (ftZero.rsq(d1, d2)) {
					printf("0");
				} else if (ftNeg.rsq(d1, d2) % 2 == 0) {
					printf("+");
				} else {
					printf("-");
				}
			} else if (q == 'C') {
				if (x[d1] >= 0 && d2 < 0)
					ftNeg.adjust(d1, 1);
				else if (x[d1] < 0 && d2 >= 0)
					ftNeg.adjust(d1, -1);

				if (x[d1] != 0 && d2 == 0)
					ftZero.adjust(d1, 1);
				else if (x[d1] == 0 && d2 != 0)
					ftZero.adjust(d1, -1);

				x[d1] = d2;
			}
		}

		printf("\n");
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
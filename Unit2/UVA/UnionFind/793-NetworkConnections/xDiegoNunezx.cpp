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

class UnionFind {                                              // OOP style
    private:
    vi p, rank, setSize;                       // remember: vi is vector<int>
    int numSets;
    public:
    UnionFind(int N) {
        setSize.assign(N, 1); 
        numSets = N; 
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) 
        p[i] = i; 
    }
    
    int findSet(int i) { 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) { 
        return findSet(i) == findSet(j); 
    }

    void unionSet(int i, int j) { 
        int x = findSet(i), y = findSet(j);
        if (!isSameSet(i, j)) { 
            numSets--; 
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) { 
                p[y] = x; 
                setSize[x] += setSize[y];
            } else { 
                    p[x] = y; setSize[y] += setSize[x];
                    if (rank[x] == rank[y]) rank[y]++; 
            }
        } 
    }

    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void solve() {
    int ncomputers, i, j;
    char query[2], s[100];
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &ncomputers);
        UnionFind network(ncomputers);
        getchar();
        int sa=0, ua=0;
        while(gets(s)){
            if(s[0] == '\0') break;
            sscanf(s, "%s %d %d", query, &i, &j);
            if(query[0] == 'q'){
                if(network.isSameSet(i,j)) sa++;
                else ua++;
            } else {
                network.unionSet(i,j);
            }
        }
        printf("%d,%d\n", sa, ua);
        if(T)	puts("");
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
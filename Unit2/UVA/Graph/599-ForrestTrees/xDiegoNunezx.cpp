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
    int aristas=0, Novertices=0, trees, acorns=0, n;
    string arista, vertices;
    bitset<26> bosque;

    while(true){
        getline(cin, arista);
        if(arista[0] == '*') break;
        //printf("%s\n", nodo.c_str());
        n = arista[1] - 65; 
        //printf("%c %d\n", nodo[1], n);
        bosque.set(n);
        n = arista[3] - 65;
        bosque.set(n);
        aristas++;
    }

    getline(cin, vertices);
    for (int i = 0; i < vertices.size(); i+=2){
        Novertices++;
        n = vertices[i] - 65;
        if(!bosque.test(n)) acorns++;
    }
    
    trees = Novertices-aristas-acorns;

    printf("There are %d tree(s) and %d acorn(s).\n", 
                    trees, acorns);
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    int T; scanf("%d\n", &T);
    FO(tc, T){
        solve();
    }
    return 0;
}
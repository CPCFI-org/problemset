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
    // N: Stations | S: Capacity of carriers | Q: Capacity of N
    int n, s, q, cargoes, cargo, minutes=0, station = 0;
    queue<int> stations[100];
    stack<int> carrier;
    scanf("%d %d %d", &n, &s, &q);
    FO(i, n){
        scanf("%d", &cargoes);
        FO(j, cargoes){
            scanf("%d", &cargo);
            stations[i].push(cargo-1);
        }
    }

    while(true){
        while(!carrier.empty()&&(carrier.top()== station||stations[station].size()<q)){
            if(carrier.top() != station){
                stations[station].push(carrier.top());
            }
            carrier.pop();
            minutes++;
        }

        while(carrier.size()<s && !stations[station].empty()){ 
            carrier.push(stations[station].front());
            stations[station].pop();
            minutes++;
        }

        bool clear = carrier.empty();
		FO(i,n) clear &= stations[i].empty();
		if (clear) break;
        
        station = (station + 1) % n;
        minutes += 2;
    }

    pint(minutes);
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    int T;
    scanf("%d",&T);
    FO(tc, T){
        solve();
    }
    return 0;
}
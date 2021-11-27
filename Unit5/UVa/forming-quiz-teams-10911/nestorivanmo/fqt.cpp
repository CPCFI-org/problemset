#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl                        '\n'
#define fastIO()                    cin.tie(0); cout.tie(0);
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& (v) : (arr))
#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;
#define si(x)	                    scanf("%d",&x)
#define sl(x)	                    scanf("%lld",&x)
#define pi(x)	                    printf("%d\n",x)
#define pl(x)	                    printf("%lld\n",x)
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end() 
#define sz(x)                       (int) x.size()
#define LB(arr, x)                  lower_bound(all(arr), x)-(arr).begin()
#define UB(arr, x)                  upper_bound(all(arr), x)-(arr).begin()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1, T2>& pair){
    cout << "{"; _debug(pair.F); cout << ","; _debug(pair.S); cout << "}";  
}

template <typename T>
void _debug(vector<T>& vec){
    int n = sz(vec);
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    FO(i, n-1){
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n-1]); cout << "]";
}

void _debug(vector<string>& vec){
    int n = sz(vec);
    cout << endl;
    FO(i, n){
        cout << vec[i] << endl;
    }
}

template <typename T>
void _debug(vector<vector<T>>& A){
    int n = sz(A);
    cout << endl;
    FO(i, n){
        _debug(A[i]); cout << endl;
    }
}

template <typename T>
void print(T& x){
    cout << x << endl;
    return;
}

template <typename T>
void print(vector<T>& vec, int a=0, int b=-1){
    if(b == -1){b = sz(vec);}
    if(b == 0){return;}
    FOR(i, a, b-1){
        cout << vec[i] << " ";
    }
    cout << vec[b-1] << endl;
    return; 
}

// -----------------------------------------------------------------------------
// Solution starts here
// -----------------------------------------------------------------------------

int N, target;
string name;
vector<vector<double>> dist(20, vector<double>(20));
vector<double> memo(1 << 16, -1.0);

double matching(int bitmask) { //finds a perfect matching between N groups of coordinates
    if (bitmask == target) return memo[bitmask] = 0;
    if (memo[bitmask] > -0.5) return memo[bitmask];

    double ans = INF;
    int p1, p2;
    for (p1 = 0; p1 < 2*N; p1++)
        if (!(bitmask & (1 << p1)))
            break;

    /*
        bitmask = 1001
        p1 = 2
        p2 = 1
        cost = dist[2][1] + matching(1111)
        cost = di + 0
    */

    for (p2 = p1+1; p2 < 2*N; p2++) {
        if (!(bitmask & (1 << p2))) {
            ans = min(
                ans,
                dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2))
            );
        }
    }

    return memo[bitmask] = ans;
}


void solve(int numCase) {
    vector<int> x(20), y(20);
    FO(i, 2*N)
        cin >> name >> x[i] >> y[i];

    FO(i, 2*N-1)
        FOR(j, i+1, 2*N)
            dist[i][j] = dist[j][i] = hypot(x[i]-x[j], y[i]-y[j]);

    FO(i, (1 << 16)) memo[i] = -1.0;

    target = (1 << 2*N)-1; // 10000 --> 01111
    printf("Case %d: %.2lf\n", numCase, matching(0));
    return;
}

int main() {
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int numCase = 1;
    while(si(N), N) {
        solve(numCase++);
    }
    return 0;
}
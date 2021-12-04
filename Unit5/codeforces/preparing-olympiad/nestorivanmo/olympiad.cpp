#include <bits/stdc++.h>
using namespace std;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

void Clean() {
    printf("\n==================\n\n");
}

// ---------------------------------------------
// Start coding here
// ---------------------------------------------
#define INF 1e9

int main() {
    if (getenv("LOCAL")) { setIO(); }
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<long long> difficulties(n);
    for(int i = 0; i<n; i++) cin >> difficulties[i];
    int ans = 0;
    for (int s = 0; s < (1<<n); s++) {
        long long min_difficulty = INF;
        long long max_difficulty = -INF;
        long long total_difficulty = 0;
        for (int bit = 0; bit < n; bit++) {
            if (s & (1<<bit)) {
                min_difficulty = min(min_difficulty, difficulties[bit]);
                max_difficulty = max(max_difficulty, difficulties[bit]);
                total_difficulty += difficulties[bit];
            }
        }
        long long diff = max_difficulty - min_difficulty;
        if (diff >= x && total_difficulty >= l && total_difficulty <= r) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
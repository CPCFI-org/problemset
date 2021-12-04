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


int main() {
    if (getenv("LOCAL")) { setIO(); }
    int n; cin >> n;
    vector<int> degrees(n);
    for(int i = 0; i < n; i++) cin >> degrees[i];
    long long sum_of_all_subsets; //snake case
    for (int s = 0; s < (1<<n); s++) {
        sum_of_all_subsets = 0;
        for (int bit = 0; bit < n; bit++) {
            if (s & (1 << bit)) {
                sum_of_all_subsets += degrees[bit];
            } else {
                sum_of_all_subsets -= degrees[bit];
            }
        }
        if (sum_of_all_subsets % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
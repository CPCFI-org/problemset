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
    int n, x; 
    cin >> n >> x;
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];
    
    vector<pair<int,int>> best(1<<n);
    // base case: elevator ride empty
    best[0] = {1,0}; // 1 ride, weight 0

    // iterative cases
    for (int s = 1; s < (1<<n); s++) { // O(2^n * n)
        best[s] = {n+1, 0}; // n+1 elevator rides with weight 0
        for (int bit = 0; bit < n; bit++) {
            if (s & (1<<bit)) {
                // we need to find an elevator that does not contain
                // person i (bit)
                // s = 101 we need to find 100 given that bit = 0
                auto previous_elevator = best[s^(1<<bit)];
                // DP
                int previous_elevator_weight = previous_elevator.second;
                int current_person_weight = weights[bit];
                if (previous_elevator_weight + current_person_weight <= x) {
                    previous_elevator.second += current_person_weight;
                } else {
                    previous_elevator.first++;
                    previous_elevator.second = current_person_weight;
                }
                best[s] = min(best[s], previous_elevator);
            }
        }
    }
    for (auto b : best) {
        printf("{%d, %d} ", b.first, b.second);
    }
    cout << best[(1<<n)-1].first;
    return 0;
}
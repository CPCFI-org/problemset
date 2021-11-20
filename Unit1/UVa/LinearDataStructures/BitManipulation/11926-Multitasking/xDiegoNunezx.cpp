#include <bits/stdc++.h>
using namespace std;

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

typedef vector<int> vi;
typedef vector<long long> vll;

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

bitset<1000001> schedule;

bool hasConflict(int n, int m, vector<int> &s, vector<int> &e, vector<int> &r){
    // One-time tasks.
    for (int i = 0; i < n; ++i)
    {
        int start = s[i], end = e[i];
        // "Touching" is OK, so check from start + 1.
        for (int t = start + 1; t <= end; ++t)
        {
            if (schedule.test(t))
                return true;
            else
                schedule.set(t);
        }
    }
    // Repeating tasks.
    for (int i = n; i < n + m; ++i)
    {
        int start = s[i], end = e[i], interval = r[i];     
        while (start < 1000000)
        {
            for (int t = start + 1; t <= end; ++t)
            {
                if (schedule.test(t))
                    return true;
                else
                    schedule.set(t);
            }          
            start += interval;
            end = min(end + interval, 1000000);
        }
    }
    return false;
}


void solve() {
    int n, m;
    while (cin >> n >> m, !(n == 0 && m == 0))
    {
        vector<int> s(n + m), e(n + m), r(n + m);
        for (int i = 0; i < n; ++i)
            cin >> s[i] >> e[i];
        for (int i = n; i < n + m; ++i)
            cin >> s[i] >> e[i] >> r[i];

        schedule.reset();     
        if (hasConflict(n, m, s, e, r))
            cout << "CONFLICT" << endl;
        else
            cout << "NO CONFLICT" << endl;
    }
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
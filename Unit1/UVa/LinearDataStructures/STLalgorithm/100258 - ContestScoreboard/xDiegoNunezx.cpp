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
/*
Keep an array of team (contestant) objects. 
Each team has an integer array where p[i] is the number of penalty minutes accrued for problem i, 
and a boolean array where b[i] is true if problem i has been solved. 
Each team also needs a boolean that is true if they've made a submission, 
and two ints representing their current number of problems solved and penalty minutes.
For each line in the input, set the given team's active boolean regardless of what the letter is. 
Then, if the letter is I, add 20 to that teams p[i]. 
If the letter is C and b[i] is false, make b[i] true, add time+p[i] to their total penalty minutes, 
and increment their number of problems solved.
At the end, sort the teams by problems descending, then penalty minutes ascending, then team number ascending. 
Print out all active teams in the order they now appear in the array.
 */

struct contestant{
    int id;
    int p[9];
    bool b[9];
    bool submission;
    int nproblems;
    int penalty;
};

bool d(contestant a, contestant b) {
    if (a.nproblems != b.nproblems)
        return a.nproblems > b.nproblems;   
    else if (a.penalty != b.penalty)       
        return a.penalty < b.penalty;       
    else                        
        return a.id < b.id;
}

void solve() {
    contestant *contestants = new contestant[100];
    FO(i, 100){
        contestants[i].id = i+1;
        contestants[i].nproblems = 0;
        contestants[i].submission = false;
        contestants[i].penalty = 0;
        FO(j, 9){
            contestants[i].p[j] = 0;
            contestants[i].b[j] = false;
        }
    }
    int con, problem, time;
    char l, ar[50];
    while(gets(ar) && ar[0]!='\0'){
        sscanf(ar,"%d %d %d %c", &con, &problem, &time, &l);
        con--;
        problem--;
        contestants[con].submission = true;
        if(l == 'I') contestants[con].p[problem] += 20;
        if(l == 'C' && contestants[con].b[problem] == false){
            contestants[con].b[problem] = true;
            contestants[con].penalty += time + contestants[con].p[problem];
            contestants[con].nproblems++;
        }
    }
    sort(contestants, contestants+100, d);
    FO(i, 100){
        if(contestants[i].submission == 1){
            printf("%d ", contestants[i].id);
            printf("%d ", contestants[i].nproblems);
            printf("%d\n", contestants[i].penalty);
        }
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d\n",&T);
    FO(tc, T){
        solve();
    }
    return 0;
}
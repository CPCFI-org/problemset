//978
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
    int B, SG, SB, lemmming, j;
    multiset<int, greater<int> >::iterator warriorb, warriorg, a;
    multiset<int, greater<int> > blue, green, blueb, greenb;
    
    scanf("%d %d %d", &B, &SG, &SB);
    
    FO(i, SG){ 
        si(lemmming);
        green.insert(lemmming);
    }
    
    FO(i, SB){ 
        si(lemmming);
        blue.insert(lemmming);
    }
    
    int n=3;
    while(green.size() != 0 && blue.size() != 0){  
        if(green.size()<B || blue.size()<B){
            j = (int) green.size() < (int) blue.size() ? (int) green.size() : (int) blue.size();
        } else{
            j = B;
        }

        warriorg = green.begin();
        warriorb = blue.begin();

        FO(i,j){
            greenb.insert(*warriorg);
            blueb.insert(*warriorb);
            warriorg++;
            warriorb++;
        }

        warriorg = greenb.begin();
        warriorb = blueb.begin();
        
        while(j--){
            if(*warriorg>*warriorb){
                green.insert(*warriorg-*warriorb);
                a = green.find(*warriorg);
                green.erase(a);
                a = blue.find(*warriorb);
                blue.erase(a);
            } else if(*warriorg<*warriorb){
                blue.insert(*warriorb-*warriorg);
                a = green.find(*warriorg);
                green.erase(a);
                a = blue.find(*warriorb);
                blue.erase(a);
            } else {
                a = green.find(*warriorg);
                green.erase(a);
                a = blue.find(*warriorb);
                blue.erase(a);
            }
            warriorg++;
            warriorb++;
        }
        blueb.clear();
        greenb.clear();
    }
    
    if(green.size()==0 && blue.size()==0){
        printf("green and blue died\n");
    } else if(green.size()==0){
        printf("blue wins\n");
        for(auto& i : blue){
            printf("%d\n", i);
        }
    } else {
        printf("green wins\n");
        for(auto& i : green){
            printf("%d\n", i);
        }
    }
    printf("\n");
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    int T; si(T);
    FO(tc, T){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x)
#define pll(x)          printf("%lld\n", x)
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define all(x)          x.begin(), x.end()

typedef vector<int> vi;
typedef vector<long long> vll;

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------
void setIO(){
    string file = __FILE__;
    file = string(file.begin(),file.end()-3);
    string input_file = file+"in";
    string output_file =file+"out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

void solve() {
    int n;
    si(n);
     
    long long inicio,fin,paga;
    map<long long,vector<pair<long long,long long>>> fines; //Almacena los fines y sus correspondientes inicios con sus recompensas
    map<long long,long long> dp;//almacena el máximo ganado hasta determinado día
    
    for(int i=0;i<n;i++){
        scanf("%lld",&inicio);
        scanf("%lld",&fin);
        scanf("%lld",&paga);
        fin++;
        fines[fin].push_back(make_pair(inicio,paga));
        dp[inicio]=0;
        dp[fin]=0;
    }
    
    pair<long,long> anterior;
    anterior.first=0;
    anterior.second=0;

    for(auto& dia:dp){
        dia.second = anterior.second;
        if(fines.count(dia.first)){
            for(auto& inicio:fines[dia.first]){ //Para todos los inicios de proyectos que terminan ese día
                    dia.second=max(dia.second,dp[inicio.first]+inicio.second);
            }
        }
        anterior=dia;
    }
    cout<<anterior.second<<endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
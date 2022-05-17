//https://cses.fi/problemset/task/1682/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define PD(t) printf("%d",t)
#define PLD(t) printf("%ld",t)
#define PLLD(t) printf("%lld",t)
#define PC(t) printf("%c",c)
#define PS(t) printf("%s",t)
#define PF(t) printf("%f",t)
#define PLF(t) printf("%lf",t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FO(i, b) for(int  i = 0; i<b; i++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define read(type) readInt<type>()
#define TR(v,arr) for (auto& (v): (arr))
#define endl '\n'
#define fastIO cin.tie(0); cout.tie(0);
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef queue<int> QI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
int numberOfNodes;
unordered_map<int, vector<int> > adj,rev;

void DFS1(int i,vector<bool>& visited,stack<int>& mystack)
{
    if(visited[i]) return;
    visited[i]=true;
    for(int j: adj[i]) DFS1(j,visited,mystack);
    mystack.push(i);
}

void DFS2(int i,vector<bool>& visited){
    if(visited[i]) return;
    visited[i] = true;
    for(int j: rev[i]) DFS2(j,visited);
}

void reverse()
{
    for(int i=0;i<numberOfNodes;++i)
    {
        for(int j: adj[i])
            rev[j].PB(i);
    }
}
void findSCCs(){
    stack<int> mystack;

    vector<bool> visited(numberOfNodes,false);
    for(int i=0;i<numberOfNodes;++i)
        if(!visited[i])
            DFS1(i,visited,mystack);

    reverse();
    for(int i=0;i<numberOfNodes;++i)
        visited[i] = false;

    //print adjacency lists
    // FO(i,numberOfNodes){
    //     cout<<i+1<<"->";
    //     for(int j: adj[i])
    //         cout<<j+1<<" ";
    //     cout<<endl;
    // }
    // cout<<"REV"<<endl;
    // FO(i,numberOfNodes){
    //     cout<<i+1<<"->";
    //     for(int j: rev[i])
    //         cout<<j+1<<" ";
    //     cout<<endl;
    // }
    // cout<<"Strongly Connected Components are:\n";
    int nFamilies = 0;
    int x = mystack.top();
    debug(x);
    DFS2(x,visited);
    FOR(i,0,numberOfNodes,1){
        if (i==x) 
            continue;
        if (!visited[i]) {
            putl("NO");
            put(i+1,x+1);
            return;
        }
    }
    put("YES");
}

void solve(){
    cin>>numberOfNodes;
    int nEdges;
    cin>>nEdges;

    FO(i,nEdges){
        int u,v;
        cin>>u>>v;
        adj[u-1].PB(v-1);
    }

    findSCCs();
    
}


void setIO(){
    string file = __FILE__;
    file = string(file.begin(),file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r",stdin);
    freopen(output_file.c_str(),"w",stdout);
}

/********** Main()  function **********/
int32_t main(){
    
    if(getenv("CP_IO")){setIO();}
    fastIO;
    int T=1;
    FO(tc,T)
        solve();
    return 0;
}
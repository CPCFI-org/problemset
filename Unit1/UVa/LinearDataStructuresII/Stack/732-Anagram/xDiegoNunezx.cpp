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

/*
This problem requires you to print the stack operations to build an anagram of a word. 
The basic approach should be a dfs searching through all possibilities of push 
and pop with slight modification for efficiency. A plain dfs will get TLE, so we need some 
optimization. First off, if two words do not match in length there can be no valid arrangement. 
Second, we can limit the search by stopping when the output so far does not match the output 
word requested. While the problem highly suggested the use of a stack, I chose to use a string 
so passing arguments in dfs was slightly easier. It follows the same principles regardless.
*/

string in, out;

void dfs(string a, string b, string stack, string path, int n) {
    if(n == in.length() * 2) {
        if(b == out)
            cout << path << endl;
        return;
    }
    // push
    if(a.length() > 0)
        dfs(a.substr(1, a.length() - 1), b, \
            stack + a[0], path + (n == 0? "i" : " i"), n + 1);
    // pop
    if(stack.length() > 0 && stack[stack.length() - 1] == out[b.length()])
        dfs(a, b + stack[stack.length() - 1], \
            stack.substr(0, stack.length() - 1), \
            path + " o", n + 1);
}

int main() {
    if (getenv("CP_IO")) { setIO(); }
    while(cin >> in >> out) {
        printf("[\n");
        if(in.length() == out.length())
            dfs(in, "", "", "", 0);
        printf("]\n");
    }
    return 0;
}
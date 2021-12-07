//c++ CreatingStrings.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define print(x)        printf("%d\n", x);

void solve() {
    char word[9];
    scanf("%s", word);
    int word_size = (int) strlen(word);
    // cout << word << endl;
    sort(word, word+word_size);
    // cout << word << endl;
    set<string> permutations;
    permutations.insert(string(word, word+word_size));

    while (next_permutation(word, word+word_size)) { 
        /*
        Your task is to generate all different strings that can be created using its characters.
        */
        permutations.insert(string(word, word+word_size));
    }

    print(permutations.size())

    for(string perm : permutations){
        cout << perm << '\n';
    }
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
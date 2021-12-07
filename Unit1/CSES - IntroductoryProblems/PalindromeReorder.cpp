//c++ PalindromeReorder.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)

const int alphabetLetters = 26;

void solve() {

    string word; 
    cin >> word;

    vector<int> rept (26);
    
    for(char c : word) {
        rept[c - 'A']++; 
    }

    int odd = -1;
    //Just one odd word
    for (int i=0; i<alphabetLetters; i++){
        if (rept[i]%2 != 0 && rept[i] != 0){
            if (odd == -1){
                odd = i;
            } else {
                printf("NO SOLUTION");
                return;
            }
        }
    }

    string finalWord; 
    for (int i=0; i<alphabetLetters; i++){
        for (int j=0; j < rept[i]/2; j++) {
            finalWord.push_back(i + 'A');
        }
    }   

    if (odd != -1){
        finalWord.push_back(odd + 'A');
    }

    for (int i=(alphabetLetters-1); i>=0; i--){
        for (int j=0; j < rept[i]/2; j++) {
            finalWord.push_back(i + 'A');
        }
    }
    cout << finalWord << endl;

}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
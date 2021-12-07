//c++ GrayCode.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)        for (int i = 0; i < (b); i++)
#define si(x)           scanf("%d", &x);

void solve() {
    int bit; 
    si(bit)

    vector<string> bits;
    //Bit pattern
    bits.push_back("0");
    bits.push_back("1");

    int fullItems = 1<<bit; //1*(2**bit))
    for (int i = 2; i < (1<<bit); i = i<<1) {

        //Enter the mising numbers
        for (int j = i-1 ; j >= 0 ; j--){
            // print(j)
            bits.push_back(bits[j]);
        }
        //Append 0 to the first half
        for (int j = 0 ; j < i ; j++){
            bits[j] = "0" + bits[j];
        }
        
        //Append 1 to the second half
        for (int j = i ; j < 2*i ; j++){
            bits[j] = "1" + bits[j];
        }
    }
 
    for (int i = 0 ; i < bits.size() ; i++ ){
        cout << bits[i] << endl;
    }

}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}
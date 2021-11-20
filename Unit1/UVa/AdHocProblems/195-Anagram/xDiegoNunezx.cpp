#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(char A, char B){
	char sa = tolower(A);
	char sb = tolower(B);
	if( sa == sb )
		return A < B;
	return sa < sb;
}

int main(){
    string palabra;
    int n, letras;
    scanf("%d",&n);
    while(n--){
        cin >> palabra;
        letras = palabra.size();
        sort(palabra.begin(), palabra.end(), comp);
        do
        {
            printf("%s\n", palabra.c_str());
        } while (next_permutation(palabra.begin(), palabra.end(), comp));
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
//Algunos macros para ayudar
#define endl        '\n'

    //Definiciones de ciclos for: crementar, incrementar
#define FO(i, b)    for(int i = (a); i < (b); i++)
#define FOR(i, a, b)    for(int i = (a); i < (b); i++)
#define rFOR(i, a, b)    for(int i = (a); i > (b); i--) //a es nuestro valor de inicio

#define pint(x)            printf("%d\n",x);
#define pll(x)            printf("%lld\n",x); //imprimir un long long
#define si(x)            scanf("%d",&x);        //Escaneo de un entero
#define sl(x)            scanf("%lld",&x);
#define TR(v, arr)      for(auto& (v) : (arr)) //Es como un for each


//TYPEDEF YA NO ES MACROS
typedef vector<int> vi;
typedef vector<long long> vll;

void setIO(){
    string file = __FILE__;

    file = string(file.begin(), file.end()-3);
    string out_file = file + "out";
    string in_file = file + "in";

    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

void solution(string cadena){
    
    FOR(i,0,10){
        int r = 0;
        char c = i + '0';
        r = count(cadena.begin(), cadena.end(), c);
        if (i == 9)
            cout<<r<<endl;
        else
            cout<<r<<" ";
    }
    
    
}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n,x;
    string str;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        cin>>x;
        str.clear();
        for(int j = 1; j <= x;j++){
            str.append(to_string(j));
        } 
        // cout<<str<<endl;
        solution(str);
    }
    return 0;
}

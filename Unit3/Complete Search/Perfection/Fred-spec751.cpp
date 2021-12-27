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



void solution(int n){
    int res = 0;
    int espacios = 5;
    string ss;
    if (n == 0){
        cout<<"END OF OUTPUT\n";
        return;
    }

    FOR(i,1,(n/2)+1){
        if(n%i == 0){
            res += i;
        }
    }
    ss = to_string(n);
    espacios -= ss.length(); 
    if (res > n)
        cout<<string(espacios, ' ')<<n<<"  ABUNDANT"<<'\n';
    else if (res == n)
        cout<<string(espacios, ' ')<<n<<"  PERFECT"<<'\n';
    else
        cout<<string(espacios, ' ')<<n<<"  DEFICIENT"<<'\n';

}

int main(){
    if(getenv("CP_IO"))
        setIO();
    int n,maxN = 0;
    vi vector;
    string ss;   
    cout<<"PERFECTION OUTPUT"<<endl;
    while (true){
        cin>>n;
        vector.push_back(n);
        maxN = max(maxN,n);
        if (n == 0)
            break;
    }
    ss = to_string(maxN); 
    TR(v,vector){
        solution(v);
    }  
    
    return 0;
}

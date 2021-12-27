#include<bits/stdc++.h>
using namespace std;
 
		//Algunos macros para ayudar
#define endl		'\n'
 
	//Definiciones de ciclos for: crementar, incrementar
#define FO(i, b)	for(int i = (a); i < (b); i++)
#define FOR(i, a, b)	for(int i = (a); i < (b); i++)
#define rFOR(i, a, b)	for(int i = (a); i > (b); i--) //a es nuestro valor de inicio
 
#define pint(x)			printf("%d\n",x);
#define pll(x)			printf("%lld\n",x); //imprimir un long long
#define si(x)			scanf("%d",&x);	    //Escaneo de un entero
#define sl(x)			scanf("%lld",&x);
#define TR(v, arr)      for(auto& (v) : (arr)) //Es como un for each
 
 
				//TYPEDEF YA NO ES MACROS
typedef vector<int> vi;
typedef vector<long long> vll;
vector<long long> v;
int indice = 0;
int solution(int n, int i)
	{
		if (n!=v[i])
			{
				indice++;
				return 1;
			}
			
		
		if (n==v[i])
			indice++;
		
		return solution(n,i+1);
	}
 
 
int main()
	{
		int aux;
		
		int t; si(t)
		long long r=0;
		
		for(int i =0 ;i<t;i++)
			{
				si(aux)
				v.push_back(aux);
			}
		sort(v.begin(),v.end());
		
		while(indice<t)
			{
				//cout<<indice<<" Result: "<<v[indice]<<endl;
				r += solution(v[indice],indice+1);
				
			}
		
		cout<<r;
		
		return 0;
	}

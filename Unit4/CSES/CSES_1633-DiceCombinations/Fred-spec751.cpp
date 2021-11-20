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

const int maxn = 1e6+7; 

int dp[maxn]; // Me dice la cantidad de maneras de construir un número 

int main()
	{
		int modulo = 1e9+7;
		int n;
		si(n)
		dp[0] = 1;
		for(int j = 1;j<=n;j++) // Me recorrer de 1 hasta el número deseado a construir 
			{
				for(int i = 1;i<=6;i++)
					{
						if(j-i>=0)
							{
								dp[j] += dp[j-i];
								dp[j]%=modulo;
							}
							
						else
							break;	// No tiene sentido seguir iterando si los siguientes números son mayores al 
							// número que deseo construir
					}		
			}
		cout<<dp[n];
		return 0;
	}
	


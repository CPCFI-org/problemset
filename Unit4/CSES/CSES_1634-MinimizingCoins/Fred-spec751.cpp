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
int dp[maxn];
vector<int> coins;

int main()
	{
		int m,n,aux,k=0;
		scanf("%d %d",&m,&n);
		
		for(int i = 0;i<m;i++)
			{
				si(aux)
				coins.push_back(aux);
			}
		sort(coins.begin(),coins.end());
		//Caso base
		
		//dp[0] = 0;
		for(int i = 1;i<=n;i++)
			{
				dp[i]=1e9; // Se hace esto para que siempre en la primera comparación del min
				// se tome a dp[i-coins[j]]+1
				// y ya después en una segunda iteración se compara al resultado obtenido anteriorimen
				// con el resultado que se obtuve actualmente
				
				for(int j = 0;j<m;j++)
					{
						if(i-coins[j]>=0)
							dp[i] = min(dp[i],dp[i-coins[j]]+1);
						
					}
				//cout<<dp[i-1];
			}
		if(dp[n]==1e9) // En caso de nunca entrar al for entonces unicamente se tiene el valor 1e9
			cout<<"-1";
		else
			cout<<dp[n];
		return 0;
	}
	


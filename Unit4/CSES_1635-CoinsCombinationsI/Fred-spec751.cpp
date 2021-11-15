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


const int maxn = 1e6;
int dp[maxn]; 
int main()
	{
	    int coins[101]={};
		int len,sum,aux;
		int modulo=1e9+7;
		scanf("%d %d",&len,&sum);
		for(int i  =0;i<len;i++)
			{
				scanf("%d",&coins[i]);
			}
		//sort(coins,coins+len);
		dp[0] = 1;
		for(int i = 1;i<=sum;i++)
			{
				for(int j =0;j<len;j++)
					{
						if(i-coins[j]>=0)
						{
							dp[i] += dp[i-coins[j]]; 
							dp[i]%=modulo;
						}
						
					}
			}
		printf("%d",dp[sum]);
		return 0;
	}
	


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


int main()
	{
		int n,m,i,j=0;
		int price[1007];
		int pages[1007];
		
		scanf("%d %d",&n,&m);
		int dp[n+1][m+1] = {}; // Importante inicializarlo de esta manera, en 0 para que el compilador del Juez no genere un wrong ans.
		for(i = 0;i<n;i++)
			cin>>price[i];
		for(i = 0;i<n;i++)
			cin>>pages[i];
		//memset(dp,0,sizeof dp); // Segunda manera de inicializar la tabla con 0.
	
		for(i=1;i<=n;i++)
			{
				for(j=0;j<=m;j++)
					{
						dp[i][j] = dp[i-1][j];
								if(j-price[i-1]>=0)
									{
										dp[i][j] = max(dp[i-1][j-price[i-1]]+pages[i-1],dp[i][j]); 
									}
									
					}
			}
		/*Para realizar la impresión de la tabla.
		for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
					{
						cout<<dp[i][j]<<" ";
					}
				cout<<"\n";
			}*/
		cout<<dp[n][m];
		return 0;
	}
	


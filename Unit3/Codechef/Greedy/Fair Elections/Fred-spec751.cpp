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

int t,n,m,rn=0,rm=0,aux;
	//vectores:
vector<int> vn;
vector<int> vm;

void solution()
	{
		int diference = 0;
		for(int i=0;i<=n;i++)
			{
				if(rn>rm)
					{
						printf("%d\n",i);
						return;
					}
					
		
				
				
				//oper:
				rn -= vn[i];
				rm -= vm[i];
				
				rn += vm[i]; // Se añade el valor más grande
				rm += vn[i]; // se le añade el valor menor
			}
		printf("-1\n");// No solution;
		return;
	}

int main()
	{
	
		scanf("%d",&t);
		while(t--)
			{
				scanf("%d %d",&n,&m);
				//reset:
				rn=0;
				rm=0;
				vn.clear();
				vm.clear();
				//store:
				
				
				for(int i =0;i<n;i++)
					{
						scanf("%d",&aux);
						vn.push_back(aux);
						rn += aux;
					}
						
				for(int i =0;i<m;i++)
					{
						scanf("%d",&aux);
						vm.push_back(aux);
						rm += aux;
					}
				
				sort(vm.begin(), vm.end(), std::greater<int>());
				sort(vn.begin(), vn.end());
				//cout<<vn[0]<<"    "<<vm[0]<<endl;
				
				solution();
				
			}
		return 0;
	}
	

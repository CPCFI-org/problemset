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
		int t,aux,r,i=0;
		int arr[12]={2048,1024,512,256,128,64,32,16,8,4,2,1};
		scanf("%d",&t);
		while(t--)
			{
			    i=0;
			    r=0;
				scanf("%d",&aux);
				while(aux!=0)
				    {
				        if(aux>=arr[i])
				            {
				                aux-=arr[i];
				                r+=1;
				            }
				        else
				            {
				                i++;
				            }
				        
				    }
				cout<<r<<endl;
			}
		return 0;
	}
	

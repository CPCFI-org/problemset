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
		int arr[6] ={100,50,10,5,2,1};
		int t,number,i=0,contador;
		si(t)
		while(t--)
			{
				i=0;
				contador = 0;
				cin>>number;
				while(number!=0)
					{
					
						if(number<arr[i])
							i++;
						else
							{
								number -= arr[i];
								contador++;
							}
						
					}
				cout<<contador<<endl;
			}
		return 0;
	}
	

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
 
const int maxn=2e5+10;
 
int main()
	{
		long long in1=0,in2=0;
		// n : numero de ni�os
		//p: peso total permitido
		long long n,p,x,i=0,len;
		//vector<long long> v;
		long long arr[maxn] {};
		scanf("%lld %lld",&n,&p);
		
		for(int i = 0;i<n;i++)
			{
				cin>>arr[i];
				//v.push_back(x);
			}
		
		sort(arr, arr+n, greater<int>());
		
		//cout<<arr[n-1];
		//6 combinaciones
		len = n;
		in2=len-1;
		while(len>1)
			{
				
				//cout<<v[0]<<"  "<<v[len-1]<<"\n";
				
				//if(v[0]+v[len-1]<=p)
				if(arr[in1] + arr[in2] <=p)
					{
						
						
						//v.pop_back();
						in1++;
						//v.erase(v.begin());
						in2--;
						
						len -=2;
						//cout<<arr[in1]<<"  "<<arr[in2]<<"\n";
						i++;
						
					}
				else
					{
						//v.erase(v.begin());
						in1++;
						
						len -=1;
						i++;
						
					}
				//cout<<len<<"\n";
				//cout<<i<<"\n";
			}
		if(len==1)
			i++;
		cout<<i;
		
		return 0;
	}

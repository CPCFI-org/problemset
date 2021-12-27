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
struct sort_pred { bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) { return left.second < right.second; } };
 
 
int main()
	{
		int t,x,y,ans=1,menor1,max;
		pair<int,int> pareja;
		vector<pair<int,int>> v;
		si(t)
		for(int i = 0;i<t;i++)
			{
				scanf("%d %d",&x,&y);
				pareja = make_pair (x,y);
				v.push_back(pareja);
			}
		//sort(v.begin(),v.end());
		sort(v.begin(), v.end(), sort_pred());
 
	
		//for (const auto &item : v) {
        //cout<< item.first << item.second << "\n\n";
    	
		//}
		
		menor1 = v[0].second;
		
		
		for(int i = 1;i<=t;i++)
			{
				if(menor1 <= v[i].first)
					{
						//cout<<menor<<"   "<<v[i].first<<"\n";
						
						menor1 = v[i].second;
						ans++;
					}
				//cout<<it.first<<" \n";
				
			}
		cout<<ans;
			
		return 0;
	}

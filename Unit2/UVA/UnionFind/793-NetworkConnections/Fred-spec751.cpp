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

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main()
	{
		int n,tamano,n1,n2,afirmativo=0,q=0;
		
		scanf("%d",&n);
		while(n--)
			{
				afirmativo = 0;
				q=0;
				
				scanf("%d",&tamano);
				UnionFind UF(tamano+1);
				
				char query;
				string datos;
				getline(cin,datos);
				while(1)
					{
						
						getline(cin,datos);
						if(datos.size()==0)
							{
								break;
							}
						istringstream convertidor(datos);
						convertidor>> query >> n1 >> n2;
						//cout<<query<<n1<<n2<<"\n";
						if(query=='q')
							{
								if(UF.isSameSet(n1,n2))
										{
											
											afirmativo++;
										}
								else
									{
										q++;
									}
							}
						else
							{
								UF.unionSet(n1,n2);
							}
					}
				
				printf("%d,%d\n",afirmativo,q);
				//Ahora evaluar si existe una linea de en blanco, solo si existe un siguiente número, o sea que n!=0
				if(n!=0)
					printf("\n");
			}
		
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


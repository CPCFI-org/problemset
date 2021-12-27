#include <bits/stdc++.h>
using namespace std;



// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------


int i,len;
//char palabra[199];
char letras;
std::vector<char> palabra2;
char palabra[500];



bool es_palindromo() 
	{
		i=0;
		
		int j = palabra2.size()-1;
		//j=-1;
		while(i<=j)
			{
				if(palabra2[i]!=palabra2[j])
					{
						return false;
					}
				i++; j--;
			}
		return true;
	}



int main() {
    
	int j=0;
    while(true)
        {
        	//fflush(stdin);
			gets(palabra);
			
			
			
			if(strcmp("DONE",palabra)==0)
				break;
		//	printf("Hasta aquí bien");	
		//	palabra[0]=tolower(palabra[0]);
			len = strlen(palabra);
			
			//hacer_mini();
			
			
			for(i=0;i<len;i++)
				{
					if(palabra[i]!='!' && palabra[i]!='?' && palabra[i]!='.' && palabra[i]!=',')
						{
							if(palabra[i]!=' ')
								{
									letras = tolower(palabra[i]);
									palabra2.push_back(letras);
								}
							
						}
					//palabra[i] = '\0';
				}
			
			/* IMPRESIÓN DE PARA VERIFICAR
			for(i=0;i<palabra2.size();i++)
			cout<<palabra2[i];
			printf("\n");
			*/
			
            if(es_palindromo()==true)
                {
                    printf("You won't be eaten!\n");
                }
            else
            	{
            		printf("Uh oh..\n");
				}
				
			palabra2.clear();
        }
        
    return 0;
}

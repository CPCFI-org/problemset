#include<stdio.h>
int main()
	{
		double h,u,d,f;
		int dia = 0;
		int exito;
		double inicio;
		
		bool salir = true;
		
		
		while(scanf("%lf %lf %lf %lf",&h,&u,&d,&f),(h||u||d||f))
			{
				dia=0;
				f = (f/100) * u;
				
				inicio = 0;
				
				while(salir==true)
					{
						dia++;
						
						inicio+=u;
						
						u-=f;
						
						if(u<0)
							u=0;
						
						if(inicio>h )
							{
								exito = 1;
								break;
								
							}
						
						inicio -= d;  
							
						if(inicio<0)
							{
								exito = 0;
								break;
							}
					}
				
				if(exito == 1)
					{
						printf("success on day %d\n",dia);
					}
				else
					{
						printf("failure on day %d\n",dia);
					}
			
			}	
			
				
	}

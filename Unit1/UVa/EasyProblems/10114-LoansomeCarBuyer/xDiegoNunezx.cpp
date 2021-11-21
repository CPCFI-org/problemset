#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
    int duracion, registros;
    double pagoInicial, carro, meses[101];

    while (true){
        scanf("%d %lf %lf %d ", &duracion, &pagoInicial, &carro, &registros);
        if (duracion < 0)
            break;

        int mes;
        double porcentaje;
        while (registros--){
            scanf("%d %lf", &mes, &porcentaje);
            for (int i = mes; i < 101; i++)
                meses[i] = porcentaje;
        }

        int noMeses = 0;
        double pagoMensual = carro / duracion;
        double deuda = carro;
        carro = (carro + pagoInicial) * (1 - meses[0]);
        while (carro < deuda){
            noMeses++;
            deuda -= pagoMensual;
            carro = carro * (1 - meses[noMeses]);
        }
        if(noMeses != 1) printf("%d months\n", noMeses);
        else printf("1 month\n");
    }
    return 0;
}
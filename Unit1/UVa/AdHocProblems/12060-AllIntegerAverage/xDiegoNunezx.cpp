#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int cases, suma, numero, a, b, c, i=1, espacios, guiones, mcd;
    string avg;
    while(true){
        scanf("%d", &cases);
        if(cases == 0) break;
        printf("Case %d:\n", i);
        avg = "";
        suma = 0;
        for (int i = 0; i < cases; i++){
            scanf("%d", &numero);
            suma += numero;
        }

        if(suma==0){
            printf("0\n");
            i++;
            continue;
        }

        a = suma / cases;
        b = suma % cases;
        c = cases;

        if(a < 0){
            a *= -1;
            avg+= "- " + to_string(a);
        }
        else if(a != 0) avg += to_string(a);
        
        if(b == 0){
            printf("%s\n", avg.c_str());
            i++;
            continue;
        }
        if(b<0 && a==0) avg+= "- ";
        if(b<0) b*=-1; 

        for(int j=1; j<=c; j++){
            if((b%j==0) && (c%j==0)) mcd = j;
        }

        b /= mcd;
        c /= mcd;

        string g = to_string(c);
        guiones = g.size();
        for (int j = 0; j < guiones; j++){
            avg += "-";
        }

        espacios = avg.size()-to_string(b).size();
        for (int j = 0; j < espacios; j++){
            printf(" ");
        }

        printf("%d\n", b);
        printf("%s\n", avg.c_str());
        espacios = avg.size() - guiones;
        for (int j = 0; j < espacios; j++){
            printf(" ");
        }
        printf("%d\n", c);
        i++;
    }
    return 0;
}
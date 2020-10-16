#include <stdio.h>

 int main(){

     int elementos_maximos = 100;

     int serie[elementos_maximos];

     int i;

     for(i=1;i<=elementos_maximos;i++){

         serie[i] = i * i;

     }

     int sumatoria = 0;

     for(i=1;i<=elementos_maximos;i++){

         sumatoria = sumatoria + serie[i];

     }

     printf("Valores sumados: ");

     for(i=1;i<=elementos_maximos;i++){

         printf("%d, ", serie[i]);

     }

     printf("\nSumatoria %d", sumatoria);

     int total_calculado = (elementos_maximos*(elementos_maximos + 1)*(2*elementos_maximos + 1))/6;

     printf("\nTotal calculado %d", total_calculado);

     return 0;

 }

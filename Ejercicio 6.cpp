#include <stdio.h>

  struct cuadrilatero{

     int base;

     int altura;

   };

int main(){

   struct cuadrilatero cuadrilatero1;

   struct cuadrilatero cuadrilatero2;

   cuadrilatero1.base = 5;

   cuadrilatero1.altura = 3;

   cuadrilatero2.base = 20;

   cuadrilatero2.altura = 12;

   printf("Base del cuadrilatero 1: %d \n", cuadrilatero1.base);

   printf("Altura del cuadrilatero 1: %d \n", cuadrilatero1.altura);

   printf("Base del cuadrilatero 2: %d \n", cuadrilatero2.base);

   printf("Altura del cuadrilatero 2: %d \n", cuadrilatero2.altura);

   char vertical = '|', horizontal = '-', esquina = '+';
     int alto_contador, contador_horizontal;
     printf("\n\n");

     for (alto_contador = 0; alto_contador < cuadrilatero2.altura; alto_contador ++)
     {  for (contador_horizontal = 0; contador_horizontal < cuadrilatero2.base; contador_horizontal ++)
        {  if (alto_contador == 0 || alto_contador == cuadrilatero2.altura - 1){
             if (contador_horizontal == 0 || contador_horizontal == cuadrilatero2.base - 1){
               printf("%c", esquina);
             } else { printf("%c", horizontal); }
        } else {
              if (contador_horizontal == 0 || contador_horizontal == cuadrilatero2.base - 1){
                printf("%c", vertical);
              } else { printf(" "); }
        }
        }
        printf("\n" );
     }

      printf("\n\n");

     for (alto_contador = 0; alto_contador < cuadrilatero1.altura; alto_contador ++)
     {  for (contador_horizontal = 0; contador_horizontal < cuadrilatero1.base; contador_horizontal ++)
        {  if (alto_contador == 0 || alto_contador == cuadrilatero1.altura - 1){
             if (contador_horizontal == 0 || contador_horizontal == cuadrilatero1.base - 1){
               printf("%c", esquina);
             } else { printf("%c", horizontal); }
        } else {
              if (contador_horizontal == 0 || contador_horizontal == cuadrilatero1.base - 1){
                printf("%c", vertical);
              } else { printf(" "); }
        }
        }
        printf("\n" );
     }

  return 0;

 }

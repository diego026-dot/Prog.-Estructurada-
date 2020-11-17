#include <stdio.h>
#include <stdlib.h>

typedef struct{

        int base;
        int altura;

} cuadrilatero;

int funcion_ImprimeCuadrilatero (cuadrilatero *, int *);
void f_lecura(cuadrilatero *, int *);

int main (){

        cuadrilatero array[50];
        int tamanio;
        int cont_1 = 0;

        do{
                fflush(stdin);
                printf("\nIngrese numero de cuadrilateros que desea impirmir:");
                scanf("%d", &tamanio);
        }while(tamanio > 50 ||  tamanio < 1);

        for( cont_1 = 0; cont_1 < tamanio; cont_1 ++){
                f_lecura(array, &cont_1);
        }
        for (cont_1 = 0; cont_1 < tamanio; cont_1 ++){
                funcion_ImprimeCuadrilatero (array, &cont_1);
        }

}

int funcion_ImprimeCuadrilatero (cuadrilatero A[], int * cont_1){
  char vertical = '|', horizontal = '-', esquina = '+';

  int alto_contador, contador_horizontal;
  printf("\n\n");

  for (alto_contador = 0; alto_contador < A[*cont_1].altura; alto_contador ++){
            for (contador_horizontal = 0; contador_horizontal < A[*cont_1].base; contador_horizontal ++){
                    if (alto_contador == 0 || alto_contador == A[*cont_1].altura - 1){
                              if (contador_horizontal == 0 || contador_horizontal == A[*cont_1].base - 1){
                                            printf("%c", esquina);
                                        } else {
                                            printf("%c", horizontal); }
                                            } else {
                                                  if (contador_horizontal == 0 || contador_horizontal == A[*cont_1].base - 1){
                                                          printf("%c", vertical);
                                                    } else {
                                                          printf(" "); }
                                                      }
                                                    }
                                                    printf("\n" );
                                                  }
}

void f_lecura(cuadrilatero A[], int *cont_1){
          printf("Ingrese la altura del cuadrilatero %d: ", *cont_1 + 1);
          scanf("%d", &A[*cont_1].altura);
          printf("Ingrese la base del cuadrilatero %d: ", *cont_1 + 1);
          scanf("%d", &A[*cont_1].base);
}

#include<stdio.h>
#include<stdlib.h>

const int val_max = 50;

void f_lectura(int [][val_max], int, int);
void f_suma(int [][val_max],int [][val_max], int [][val_max], int, int);
void f_Impresion(int [][val_max], int, int);

int main(int num_de_arg, char **dimensiones_para_arreglos){

      int MA[val_max][val_max], MB[val_max][val_max], MR[val_max][val_max];
      int filas, columnas;
      int cont_1;

      do{
              printf("\nIngrese el numero de filas de los arreglos: ");
              scanf("%d", &filas);
      }while(filas > val_max || filas < 1);

      do{
              printf("\nIngrese el numero de columnas de los arreglos: ");
              scanf("%d", &columnas);
      }while(columnas > val_max || columnas < 1);

      printf("\nLectura de la matriz A\n");
      f_lectura(MA, filas, columnas);
      printf("\nLectura de la matriz B\n");
      f_lectura(MB, filas, columnas);
      f_suma(MA, MB, MR, filas, columnas);
      printf("\n\nMatriz A\n\n" );
      f_Impresion(MA, filas, columnas);
      printf("\n\nMatriz B\n\n" );
      f_Impresion(MB, filas, columnas);
      printf("\n\nMatriz R\n\n" );
      f_Impresion(MR, filas, columnas);
          printf("\n\n\tFin del programa.\n\n");
return 0;
}

    void f_lectura(int A[][val_max], int F, int C){
            int I, J;
            for(I = 0; I < F; I++){
                    for(J = 0; J < C; J ++){
                            printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
                            scanf("%d", &A[I][J]);
                    }
            }
    }

    void f_suma(int M1[][val_max], int M2[][val_max], int M3[][val_max], int F, int C){
            int I, J;
            for(I = 0; I < F; I ++){
                    for(J = 0; J < C; J ++){
                            M3[I][J] = M1[I][J] + M2[I][J];
                    }
            }
    }

    void f_Impresion(int A[][val_max], int F, int C){
            int I, J;
            for(I = 0; I < F; I ++){
                    for(J = 0; J < C; J ++){
                            printf("\t%d", A[I][J]);
                    }
                    printf("\n");
            }
    }

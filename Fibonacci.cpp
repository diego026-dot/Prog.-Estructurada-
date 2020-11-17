#include<stdio.h>
#include<stdlib.h>

int fibonacci_funcion(int num){

  if (num == 0 || num == 1){
        return 1;
  }else {
        return fibonacci_funcion(num - 1) + fibonacci_funcion(num - 2);
  }
}

int main (int arg_cont, char **arg_V){ 
                                       
    int valor = 0;
    int i = 0;

    for (i = 1; i < arg_cont; i ++){  
            valor = atoi(arg_V[i]);   
                                      
            printf("\nTermino: %d\tValor del termino: %d", valor, fibonacci_funcion(valor));
    }
    printf("\n");


  return 0;
}

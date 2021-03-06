#include <stdio.h>
#include <stdlib.h>

long cache[100];
int contador = 0;
int contador_cache = 0;

long fibonacci(int numero){
  contador ++;
    if(numero == 0 || numero == 1){
        return 1;
    }else{
        return fibonacci(numero-1) + fibonacci(numero-2);
    }
}

long f_fibo_cache(long numero){
        contador_cache ++;
        long valor_en_cache = cache[numero];
        if (valor_en_cache <= 0){
                cache[numero] = f_fibo_cache(numero - 1) + f_fibo_cache(numero - 2);
                valor_en_cache = cache[numero];
        }
        return valor_en_cache;
}

int main (int no_de_argumentos, char **valores){
        long termino_n = 0;
        cache[0] = 1;
        cache[1] = 1;
        int i;
        for (i = 1; i < no_de_argumentos; i ++){
                termino_n = atoi(valores[i]);
                printf("no. %ld\tfuncion Fibonacci: %ld\n", termino_n, fibonacci(termino_n));
        }
        printf("La funcion Fibonacci fue llamada %d veces\n",contador);

        for (i = 1; i < no_de_argumentos; i ++){
                termino_n = atoi(valores[i]);
                printf("no. %ld\t funcion Fibonacci Cache: %ld\n", termino_n, f_fibo_cache(termino_n));
        }
        printf("La funcion Fibonacci con memoria fue llamada %d veces\n",contador_cache);
        return 0;
}


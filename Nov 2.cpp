#include <stdio.h>

int main(){
   FILE *fp;
   char matricula_str[255], primer_parcial_str[255], segundo_parcial_str[255], pia_str[255], final_str[255];
   fp = fopen("/home/radical-ab/Escritorio/Archivos/evaluaciones.csv", "r+");
   int i =0;



   fscanf(fp, "%s %s %s %s %s\n", matricula_str, primer_parcial_str, segundo_parcial_str, pia_str, final_str);
   for(i =0; i < 3; i++){
       printf("a ");
   fscanf(fp, "%s %s %s %s %s\n", matricula_str, primer_parcial_str, segundo_parcial_str, pia_str, final_str);
       printf("los valores de la linea %d son: %s %s %s %s %s\n", i, matricula_str, primer_parcial_str, segundo_parcial_str, pia_str, final_str);
   }
   fclose(fp);
}

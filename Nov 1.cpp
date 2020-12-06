#include <stdio.h>
#include <string.h>



struct Evaluacion{
    char Matricula[15];
    int PrimerParcial;
    int SegundoParcial;
    int PIA;
    float Final;
};



int main(){
   FILE *fp;
   fp = fopen("/home/radical-ab/Escritorio/Archivos/evaluaciones.csv", "w+");
   struct Evaluacion Evaluaciones[3];
   strcpy(Evaluaciones[0].Matricula, "11");
   Evaluaciones[0].PrimerParcial = 9;
   Evaluaciones[0].SegundoParcial = 9;
   Evaluaciones[0].PIA = 9;
   Evaluaciones[0].Final = 9;



   strcpy(Evaluaciones[1].Matricula, "12");
   Evaluaciones[1].PrimerParcial = 8;
   Evaluaciones[1].SegundoParcial = 8;
   Evaluaciones[1].PIA = 8;
   Evaluaciones[1].Final = 8;



   strcpy(Evaluaciones[2].Matricula, "13");
   Evaluaciones[2].PrimerParcial = 7;
   Evaluaciones[2].SegundoParcial = 7;
   Evaluaciones[2].PIA = 7;
   Evaluaciones[2].Final = 7;
   fprintf(fp, "Matricula, PrimerParcial, SegundoParcial, PIA, Final\n");
   for(int i = 0; i < 3; i++){
       fprintf(fp, "%s, %d, %d, %d, %.2f\n", Evaluaciones[i].Matricula, Evaluaciones[i].PrimerParcial, Evaluaciones[i].SegundoParcial, Evaluaciones[i].PIA, Evaluaciones[i].Final);
   }
   fclose(fp);
   printf("Archivo guardado");
 return 0;}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define Buff 2048

typedef struct alumno {
	char mat[8];
	int cal[7];
	unsigned int n_parcialesR;
	double prom;
} alumn;

typedef struct calP {
	unsigned int nalumns;
	int *califAlumnosParcial;
	double promedio;
} calP;

typedef struct grupo {
	unsigned int nalumns;
	int *calAlumns;
	double prom;
} gpo;

unsigned int get_total_lines_file(char* archivo) {
	FILE* fp = fopen(archivo,"r");
	if(!fp) {
		printf("Error. No se pudo abrir el csv\n",archivo);
		exit(EXIT_FAILURE);
	}
	int nlineas = 0;
	char texto[Buff];
	while(fgets(texto,Buff,fp) != NULL) {
		nlineas++;
	}
	
	fclose(fp);
	
	return nlineas;
}

char** split_str(char* str, const char a_delim) {
	char **_str = NULL;
	size_t count;
	char *str_tmp = str;
	char *last_delim = NULL;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = '\0';

	while(*str_tmp) {
		if(*str_tmp == a_delim) {
			count++;
			last_delim = str_tmp;
		}
		str_tmp++;
	}
	
	count += last_delim < (str + strlen(str) - 1);
	
	count++;
	
	_str = malloc(sizeof(char*)*(size_t)count);
	if(_str) {
		size_t idx = 0;
		char* token = strtok(str,delim);
		while(token) {
			assert(idx < count);
			*(_str + idx++) = strdup(token);
			token = strtok(NULL,delim);
		}
		assert(idx == (count - 1));
		*(_str + idx) = '\0';
	} else {
		printf("Error. No se pudo reservar espacio en memoria.\n");
		exit(EXIT_FAILURE);
	}
	
	return _str;
}

alumn register_student(char** tokens) {
	size_t i = 0,k = 0;
	alumn a;
	
	for(i = 0; *(tokens + i); ++i) {
		if(i > 0) {
			a.cal[k] = (int)strtol(tokens[i],NULL,10);
			k++;
		} else {
			strncpy(a.mat,tokens[i],strlen(tokens[i]));
		}
	}
	
	return a;
}

void ver_datos(char* _filename, alumn* alumnos) {
	FILE* stream = fopen(_filename,"r");
	if(!stream) {
		printf("Error. No se pudo abrir el csv.\n",_filename);
		exit(EXIT_FAILURE);
	}
	size_t idx = 0;
	size_t i = 0;
	char texto[Buff];
	unsigned int n_lines = 0;
	char** tokens = NULL;
	while(fgets(texto,Buff,stream) != NULL) {
		n_lines++;
		texto[strcspn(texto,"\n")] = '\0';
		if(n_lines > 1) {
			tokens = split_str(texto,',');
			if(tokens) {
				alumnos[idx] = register_student(tokens);
		
				for(i = 0; *(tokens + i); ++i) {
					free(*(tokens+i));
				}
				free(tokens);
				tokens = NULL;
			}
			idx++;
		}
	}
	
	fclose(stream);
}

void saveData_at_file(const char* _namefile, alumn* alumnos, calP* calificaciones, gpo g, const size_t tamA, const size_t tamC) {
	FILE* stream = fopen(_namefile,"w");
	if(!stream) {
		printf("Error. No se pudo abrir el archivo %s en modo escritura.\n",_namefile);
		exit(EXIT_FAILURE);
	}
	size_t i = 0, j = 0;
	size_t len = 0;
	fprintf(stream,"MATRICULA,PARCIAL1,PARCIAL2,PARCIAL3,PARCIAL4,PARCIAL5,PARCIAL6,PARCIAL7,Prom Calif Parciales,No. de parciales no aprobados\n");
	for(i = 0; i < tamA; ++i) {
		len = strlen(alumnos[i].mat);
		for(j = len - 4; j < len; ++j) {
			if(j==3){
				fprintf(stream,"´");
			}
			fputc(alumnos[i].mat[j],stream);
		}
		fprintf(stream,",%d,%d,%d,%d,%d,%d,%d,%d,%u\n",alumnos[i].cal[0],alumnos[i].cal[1],alumnos[i].cal[2],alumnos[i].cal[3],alumnos[i].cal[4],alumnos[i].cal[5],alumnos[i].cal[6],(int)alumnos[i].prom,alumnos[i].n_parcialesR);
	}
	fprintf(stream,"PROMEDIO,");
	for(i = 0; i < tamC; ++i) {
		fprintf(stream,"%d,",(int)calificaciones[i].promedio);
	}
	fprintf(stream,"%d\n",(int)g.prom);
	fprintf(stream,"Alumnos no aprobados,");
	for(i = 0; i < tamC; ++i) {
		fprintf(stream,"%u,",calificaciones[i].nalumns);
	}
	fprintf(stream,"%u",g.nalumns);
	fclose(stream);
}

double calcular_promedioFinal(int* calif, const size_t tam) {
	double prom = 0.0;
	size_t i = 0;
	for(i = 0; i < tam; ++i) {
		prom += calif[i];
	}
	prom /= tam;
	return prom;
}

unsigned int Nparciales_Reprobados(int* calif,const size_t tam) {
	size_t i = 0;
	unsigned int reprobados = 0;
	for(i = 0; i < tam; ++i) {
		if(calif[i] < 7)
			reprobados++;
	}

	return reprobados;
}

void ini_CalifParcial(unsigned* n_alumR, double* prom, int** califAlumP, const size_t tam, alumn* alumnos, const unsigned idx_P) {
	*n_alumR = 0;
	*prom = 0.0;
	*califAlumP = (int*) malloc(sizeof(int)*(size_t)tam);
	if(!(*califAlumP)) {
		printf("Error. No se pudo reservar espacio en memoria\n");
		exit(EXIT_FAILURE);
	}
	size_t k = 0;
	for(k; k < tam; ++k) {
		(*califAlumP)[k] = alumnos[k].cal[idx_P];
	}
}

double calcular_promParcial(int* califAlumnosP, const size_t tam) {
	double prom = 0.0;
	size_t i = 0;
	for(i; i < tam; ++i) {
		prom += califAlumnosP[i];
	}
	prom /= tam;

	return prom;
}

unsigned int NalumnosReprobados_P(int* califAlumnosP, const size_t tam) {
	unsigned int reprobados = 0;
	size_t i = 0;
	for(i; i < tam; ++i) {
		if(califAlumnosP[i] < 7)
			reprobados++;
	}

	return reprobados;
}

void ini_califGrupo(gpo* g, alumn* alumnos, const size_t tam) {
	g->calAlumns = (int*) malloc(sizeof(int)*(size_t)tam);
	if(!g->calAlumns) {
		printf("Error. No se pudo reservar espacion en memoria\n");
		exit(EXIT_FAILURE);
	}
	size_t i = 0;
	for(i; i < tam; ++i) {
		g->calAlumns[i] = (int)alumnos[i].prom;
	}
}

double calcular_promGrupo(int* califAlumnos, const size_t tam) {
	size_t i = 0;
	double prom = 0.0;
	for(i; i < tam; ++i) {
		prom += califAlumnos[i];
	}
	prom /= tam;

	return prom;
}

unsigned int NAlumnosReprobados_G(int* califAlumnos, const size_t tam) {
	unsigned int reprobados = 0;
	size_t i = 0;
	for(i; i < tam; ++i) {
		if(califAlumnos[i] < 7)
			reprobados++;
	}

	return reprobados;
}

void print_arrayAlumnos(alumn* alumnos,const size_t tam) {
	size_t i = 0, j = 0;
	for(i = 0; i < tam; ++i) {
		printf("ESTUDIANTE %d\nMATRICULA: %s\nCALIFICACION: ",i+1,alumnos[i].mat);
		for(j = 0; j < 7; ++j) {
			printf("|Parcial %d= %d| ",j+1,alumnos[i].cal[j]);
		}
		printf("\nPARCIALES REPROBADOS: %u\nPROMEDIO FINAL DEL ESTUDIANTE= %.2lf",alumnos[i].n_parcialesR,alumnos[i].prom);
		if(i < tam - 1)
			printf("\n\n");
	}
	printf("\n");
	system("pause");
	system("cls");
}

void print_arrayCalifP(calP* calificaciones, const size_t tam) {
	size_t i = 0;
	for(i = 0; i < tam; ++i) {
		printf("EXAMEN PARCIAL %d\nTotal DE ESTUDIANTES REPROBADOS= %u\nPROMEDIO DEL EXAMEN PARCIAL: %.2lf",i+1,calificaciones[i].nalumns,calificaciones[i].promedio);
		if(i < tam - 1)
			printf("\n\n");
	}
	printf("\n");
}

int main() {
	const size_t TAM = get_total_lines_file("calificaciones_pia_pe.csv") - 1;
	alumn alumn[TAM];
	calP calificacionesP[7];
	gpo g = {0,NULL,0.0};
	size_t i = 0, j = 0;

	ver_datos("calificaciones_pia_pe.csv",alumn);
	
	//Por alumno
	
	for(i = 0; i < TAM; ++i) {
		alumn[i].prom = round(calcular_promedioFinal(alumn[i].cal,7));
		alumn[i].n_parcialesR = Nparciales_Reprobados(alumn[i].cal,7);
	}
	
	//Por calificacion parcial
	
	for(i = 0; i < 7; ++i) {
		ini_CalifParcial(&calificacionesP[i].nalumns,&calificacionesP[i].promedio,&calificacionesP[i].califAlumnosParcial,TAM,alumn,i);
		calificacionesP[i].promedio = round(calcular_promParcial(calificacionesP[i].califAlumnosParcial,TAM));
		calificacionesP[i].nalumns = Nparciales_Reprobados(calificacionesP[i].califAlumnosParcial,TAM);
	}
	
	//Por grupo
	
	ini_califGrupo(&g,alumn,TAM);
	g.prom = round(calcular_promGrupo(g.calAlumns,TAM));
	g.nalumns = NAlumnosReprobados_G(g.calAlumns,TAM);
	
	//Guardar datos
	
	saveData_at_file("NuevoArchivo.csv",alumn,calificacionesP,g,TAM,7);
	
	//Impresion de datos
	
	print_arrayAlumnos(alumn,TAM);
	printf("\n");
	print_arrayCalifP(calificacionesP,7);
	
	printf("\n\n----El promedio grupal es: %.2lf----\n\n----El total de alumnos reprobados es: %u----\n",g.prom,g.nalumns);
	
	//Liberar memoria reservada
	
	for(i = 0; i < 7; ++i) {
		free(calificacionesP[i].califAlumnosParcial);
	}
	free(g.calAlumns);

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cursos.h"

#include "../Utilidades/Utilidades.h"

void introduciromodificarcursos(int tipo){


	short unsigned int LIMITE_NOMBRECURSO = 20;
	short unsigned int LIMITE_MONITOR = 20;

	// recordar el espacio para 0/

	char nombrecurso[LIMITE_NOMBRECURSO+1];
	char monitor[LIMITE_MONITOR+1];
	int anyo = 0;
	int mes = 0;
	int dia = 0;
	int horas = 0;
	int plazadisp = 0;
	int codcurso = 0;
	int CODCURSOviejo = 0;


	Cursos *arrayCursos;
	int dimension = larguraStatment();
	arrayCursos = (Cursos*) malloc (dimension *sizeof(Cursos));
	seleccionCursos(arrayCursos);
	int posOld = 0;

	// La variable existe, ademas de verificar que el dato introducido ya existe, tambien nos dice a cual de lo objetos pertnece (nos da su posicion)
	int existe = 0; //Cuando el valor introducido no exista su valor sera -1
	if (tipo ==1){
		mostrarCursos(arrayCursos);
		do{
			printf("%s\n","	Introduzca el Codigo del curso:" );
			scanf("%d", CODCURSOviejo);
			fflush(stdin);
			verificar =comprobacionCodCurso(CODCURSOviejo);
			existe= codRepetido(CODCURSOviejo, 1);
			if(existe == -1){
				printf("%s\n","El CODIGO del CURSO introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
			}
		}while(verificar != 0 && existe != -1);
	}

	posOld = existe;
	existe = -1;

	// introduccion y modificacion del CODIGO del CURSO
		do{
			if(existe != -1){
				printf("%s\n","El CODIGO del CURSO introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
			}
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*'\n");
			}
			printf("%s\n","	Introduzca el CODIGO del CURSO:" );
			scanf("%d", codcurso);
			fflush(stdin);
			
			if (!(tipo== 1 &&  codcurso[0] == '*')){
				existe= codRepetido(codcurso);
				verificar =comprobacionCodCurso(codcurso);
			}
		}while((verificar != 0 && existe == -1) && !(tipo== 1  && codcurso[0] == 42));

	// introduccion y modificacion de NOMBRE del CURSO
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el NOMBRE del CURSO:" );
			fgets(nombrecurso,LIMITE_NOMBRECURSO+1,stdin);
			fflush(stdin);
			strtok(nombrecurso, "\n");
			if (!(tipo== 1 && strlen(nombrecurso) == 1 && nombrecurso[0] == '*')){
				verificar = ponerMayusculas(nombrecurso);
			}
		}while((verificar!=0) && !(tipo== 1 && strlen(nombrecurso) == 1 && nombrecurso[0] == '*'));

// AÑO
	do{ 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el AÑO:" );
			scanf("%i",&anyo);
			fflush(stdin);
			if (!(tipo== 1 && anyo == 0)){
				
				
			}	
		}while(!(tipo== 1 && anyo == 0)) ;

// MES 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el MES:" );
			scanf("%i",&mes);
			fflush(stdin);
			if (!(tipo== 1 && mes == 0)){
				
				
			}	
		}while(!(tipo== 1 && mes == 0)) ;

// DIA 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el DIA:" );
			scanf("%i",&dia);
			fflush(stdin);
			if (!(tipo== 1 && dia == 0)){
				
				
			}	
		}while(!(tipo== 1 && dia == 0)) ;ç
		verificar = comprobacionFecha(anyo,mes,dia);
	}while(verificar != 0);

// Plazas Disponibles


		do{
			
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*'\n");
			}
			printf("%s\n","	Introduzca el cuantas Plazas hay Disponibles:" );
			scanf("%i", plazadisp);
			fflush(stdin);
			
			if (!(tipo== 1 &&  plazadisp[0] == '*')){
				verificar =comprobacionPlazasDisp(plazadisp);
			}
		}while((verificar != 0 ) && !(tipo== 1  && plazadisp[0] == 42));

// Nombre del MONITOR
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el NOMBRE del MONITOR:" );
			fgets(monitor,LIMITE_MONITOR+1,stdin);
			fflush(stdin);
			strtok(monitor, "\n");
			if (!(tipo== 1 && strlen(monitor) == 1 && monitor[0] == '*')){
				verificar = ponerMayusculas(monitor);
			}
		}while((verificar!=0) && !(tipo== 1 && strlen(monitor) == 1 && monitor[0] == '*'));

		if(tipo == 1){
				if(codcurso[0] == '*'){
					strcpy(codcurso, arrayCursos[posOld].codcurso);
				}if(nombrecurso[0] == '*'){
					strcpy(nombre, arrayCursos[posOld].nombrecurso);
				}if(anyo == 0){
					anyo = arrayCursos[posOld].anyo;
				}if(mes == 0){
					mes = arrayCursos[posOld].mes;
				}if(dia == 0){
					dia=arrayCursos[posOld].dia;
				}if(horas == 0){
					horas = arrayCursos[posOld].horas;
				}if(plazadisp == 0){
					plazadisp = arrayCursos[posOld].plazadisp;
				}if(monitor[0] == '*'){
					strcpy(monitor, arrayCursos[posOld].monitor);
				}
				eliminacionCurso(CODCURSOviejo); //Se elimina el viejo Curso
				// Se escribe el curso con los datos modificados
				Cursos nuevoCurso ={codcurso, nombrecurso, anyo, mes,dia,plazadisp, monitor};
				reguistrarCurso(nuevoCurso);
			
			}else{
				Cursos nuevoCurso ={codcurso, nombrecurso, anyo, mes,dia,plazadisp, monitor};
				reguistrarCurso(nuevoCurso);
			}	
			liberarMemoriaCursos(arrayCursos,dimension);



}


void mostrarCursos(){
	Cursos *arrayCursos;
	int dimension = larguraStatment();
	arrayCursos = (Cursos*) malloc (dimension *sizeof(Cursos));
	seleccionCursos(arrayCursos);
	for (int i = 0; i < dimension; ++i){
		printf("Curso %i:\n",(i+1));
		printf("   NOMBRE CURSO: %s\n",arrayCursos[i].nombrecurso);
		printf("   COD CURSO: %i\n",arrayCursos[i].codcurso);
		printf("   FECHA: %i / %i / %i \n",arrayCursos[i].anyo, arrayCursos[i].mes , arrayCursos[i].dia);
		printf("   PLAZAS DISPONIBLES: %i\n",arrayCursos[i].plazadisp);
		printf("   MONITOR: %s\n",arrayCursos[i].monitor);
		
	}
	liberarMemoria(arrayCursos,dimension);
}

void borrar(){
	int existe = 0;
	int verificar;
	int LIMITE_DNI = 9;
	char DNI[LIMITE_DNI+1];
	int longitud=0;
	
	longitud = larguraStatment();
	
	if(longitud != 0){
		do{
		printf("%s\n","	Introduzca el Codigo del Curso:" );
		scanf("%d", codcurso);
		fflush(stdin);
		verificar =comprobacionCodCurso(codcurso);
		existe= codRepetido(DNI, 1,0);
		if(existe == -1){
			printf("%s\n","El DNI introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
		}
		}while(verificar == 1 || existe == -1);

		
		eliminacionCurso(codcurso);
		
		

		printf("\n %s\n\n","La eliminacion se ha efectuado correrctamente." );
	}else{
		printf("%s\n","No hay ningun objeto reguistrado. Por lo tanto, no se puede efectuar la eliminacion." );
	}
}

void liberarMemoriaCursos(Cursos* arrayCursos, int dimension){
	for(int i = 0; i<dimension; i++){
		free(arrayCursos[i].nombrecurso);
		arrayCursos[i].curso = NULL;
		free(arrayCursos[i].monitor);
		arrayCursos[i].monitor = NULL;		
		

		free(arrayCursos);
		arrayCursos== NULL;
	}
}
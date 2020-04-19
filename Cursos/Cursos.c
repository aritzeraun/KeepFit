#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Cursos.h>

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
			existe= repetido(CODCURSOviejo, 1);
			if(existe == -1){
				printf("%s\n","El CODIGO del CURSO introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
			}
		}while(verificar != 0 && existe != -1);
	}

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
				existe= repetido(codcurso);
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
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el AÑO:" );
			scanf("%i",&anyo);
			fflush(stdin);
			if (!(tipo== 1 && anyo == 0)){
				verificar =comprobacionANIO(anyo);
				
			}	
		}while((verificar !=0 ) && !(tipo== 1 && anyo == 0)) ;

// MES 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el MES:" );
			scanf("%i",&mes);
			fflush(stdin);
			if (!(tipo== 1 && mes == 0)){
				verificar =comprobacionMES(mes);
				
			}	
		}while((verificar !=0 ) && !(tipo== 1 && mes == 0)) ;

// DIA 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el DIA:" );
			scanf("%i",&dia);
			fflush(stdin);
			if (!(tipo== 1 && dia == 0)){
				verificar =comprobacionDIA(dia);
				
			}	
		}while((verificar !=0 ) && !(tipo== 1 && dia == 0)) ;

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
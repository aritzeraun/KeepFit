#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cursos.h"

#include "../Utilidades/Utilidades.h"

void introduciromodificarcursos(int tipo){

	short unsigned int LIMITE_NOMBRE= 20;
	short unsigned int LIMITE_MONITORDNI = 9;
	// recordar el espacio para 0/
	char nombrecurso[LIMITE_NOMBRE+1];
	char DNI[LIMITE_MONITORDNI+1];
	int anyoInicio = 0;
	int mesInicio = 0;
	int diaInicio = 0;
	int anyoFin = 0;
	int mesFin = 0;
	int diaFin = 0;
	int horas = 0;
	int diaSemana= 0;
	int plazas = 0;
	int codCurso = 0;
	int CODCURSOviejo = 0;

	Cursos *arrayCursos;
	int dimension = larguraCursos();
	arrayCursos = (Cursos*) malloc (dimension *sizeof(Cursos));
	seleccionCursos(arrayCursos);
	int posOld = 0;

	// La variable existe, ademas de verificar que el dato introducido ya existe, tambien nos dice a cual de lo objetos pertnece (nos da su posicion)
	int existe = 0; //Cuando el valor introducido no exista su valor sera -1
	int verificar = 0;
	if (tipo ==1){
		mostrarCursos(arrayCursos);
		do{
			printf("%s\n","	Introduzca el Codigo del curso:" );
			scanf("%i", CODCURSOviejo);
			fflush(stdin);
			verificar =comprobacionCodCurso(CODCURSOviejo);
			existe= codRepetido(CODCURSOviejo);
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
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0'\n");
			}
			printf("%s\n","	Introduzca el CODIGO del CURSO:" );
			scanf("%d", codCurso);
			fflush(stdin);
			
			if (!(tipo== 1 &&  codCurso == 0)){
				existe= codRepetido(codCurso);
				verificar =comprobacionCodCurso(codCurso);
			}
		}while((verificar != 0 && existe == -1) && !(tipo== 1  && codCurso == 0));

	// introduccion y modificacion de NOMBRE del CURSO
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el NOMBRE del CURSO:" );
			fgets(nombrecurso,LIMITE_NOMBRE+1,stdin);
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
			scanf("%i",&anyoInicio);
			fflush(stdin);
		}while(!(tipo== 1 && anyoInicio == 0)) ;
// MES 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el MES:" );
			scanf("%i",&mesInicio);
			fflush(stdin);	
		}while(!(tipo== 1 && mesInicio == 0)) ;
// DIA 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el DIA:" );
			scanf("%i",&diaInicio);
			fflush(stdin);
		}while(!(tipo== 1 && diaInicio == 0)) ;

		verificar = comprobacionFecha(anyoInicio,mesInicio,diaInicio);
	}while(verificar != 0);

// AÑO FIN
	do{ 
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el AÑO:" );
			scanf("%i",&anyoFin);
			fflush(stdin);
		}while(!(tipo== 1 && anyoFin == 0)) ;
// MES FIN
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el MES:" );
			scanf("%i",&mesFin);
			fflush(stdin);	
		}while(!(tipo== 1 && mesFin == 0)) ;
// DIA FIN
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el DIA:" );
			scanf("%i",&diaFin);
			fflush(stdin);
		}while(!(tipo== 1 && diaFin == 0)) ;

		verificar = comprobacionFecha(anyoFin,mesFin,diaFin);
	}while(verificar != 0);

// Plazas Disponibles
		do{
			
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*'\n");
			}
			printf("%s\n","	Introduzca el cuantas Plazas hay Disponibles:" );
			scanf("%i", plazas);
			fflush(stdin);
			
			if (!(tipo== 1 &&  plazas == '0')){
				verificar =comprobacionPlazasDisp(plazas);
			}
		}while((verificar != 0 ) && !(tipo== 1  && plazas == 0));

// Nombre del MONITOR
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el DNI del MONITOR:" );
			fgets(DNI,LIMITE_MONITORDNI+1,stdin);
			fflush(stdin);
			strtok(DNI, "\n");
			if (!(tipo== 1 && strlen(DNI) == 1 &&  DNI[0] == '*')){
				verificar = comprobacionDNI(DNI);




			}
		}while((verificar!=0) && !(tipo== 1 && strlen(DNI) == 1 && DNI[0] == '*'));

		if(tipo == 1){
				if(codCurso == '0'){
					codCurso =arrayCursos[posOld].codigo;
				}if(nombrecurso[0] == '*'){
					strcpy(nombrecurso, arrayCursos[posOld].nombre);
				}if(anyoInicio == 0){
					anyoInicio = arrayCursos[posOld].anyoInicio;
				}if(mesInicio == 0){
					mesInicio = arrayCursos[posOld].mesInicio;
				}if(diaInicio == 0){
					diaInicio=arrayCursos[posOld].diaInicio;
				}if(anyoFin == 0){
					anyoFin = arrayCursos[posOld].anyoFin;
				}if(mesFin == 0){
					mesFin = arrayCursos[posOld].mesFin;
				}if(diaFin == 0){
					diaFin=arrayCursos[posOld].diaFin;
				}if(horas == 0){
					horas = arrayCursos[posOld].hora;
				}if(plazas == 0){
					plazas = arrayCursos[posOld].plazas;
				}if(DNI[0] == '*'){
					strcpy(DNI, arrayCursos[posOld].DNI);
				}
				eliminacionCurso(CODCURSOviejo); //Se elimina el viejo Curso
				// Se escribe el curso con los datos modificados
			}	
			Cursos nuevoCurso ={codCurso, nombrecurso, anyoInicio, mesInicio,diaInicio,anyoFin, mesFin,diaFin,plazas, diaSemana,horas,DNI};
				reguistrarCurso(nuevoCurso);
			liberarMemoriaCursos(arrayCursos,dimension);
}
int codRepetido( int codigo){
		Cursos *arrayCursos;
	int dimension = larguraCursos();
	arrayCursos = (Cursos*) malloc (dimension *sizeof(Cursos));
	seleccionCursos(arrayCursos);
	
	for(int i = 0; i< dimension; i++){
		if(codigo== arrayCursos[i].codigo){
			return i;
			break;
		}
	}
	return -1;
}

void mostrarCursos(){
	Cursos *arrayCursos;
	int dimension = larguraCursos();
	arrayCursos = (Cursos*) malloc (dimension *sizeof(Cursos));
	seleccionCursos(arrayCursos);

	char diaSemana[10];
	int horas = 0;
	int minutos = 0;
	for (int i = 0; i < dimension; ++i){
		printf("Curso %i:\n",(i+1));
		printf("   CODIGO CURSO: %i\n",arrayCursos[i].codigo);
		printf("   NOMBRE CURSO: %s\n",arrayCursos[i].nombre);
		printf("   FECHA DE INICIO:  %i / %i / %i \n",  arrayCursos[i].diaInicio,arrayCursos[i].mesInicio , arrayCursos[i].anyoInicio);
		printf("   FECHA FIN: %i / %i / %i \n",  arrayCursos[i].diaFin,arrayCursos[i].mesFin , arrayCursos[i].anyoFin);
		printf("   PLAZAS DISPONIBLES: %i\n",arrayCursos[i].plazas);
		if(arrayCursos[i].diaSemana ==1){
			strcpy(diaSemana,"Lunes");
		}else if(arrayCursos[i].diaSemana ==2){
			strcpy(diaSemana,"Martes");
		}else if(arrayCursos[i].diaSemana ==3){
			strcpy(diaSemana,"Miercoles");
		}else if(arrayCursos[i].diaSemana ==4){
			strcpy(diaSemana,"Jueves");
		}else if(arrayCursos[i].diaSemana ==5){
			strcpy(diaSemana,"Viernes");
		}else if(arrayCursos[i].diaSemana ==6){
			strcpy(diaSemana,"Sabado");
		}
		printf("   DiA DE LA SEMANA: %s\n",diaSemana);
		horas = arrayCursos[i].hora / 100;
		minutos= arrayCursos[i].hora - horas;
		printf("   HORA DE COMIENZO:  %i:%i\n",horas,minutos);
		printf("    DNI DElMONITOR: %s\n\n",arrayCursos[i].DNI);
	}
	liberarMemoriaCursos(arrayCursos,dimension);
}

void borrarCurso(){
	int existe = 0;
	int verificar;
	int codCurso = 0;
	int longitud = larguraCursos();
	
	if(longitud != 0){
		do{
		printf("%s\n","	Introduzca el Codigo del Curso:" );
		scanf("%d", codCurso);
		fflush(stdin);
		verificar =comprobacionCodCurso(codCurso);
		existe= codRepetido(codCurso);
		if(existe == -1){
			printf("%s\n","El  codigo introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
		}
		}while(verificar == 1 || existe == -1);

		eliminacionCurso(codCurso);
		printf("\n %s\n\n","La eliminacion se ha efectuado correrctamente." );
	}else{
		printf("%s\n","No hay ningun objeto reguistrado. Por lo tanto, no se puede efectuar la eliminacion." );
	}
}

void liberarMemoriaCursos(Cursos* arrayCursos, int dimension){
	for(int i = 0; i<dimension; i++){
		free(arrayCursos[i].nombre);
		arrayCursos[i].nombre = NULL;
		free(arrayCursos[i].DNI);
		arrayCursos[i].DNI = NULL;		
	}
	free(arrayCursos);
	arrayCursos== NULL;
}
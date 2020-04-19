#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Espacios.h"
#include "../EspaciosBD/EspaciosBD.h"
#include "../Utilidades/Utilidades.h"
void IMEspacios(int tipo){

	short unsigned int verificar = 1;
	short unsigned int LIMITE_NOMBRE =20;
	short unsigned int LIMITE_DESCRIPCION = 50;
	// recuerdar el espacio para \0
	char nombre[LIMITE_NOMBRE+1];
	char descripcion[LIMITE_DESCRIPCION+1];
	int codigo = 0;
	int metrosCuadrados = 0;
	int capacidad = 0;

	Espacios *arrayEspacios;
	int dimension =  larguraEspacios();
	arrayEspacios = (Espacios*) malloc (dimension *sizeof(Espacios));
	seleccionEspacios(arrayEspacios);
	
	if(!(tipo==1 && dimension==0)){
		int posOld= 0;
		// La variable existe, ademas de verificar que el dato introducido ya existe, tambien nos dice a cual de lo objetos pertnece (nos da su posicion)
		int existe = 0; //Cuando el valor introducido no exista su valor sera -1
		if (tipo ==1){
			mostrarEspacios();
			do{
				printf("%s\n","	Introduzca el CODIGO del espacio:" );
				scanf("%i", &codigo);
				fflush(stdin);
				existe= unico(codigo, 1);
				if(existe == -1){
					printf("%s\n","El codigo introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
				}
			}while(existe == -1);
			posOld = existe;
			existe = -1;
		}else{
			codigo = unico (0,0);
			// en el caso del cogigo, el programa lo calcula automaticamente sin que el usuario tenga que introducirla.
		}
		
		// introduccion y modificacion de NOMBRE
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el NOMBRE:" );
			fgets(nombre,LIMITE_NOMBRE+1,stdin);
			fflush(stdin);
			strtok(nombre, "\n");
			if (!(tipo== 1 && strlen(nombre) == 1 && nombre[0] == '*')){
				verificar = ponerMayusculas(nombre);
			}
		}while((verificar!=0) && !(tipo== 1 && strlen(nombre) == 1 && nombre[0] == '*'));

		// metros cuadrados
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca los METROS CUADRADOS del espacio:" );
			scanf("%i", &metrosCuadrados);
			fflush(stdin);
			if (!(tipo== 1 && metrosCuadrados == 0)){
				verificar = comprobacionMetrosCuadrados(metrosCuadrados);
			}	
		}while((verificar !=0) && !(tipo== 1 && metrosCuadrados == 0));

		// capacidad
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca la CAPACIDAD DE PERSONAS del espacio:" );
			scanf("%i",&capacidad);
			fflush(stdin);
			if (!(tipo== 1 && capacidad == 0)){
				verificar =comprobacionCapacidad(metrosCuadrados, capacidad);
			}	
		}while((verificar !=0) && !(tipo== 1 && capacidad == 0)) ;

		// descripcion
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el DESCRIPCION:" );
			fgets(descripcion,LIMITE_DESCRIPCION +1,stdin);
			fflush(stdin);
			strtok(descripcion, "\n");
			if (!(tipo== 1 && strlen(descripcion) == 1 && descripcion[0] == '*')){
				verificar =ponerMayusculas(descripcion);
			}
		}while((verificar !=0) && !(tipo== 1 && strlen(descripcion) == 1 && descripcion[0] == '*'));

			// En el caso de la modificacion, si el usuario introduce un * se mantendra el valor, en el caso contrario, se modificara.
			if(tipo == 1){
				codigo=arrayEspacios[posOld].codigo;
				if(nombre[0] == '*'){
					strcpy(nombre, arrayEspacios[posOld].nombre);
				}if(metrosCuadrados == 0){
					metrosCuadrados=arrayEspacios[posOld].metrosCuadrados;
				}if(capacidad== 0){
					capacidad=arrayEspacios[posOld].capacidad;
				}if(descripcion[0] == '*'){
					strcpy(descripcion, arrayEspacios[posOld].descripcion);
				}
				eliminacionEspacio(codigo); //Se elimina el viejo Espacio	
			}// Se escribe el cliente con los datos modificados	
			Espacios nuevoEspacio ={codigo, nombre, metrosCuadrados, capacidad,descripcion};
			reguistrarEspacio(nuevoEspacio);	
			liberarMemoriaEspacios(arrayEspacios,dimension);
	}else{
		printf("%s\n","No hay Espacios reguistrados. Por lo tanto, no se pueden modificar." );
	}
}

int unico(int codigo, int crearOBuscar){
	int dimension = larguraEspacios();
	Espacios *arrayEspacios;
	arrayEspacios = (Espacios*) malloc (dimension *sizeof(Espacios));
	seleccionEspacios(arrayEspacios);

	if(crearOBuscar == 0){
		if(dimension == 0){  // el primer codigo sera 1.
			return 1;
		}else{ //verifica que no haya huecos en la secuencia de los codigos
			for(int i = 0; i< dimension; i++){ 
				if((i+1) != arrayEspacios[i].codigo){
					return (i+1);
					break;
				}
			}
			// en el caso de que no haya huecos, se crea un nuevo codigo.
			return (dimension + 1);
		}
	}else{
		for(int i = 0; i< dimension; i++){ 
			if(codigo == arrayEspacios[i].codigo){
				return i;
				break;
			}
		}
		return -1;
	}
	liberarMemoriaEspacios(arrayEspacios,dimension);
}
void mostrarEspacios(){
	Espacios* arrayEspacios;
	int dimension = larguraEspacios();
	arrayEspacios = (Espacios*) malloc (dimension *sizeof(Espacios));
	seleccionEspacios(arrayEspacios);
	for (int i = 0; i < dimension; ++i){
		printf("Espacio %i:\n",(i+1));
		printf("   CODIGO: %i\n",arrayEspacios[i].codigo);
		printf("   NOMBRE: %s\n",arrayEspacios[i].nombre);
		printf("   METROS CUADRADOS: %i\n",arrayEspacios[i].metrosCuadrados);
		printf("   CAPACIDAD DE PERSONAS: %i\n",arrayEspacios[i].capacidad);
		printf("   DESCRIPCION: %s\n",arrayEspacios[i].descripcion);
	}
	liberarMemoriaEspacios(arrayEspacios,dimension);
}
void borrarEspacios(){
	int existe = 0;
	int codigo;
	int longitud= larguraEspacios();
	
	if(longitud != 0){
		do{
		printf("%s\n","	Introduzca el CODIGO del espacio:" );
		scanf("%i",&codigo);
		existe= unico(codigo,1);//mandamos un 1 porque queremos buscar si el codigo existe
			if(existe == -1){
				printf("%s\n","El DNI introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
			}
		}while(existe == -1);

		eliminacionEspacio(codigo);
		printf("\n %s\n\n","La eliminacion se ha efectuado correrctamente." );
	}else{
		printf("%s\n","No hay ningun objeto reguistrado. Por lo tanto, no se puede efectuar la eliminacion." );
	}
}
void liberarMemoriaEspacios(Espacios* arrayEspacios, int dimension){
	for(int i = 0; i<dimension; i++){
		
		free(arrayEspacios[i].nombre);
		arrayEspacios[i].nombre = NULL;		
		free(arrayEspacios[i].descripcion);
		arrayEspacios[i].descripcion = NULL;
	}
	free(arrayEspacios);
	arrayEspacios== NULL;
}
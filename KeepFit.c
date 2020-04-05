#include <stdio.h>
#include <stdlib.h>
#include "Clientes/Clientes.h"

// De momemnto, no se preve que el programa vaya a recibir parametros externos.
// Cuando realicemos el siguiente ptrograma en C++  esto podra variar.
int main(void){
	int opcion = 0;
	short int inicio =0;
	while (opcion !=5){
		if(inicio == 0){
			printf("%s","Bienvenido a KeepFit SL. " );
			inicio++;
		}
		printf("%s\n", "Cual de las siguientes acciones desea realizar?");
		printf("%s\n","1. Reguistar nuevo Cliente." );
		scanf("%i", &opcion);
		fflush(stdin);

		// Creacion de tablas de los distintos modulos.
		 crearTablaClientes();
		 int length=0;
		 Clientes* lecturaCli;
		switch (opcion){
			case 1:
			printf("%s\n","Introduzca el DNI:" );
			printf("%s\n", "Introduzca el NOMBRE:");
			printf("%s\n","Introduzca el APELLIDO:");
			Clientes a ={"7259384M","Aritz","Eraetamurgil","Murgil",648787,"aunopendeusto.es","20955005105499400"};
			reguistrarCliente(a);
			break;
			case 2:
			length= larguraStatment();
			lecturaCli= (Clientes*)malloc(length*sizeof(Clientes));
			(lecturaCli)=seleccionClientes(lecturaCli);
			
			free(lecturaCli);

			break;
			case 3:
			break;
			case 4:
			break;
			default: printf("%s\n","Porfavor, introduzca una opcion valida." );
		}

	}
return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "Clientes/Clientes.h"
#include "ClientesBD/ClientesBD.h"

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
		switch (opcion){
			case 1:
			introducirCliente();	
			break;
			case 2:
		

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
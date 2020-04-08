#include <stdio.h>
#include <stdlib.h>
#include "Clientes/Clientes.h"
#include "ClientesBD/ClientesBD.h"

void imprimirOpciones(char * objeto);
void menuClientes();

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
		printf("%s\n", "Indique con cual de los siguientes objetos desea trabajar:");
		printf("%s\n","1. Clientes." );
		printf("%s\n","2. Trabajadores (Entrenadores)." );
		printf("%s\n","3. Cursos o Eventos." );
		printf("%s\n","4. Reservas." );
		printf("%s\n","5. Salir del programa." );
		scanf("%i", &opcion);
		fflush(stdin);

		// Creacion de tablas de los distintos modulos.
		 crearTablaClientes();
		switch (opcion){
			case 1:
			menuClientes();	
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
				printf("%s\n", "Gracias por haber confiado en los servicios de KeepFit. Hasta Pronto." );
			break;
			default: printf("%s\n","Porfavor, introduzca una opcion valida." );
		}
	}
return 0;
}

void imprimirOpciones(char * objeto){

	printf("%s %ss.\n", "Indique la accion que desea realizar con los ", objeto);
		printf("%s %s.\n","1. Crear nuevo ", objeto);
		printf("%s %s.\n","2. Mostrar ", objeto);
		printf("%s %s.\n","3. Eliminar", objeto);
		printf("%s %s.\n","4. Modificar", objeto);
		printf("%s %s.\n","5. Salir del apartado", objeto);
}
void menuClientes(){
	short int opcion =0;
	while (opcion !=5){
		imprimirOpciones("Cliente");
		scanf("%i", &opcion);
		fflush(stdin);
		Clientes *arrayClientes;
		int dimension = 0;
		switch (opcion){
			case 1:
			// Como se tratade crear un nuevo Cliente, el tipo sera 0.
				introducirOmodificarCliente(0);	
			break;
			case 2:
				dimension = mostrarClientes(arrayClientes);
			break;
			case 3:
				dimension = mostrarClientes(arrayClientes);
				borrarClientes();
			break;
			case 4:
				// Como se tratade crear un nuevo Cliente, el tipo sera 0.
				introducirOmodificarCliente(1);	
			break;
			case 5:
			// Se define caso 5 para que no se imprima el mensage  del default cuando se desee salir de este menu.
			break;
			default: printf("%s\n","Porfavor, introduzca una opcion valida." );
		}
	}
}
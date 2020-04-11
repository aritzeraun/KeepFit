#include <stdio.h>
#include <stdlib.h>
#include "Acciones/Acciones.h"
#include "ClientesBD/ClientesBD.h"
#include "EmpleadosBD/EmpleadosBD.h"

void imprimirOpciones(char * objeto);
void menu();
void menuEmpleados();

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
		 crearTablaEmpleados();

		switch (opcion){
			case 1:
				menu(1);	
			break;
			case 2:
				menu(2);
			break;
			case 3:
				menu(3);
			break;
			case 4:
				menu(4);
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
void menu(int tipo){
	short int opcion =0;
	while (opcion !=5){
		char* tipoObjeto[] ={"Cliente","Empleado","Curso","Reservas"};
		imprimirOpciones(tipoObjeto[tipo-1]);
		scanf("%i", &opcion);
		fflush(stdin);
		
		switch (opcion){
			case 1:
				if (tipo==1){
					introducirOmodificar(0,0);// Como se trata de crear un nuevo Cliente, el tipo sera 0. 
					// En cuanto al modulo, tambien es 0 porque representa un Cliente.
				}else if (tipo ==2){
					introducirOmodificar(0,1);	  // Como se trata de crear un nuevo Empleado, el tipo sera 0.
					// En cuanto al modulo, su valor es uno debido a que se trata de un Empleado.
				}else if(tipo == 3) {

				}else{

				}
			break;
			case 2:
				if (tipo==1){
					mostrar(0);// Como se trata de mostrar un Cliente, se envia  un cero como tipo de modulo.
				}else if (tipo ==2){
					mostrar(1); // Como se trata de mostrar un Empleado, se envia  un uno como tipo de modulo.
				}else if(tipo == 3) {

				}else{

				}
			break;
			case 3:
				if (tipo==1){
					mostrar(0); // Como se trata de mostrar un Cliente, se envia  un cero como tipo de modulo.
					borrar(0);  //Al igual que en mostrar, al tratarse de un Cliente, se envia un cero como valor de modulo.
				}else if (tipo ==2){
					mostrar(1); // Como se trata de mostrar un Empleado, se envia  un uno como tipo de modulo.
					borrar(1);  //Al igual que en mostrar, al tratarse de un Empleado, se envia un uno como valor de modulo.
				}else if(tipo == 3) {

				}else{

				}
			break;
			case 4:
				if (tipo==1){
				introducirOmodificar(1,0);	// Como se trata de modificar un cliente ya existente, el tipo sera 1. 
				// Como se trata de un Cliente, el valor del modulo es 0.
				}else if (tipo ==2){
					introducirOmodificar(1,0);// Como se trata de modificar un Empleado ya existente, el tipo sera 1. 
				// Como se trata de un Empleado, el valor del modulo es 1.
				}else if(tipo == 3) {

				}else{

				}
			break;
			case 5:// Se define caso 5 para que no se imprima el mensage  del default cuando se desee salir de este menu.
			break;
			default: printf("%s\n","Porfavor, introduzca una opcion valida." );
		}
	}
}
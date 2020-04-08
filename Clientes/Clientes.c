#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Clientes.h"
#include "../ClientesBD/ClientesBD.h"
#include "../Utilidades/Utilidades.h"
void introducirOmodificarCliente(int tipo){

	short unsigned int verificar = 1;
	short unsigned int LIMITE_DNI =9;
	short unsigned int LIMITE_NOMBRE =20;
	short unsigned int LIMITE_APELLIDO = 30;
	short unsigned int LIMITE_DIR = 50;
	short unsigned int LIMITE_CTA = 24;
	short unsigned int LIMITE_EMAIL = 50;
	// recuerdar el espacio para \0
	char DNIviejo[LIMITE_DNI+1];
	char DNI[LIMITE_DNI+1];
	char nombre[LIMITE_NOMBRE+1];
	char apellido[LIMITE_APELLIDO+1];
	char direccion[LIMITE_DIR+1];
	int TLF = 0;
	char n_cta[LIMITE_CTA +1];
	char email[LIMITE_EMAIL +1];
	Clientes *arrayClientes;
	int posOld= 0;
	// La variable existe, ademas de verificar que el dato introducido ya existe, tambien nos dice a cual de lo objetos pertnece (nos da su posicion)
	int existe = 0; //Cuando el valor introducido no exista su valor sera -1
	if (tipo ==1){
		mostrarClientes(arrayClientes);
		do{
			printf("%s\n","	\nIntroduzca el DNI:" );
			fgets(DNIviejo,LIMITE_DNI+1,stdin);
			fflush(stdin);
			existe= repetido(DNIviejo, 1);
			if(existe == 0){
				printf("%s\n","El DNI introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
			}
			verificar =comprobacionDNI(DNIviejo);
		}while(verificar != 0 && existe != -1);
	}
	posOld = existe;

	do{
		if(existe != -1){
			printf("%s\n","El DNI introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
		}
		if(tipo==1){
				printf("El DNI del cliente que desea modificar es: %s \n", arrayClientes[posOld].DNI);
				printf("%s\n","En el caso de que no desee modificarlo introduzca   '*'\n");
		}
		printf("%s\n","	Introduzca el DNI:" );
		fgets(DNI,LIMITE_DNI+1,stdin);
		fflush(stdin);
		if (!(tipo== 1 && strlen(DNI) == 1 && DNI[0] == '*')){
			existe= repetido(DNI, 1);
			verificar =comprobacionDNI(DNI);
		}
	}while((verificar != 0 && existe == -1)||(tipo== 1 && strlen(DNI) == 1 && DNI[0] == '*'));

	do{
		if(tipo==1){
				printf("El NOMBRE cliente que desea modificar es: %s \n", arrayClientes[posOld].nombre);
				printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
		}
		printf("%s\n","	Introduzca el NOMBRE:" );
		fgets(nombre,LIMITE_NOMBRE+1,stdin);
		fflush(stdin);
		if (!(tipo== 1 && strlen(nombre) == 1 && nombre[0] == '*')){
			verificar = ponerMayusculas(nombre);
		}
	}while((verificar!=0) || (tipo== 1 && strlen(nombre) == 1 && nombre[0] == '*'));

	do{
		if(tipo==1){
				printf("El APELLIDO cliente que desea modificar es: %s \n", arrayClientes[posOld].apellido);
				printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
		}
		printf("%s\n","	Introduzca el APELLIDO:" );
		fgets(apellido,LIMITE_APELLIDO+1,stdin);
		fflush(stdin);
		if (!(tipo== 1 && strlen(apellido) == 1 && apellido[0] == '*')){
			verificar =ponerMayusculas(apellido);
		}	
	}while((verificar !=0) || (tipo== 1 && strlen(apellido) == 1 && apellido[0] == '*'));

	do{
		if(tipo==1){
				printf("El DIRECCION DE LA VIVIENDA HABITUAL cliente que desea modificar es: %s \n", arrayClientes[posOld].direccion);
				printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
		}
		printf("%s\n","	Introduzca el DIRECCION DE LA VIVIENDA HABITUAL:" );
		fgets(direccion,LIMITE_DIR +1,stdin);
		fflush(stdin);
		if (!(tipo== 1 && strlen(direccion) == 1 && direccion[0] == '*')){
			verificar =ponerMayusculas(direccion);
		}
	}while((verificar !=0) ||(tipo== 1 && strlen(direccion) == 1 && direccion[0] == '*'));

	do{
		if(tipo==1){
				printf("El TELEFONO cliente que desea modificar es: %s \n", arrayClientes[posOld].tlf);
				printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
		}
		printf("%s\n","	Introduzca el NUMERO DE TELEFONO:" );
		scanf("%i",&TLF);
		fflush(stdin);
		if (!(tipo== 1 && TLF == 0)){
			verificar =comprobacionTLF(TLF);
		}	
	}while((verificar !=0)|| (tipo== 1 && TLF == 0)) ;

	do{
		if(tipo==1){
				printf("El NUMERO DE CUENTA BANCARIA cliente que desea modificar es: %s \n", arrayClientes[posOld].n_cta);
				printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
		}
		printf("%s\n","	Introduzca el NUMERO DE CUENTA BANCARIA:" );
		fgets(n_cta,LIMITE_CTA+1,stdin);
		fflush(stdin);
		if (!(tipo== 1 && strlen(n_cta) == 1 && n_cta[0] == '*')){
			verificar =comprobacionIBAN(n_cta);
		}		
	}while((verificar !=0)||(tipo== 1 && strlen(n_cta) == 1 && n_cta[0] == '*'));

	do{
		if(tipo==1){
				printf("El EMAIL cliente que desea modificar es: %s \n", arrayClientes[posOld].email);
				printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
		}
		printf("%s\n","	Introduzca el EMAIL" );
		fgets(email,LIMITE_EMAIL+1,stdin);
		fflush(stdin);
		if (!(tipo== 1 && strlen(email) == 1 && email[0] == '*')){
			existe = repetido(email, 2);
			verificar =comprobacionEmail(email);
		}	
	}while((verificar !=0 && existe == -1) ||(tipo== 1 && strlen(email) == 1 && email[0] == '*'));

// En el caso de la modificacion, si el usuario introduce un * se mantendra el valor, en el caso contrario, se modificara.
	if(tipo == 1){
		if(DNI[0] == '*'){
			strcpy(DNI, arrayClientes[posOld].DNI);
		}if(nombre[0] == '*'){
			strcpy(nombre, arrayClientes[posOld].nombre);
		}if(apellido[0] == '*'){
			strcpy(apellido, arrayClientes[posOld].apellido);
		}if(direccion[0] == '*'){
			strcpy(direccion, arrayClientes[posOld].direccion);
		}if(TLF == 0){
			TLF=arrayClientes[posOld].tlf;
		}if(n_cta[0] == '*'){
			strcpy(n_cta, arrayClientes[posOld].n_cta);
		}if(email[0] == '*'){
			strcpy(email, arrayClientes[posOld].email);
		}
		eliminacionCliente(DNIviejo); //Se elimina el viejo Cliente
		// Se escribe el cliente con los datos modificados
		Clientes nuevoCliente ={DNI, nombre, apellido, direccion,TLF,n_cta, email};
		reguistrarCliente(nuevoCliente);
	
	}else{
		Clientes nuevoCliente ={DNI, nombre, apellido, direccion,TLF,n_cta, email};
		printf("%s\n", "iepa");
		reguistrarCliente(nuevoCliente);
	}	
}

int repetido(char *cadena, int tipo){
	// Para reutilizar codigo, se ddefine como tipo 1 los DNIs y tipo 2 los emails.
	Clientes *arrayClientes;
	int dimension = larguraStatment();
	arrayClientes = (Clientes*) malloc (dimension *sizeof(Clientes));
	seleccionClientes(arrayClientes);
	short int cmp =1;
	// Dentro de la busqueda secuencial, este es el procedimiento de comparacion que ofrece un gasto de tiempo menor.
	if(tipo ==1){
		for(int i = 0; i< dimension; i++){ // si se devuelve un 0 es que los DNIs son iguales y, por lo tanto, hay un Cliente reguistrado con el mismo DNI.
			cmp =strcmp(arrayClientes[i].DNI, cadena);
			if(cmp == 0){
				return i;
				break;
			}
		}
	}else if (tipo == 2){ //Comprueba que no haya dos emails iguales
		for(int i = 0; i< dimension; i++){
			cmp =strcmp(arrayClientes[i].email,cadena );
			if(cmp == 0){
				printf("%s\n","El EMAIL introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
				return i;
				break;
			}
		}
	}
	
	if (cmp != 0){
		return -1;
	}
}
int mostrarClientes(Clientes* arrayClientes){
	int dimension = larguraStatment();
	arrayClientes = (Clientes*) malloc (dimension *sizeof(Clientes));
	seleccionClientes(arrayClientes);
	for (int i = 0; i < dimension; ++i){
		printf("Cliente %i:\n",(i+1));
		printf("   DNI: %s\n",arrayClientes[i].DNI);
		printf("   NOMBRE: %s\n",arrayClientes[i].nombre);
		printf("   APELLIDO: %s\n",arrayClientes[i].apellido);
		printf("   DIRECCION: %s\n",arrayClientes[i].direccion);
		printf("   TELEFONO: %i\n",arrayClientes[i].tlf);
		printf("   CUENTA BANCARIA: %s\n",arrayClientes[i].n_cta);
		printf("   EMAIL: %s\n\n",arrayClientes[i].email);
	}
	return dimension;
}
void borrarClientes(){
	int existe;
	int verificar;
	int LIMITE_DNI = 9;
	char DNI[LIMITE_DNI+1];
	do{
		printf("%s\n","	Introduzca el DNI:" );
		fgets(DNI,LIMITE_DNI+1,stdin);
		fflush(stdin);
		existe= repetido(DNI, 1);
		if(existe == -1){
			printf("%s\n","El DNI introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
		}
		verificar =comprobacionDNI(DNI);
	}while(!(verificar == 0 && existe != -1));

	eliminacionCliente(DNI);
	printf("\n %s\n\n","La eliminacion se ha efectuado correrctamente." );

}
void liberarMemoria(Clientes* arrayClientes, int dimension){
	for(int i = 0; i<dimension; i++){
		printf("%i\n", 1);
		free(arrayClientes[i].DNI);
		arrayClientes[i].DNI = NULL;
		printf("%i\n", 188);
		free(arrayClientes[i].nombre);
		arrayClientes[i].nombre = NULL;
			printf("%i\n", 2);		
		free(arrayClientes[i].apellido);
		arrayClientes[i].apellido = NULL;
			printf("%i\n", 3);
		free(arrayClientes[i].direccion);
		arrayClientes[i].direccion = NULL;
			printf("%i\n", 4);
		free(arrayClientes[i].n_cta);
		arrayClientes[i].n_cta = NULL;
			printf("%i\n", 5);
		free(arrayClientes[i].email);
		arrayClientes[i].email = NULL;
	free(arrayClientes);
	arrayClientes== NULL;
	}
}
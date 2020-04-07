#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Clientes.h"
#include "../ClientesBD/ClientesBD.h"
#include "../Utilidades/Utilidades.h"
void introducirCliente(){

	short unsigned int verificar = 1;
	short unsigned int LIMITE_DNI =9;
	short unsigned int LIMITE_NOMBRE =20;
	short unsigned int LIMITE_APELLIDO = 30;
	short unsigned int LIMITE_DIR = 50;
	short unsigned int LIMITE_CTA = 24;
	short unsigned int LIMITE_EMAIL = 50;
	int existe = 0;

	do{
		printf("%s\n","	Introduzca el DNI:" );
		char DNI[LIMITE_DNI+1];
		// recuerdar el espacio para \0
		fgets(DNI,LIMITE_DNI+1,stdin);
		fflush(stdin);
		existe= repetido(DNI, 1);
		verificar =comprobacionDNI(DNI);
	}while(verificar != 0 && existe == 0);

	do{
		printf("%s\n","	Introduzca el NOMBRE:" );
		char nombre[LIMITE_NOMBRE+1];
		fgets(nombre,LIMITE_NOMBRE+1,stdin);
		fflush(stdin);
		verificar = ponerMayusculas(nombre);
	}while(verificar!=0);

	do{
		printf("%s\n","	Introduzca el APELLIDO:" );
		char apellido[LIMITE_APELLIDO+1];
		fgets(apellido,LIMITE_APELLIDO+1,stdin);
		fflush(stdin);
		verificar =ponerMayusculas(apellido);
	}while(verificar !=0);

	do{
		printf("%s\n","	Introduzca el DIRECCION DE LA VIVIENDA HABITUAL:" );
		char direccion[LIMITE_DIR+1];
		fgets(direccion,LIMITE_DIR +1,stdin);
		fflush(stdin);
		verificar =ponerMayusculas(direccion);
	}while(verificar !=0);

	do{
		printf("%s\n","	Introduzca el NUMERO DE TELEFONO:" );
		int TLF = 0;
		scanf("%i",&TLF);
		fflush(stdin);
		verificar =comprobacionTLF(TLF);
	}while(verificar !=0);

	do{
		printf("%s\n","	Introduzca el NUMERO DE CUENTA BANCARIA:" );
		char n_cta[LIMITE_CTA +1];
		fgets(n_cta,LIMITE_CTA+1,stdin);
		fflush(stdin);
		verificar =comprobacionIBAN(n_cta);
	}while(verificar !=0);

	do{
		printf("%s\n","	Introduzca el EMAIL" );
		char email[LIMITE_EMAIL +1];
		fgets(email,LIMITE_EMAIL+1,stdin);
		fflush(stdin);
		existe = repetido(email, 2);
		verificar =comprobacionEmail(email);
	}while(verificar !=0 && repetido == 0);

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
				printf("%s\n","El DNI introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
				return 1;
				break;
			}
		}
	}else if (tipo == 2){ //Comprueba que no haya dos emails iguales
		for(int i = 0; i< dimension; i++){
			cmp =strcmp(arrayClientes[i].email,cadena );
			if(cmp == 0){
				printf("%s\n","El EMAIL introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
				return 1;
				break;
			}
		}
	}
	
	if (cmp != 0){
		return 0;
	}
}
void  mostrarClientes(){
	Clientes *arrayClientes;
	int dimension = larguraStatment();
	arrayClientes = (Clientes*) malloc (dimension *sizeof(Clientes));
	seleccionClientes(arrayClientes);

	for (int i = 0; i < dimension; ++i)
	{
		printf("Cliente %i:\n",i);
		printf("   DNI: %s\n",arrayClientes[i].DNI);
		printf("   NOMBRE: %s\n",arrayClientes[i].nombre);
		printf("   APELLIDO: %s\n",arrayClientes[i].apellido);
		printf("   DIRECCION: %s\n",arrayClientes[i].direccion);
		printf("   TELEFONO: %i\n",arrayClientes[i].tlf);
		printf("   CUENTA BANCARIA: %s\n",arrayClientes[i].n_cta);
		printf("   EMAIL: %s\n\n",arrayClientes[i].email);
	}

}
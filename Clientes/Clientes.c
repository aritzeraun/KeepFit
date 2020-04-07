#include <stdio.h>
#include "Clientes.h"
#include "../ClientesBD/ClientesBD.h"
#include "../Utilidades/Utilidades.h"
void introducirCliente(){

	short unsigned int verificar = 1;
	short unsigned int LIMITE_DNI =9;
	short unsigned int LIMITE_NOMBRE =20;
	short unsigned int LIMITE_APELLIDO = 30;
	short unsigned int LIMITE_ DIR = 50;
	short unsigned int LIMITE_CTA = 24;

	do{
		printf("%s\n","	Introduzca el DNI:" );
		char DNI[LIMITE_DNI+1];
		// recuerdar el espacio para \0
		fgets(DNI,LIMITE_DNI+1,stdin);
		fflush(stdin);
		verificar =comprobacionDNI(DNI);
	}while(verificar != 0);
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
		scanf("%i",%TLF)
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

	

}
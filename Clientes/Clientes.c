#include <stdio.h>
#include "Clientes.h"
#include "../ClientesBD/ClientesBD.h"
#include "../Utilidades/Utilidades.h"
void introducirCliente(){
	int verificarDNI = 1;
	do{
		printf("%s\n","	Introduzca el DNI:" );
		char DNI[10];
		// recuerdar el espacio para \0
		fgets(DNI,10,stdin);
		fflush(stdin);
		verificarDNI =comprobacionDNI(DNI);
	}while(verificarDNI!=0);
	comprobacionTLF(99877);
	printf("%s\n", "Introduzca el NOMBRE:");
	printf("%s\n","Introduzca el APELLIDO:");
}
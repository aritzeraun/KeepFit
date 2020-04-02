#ifndef _CLIENTES_H
#define _CLIENTES_H
typedef struct{
	char *DNI;
	char *nombre;
	char *apellido;
	char *direccion;
	int tlf;
	int n_ct;
	char *emial;
}Clientes;
void reguistrarCliente(Clientes nuevo_cli);
#endif
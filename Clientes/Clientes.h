#ifndef _CLIENTES_H
#define _CLIENTES_H
typedef struct{
	char *DNI;
	char *nombre;
	char *apellido;
	char *direccion;
	int tlf;
	int n_cta;
	char *email;
}Clientes;
void reguistrarCliente(Clientes nuevo_cli);
void crearTablaClientes();
void void eliminacionCliente(Clientes newCli);
#endif
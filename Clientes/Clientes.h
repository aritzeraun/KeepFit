#ifndef _CLIENTES_H
#define _CLIENTES_H
typedef struct{
	char *DNI;
	char *nombre;
	char *apellido;
	char *direccion;
	int tlf;
	char *n_cta;
	char *email;
}Clientes;

void reguistrarCliente(Clientes nuevo_cli);
void crearTablaClientes();
void eliminacionCliente(Clientes newCli);
Clientes* seleccionClientes(Clientes arrayLectura[5]);
int charToNumber(char *cadena);
int larguraStatment();
#endif
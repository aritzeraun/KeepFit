#include "../ClientesBD/ClientesBD.h"
#ifndef _CLIENTES_H
#define _CLIENTES_H
void introducirOmodificarCliente(int tipo);
int repetido(char *cadena, int tipo);
void mostrarClientes();
void borrarClientes();
void liberarMemoria(Clientes* arrayClientes, int dimension);
#endif
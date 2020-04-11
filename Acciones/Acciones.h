#include "../ClientesBD/ClientesBD.h"
#include  "../EmpleadosBD/EmpleadosBD.h"

#ifndef _ACCIONES_H
#define _ACCIONES_H
void introducirOmodificar(int tipo, int modulo);
int repetido(char *cadena, int tipo, int modulo);
void mostrar(int modulo);
void borrar(int modulo);
void liberarMemoria(Clientes* arrayClientes, int dimension, int  modulo);
#endif
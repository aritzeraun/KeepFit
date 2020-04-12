#include "../ClientesBD/ClientesBD.h"
#include  "../EmpleadosBD/EmpleadosBD.h"

#ifndef _ACCIONES_H
#define _ACCIONES_H
void introducirOmodificar(int tipo, int modulo);
int repetido(char *cadena, int tipo,int datoNumerico, int modulo);
void mostrarClientes();
void mostrarEmpleados();
void borrar(int modulo);
void liberarMemoriaClientes(Clientes* arrayClientes, int dimension);
void liberarMemoriaEmpleados(Empleados* arrayClientes, int dimension);
#endif
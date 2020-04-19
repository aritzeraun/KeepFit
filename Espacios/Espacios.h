#include "../EspaciosBD/EspaciosBD.h"

#ifndef _ESPACIOS_H
#define _ESPACIOS_H
void IMEspacios(int tipo);
int unico(int codigo, int crearOBuscar);
void mostrarEspacios();
void borrarEspacios();
void liberarMemoriaEspacios(Espacios* arrayClientes, int dimension);
#endif
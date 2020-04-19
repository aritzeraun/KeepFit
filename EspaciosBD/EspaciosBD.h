#ifndef _ESPACIOSBD_H
#define _ESPACIOSBD_H
typedef struct{
	int codigo;
	char *nombre;
	int metrosCuadrados;
	int capacidad;
	char *descripcion;
}Espacios;
void reguistrarEspacio(Espacios nuevoEspacio);
void crearTablaEspacios();
void eliminacionEspacio( int codigo);
void seleccionEspacios(Espacios arrayLectura[]);
int larguraEspacios();
#endif
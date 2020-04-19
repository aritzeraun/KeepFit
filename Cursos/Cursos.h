#include "../CursosBD/CursosBD.h"

#ifndef _CURSOS_H
#define _CURSOS_H
void introduciromodificarcursos(int tipo);
int codRepetido(char *cadena, int tipo,int datoNumerico);
void mostrarCursos();
void borrar();
void liberarMemoriaCursos(Cursos* arrayCursos, int dimension);

#endif
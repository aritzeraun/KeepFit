#include "../CursosBD/CursosBD.h"
#ifndef _CURSOS_H
#define _CURSOS_H
void introduciromodificarcursos(int tipo);
int codRepetido(int codigo);
void mostrarCursos();
void borrarCursos();
void liberarMemoriaCursos(Cursos* arrayCursos, int dimension);

#endif
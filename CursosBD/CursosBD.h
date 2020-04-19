#ifndef _CURSOSBD_H
#define _CURSOSBD_H
typedef struct{
	int codigo;
	char *nombre;
	int anyoInicio;
	int mesInicio;
	int diaInicio;
	int anyoFin;
	int mesFin;
	int diaFin;
	int plazas;
	int diaSemana;
	int hora;
	char *DNI;
}Cursos;
void reguistrarCurso(Cursos nuevoCurso);
void crearTablaCursos();
void eliminacionCurso(int codigo);
void seleccionCursos(Cursos arrayLectura[]);
int larguraCursos();
#endif
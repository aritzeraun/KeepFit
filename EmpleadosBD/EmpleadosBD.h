#ifndef _EMPLEADOSBD_H
#define _EMPLEADOSBD_H
typedef struct{
	char *DNI;
	char *nombre;
	char *apellido;
	char *direccion;
	int tlf;
	char *n_cta;
	char *email;
	char * n_ss;
	float sueldo;
	char *especialidad;
	char *cargo;
	int horario;
}Empleados;
void reguistrarEmpleado(Empleados nuevo_emp);
void crearTablaEmpleados();
void eliminacionEmpleado(char *DNI);
void seleccionEmpleado(Empleados arrayLectura[]);
int larguraSentencia();
#endif
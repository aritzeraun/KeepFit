#ifndef _UTILIDADES_H
#define _UTILIDADES_H
int comprobacionDNI(char *DNI);
int comprobacionTLF(int TLF);
int comprobacionIBAN(char *IBAN);
int ponerMayusculas(char * cadena);
int comprobacionEmail(char *email);
int comprobacionN_SS(unsigned long long n_ss);
int comprobacionSueldo(double sueldo);
int comprobacionHorario (char *horario);
int comprobacionPrecio(float precio);
int comprobacionFecha(int anyo, int mes, int dia);
int comprobacionMetrosCuadrados(int metrosCuadrados);
int comprobacionCapacidad(int metrosCuadrados, int capacidad);
int comprobacionCodCurso(int codcurso);
int comprobacionPlazasDisp(int plazasDisp);
int comprobacionDiaSemana(char *diaSemana);
#endif
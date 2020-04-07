#include <stdio.h>
#include <string.h>
#include "Utilidades.h"

int comprobacionDNI(char *DNI){
	int contador=0;
	int ascii =0;

	if(strlen(DNI)==9){
		for(int i = 0;i<9;i++){
			ascii= DNI[i];

			if(i<8){
				if(ascii>=48 && ascii<58){
					contador++;
				}
			}else{
				if(ascii<48 || ascii>57){
					contador++;
				}
			}
		}
		if(contador==9){
			// todo esta correcto
			return 0;
		}else{
			// El formato del DNI no es adecuado
			return 1;
		}
	}else{
		printf("%s\n","El DNI introducido tiene una largura incorrecta." );
		return 1;
	}
}
int comprobacionTLF(int TLF){
	if(TLF<=999999999 && TLF>=100000000){ //los telefonos tienen 9 zifras numericas
		if(TLF>=600000000 && TLF<800000000){
			// Hoy en dia los telefonos moviles pueden empezar de 6 o 7.
			return 0;
		}else if(TLF<=999999999 && TLF>=900000000){
			// Todos los telefonos fijos empiezan con el numero 9 en españa.
			return 0;
		}else{
			printf("%s\n","El TELEFONO introducido tiene un prefijo desconocido en el terrritorio estatal." );
			return 1;
		}
	}else{
		printf("%s\n","El TELEFONO introducido tiene una largura incorrecta." );
		return 1;
	}
}
int comprobacionIBAN(char* IBAN){
	short int tipo= 0;
	short int contador = 0;
	int ascii = 0;
	if(strlen(IBAN)==20  || strlen(IBAN)==24){
		if(strlen(IBAN)==24){
			tipo =2;
			if(IBAN[0]=='E'){
				if(IBAN[0]=='S'){
					contador++;
				}else{
					printf("%s\n","El formato del IBAN no es el adecuado." );
				}
			}else{
				printf("%s\n","El formato del IBAN no es el adecuado." );
			}
		}
		for(int i = 0; i<(20+tipo); i++){
			ascii= IBAN[i+tipo];
			if(ascii>=48 && ascii<58){
					contador++;
				}
		}
		if(contador== 20 || contador==23){
			return 0;
		}else{
			printf("%s\n","El IBAN se compone de 20 digitos numericos o 'ES' y 22 digitos numericos." );
			return 1;
		}
	}else{
		printf("%s\n","El IBAN introducido tiene una logitud indeseada. Recuerda que el IBAN puede tener 20 o 24 caracteres." );
	}
}
// comprueba que la cadena no tenga caracteres 'raros' y pone en mayusculas el primer caracter de cada palabra
int ponerMayusculas(char * cadena){
	int mayuscula = 0;
	int contador = 0;

	if(strlen(cadena)>3){
		if((cadena[0]>=65 && cadena<=90)||(cadena[0]>=97 && cadena<=122)){
			contador++;
			for(int i =1;i<strlen(cadena); i++){
				if((cadena[0]>=65 && cadena<=90)||(cadena[0]>=97 && cadena<=122)|| (cadena==32)){
					contador++;
				}
			}
			// cambio de minusculas a mayusculas
			if(strlen(cadena)==contador){
				cadena[0]=cadena[0]+32;
				for(int i =1;i<strlen(cadena);i++){
					if(cadena[i]==32){//lee donde estan los espacios
						mayusculas= i+1;
					}
					if(i=mayusculas && cadena[i]!=32){//concierte las mayusculas en minusculas
						cadena[i]=cadena[i]+32;
					}
				}
				return =0;
				// si la cadena contiene caracteres raros se devuelve un 1
			}else{
				printf("%s\n","Nose aceptan caraceres raros en las cadenas. Por favor vuelva a introducirlo." );
				return 1;
			}

		}else{
			return 1;
			printf("%s\n","La cadena no puede empezar con un caracter considerado raro o con un espacio." );
			printf("%s\n","Se admiten solo [a-z] y [A-Z]." );
		}
	}else{
		return 1;
	}
}
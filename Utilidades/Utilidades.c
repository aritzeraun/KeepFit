#include <stdio.h>
#include <string.h>
#include "Utilidades.h"

int comprobacionDNI(char *DNI){
	int contador=0;

	if(strlen(DNI)==9){
		for(int i = 0;i<9;i++){

			if(i<8){
				if(DNI[i]>=48 && DNI[i]<58){
					contador++;
				}
			}else{
				if((DNI[i]>=65 && DNI[i]<=90)||(DNI[i]>=97 && DNI[i]<=122)){
					contador++;
					// Pone la letra del DNI en mayusculas si no lo esta
					if((DNI[i]>=97 && DNI[i]<=122)){
						DNI[8]= DNI[8]-32;
					}
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
			tipo =4;
			if(IBAN[0]=='E'){
				contador++;
				if(IBAN[1]=='S'){
					contador++;
					if((IBAN[2]<=57 && IBAN[2]>=48)&&(IBAN[3]<=57 && IBAN[3]>=48)){
						contador= contador+2;
					}
				}else{
					printf("%s\n","El formato del IBAN no es el adecuado." );
					return 1;
				}
			}else{
				printf("%s\n","El formato del IBAN no es el adecuado." );
				return 1;
			}
		}
		for(int i = 0; i<(21+tipo); i++){
			ascii= IBAN[i+tipo];
			if(ascii>=48 && ascii<58){
					contador++;
				}
		}
		if(contador== 20 || contador==24){
			return 0;
		}else{
			printf("%s\n","El IBAN se compone de 20 digitos numericos o 'ES' y 22 digitos numericos." );
			return 1;
		}
	}else{
		printf("%s\n","El IBAN introducido tiene una logitud indeseada. Recuerda que el IBAN puede tener 20 o 24 caracteres." );
		return 1;
	}
}


// comprueba que la cadena no tenga caracteres 'raros' y pone en mayusculas el primer caracter de cada palabra
int ponerMayusculas(char * cadena){
	int mayuscula = 0;
	int contador = 0;

	if(strlen(cadena)>2){
		if((cadena[0]>=65 && cadena[0]<=90)||(cadena[0]>=97 && cadena[0]<=122)){
			contador++;
			for(int i =1;i<strlen(cadena); i++){
				if((cadena[i]>=65 && cadena[i]<=90)||(cadena[i]>=97 && cadena[i]<=122)|| (cadena[i]==32)){
					contador++;
					if((cadena[i]>=65 && cadena[i]<=90)){
						cadena[i] = cadena[i] +32;
					}
				}
			}
			// cambio de minusculas a mayusculas
			if(strlen(cadena)==contador){
				if((cadena[0]>=97 && cadena[0]<=122)){
					cadena[0]=cadena[0]-32;
				}
				for(int i =1;i<strlen(cadena);i++){
					if(cadena[i]==32){//lee donde estan los espacios
						mayuscula= i+1;
					}
					if(i==mayuscula && cadena[i]!=32){//convierte las mayusculas en minusculas
						if((cadena[i]>=97 && cadena[i]<=122)){
							cadena[i]=cadena[i]-32;
						}
					}
				}
				return 0;
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


int comprobacionEmail(char *email){
	int posicionArroba= 0;
	int posicionPunto= 0;

	if(strlen(email)>=6){
		// el primer caracter de un email solo puede pertenecer a estos subconjuntos de caracteres:
		//  [a-z], [A-Z] y [0-9]
		// Comprovacion de usuario
		if((email[0]>=65 && email[0]<=90)||(email[0]>=97 && email[0]<=122)|| (email[0]>=48 && email[0]<=57)){
			for(int i=1;i<(strlen(email)-4);i++){ //minimo para tener el formato deseado
				if((email[i]>=65 && email[i]<=90)||(email[i]>=97 && email[i]<=122)|| (email[i]>=48 && email[i]<=57)){

				}else if (email[i]== 64){
					posicionArroba = i;
				}else{
					printf("%s\n", "El email introducido contiene caracteres raros. Solo se se admiten los siguentes:" );
					printf("%s\n","[a-z], [A-Z] y [0-9]" );
					return 1;
				}
			}
			if(posicionArroba != 0){
				// comprovacion de dominio 'real'
				for (int i=posicionArroba+1;i<(strlen(email)-1);i++) // el menos dos es debido a la raiz de las direcciones
				{  //  [a-z], [A-Z] y [0-9]    por ejemplo se admite el email 123@123.com
					if((email[i]>=65 && email[i]<=90)||(email[i]>=97 && email[i]<=122)|| (email[i]>=48 && email[i]<=57)){

					}else if (email[i]== 46){
						posicionPunto = i;
					}else{
						printf("%s\n", "El email introducido contiene caracteres raros. Solo se se admiten los siguentes:" );
						printf("%s\n","[a-z], [A-Z] y [0-9]" );
						return 1;
					}
				}
				if (posicionPunto != 0){
					for (int i=posicionPunto+1;i<strlen(email)-1;i++){
						if(strlen(email)-(posicionPunto+2)<=3){
							// La raiz solo contiene caracteres en minusculas
							if(email[i]>=97 && email[i]<=122){
							}else{
								printf("%s\n",email[i] );
								printf("%s\n", "La raiz contiene caracteres raros. Solo se se admiten los siguentes: [a-z]" );
								return 1;						}
						}else{
							printf("%s\n", "No se apcentan raices (.es; .eus; .org ...) de más de tres caracteres.");
						}
					}
					return 0;
				}else{
					printf("%s\n", "El email introducido debe incluir un punto entre el dominio y la raiz. Formato: a@a.eus" );
					return 1;
				}
			}else{
				printf("%s\n", "El email introducido debe incluir un arroba. Formato: a@a.eus" );
				return 1;
			}

		}else{
			printf("%s\n", "El email introducido no tiene el formato deseado. Formato: a@a.eus" );
			return 1;
		}

	}else{
		printf("%s\n","El email introducido no tiene ni la longitud ni el formato necesario por un email. " );
		return 1;
	}
}
int comprobacionN_SS(unsigned long long n_ss){

	if(n_ss>=100000000000 && n_ss<=999999999999){
		return 0;
	}else{
		printf("%s\n","El numero de la seguridad social debe tener 12 digitos numericos. Vuelva introducirlo." );
		return 1;
	}

}
int comprobacionSueldo(double sueldo){
	if (sueldo<1187.49){
		printf("%s\n","El convenio sectorial de Euskadi establece que el sueldo minimo mensual debe ser"
			"superior o igual a 1187.49 euros." );
		return 1;
	}else if(sueldo> 5200.75){
		printf("%s\n","Tal y como se acordo en la junta anual de socios, los sueldos corporativos" );
		printf("%s\n", " NO podran superar el umbral de 5200.75 euros en la compania KeepFit SL.");
		return 1;
	}else{
		return 0;
	}

}
int comprobacionHorario (char *horario){

	if(strcmp(horario,"Mananas")==0 || strcmp(horario,"mananas")== 0 ||strcmp(horario,"Manana")==0 ||strcmp(horario,"manana")==0){
		return 2;  //como el horario se guardara en la BD como un numero (para ahorrar espacio y ser mas eficiente), se ha elegido 
		// que las mananas representaran el valor 2
	}else if (strcmp(horario,"Tardes") == 0 || strcmp(horario,"tardes") == 0 ||strcmp(horario,"tarde") == 0 ||strcmp(horario,"Tarde") == 0){
		return 3; //como el horario se guardara en la BD como un numero (para ahorrar espacio y ser mas eficiente), se ha elegido 
		// que las tardes representaran el valor 3
	}else{
		return 1;
	}
} 
int comprobacionFecha(int anyo, int mes, int dia){
	 int limite_dia = 0; // indica los dias que tiene un mes
	 short unsigned int bisiesto = 0;

	if(anyo<2020 || anyo>2050){
				printf("%s\n", "Solo se pueden reguistra fechas entre 2020/1/01 y /2030/12/31");
				return 1;
			}else{
			
				if(mes<1 || mes>12){
					printf("%s\n","Recuerda, los meses son dese 1 a 12." );
					return 1;
				}else{

					if(mes==4 || mes==6 || mes==9 || mes==11 ){
						limite_dia=30;
					}else if(mes==2){
						// si el anyo es multiplo de 4 es bisiesto
						bisiesto= anyo- (anyo/4)*4;
						if(bisiesto ==0){
							limite_dia=29;
						}else{
							limite_dia=28;
						}
					}else{
						limite_dia=31;
					}
					
					if(dia<1 ||dia>limite_dia){
						printf("%s\n", "el dia introducido no corresponde con el mes introducido.");
						return 1;
					}else{
                      return 0; //la fecha introducida tiene el formato correcto
					}
				}
			}
}
int comprobacionPrecio(float precio){
	if(precio<0.0){
		printf("%s\n","El precio de un curso o evento no puede ser negativo. En todo caso puede ser gratuito (precio 0.0 ).");
		return 1;
	}else if (precio>600.00){
		printf("%s\n","El precio de un curso o evento no puede ser superior a 600 euros en nuestro centro. Por favor, vuelva a intentarlo.");
		return 1;
	}else{
		return 0;
	}
}
int comprobacionMetrosCuadrados(int metrosCuadrados){
	if(metrosCuadrados<5){
		printf("%s\n", "Un espacio no puede tener menos de 5 metros cuadrados para considerarse como tal. Por favor, vuelva a intenetarlo:");
		return 1;
	}else if (metrosCuadrados>5000){
		printf("%s\n", "Un espacio no puede tener mas de 5000 metros cuadrados para considerarse como tal. Por favor, vuelva a intenetarlo:");
		return 1;
	}else{
		return 0;
	}
}
int comprobacionCapacidad(int metrosCuadrados, int capacidad){
	// por ley, una ppersona necesita un minimo de 4 metros cuadrados para hacer deporte en un espacio. Por lo tanto, no podremos superar dicho varometro.
	int CAPACIDAD_MAXIMA = metrosCuadrados / 4;
	if(capacidad>CAPACIDAD_MAXIMA){
		printf("%s\n","Por ley no se puede superar el limite de 4 metros cuadrados por persona. Por favor, reduzca la capacidad de personas:" );
		return 1;
	}else{
		return 0;
	}
}

int comprobacionCodCurso(int codcurso){
	// Para usar un sistema de codigo facil de aprender solo es numerico. Se considera que no es posible tener más de 999 cursos distintos.
	if (codcurso >= 1000  || codcurso <= 0 ){
		printf("%s \n", "El codigo introducido debe tener un valor entre 0 y 999");
		return 1;
	}else{
		return 0;
	}
}

int comprobacionPlazasDisp(int plazasDisp){
	// Para crear un evento como mínimo se necesitan tener 5 participantes y el espacio más grande nos permite tener a 20 personas a la vez.
	if (plazasDisp >= 25 || plazasDisp < 5){
		printf("(%s)\n", "Las plazas disponibles deben ser entre 5 y 25 participantes" );
		return 1;
	}else{
		return 0;
	}
}
int comprobacionDiaSemana(char *diaSemana){
	if(strcmp("Lunes",diaSemana) == 0 || strcmp("lunes",diaSemana) == 0 ){
			return 1;
		}else if(strcmp("Martes",diaSemana) == 0 || strcmp("martes",diaSemana) == 0 ){
			return 2;
		}else if(strcmp("Miercoles",diaSemana) == 0 || strcmp("miercoles",diaSemana) == 0 ){
			return 3;
		}else if(strcmp("Jueves",diaSemana) == 0 || strcmp("mjueves",diaSemana) == 0 ){
			return 4;
		}else if(strcmp("Viernes",diaSemana) == 0 || strcmp("viernes",diaSemana) == 0 ){
			return 5;
		}else if(strcmp("Sabado",diaSemana) == 0 || strcmp("sabado",diaSemana) == 0 ){
			return 6;
		}else{
			return -1;
		}
}
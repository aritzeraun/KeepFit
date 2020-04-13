#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Acciones.h"
#include "../ClientesBD/ClientesBD.h"
#include "../EmpleadosBD/EmpleadosBD.h"
#include "../Utilidades/Utilidades.h"
void introducirOmodificar(int tipo, int modulo){

	short unsigned int verificar = 1;
	short unsigned int LIMITE_DNI =9;
	short unsigned int LIMITE_NOMBRE =20;
	short unsigned int LIMITE_APELLIDO = 30;
	short unsigned int LIMITE_DIR = 50;
	short unsigned int LIMITE_CTA = 24;
	short unsigned int LIMITE_EMAIL = 50;
	short unsigned int LIMITE_ESPECIALIDAD = 30;
	short unsigned int LIMITE_CARGO = 30;
	short unsigned int LIMITE_HORARIO = 15;
	// recuerdar el espacio para \0
	char DNIviejo[LIMITE_DNI+1];
	char DNI[LIMITE_DNI+1];
	char nombre[LIMITE_NOMBRE+1];
	char apellido[LIMITE_APELLIDO+1];
	char direccion[LIMITE_DIR+1];
	int TLF = 0;
	char n_cta[LIMITE_CTA +1];
	char email[LIMITE_EMAIL +1];
	unsigned long long n_ss = 0;
	double sueldo = 0.0;
	char especialidad [LIMITE_ESPECIALIDAD+1];
	char cargo[LIMITE_CARGO+1];
	char horario[LIMITE_HORARIO+1];
	int typeHoraio = 0;

	Clientes *arrayClientes;
	Empleados *arrayEmpleados;
	int dimension = 0;

	if(modulo == 0){
		dimension = larguraStatment();
		arrayClientes = (Clientes*) malloc (dimension *sizeof(Clientes));
		seleccionClientes(arrayClientes);
	}else{
		dimension = larguraSentencia();
		arrayEmpleados = (Empleados*) malloc (dimension *sizeof(Empleados));
		seleccionEmpleados(arrayEmpleados);
	}
	if(!(tipo==1 && dimension==0)){
		int posOld= 0;
		// La variable existe, ademas de verificar que el dato introducido ya existe, tambien nos dice a cual de lo objetos pertnece (nos da su posicion)
		int existe = 0; //Cuando el valor introducido no exista su valor sera -1
		if (tipo ==1){
			if(modulo == 0){
				mostrarClientes();
			}else{
				mostrarEmpleados();
			}
			do{
				printf("%s\n","	Introduzca el DNI:" );
				fgets(DNIviejo,LIMITE_DNI+1,stdin);
				fflush(stdin);
				verificar =comprobacionDNI(DNIviejo);
				existe= repetido(DNIviejo, 1,0, modulo);
				if(existe == -1){
					printf("%s\n","El DNI introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
				}
			}while(!(verificar == 0 && existe != -1));
		}
		
		posOld = existe;
		existe = -1;
		// introduccion y modificacion de DNI
		do{
			if(existe != -1){
				printf("%s\n","El DNI introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
			}
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*'\n");
			}
			printf("%s\n","	Introduzca el DNI:" );
			fgets(DNI,LIMITE_DNI+1,stdin);
			fflush(stdin);
			strtok(DNI, "\n");
			if (!(tipo== 1 && strlen(DNI) == 1 && DNI[0] == '*')){
				existe= repetido(DNI, 1,0, modulo);
				verificar =comprobacionDNI(DNI);
			}
		}while((verificar != 0 && existe == -1) && !(tipo== 1 && strlen(DNI) == 1 && DNI[0] == 42));
		
		// introduccion y modificacion de NOMBRE
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el NOMBRE:" );
			fgets(nombre,LIMITE_NOMBRE+1,stdin);
			fflush(stdin);
			strtok(nombre, "\n");
			if (!(tipo== 1 && strlen(nombre) == 1 && nombre[0] == '*')){
				verificar = ponerMayusculas(nombre);
			}
		}while((verificar!=0) && !(tipo== 1 && strlen(nombre) == 1 && nombre[0] == '*'));

		// Se ha decicido que solo se reguistrara el primer apellido.
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el APELLIDO:" );
			fgets(apellido,LIMITE_APELLIDO+1,stdin);
			fflush(stdin);
			strtok(apellido, "\n");
			if (!(tipo== 1 && strlen(apellido) == 1 && apellido[0] == '*')){
				verificar =ponerMayusculas(apellido);
			}	
		}while((verificar !=0) && !(tipo== 1 && strlen(apellido) == 1 && apellido[0] == '*'));

		// direcion de vivienda  habitual
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el DIRECCION DE LA VIVIENDA HABITUAL:" );
			fgets(direccion,LIMITE_DIR +1,stdin);
			fflush(stdin);
			strtok(direccion, "\n");
			if (!(tipo== 1 && strlen(direccion) == 1 && direccion[0] == '*')){
				verificar =ponerMayusculas(direccion);
			}
		}while((verificar !=0) && !(tipo== 1 && strlen(direccion) == 1 && direccion[0] == '*'));

		// telefono
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
			}
			printf("%s\n","	Introduzca el NUMERO DE TELEFONO:" );
			scanf("%i",&TLF);
			fflush(stdin);
			if (!(tipo== 1 && TLF == 0)){
				verificar =comprobacionTLF(TLF);
				existe = repetido("",3,TLF, modulo);
			}	
		}while((verificar !=0 && existe ==-1) && !(tipo== 1 && TLF == 0)) ;

		// numero de cuenta
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el NUMERO DE CUENTA BANCARIA:" );
			fgets(n_cta,LIMITE_CTA+1,stdin);
			fflush(stdin);
			strtok(n_cta, "\n");
			if (!(tipo== 1 && strlen(n_cta) == 1 && n_cta[0] == '*')){
				verificar =comprobacionIBAN(n_cta);
			}		
		}while((verificar !=0) && !(tipo== 1 && strlen(n_cta) == 1 && n_cta[0] == '*'));

		// email
		do{
			if(tipo==1){
					printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
			}
			printf("%s\n","	Introduzca el EMAIL: " );
			fgets(email,LIMITE_EMAIL+1,stdin);
			fflush(stdin);
			strtok(email, "\n");
			if (!(tipo== 1 && strlen(email) == 1 && email[0] == '*')){
				existe = repetido(email, 2,0, modulo);
				verificar =comprobacionEmail(email);
			}	
		}while((verificar !=0 && existe == -1) && !(tipo== 1 && strlen(email) == 1 && email[0] == '*'));

		if (modulo == 0){
			// En el caso de la modificacion, si el usuario introduce un * se mantendra el valor, en el caso contrario, se modificara.
			if(tipo == 1){
				if(DNI[0] == '*'){
					strcpy(DNI, arrayClientes[posOld].DNI);
				}if(nombre[0] == '*'){
					strcpy(nombre, arrayClientes[posOld].nombre);
				}if(apellido[0] == '*'){
					strcpy(apellido, arrayClientes[posOld].apellido);
				}if(direccion[0] == '*'){
					strcpy(direccion, arrayClientes[posOld].direccion);
				}if(TLF == 0){
					TLF=arrayClientes[posOld].tlf;
				}if(n_cta[0] == '*'){
					strcpy(n_cta, arrayClientes[posOld].n_cta);
				}if(email[0] == '*'){
					strcpy(email, arrayClientes[posOld].email);
				}
				eliminacionCliente(DNIviejo); //Se elimina el viejo Cliente
				// Se escribe el cliente con los datos modificados
				Clientes nuevoCliente ={DNI, nombre, apellido, direccion,TLF,n_cta, email};
				reguistrarCliente(nuevoCliente);
			
			}else{
				Clientes nuevoCliente ={DNI, nombre, apellido, direccion,TLF,n_cta, email};
				reguistrarCliente(nuevoCliente);
			}	
			liberarMemoriaClientes(arrayClientes,dimension);
		}else{
			//numero de la seguridad social
			do{
				if(tipo==1){
						printf("%s\n","En el caso de que no desee modificarlo introduzca   '0' \n");
				}
				printf("%s\n","	Introduzca el NUMERO DE LA SEGURIDAD SOCIAL: " );
				scanf("%llu",&n_ss);
				fflush(stdin);
				if (!(tipo== 1 && n_ss == 0)){
					existe = repetido("", 4,n_ss, modulo);
					verificar =comprobacionN_SS(n_ss);
				}	
			}while(!(verificar ==0 && existe == -1) && !(tipo== 1 && n_ss == 0));
			//sueldo
			do{
				if(tipo==1){
						printf("%s\n","En el caso de que no desee modificarlo introduzca   '0.0' \n");
				}
				printf("%s\n","	Introduzca el SUELDO: " );
				scanf("%lf", &sueldo);
				fflush(stdin);
				if (!(tipo== 1 && sueldo == 0.0)){
					verificar =comprobacionSueldo(sueldo);
				}	
			}while(!(verificar ==0) && !(tipo== 1 && sueldo == 0.0));

			// especialidad
			do{
				if(tipo==1){
						printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
				}
				printf("%s\n","	Introduzca la ESPECIALIDAD: " );
				fgets(especialidad,LIMITE_ESPECIALIDAD+1,stdin);
				fflush(stdin);
				strtok(especialidad, "\n");
				if (!(tipo== 1 && strlen(especialidad) == 1 && especialidad[0] == '*')){
					verificar =ponerMayusculas(especialidad);
				}	
			}while((verificar !=0) && !(tipo== 1 && strlen(especialidad) == 1 && especialidad[0] == '*'));
			// cargo
			do{
				if(tipo==1){
						printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
				}
				printf("%s\n","	Introduzca la CARGO: " );
				fgets(cargo,LIMITE_CARGO+1,stdin);
				fflush(stdin);
				strtok(cargo, "\n");
				if (!(tipo== 1 && strlen(cargo) == 1 && cargo[0] == '*')){
					verificar =ponerMayusculas(cargo);
				}	
			}while((verificar !=0) && !(tipo== 1 && strlen(cargo) == 1 && cargo[0] == '*'));

			
			do{
				if(tipo==1){
						printf("%s\n","En el caso de que no desee modificarlo introduzca   '*' \n");
				}
				printf("%s\n","	Introduzca la HORARIO:     ('Mananas' o 'Tardes')" );
				fgets(horario,LIMITE_HORARIO+1,stdin);
				fflush(stdin);
				strtok(horario, "\n");
				if (!(tipo== 1 && strlen(horario) == 1 && horario[0] == '*')){
					verificar =comprobacionHorario(horario);
					typeHoraio =verificar;
				}	
			}while((verificar ==1) && !(tipo== 1 && strlen(horario) == 1 && horario[0] == '*'));


			if(tipo == 1){
				if(DNI[0] == '*'){
					strcpy(DNI, arrayEmpleados[posOld].DNI);
				}if(nombre[0] == '*'){
					strcpy(nombre, arrayEmpleados[posOld].nombre);
				}if(apellido[0] == '*'){
					strcpy(apellido, arrayEmpleados[posOld].apellido);
				}if(direccion[0] == '*'){
					strcpy(direccion, arrayEmpleados[posOld].direccion);
				}if(TLF == 0){
					TLF=arrayEmpleados[posOld].tlf;
				}if(n_cta[0] == '*'){
					strcpy(n_cta, arrayEmpleados[posOld].n_cta);
				}if(email[0] == '*'){
					strcpy(email, arrayEmpleados[posOld].email);
				}if(n_ss == 0){
					n_ss=arrayEmpleados[posOld].n_ss;
				}if(sueldo == 0.0){
					sueldo=arrayEmpleados[posOld].sueldo;
				}if(especialidad[0] == '*'){
					strcpy(especialidad, arrayEmpleados[posOld].especialidad);
				}if(especialidad[0] == '*'){
					strcpy(especialidad, arrayEmpleados[posOld].especialidad);
				}if(cargo[0] == '*'){
					strcpy(cargo, arrayEmpleados[posOld].cargo);
				}if(horario[0] == '*'){
					typeHoraio= arrayEmpleados[posOld].horario;
				}

				eliminacionEmpleado(DNIviejo); //Se elimina el viejo Empleado		
			}
				Empleados nuevoEmpleado ={DNI, nombre, apellido, direccion,TLF,n_cta, email, n_ss, sueldo, especialidad, cargo, typeHoraio};
				reguistrarEmpleado(nuevoEmpleado);	
			liberarMemoriaEmpleados(arrayEmpleados,dimension);

		}
	}else{
		printf("%s\n","No hay objetos reguistrados. Por lo tanto, no se pueden modificar." );
	}
}

int repetido(char *cadena, int tipo,int datoNumerico, int modulo){
	int dimension;
	Clientes *arrayClientes;
	Empleados *arrayEmpleados;

	if(modulo == 0){
		dimension = larguraStatment();
		arrayClientes = (Clientes*) malloc (dimension *sizeof(Clientes));
		seleccionClientes(arrayClientes);
	}else{
		dimension = larguraSentencia();
		arrayEmpleados = (Empleados*) malloc (dimension *sizeof(Empleados));
		seleccionEmpleados(arrayEmpleados);
	}
	char *dni= (char*) malloc (9*sizeof(char));
	char *email =(char*) malloc (50*sizeof(char));
	int telefono = 0;
	short int cmp =1;
	// Para reutilizar codigo, se ddefine como tipo 1 los DNIs y tipo 2 los emails.
	// Dentro de la busqueda secuencial, este es el procedimiento de comparacion que ofrece un gasto de tiempo menor.
	switch (tipo){
		case 1:
			for(int i = 0; i< dimension; i++){ // si se devuelve un 0 es que los DNIs son iguales y, por lo tanto, hay un Cliente reguistrado con el mismo DNI.
				if(modulo == 0){ 
					strcpy(dni,arrayClientes[i].DNI );
				}else{
					strcpy(dni,arrayEmpleados[i].DNI );
				}
				cmp =strcmp(dni , cadena);
				if(cmp == 0){
					return i;
					free(dni);
					dni=NULL;
					break;
				}
			}
		break;
		case 2:  //Comprueba que no haya dos emails iguales
		for(int i = 0; i< dimension; i++){
			if(modulo == 0){ 
					strcpy(email,arrayClientes[i].email);
				}else{
					strcpy(email,arrayEmpleados[i].email );
				}
			cmp =strcmp(email,cadena);
			if(cmp == 0){
				printf("%s\n","El EMAIL introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
				return i;
				free(email);
				email=NULL;
				break;
			}
		}
		break;
		case 3: //Comprueba que no haya dos telefonos iguales
		for(int i = 0; i< dimension; i++){
			if(modulo == 0){ 
					telefono = arrayClientes[i].tlf;
				}else{
					telefono = arrayEmpleados[i].tlf;
				}
			if(telefono == datoNumerico){
				printf("%s\n","El TELEFONO introducido ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
				return i;
				break;
			}
		}
		break;
		case 4: 
		//Comprueba que no haya dos numeros de la seguridad social iguales
		for(int i = 0; i< dimension; i++){
			if(arrayEmpleados[i].n_ss == datoNumerico){
				printf("%s\n","El NUMERO DE LA SEGURIDAD SOCIAL introducida ya ha sido reguistrado  por otro usuario. Vuelve a introducir otro." );
				return i;
				break;
			}
		}
		break;
	}	
	if (cmp != 0){
		return -1;
		free(dni);
		dni=NULL;
		free(email);
		email=NULL;
	}
	if (modulo ==0){
		liberarMemoriaClientes(arrayClientes,dimension);
	}else{
		liberarMemoriaEmpleados(arrayEmpleados,dimension);
	}
	
}
void mostrarClientes(){
	Clientes* arrayClientes;
	int dimension = larguraStatment();
	arrayClientes = (Clientes*) malloc (dimension *sizeof(Clientes));
	seleccionClientes(arrayClientes);
	for (int i = 0; i < dimension; ++i){
		printf("Cliente %i:\n",(i+1));
		printf("   DNI: %s\n",arrayClientes[i].DNI);
		printf("   NOMBRE: %s\n",arrayClientes[i].nombre);
		printf("   APELLIDO: %s\n",arrayClientes[i].apellido);
		printf("   DIRECCION: %s\n",arrayClientes[i].direccion);
		printf("   TELEFONO: %i\n",arrayClientes[i].tlf);
		printf("   CUENTA BANCARIA: %s\n",arrayClientes[i].n_cta);
		printf("   EMAIL: %s\n\n",arrayClientes[i].email);
	}
	liberarMemoriaClientes(arrayClientes,dimension);
}
void mostrarEmpleados(){
	Empleados* arrayEmpleados;
	int dimension = larguraSentencia();
	arrayEmpleados = (Empleados*) malloc (dimension *sizeof(Empleados));
	seleccionEmpleados(arrayEmpleados);
	for (int i = 0; i < dimension; ++i){
		printf("Cliente %i:\n",(i+1));
		printf("   DNI: %s\n",arrayEmpleados[i].DNI);
		printf("   NOMBRE: %s\n",arrayEmpleados[i].nombre);
		printf("   APELLIDO: %s\n",arrayEmpleados[i].apellido);
		printf("   DIRECCION: %s\n",arrayEmpleados[i].direccion);
		printf("   TELEFONO: %i\n",arrayEmpleados[i].tlf);
		printf("   CUENTA BANCARIA: %s\n",arrayEmpleados[i].n_cta);
		printf("   EMAIL: %s\n",arrayEmpleados[i].email);
		printf("   NUMERO DE LA SEGURIDAD SOCIAL: %llu\n",arrayEmpleados[i].n_ss);
		printf("   SALARIO: %lf \n",arrayEmpleados[i].sueldo);
		printf("   ESPECIALIDAD: %s\n",arrayEmpleados[i].especialidad);
		printf("   CARGO: %s\n",arrayEmpleados[i].cargo);
		if(arrayEmpleados[i].horario == 2){
			printf("   HORARIO: %s\n\n","Mananas");
		}else{
			printf("   HORARIO: %s\n\n","Tardes");
		}
	}
	liberarMemoriaEmpleados(arrayEmpleados,dimension);
}
void borrar(int modulo){
	int existe = 0;
	int verificar;
	int LIMITE_DNI = 9;
	char DNI[LIMITE_DNI+1];
	int longitud=0;
	if(modulo == 0){
		longitud = larguraStatment();
	}else{
		longitud = larguraSentencia();
	}

	if(longitud != 0){
		do{
		printf("%s\n","	Introduzca el DNI:" );
		fgets(DNI,LIMITE_DNI+1,stdin);
		fflush(stdin);
		strtok(DNI, "\n");
		verificar =comprobacionDNI(DNI);
		existe= repetido(DNI, 1,0, modulo);
		if(existe == -1){
			printf("%s\n","El DNI introducido NO esta reguistrado en la Base de Datos. Vuelve a introducir otro." );
		}
		}while(verificar == 1 || existe == -1);

		if(modulo ==0){
			eliminacionCliente(DNI);
		}else{
			eliminacionEmpleado(DNI);
		}

		printf("\n %s\n\n","La eliminacion se ha efectuado correrctamente." );
	}else{
		printf("%s\n","No hay ningun objeto reguistrado. Por lo tanto, no se puede efectuar la eliminacion." );
	}
}
void liberarMemoriaClientes(Clientes* arrayClientes, int dimension){
	for(int i = 0; i<dimension; i++){
		free(arrayClientes[i].DNI);
		arrayClientes[i].DNI = NULL;
		free(arrayClientes[i].nombre);
		arrayClientes[i].nombre = NULL;		
		free(arrayClientes[i].apellido);
		arrayClientes[i].apellido = NULL;
		free(arrayClientes[i].direccion);
		arrayClientes[i].direccion = NULL;
		free(arrayClientes[i].n_cta);
		arrayClientes[i].n_cta = NULL;
		free(arrayClientes[i].email);
		arrayClientes[i].email = NULL;

		free(arrayClientes);
		arrayClientes== NULL;
	}
}

void liberarMemoriaEmpleados(Empleados* arrayEmpleados, int dimension){
	for(int i = 0; i<dimension; i++){
		free(arrayEmpleados[i].DNI);
		arrayEmpleados[i].DNI = NULL;
		free(arrayEmpleados[i].nombre);
		arrayEmpleados[i].nombre = NULL;		
		free(arrayEmpleados[i].apellido);
		arrayEmpleados[i].apellido = NULL;
		free(arrayEmpleados[i].direccion);
		arrayEmpleados[i].direccion = NULL;
		free(arrayEmpleados[i].n_cta);
		arrayEmpleados[i].n_cta = NULL;
		free(arrayEmpleados[i].email);
		arrayEmpleados[i].email = NULL;
		free(arrayEmpleados[i].especialidad);
		arrayEmpleados[i].especialidad = NULL;
		free(arrayEmpleados[i].cargo);
		arrayEmpleados[i].cargo = NULL;

		free(arrayEmpleados);
		arrayEmpleados== NULL;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "../Sqlite3/sqlite3.h"

sqlite3* conexion(){
   sqlite3 *db;
   int e = sqlite3_open("database.db", &db);
   if( e) {
      fprintf(stderr, "Se ha producido un error en la conexion con la BD. %s\n", sqlite3_errmsg(db));
   }
    return db;
}
void crearTablaClientes(){
   sqlite3 *db = conexion();
   char *mensageError;
   int e= sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS Clientes"
      "(DNI varchar(9)  primary key not null,"
      "nombre   varchar(20)  not null,"
      "apellido varchar(30)  not null,"
      "direccion varchar(50),"
      "tlf integer not null,"
      "email varchar(50),"
     " n_cta varchar(20));" ,0,0,&mensageError); 

   if(e){
      fprintf(stderr,"No se ha podido crear la tabla CLIENTES.%s\n", sqlite3_errmsg(db));
   } 
   sqlite3_close(db); 
}
void reguistrarCliente(Clientes newCli){
	   sqlite3 *db = conexion();
      char *mensageError;
      char *sql ;
      sprintf(sql,"INSERT INTO Clientes VALUES('%s','%s','%s','%s',%i,'%s','%s');",newCli.DNI, newCli.nombre,newCli.apellido, newCli.direccion, newCli.tlf, newCli.email, newCli.n_cta);
      int e = sqlite3_exec(db,sql,0,0,&mensageError);
   sqlite3_close(db);
}

void eliminacionCliente(Clientes newCli){
      sqlite3 *db = conexion();
      char *mensageError;
      char *sql ;
      sprintf(sql,"DELETE FROM Clientes WHERE DNI ='%s';", newCli.DNI);
      int e = sqlite3_exec(db,sql,0,0,&mensageError);
      if (e != SQLITE_OK ) {
           fprintf(stderr, "SQL error: %s\n", mensageError);
         }
   sqlite3_close(db);
}
 int larguraStatment(){
      sqlite3 *db = conexion();
      sqlite3_stmt *stmt;
      int length=0;
   
      sqlite3_prepare_v2(db,"SELECT * FROM Clientes;", -1, &stmt, NULL);
      while (sqlite3_step(stmt) != SQLITE_DONE) {
         length++;
      }
      sqlite3_close(db);
      return length;
 }
int charToNumber(char * cadena){
   int number=0;
   for(int i=0;i<strlen(cadena);i++){
      number = number *10 + cadena[i]-48;
   }
}

Clientes* seleccionClientes(Clientes arrayLectura[]){
      sqlite3 *db = conexion();
      sqlite3_stmt *stmt;
      int i =0;
      char *mensageError;
      char *DNI;
      char *nombre;
      char *apellido;
      char *direccion;
      char *tlf;
      char *n_cta;
      char *email;    
    sqlite3_prepare_v2(db,"SELECT * FROM Clientes;", -1, &stmt, NULL);
      while (sqlite3_step(stmt) != SQLITE_DONE) {
         char * DNIe;
         DNI =(char*) sqlite3_column_text(stmt, 0);
         strcpy(DNIe,DNI);
         (arrayLectura+i)->DNI = DNIe;
         nombre =(char*) sqlite3_column_text(stmt, 1);
         arrayLectura[i].nombre = nombre;
         apellido = (char*)sqlite3_column_text(stmt, 2);
         arrayLectura[i].apellido = apellido;
         direccion = (char*)sqlite3_column_text(stmt, 3);
         arrayLectura[i].direccion = direccion;
         tlf = (char*)sqlite3_column_text(stmt, 4);
         arrayLectura[i].tlf = charToNumber(tlf);
         n_cta = (char*) sqlite3_column_text(stmt, 5);
         arrayLectura[i].n_cta = n_cta;
         email = (char*) sqlite3_column_text(stmt, 6);
         arrayLectura[i].email= email;
         i++;
   
      }
      sqlite3_close(db);
        return arrayLectura;
}

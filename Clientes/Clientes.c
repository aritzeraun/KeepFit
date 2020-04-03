#include <stdio.h>
#include "Clientes.h"
#include "sqlite3.h"

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
   int e= sqlite3_exec(db,"CREATE TABLE IF NOT EXIST Clientes"
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
      sprintf(sql,"INSERT INTO Clientes VALUES('%s','%s','%s','%s',%i,'%s','%s');",newCli.DNI, newCli.nombre,
      newCli.apellido, newCli.direccion, newCli.tlf, newCli.email, newCli.n_cta);
      int e = sqlite3_exec(db,sql,0,0,&mensageError);
      if (e != SQLITE_OK ) {
           fprintf(stderr, "SQL error: %s\n", mensageError);
         }
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

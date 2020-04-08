#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClientesBD.h"
#include "../Clientes/Clientes.h"
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

void eliminacionCliente(char *DNI){
      sqlite3 *db = conexion();
      char *mensageError;
      char *sql ;
      sprintf(sql,"DELETE FROM Clientes WHERE DNI ='%s';",DNI);
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

void seleccionClientes(Clientes arrayLectura[]){
      sqlite3 *db = conexion();
      int tlf;
      sqlite3_stmt *stmt;
      int i =0;  
      sqlite3_prepare_v2(db,"SELECT * FROM Clientes;", -1, &stmt, NULL);

      while (sqlite3_step(stmt) != SQLITE_DONE) {
        arrayLectura[i].DNI =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 0))+1)*sizeof(char));
         strcpy((arrayLectura[i]).DNI,(char*) sqlite3_column_text(stmt, 0));
         arrayLectura[i].nombre =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 1))+1)*sizeof(char));
         strcpy((arrayLectura[i]).nombre,(char*) sqlite3_column_text(stmt, 1));
         arrayLectura[i].apellido =(char*)malloc((strlen((char*) sqlite3_column_text(stmt,2))+1)*sizeof(char));
         strcpy((arrayLectura[i]).apellido,(char*) sqlite3_column_text(stmt, 2));
         arrayLectura[i].direccion =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 3))+1)*sizeof(char));
         strcpy((arrayLectura[i]).direccion,(char*) sqlite3_column_text(stmt, 3));
         tlf= (int) sqlite3_column_int(stmt, 4);
         arrayLectura[i].tlf =(int) malloc(1*sizeof(int));
          arrayLectura[i].tlf = tlf;
         arrayLectura[i].n_cta =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 5))+1)*sizeof(char));
         strcpy((arrayLectura[i]).n_cta,(char*) sqlite3_column_text(stmt, 5));
          arrayLectura[i].email =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 6))+1)*sizeof(char));
         strcpy((arrayLectura[i]).email,(char*) sqlite3_column_text(stmt, 6));
         i++;
      }
      sqlite3_close(db);
}

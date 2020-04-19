#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EspaciosBD.h"
#include "../Sqlite3/sqlite3.h"

sqlite3* conexion(){
   sqlite3 *db;
   int e = sqlite3_open("database.db", &db);
   if( e) {
      fprintf(stderr, "Se ha producido un error en la conexion con la BD. %s\n", sqlite3_errmsg(db));
   }
    return db;
}
void crearTablaEspacios(){
   sqlite3 *db = conexion();
   char *mensageError;
   int e= sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS Espacios"
      "(codigo varchar(9)  primary key not null,"
      "nombre   varchar(20)  not null,"
      "metrosCuadrados integer  not null,"
      "capacidad integer not null,"
     " descripcion varchar(50));" ,0,0,&mensageError); 

   if(e){
      fprintf(stderr,"No se ha podido crear la tabla ESPACIOS.%s\n", sqlite3_errmsg(db));
   } 
   sqlite3_close(db); 
}
void reguistrarEspacio(Espacios newEsp){
	   sqlite3 *db = conexion();
       char* sql="INSERT INTO Espacios VALUES(?,?,?,?,?,?,?);";
       sqlite3_stmt *stmt;
       sqlite3_prepare_v2(db,sql,-1,&stmt,0);
       sqlite3_bind_text(stmt,1,newEsp.codigo,strlen(newEsp.codigo),SQLITE_STATIC);
       sqlite3_bind_text(stmt,2,newEsp.nombre,strlen(newEsp.nombre),SQLITE_STATIC);
       sqlite3_bind_int(stmt,3,newEsp.metrosCuadrados);
       sqlite3_bind_int(stmt,4,newEsp.capacidad);
       sqlite3_bind_text(stmt,5,newEsp.descripcion,strlen(newEsp.descripcion),SQLITE_STATIC);
       sqlite3_step(stmt);    
   sqlite3_close(db);
}

void eliminacionEspacio(char *codigo){
      sqlite3 *db = conexion();
      char *sql  = "DELETE FROM Espacios WHERE codigo =?;";
      sqlite3_stmt *stmt;
       sqlite3_prepare_v2(db,sql,-1,&stmt,0);
       sqlite3_bind_text(stmt,1,codigo,strlen(codigo),SQLITE_STATIC);  
      sqlite3_step(stmt);   
   sqlite3_close(db);
}
 int larguraEspacios(){
      sqlite3 *db = conexion();
      sqlite3_stmt *stmt;
      int length=0;
   
      sqlite3_prepare_v2(db,"SELECT * FROM Espacios;", -1, &stmt, NULL);
      while (sqlite3_step(stmt) != SQLITE_DONE) {
         length++;
      }
      sqlite3_close(db);
      return length;
 }

void seleccionEspacios(Espacios arrayLectura[]){
      sqlite3 *db = conexion();
      int i = 0;
      sqlite3_stmt *stmt;
      sqlite3_prepare_v2(db,"SELECT * FROM Espacios;", -1, &stmt, NULL);

      while (sqlite3_step(stmt) != SQLITE_DONE) {
        arrayLectura[i].codigo =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 0))+1)*sizeof(char));
         strcpy((arrayLectura[i]).codigo,(char*) sqlite3_column_text(stmt, 0));
         arrayLectura[i].nombre =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 1))+1)*sizeof(char));
         strcpy((arrayLectura[i]).nombre,(char*) sqlite3_column_text(stmt, 1));
          arrayLectura[i].metrosCuadrados =(int) sqlite3_column_int(stmt, 4);
          arrayLectura[i].capacidad =(int) sqlite3_column_int(stmt, 4);
         arrayLectura[i].descripcion =(char*)malloc((strlen((char*) sqlite3_column_text(stmt,4))+1)*sizeof(char));
         strcpy((arrayLectura[i]).descripcion,(char*) sqlite3_column_text(stmt, 4));
         i++;
      }
      sqlite3_close(db);
}

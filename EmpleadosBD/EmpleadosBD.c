#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EmpleadosBD.h"
#include "../Sqlite3/sqlite3.h"

sqlite3* conexionE(){
   sqlite3 *db;
   int e = sqlite3_open("database.db", &db);
   if( e) {
      fprintf(stderr, "Se ha producido un error en la conexion con la BD. %s\n", sqlite3_errmsg(db));
   }
    return db;
}
void crearTablaEmpleados(){
   sqlite3 *db = conexionE();
   char *mensageError;
   int e= sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS Empleados"
      "(DNI varchar(9)  primary key not null,"
      "nombre   varchar(20)  not null,"
      "apellido varchar(30)  not null,"
      "direccion varchar(50) not null,"
      "tlf integer not null,"
      "n_cta varchar(20) not null,"
     " email varchar(50) not null,"
     "n_ss integer(12)not null,"
     "sueldo real not null,"
     "especialidad varchar(30) not null,"
     "cargo varchar(30) not null,"
     "horario integer(1) not null);" ,0,0,&mensageError); 

   if(e){
      fprintf(stderr,"No se ha podido crear la tabla CLIENTES.%s\n", sqlite3_errmsg(db));
   } 
   sqlite3_close(db); 
}
void reguistrarEmpleado(Empleados newEmp){
	   sqlite3 *db = conexionE();
       char* sql="INSERT INTO Empleados VALUES(?,?,?,?,?,?,?,?,?,?,?,?);";
       sqlite3_stmt *stmt;
       sqlite3_prepare_v2(db,sql,-1,&stmt,0);
       sqlite3_bind_text(stmt,1,newEmp.DNI,strlen(newEmp.DNI),SQLITE_STATIC);
       sqlite3_bind_text(stmt,2,newEmp.nombre,strlen(newEmp.nombre),SQLITE_STATIC);
       sqlite3_bind_text(stmt,3,newEmp.apellido,strlen(newEmp.apellido),SQLITE_STATIC);
       sqlite3_bind_text(stmt,4,newEmp.direccion,strlen(newEmp.direccion),SQLITE_STATIC);
       sqlite3_bind_int(stmt,5,newEmp.tlf);
       sqlite3_bind_text(stmt,6,newEmp.n_cta,strlen(newEmp.n_cta),SQLITE_STATIC);
       sqlite3_bind_text(stmt,7,newEmp.email,strlen(newEmp.email),SQLITE_STATIC);
       sqlite3_bind_int64(stmt,8,newEmp.n_ss);
       sqlite3_bind_double(stmt,9,newEmp.sueldo);
       sqlite3_bind_text(stmt,10,newEmp.especialidad,strlen(newEmp.especialidad),SQLITE_STATIC);
       sqlite3_bind_text(stmt,11,newEmp.cargo,strlen(newEmp.cargo),SQLITE_STATIC);
       sqlite3_bind_int(stmt,12,newEmp.horario);
       sqlite3_step(stmt);    
   sqlite3_close(db);
}

void eliminacionEmpleado(char *DNI){
      sqlite3 *db = conexionE();
      char *sql  = "DELETE FROM Empleados WHERE DNI=?;";
      sqlite3_stmt *stmt;
       sqlite3_prepare_v2(db,sql,-1,&stmt,0);
       sqlite3_bind_text(stmt,1,DNI,strlen(DNI),SQLITE_STATIC);  
       sqlite3_step(stmt); 
   sqlite3_close(db);
}
 int larguraSentencia(){
      sqlite3 *db = conexionE();
      sqlite3_stmt *stmt;
      int length=0;
   
      sqlite3_prepare_v2(db,"SELECT * FROM Empleados", -1, &stmt, NULL);
      while (sqlite3_step(stmt) != SQLITE_DONE) {
         length++;
      }
      sqlite3_close(db);
      return length;
 }

void seleccionEmpleados(Empleados arrayLectura[]){
      sqlite3 *db = conexionE();
      sqlite3_stmt *stmt; 
      int i = 0;
      double n_ss;
      sqlite3_prepare_v2(db,"SELECT * FROM Empleados;", -1, &stmt, NULL);

      while (sqlite3_step(stmt) != SQLITE_DONE) {
        arrayLectura[i].DNI =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 0))+1)*sizeof(char));
        strcpy((arrayLectura[i]).DNI,(char*) sqlite3_column_text(stmt, 0));
        arrayLectura[i].nombre =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 1))+1)*sizeof(char));
        strcpy((arrayLectura[i]).nombre,(char*) sqlite3_column_text(stmt, 1));
        arrayLectura[i].apellido =(char*)malloc((strlen((char*) sqlite3_column_text(stmt,2))+1)*sizeof(char));
        strcpy((arrayLectura[i]).apellido,(char*) sqlite3_column_text(stmt, 2));
        arrayLectura[i].direccion =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 3))+1)*sizeof(char));
        strcpy((arrayLectura[i]).direccion,(char*) sqlite3_column_text(stmt, 3));
        arrayLectura[i].tlf = (int) sqlite3_column_int(stmt, 4);
        arrayLectura[i].n_cta =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 5))+1)*sizeof(char));
        strcpy((arrayLectura[i]).n_cta,(char*) sqlite3_column_text(stmt, 5));
        arrayLectura[i].email =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 6))+1)*sizeof(char));
        strcpy((arrayLectura[i]).email,(char*) sqlite3_column_text(stmt, 6));
        arrayLectura[i].n_ss= (int) sqlite3_column_int64(stmt, 7);
        arrayLectura[i].sueldo= (double) sqlite3_column_double(stmt, 8);
        arrayLectura[i].especialidad =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 9))+1)*sizeof(char));
        strcpy((arrayLectura[i]).especialidad,(char*) sqlite3_column_text(stmt, 9));
        arrayLectura[i].cargo =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 10))+1)*sizeof(char));
        strcpy((arrayLectura[i]).cargo,(char*) sqlite3_column_text(stmt, 10));
        arrayLectura[i].horario= (int) sqlite3_column_int(stmt, 11);
        i++;
      }
      sqlite3_close(db);
}

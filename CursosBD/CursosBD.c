#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursosBD.h"
#include "../Cursos/Cursos.h"
#include "../Sqlite3/sqlite3.h"

sqlite3* conexionCursos(){
   sqlite3 *db;
   int e = sqlite3_open("database.db", &db);
   if( e) {
      fprintf(stderr, "Se ha producido un error en la conexion con la BD. %s\n", sqlite3_errmsg(db));
   }
    return db;
}
void crearTablaCursos(){
   sqlite3 *db = conexionCursos();
   char *mensageError;
   int e= sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS Cursos"
      "(codigo integer  primary key not null,"
      "nombre   varchar(20)  not null,"
      "anyoInicio integer  not null,"
      "mesInicio integer not null,"
      "diaInicio integer not null,"
      "anyoFin integer  not null,"
      "mesFin integer not null,"
      "diaFin integer not null,"
      "plazas integer  not null,"
      "diaSemana integer not null,"
      "hora integer not null,"
     " DNI varchar(9));" ,0,0,&mensageError); 
   if(e){
      fprintf(stderr,"No se ha podido crear la tabla Cursos.%s\n", sqlite3_errmsg(db));
   } 
   sqlite3_close(db); 
}
void reguistrarCursos(Cursos newCurso){
	   sqlite3 *db = conexionCursos();
       char* sql="INSERT INTO Cursos VALUES(?,?,?,?,?,?,?,?,?,?,?,?);";
       sqlite3_stmt *stmt;
       sqlite3_prepare_v2(db,sql,-1,&stmt,0);
       sqlite3_bind_int(stmt,1,newCurso.codigo);
       sqlite3_bind_text(stmt,2,newCurso.nombre,strlen(newCurso.nombre),SQLITE_STATIC);
       sqlite3_bind_int(stmt,3,newCurso.anyoInicio);
       sqlite3_bind_int(stmt,4,newCurso.mesInicio);
       sqlite3_bind_int(stmt,5,newCurso.diaInicio);
       sqlite3_bind_int(stmt,6,newCurso.anyoFin);
       sqlite3_bind_int(stmt,7,newCurso.mesFin);
       sqlite3_bind_int(stmt,8,newCurso.diaFin);
       sqlite3_bind_int(stmt,9,newCurso.plazas);
       sqlite3_bind_int(stmt,10,newCurso.diaSemana);
       sqlite3_bind_int(stmt,11,newCurso.hora);
       sqlite3_bind_text(stmt,12,newCurso.DNI,strlen(newCurso.DNI),SQLITE_STATIC);
       sqlite3_step(stmt);    
   sqlite3_close(db);
}

void eliminacionCurso(int codigo){
      sqlite3 *db = conexionCursos();
      char *sql  = "DELETE FROM Cursos WHERE DNI =?;";
      sqlite3_stmt *stmt;
       sqlite3_prepare_v2(db,sql,-1,&stmt,0);
       sqlite3_bind_int(stmt,1,codigo);
      sqlite3_step(stmt);   
   sqlite3_close(db);
}
 int larguraCursos(){
      sqlite3 *db = conexionCursos();
      sqlite3_stmt *stmt;
      int length=0;
   
      sqlite3_prepare_v2(db,"SELECT * FROM Cursos;", -1, &stmt, NULL);
      while (sqlite3_step(stmt) != SQLITE_DONE) {
         length++;
      }
      sqlite3_close(db);
      return length;
 }

void seleccionCursos(Cursos arrayLectura[]){
      sqlite3 *db = conexionCursos();
      int i = 0;
      sqlite3_stmt *stmt;
      sqlite3_prepare_v2(db,"SELECT * FROM Cursos;", -1, &stmt, NULL);

      while (sqlite3_step(stmt) != SQLITE_DONE) {
        arrayLectura[i].codigo=(int) sqlite3_column_int(stmt, 0);
        arrayLectura[i].nombre =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 1))+1)*sizeof(char));
        strcpy((arrayLectura[i]).nombre,(char*) sqlite3_column_text(stmt, 1));
        arrayLectura[i].anyoInicio =(int) sqlite3_column_int(stmt, 2);
        arrayLectura[i].mesInicio =(int) sqlite3_column_int(stmt, 3);
        arrayLectura[i].diaInicio =(int) sqlite3_column_int(stmt, 4);
        arrayLectura[i].anyoFin =(int) sqlite3_column_int(stmt, 5);
        arrayLectura[i].mesFin =(int) sqlite3_column_int(stmt, 6);
        arrayLectura[i].diaFin =(int) sqlite3_column_int(stmt, 7);
        arrayLectura[i].plazas =(int) sqlite3_column_int(stmt, 8);
        arrayLectura[i].diaSemana=(int) sqlite3_column_int(stmt, 9);
        arrayLectura[i].hora=(int) sqlite3_column_int(stmt, 10);
        arrayLectura[i].DNI =(char*)malloc((strlen((char*) sqlite3_column_text(stmt, 11))+1)*sizeof(char));
        strcpy((arrayLectura[i]).DNI,(char*) sqlite3_column_text(stmt, 11));
        i++;
      }
      sqlite3_close(db);
}

#include <stdio.h>
#include "Clientes.h"
#include "sqlite3.h"

void reguistrarCliente(Clientes nuevo_cli){
	  sqlite3 *db;
   char *zErrMsg = 0;
   int rc = sqlite3_open("database.db", &db);
   rc= sqlite3_exec(db,"INSERT INTO ejemplo VALUES(1,'iepa');",0,0,&zErrMsg);
   if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
      }

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_close(db);
}

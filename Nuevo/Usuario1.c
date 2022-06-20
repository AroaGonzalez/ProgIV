#include "Usuario1.h"
#include <string.h>
#include "sqlite3.h"
#include <stdio.h>

void generarUsuario(Usuario1* u, char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya)
{
    strcpy(u->nombre, nombre);
    strcpy(u->apellido, apellido);
    strcpy(u->fNac, fNac);
    strcpy(u->genero, genero);
    strcpy(u->DNI, DNI);
    strcpy(u->direccion, direccion);
    strcpy(u->tel, tel);
    strcpy(u->nombreUsuario, nombreUsuario);
    strcpy(u->contrasenya, contrasenya);
}

int comparaUsuario(char* nombreUsuario, char* contrasenya) 
{

    sqlite3* db;
    char* err_msg = 0;
    sqlite3_stmt* res;

    int rc = sqlite3_open("../data.db", &db); //CAMBIAR NOMBRE DB

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char sql[100] = "SELECT nombreUsuario, Contrasenya FROM Usuario WHERE nombreUsuario = '";
    strcat(sql, nombreUsuario);
    strcat(sql, "'");

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK) {

        sqlite3_bind_int(res, 1, 3);
    }
    else {

        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    int comp = 1;

    if (step == SQLITE_ROW) {

        comp = strcmp(nombreUsuario, sqlite3_column_text(res, 0));
        comp += strcmp(contrasenya, sqlite3_column_text(res, 1));
    } 

    sqlite3_finalize(res);
    sqlite3_close(db);

    if (comp != 0) {
        return 1;
    }

    return 0;
}




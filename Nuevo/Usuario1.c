#include "Usuario1.h"
#include <string.h>
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

void generarUsuario(Usuario1 *u, char *nombre, char *apellido, char *fNac, char *genero, char *DNI, char *tel, char *direccion, char *nombreUsuario, char *contrasenya)
{
    u->nombre = (char *)malloc(sizeof(char) * strlen(nombre) + 1);
    strcpy(u->nombre, nombre);
    u->apellido = (char *)malloc(sizeof(char) * strlen(apellido) + 1);
    strcpy(u->apellido, apellido);
    u->fNac = (char *)malloc(sizeof(char) * strlen(fNac) + 1);
    strcpy(u->fNac, fNac);
    u->genero = (char *)malloc(sizeof(char) * strlen(genero) + 1);
    strcpy(u->genero, genero);
    u->DNI = (char *)malloc(sizeof(char) * strlen(DNI) + 1);
    strcpy(u->DNI, DNI);
    u->direccion = (char *)malloc(sizeof(char) * strlen(direccion) + 1);
    strcpy(u->direccion, direccion);
    u->tel = (char *)malloc(sizeof(char) * strlen(tel) + 1);
    strcpy(u->tel, tel);
    u->nombreUsuario = (char *)malloc(sizeof(char) * strlen(nombreUsuario) + 1);
    strcpy(u->nombreUsuario, nombreUsuario);
    u->contrasenya = (char *)malloc(sizeof(char) * strlen(contrasenya) + 1);
    strcpy(u->contrasenya, contrasenya);
}

int comparaUsuario(char *nombreUsuario, char *contrasenya)
{

    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;

    int rc = sqlite3_open("Polideportivo.db", &db);

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char sql[200] = "SELECT nombreUsuario, Contrasenya FROM Usuario WHERE nombreUsuario = '";
    strcat(sql, nombreUsuario);
    strcat(sql, "';");

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {

        sqlite3_bind_int(res, 1, 3);
    }
    else
    {

        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    int comp = 0;

    if (step == SQLITE_ROW)
    {

        comp = strcmp(nombreUsuario, sqlite3_column_text(res, 0));
        comp += strcmp(contrasenya, sqlite3_column_text(res, 1));
    }

    sqlite3_finalize(res);
    sqlite3_close(db);

    // if (comp != 0) {
    //     return 1;
    // }

    return 0;
}

int anyadirUsuario(Usuario1 u)
{
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("Polideportivo.db", &db); // CAMBIAR NOMBRE DB

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char sql[100] = "INSERT INTO Usuario VALUES('";
    strcat(sql, u.nombre);
    strcat(sql, "', '");
    strcat(sql, u.apellido);
    strcat(sql, "', '");
    strcat(sql, u.fNac);
    strcat(sql, "', '");
    strcat(sql, u.genero);
    strcat(sql, "', '");
    strcat(sql, u.DNI);
    strcat(sql, "', '");
    strcat(sql, u.direccion);
    strcat(sql, "', '");
    strcat(sql, u.tel);
    strcat(sql, "', '");
    strcat(sql, u.nombreUsuario);
    strcat(sql, "', '");
    strcat(sql, u.contrasenya);
    strcat(sql, "');");

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    return 0;
}

void liberarUsuario(Usuario1 *usu1)
{

    free(usu1->apellido);
    free(usu1->contrasenya);
    free(usu1->direccion);
    free(usu1->DNI);
    free(usu1->fNac);
    free(usu1->genero);
    free(usu1->nombre);
    free(usu1->nombreUsuario);
    free(usu1->tel);
}
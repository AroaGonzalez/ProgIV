#include "polideportivo.h"
#include <stdio.h>
#include <string.h>
#include "sqlite3.h"

void generarPoli(Polideportivo *p, char *ref, char *nombre, char *instalaciones, char *direccion, char *municipio, char *codMunicipio, char *provincia, char *codProv, char *tel)
{
    strcpy(p->ref, ref);
    strcpy(p->nombre, nombre);
    strcpy(p->instalaciones, instalaciones);
    strcpy(p->direccion, direccion);
    strcpy(p->municipio, municipio);
    strcpy(p->codMunicipio, codMunicipio);
    strcpy(p->provincia, provincia);
    strcpy(p->codProv, codProv);
    strcpy(p->tel, tel);
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{

    NotUsed = 0;

    for (int i = 0; i < argc; i++)
    {

        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}

int visualizarPoli()
{
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("Polideportivo.db", &db); // CAMBIAR NOMBRE DB

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Cannot open database: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT * FROM Polideportivo";

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    return 0;
}

int poliPorMunicipio(char *municipio)
{
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("Polideportivo.db", &db); // CAMBIAR NOMBRE DB

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Cannot open database: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char sql[100] = "SELECT * FROM Polideportivo WHERE municipio LIKE '";
    strcat(sql, municipio);
    strcat(sql, "%'");

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    return 0;
}

int anyadirPoli(char *ref, char *nombre, char *instalaciones, char *direccion, char *municipio, char *codMunicipio, char *provincia, char *codProv, char *tel)
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

    char sql[100] = "INSERT INTO Polideportivo VALUES('";
    strcat(sql, ref);
    strcat(sql, "', '");
    strcat(sql, nombre);
    strcat(sql, "', '");
    strcat(sql, instalaciones);
    strcat(sql, "', '");
    strcat(sql, direccion);
    strcat(sql, "', '");
    strcat(sql, municipio);
    strcat(sql, "', '");
    strcat(sql, codMunicipio);
    strcat(sql, "', '");
    strcat(sql, provincia);
    strcat(sql, "', '");
    strcat(sql, codProv);
    strcat(sql, "', '");
    strcat(sql, tel);
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

int editarPoli(char *nombrePoli, char *ref, char *nombre, char *instalaciones, char *direccion, char *municipio, char *codMunicipio, char *provincia, char *codProv, char *tel)
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

    char sql[100] = "UPDATE Polideportivo SET ref = '";
    strcat(sql, ref);
    strcat(sql, "', nombre = '");
    strcat(sql, nombre);
    strcat(sql, "', instalaciones = '");
    strcat(sql, instalaciones);
    strcat(sql, "', direccion = '");
    strcat(sql, direccion);
    strcat(sql, "', municipio = '");
    strcat(sql, municipio);
    strcat(sql, "', codMunicipio = '");
    strcat(sql, codMunicipio);
    strcat(sql, "', provincia = '");
    strcat(sql, provincia);
    strcat(sql, "', codProvincia = '");
    strcat(sql, codProv);
    strcat(sql, "', tel = '");
    strcat(sql, tel);
    strcat(sql, "' where nombre = '");
    strcat(sql, nombrePoli);
    strcat(sql, "';");

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

int deletePoli(char *nombre)
{
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("Polideportivo.db", &db); // CAMBIAR NOMBRE DB

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Cannot open database: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char sql[100] = "DELETE FROM Polideportivo Where nombre = '";
    strcat(sql, nombre);
    strcat(sql, "';");

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    return 0;
}

int deleteDB()
{
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("Polideportivo.db", &db); // CAMBIAR NOMBRE

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "DROP TABLE IF EXISTS Polideportivo;";

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

int crearBase()
{

    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("Polideportivo.db", &db);

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "DROP TABLE IF EXISTS Usuario;"
                "create table Usuario(Nombre TEXT, Apellidos TEXT, Fecha TEXT, Genero TEXT, DNI TEXT, Direccion TEXT, Tel TEXT, nombreUsuario TEXT, Contrasenya TEXT);"
                "INSERT into Usuario values ('Begoña', 'Suarez', '2000', 'F', '12345678C', 'Menendez y Pelayo 22', '633707221', 'anacardo18', 'pepitoje');"
                "INSERT into Usuario values ('Vicccctor', 'Bilbao', '2000', 'M', '12345678C', 'Don quijote 3', '631234567', 'Vikturski', 'pepino123');"
                "INSERT into Usuario values ('Aitttor', 'Guayo', '2002', 'M', '12345678C', 'San Juan 23', '633987543', 'aitorrcio', '12473c');";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {

        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sql = "DROP TABLE IF EXISTS Polideportivo;"
          "create table Polideportivo(ref TEXT, nombre TEXT, instalaciones TEXT, direccion TEXT, municipio TEXT, codMunicipio TEXT, provincia TEXT, codProvincia TEXT, tel TEXT);"
          "INSERT into Polideportivo values ('00001', 'Txurdinaga', '5 pistas de tenis, 6 frontones, 1 campo de futbol, 2 piscinas, 1 gimnasio', 'Parque txurdinaga', 'Bilbao', '111', 'Bizkaia', '222', '944333222');"
          "INSERT into Polideportivo values ('00002', 'Atxuri', '1 piscina, 1 gimnasio', 'parque atxuri', 'Bilbao', '111', 'Bizkaia', '222', '944777888');"
          "INSERT into Polideportivo values ('00003', 'El Fango', '4 pistas de tenis, 1 campo de futbol, 1 campo de rugby, 2 piscinas, 1 campo de beisbol', 'Recalde 22', 'Recalde', '213', 'Bizkaia', '222', '944333222');";

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
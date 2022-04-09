#include "menu.h"
#include "sqlite3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insertarUsuario(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select DNI, Nombre, Apellidos, Fecha, Genero, Direccion, Tel, nombreUsuario, Contrasenya, Cod_cuota from Usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int DNI;
	char Nombre[30];
	char Apellidos[30];
    char Fecha;
    char Genero[1];
    char Direccion[40];
    int Tel;
    char nombreUsuario[20];
    char Contrasenya;
    int Cod_cuota;

	printf("\n");
	printf("\n");
	printf("Usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			DNI = sqlite3_column_int(stmt, 0);
			strcpy(Nombre, (char *) sqlite3_column_text(stmt, 1));
			printf("DNI: %d Nombre: %s Apellidos: %s, Fecha: %s, Genero: %s, Direccion: %s, Tel: %d\nNombre de usuario: %s, contrasenya: %s, cod_cuota: %d", DNI, Nombre, Apellidos, Fecha, Genero, Direccion, Tel, nombreUsuario, Contrasenya, Cod_cuota);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}



int main1 (void)
{

    char linea [5];
    printf("\n======================================\n");
    printf("PROYECTO PROG IV (NOMBRE PROVISIONAL XD)\n");
    printf("======================================\n\n");
    printf("Como deseas entrar? ");
    
    printf("\n\n1. AdminServer\n");
    printf("2. Servidor\n");
    printf("3. Cliente\n");
    printf("4. Salir\n\n");
    printf("Opcion: ");
    fgets(linea, 5, stdin);
    limpiarEntrada(linea, 5);

    return *linea;

    
}

int main(void)
{
    sqlite3 *db;

	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

    printf("Database opened\n");



    char opcion;

    do{
        opcion = main1();
        switch (opcion)
        {
        case '1':
            sGestionPolideportivos();
            break;

        case '2':
            mostrarMenuServerEspera();
            break;
        
        case '3':
            cGestionPolideportivos();
            break;
        
        default:
            break;
        }
    }while(opcion != '4');

    result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
}
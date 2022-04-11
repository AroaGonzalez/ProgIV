#include "menu.h"
#include "sqlite3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 30
#define DNI_LINE 8

int insertarUsuario(sqlite3 *db, int DNI[]) {
	sqlite3_stmt *stmt;

	char sql[] = "select DNI, Nombre, Apellidos, Fecha, Genero, Direccion, Tel, nombreUsuario, Contrasenya, Cod_cuota from Usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	Usuario *u;

	printf("\n");
	printf("\n");
	printf("Usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(*u->DNI, (int *) sqlite3_column_int(stmt, 0));
			*u->nombre = sqlite3_column_text(stmt, 1);
			*u->apellido = sqlite3_column_text(stmt, 2);
			*u->fNac = sqlite3_column_text(stmt, 3);
			*u->genero = sqlite3_column_text(stmt, 4);
			*u->direccion= sqlite3_column_text(stmt, 5);
			*u->DNI = sqlite3_column_int(stmt, 6);
			*u->nombreUsuario = sqlite3_column_text(stmt, 7);
			*u->contrasenya = sqlite3_column_text(stmt, 8);
			*u->cuota = sqlite3_column_int(stmt, 9);
			printf("DNI: %i Nombre: %s Apellidos: %s, Fecha: %s, Genero: %s, Direccion: %s, Tel: %d\nNombre de usuario: %s, contrasenya: %s, cod_cuota: %d", *u->DNI, *u->nombre, *u->apellido, *u->fNac, *u->genero, *u->direccion, *u->DNI, *u->nombreUsuario, *u->contrasenya, *u->cuota);
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

int insertarAdmin(sqlite3 *db, char contrasenya[]) {
	sqlite3_stmt *stmt;

	char sql[] = "select Nombre, Contrasenya from Administrador";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char Nombre;
    char Contrasenya[30];

	printf("\n");
	printf("\n");
	printf("Administradores:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			Nombre = sqlite3_column_text(stmt, 0);
			strcpy(Contrasenya, (char *) sqlite3_column_text(stmt, 1));
			printf("Nombre: %s, contrasenya: %s", Nombre, Contrasenya);
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

int insertarCliente(sqlite3 *db, char contrasenya[]) {
	sqlite3_stmt *stmt;

	char sql[] = "select Nombre, Contrasenya from Cliente";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char Nombre;
    char Contrasenya[30];

	printf("\n");
	printf("\n");
	printf("Clientes:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			Nombre = sqlite3_column_text(stmt, 0);
			strcpy(Contrasenya, (char *) sqlite3_column_text(stmt, 1));
			printf("Nombre: %s, contrasenya: %s", Nombre, Contrasenya);
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

int crearReserva(sqlite3 *db, int Cod[]) {
	sqlite3_stmt *stmt;

	char sql[] = "select Cod, Hora, Tipo, Precio, Cod_poli from Reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int Cod[3];
	int Hora;
    char Tipo;
	float Precio;
	int Cod_poli;

	printf("\n");
	printf("\n");
	printf("Reservas:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(Cod, (int *) sqlite3_column_text(stmt, 0));
			Hora = sqlite3_column_int(stmt, 1);
			Tipo = sqlite3_column_text(stmt, 2);
			Precio = sqlite3_column_double(stmt, 3);
			Cod_poli = sqlite3_column_int(stmt, 4);
			printf("Cod: %i, hora: %i, tipo: %c, precio: %f, cod_poli: %i", Cod, Hora, Tipo, Precio, Cod_poli);
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

	result = insertarUsuario(db, 12345678);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = insertarAdmin(db, "pelele");
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = insertarCliente(db, "hakunaMatata");
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = crearReserva(db, 1);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

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
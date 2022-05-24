#include "BaseDatos.h"
#include <string.h>

int insertarUsuario(sqlite3 *db, Usuario u){
	sqlite3_stmt *stmt;

	char sql[50] = "INSERT INTO USUARIO VALUES(";
	//"INSERT INTO USUARIO VALUES(DNI, Nombre, Apellidos, Fecha, Genero, Direccion, Tel, nombreUsuario, Contrasenya, Cod_cuota)"
	strcat(sql, u.DNI);
	strcat(sql, ",");
	strcat(sql, u.nombre);
	strcat(sql, ",");
	strcat(sql, u.apellido);
	strcat(sql, ",");
	strcat(sql, u.fNac);
	strcat(sql, ",");
	strcat(sql, u.genero);
	strcat(sql, ",");
	strcat(sql, u.direccion);
	strcat(sql, ",");
	strcat(sql, u.tel);
	strcat(sql, ",");
	strcat(sql, u.nombreUsuario);
	strcat(sql, ",");
	strcat(sql, u.contrasenya);
	strcat(sql, ",");
	strcat(sql, u.cuota);
	strcat(sql, ")");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

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

int selectUsuario(sqlite3 *db, Usuario *u, char* nombreUsuario) {
	sqlite3_stmt *stmt;

	char sql[50] = "select DNI, Nombre, Apellidos, Fecha, Genero, Direccion, Tel, nombreUsuario, Contrasenya, Cod_cuota from Usuario where nombreUsuario = '";
	strcat(sql, nombreUsuario);
	strcat(sql, "'");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	printf("\n");
	printf("\n");
	printf("Usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			*u->DNI = sqlite3_column_int(stmt, 0);
			*u->nombre = sqlite3_column_text(stmt, 1);
			*u->apellido = sqlite3_column_text(stmt, 2);
			*u->fNac = sqlite3_column_text(stmt, 3);
			*u->genero = sqlite3_column_text(stmt, 4);
			*u->direccion= sqlite3_column_text(stmt, 5);
			*u->DNI = sqlite3_column_int(stmt, 6);
			*u->nombreUsuario = sqlite3_column_text(stmt, 7);
			*u->contrasenya = sqlite3_column_text(stmt, 8);
			//*u.cuota = sqlite3_column_int(stmt, 9);
			printf("DNI: %i Nombre: %s Apellidos: %s, Fecha: %s, Genero: %s, Direccion: %s, Tel: %d\nNombre de usuario: %s, contrasenya: %s, cod_cuota: %d", *u->DNI, *u->nombre, *u->apellido, *u->fNac, *u->genero, *u->direccion, *u->DNI, *u->nombreUsuario, *u->contrasenya);
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

int insertarAdmin(sqlite3 *db, Administrador *a) {
	sqlite3_stmt *stmt;

	char sql[] = "select Nombre, Contrasenya from Administrador";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	printf("\n");
	printf("\n");
	printf("Administradores:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			*a->nombreUsuario = sqlite3_column_text(stmt, 0);
			*a->contrasenya = sqlite3_column_text(stmt, 1);
			printf("Nombre: %s, contrasenya: %s", *a->nombreUsuario, *a->contrasenya);
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

int insertarCliente(sqlite3 *db, Cliente *c) {
	sqlite3_stmt *stmt;

	char sql[] = "select Nombre, Contrasenya from Cliente";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	printf("\n");
	printf("\n");
	printf("Clientes:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			*c->nombreUsuario = sqlite3_column_text(stmt, 0);
			*c->contrasenya = sqlite3_column_text(stmt, 1);
			printf("Nombre: %s, contrasenya: %s", *c->nombreUsuario, *c->contrasenya);
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

int crearReserva(sqlite3 *db, Reserva *r) {
	sqlite3_stmt *stmt;

	char sql[] = "select Cod, Hora, Tipo, Precio, Cod_poli from Reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	printf("\n");
	printf("\n");
	printf("Reservas:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			*r->Cod = sqlite3_column_text(stmt, 0);
			*r->Hora = sqlite3_column_int(stmt, 1);
			*r->Tipo = sqlite3_column_text(stmt, 2);
			*r->Precio = sqlite3_column_double(stmt, 3);
			*r->Cod_poli = sqlite3_column_int(stmt, 4);
			printf("Cod: %i, hora: %i, tipo: %c, precio: %f, cod_poli: %i", *r->Cod, *r->Hora, *r->Tipo, *r->Precio, *r->Cod_poli);
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
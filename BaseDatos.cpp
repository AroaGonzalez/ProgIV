#include "BaseDatos.h"
#include <string.h>

#include "cliente.h"
#include "usuario.h"
#include "adminServer.h"

#include <iostream>
#include <string.h>

using namespace std;

int selectMaxRef(char *db) {
	/*
	char ref[100] = "0000";
	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "select MAX(Ref) from  Polideportivo";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;
	
	strcpy(ref, sql);

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;

	return SQLITE_OK;
	*/
return 0;
}

int selectAdmin(char *db, Administrador *a, char* nombreUsuario) {
	/*

	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "select Nombre, Contrasenya from Administrador where nombreUsuario = '";
	strcat(sql, nombreUsuario);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;

	return SQLITE_OK;
	*/
return 0;
}

int insertarAdmin(char *db, Administrador *a) {
	/*

	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "INSERT INTO ADMINISTRADOR VALUES(";
	strcat(sql, a->getNombreUsuario());
	strcat(sql, ",");
	strcat(sql, a->getContrasenya());
	strcat(sql, ");");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;

	return SQLITE_OK;
	*/
	return 0;
}


int insertarCliente(char *db, Cliente *c) {
	/*

	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "INSERT INTO Cliente VALUES(";
	strcat(sql, c->getNombreUsuario());
	strcat(sql, ",");
	strcat(sql, c->getContrasenya());
	strcat(sql, ");");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;

	return SQLITE_OK;
	*/return 0;
}

int selectCliente(char *db, Cliente *c, char* nombreUsuario) {
	/*

	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;
	
	char sql[] = "select Nombre, Contrasenya from Cliente where nombreUsuario = '";
	strcat(sql, nombreUsuario);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;

	return SQLITE_OK;
	*/
return 0;
}


static int borrarPoli(char *db, char* nombre) {
	/*

	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "Delete from Polideportivo where Nombre = '";
	strcat(sql, nombre);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/ return 0;
}

static int insertarPoli(char *db, Polideportivo *p)
{
	/*
	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "INSERT INTO Polideportivo VALUES(";
	strcat(sql, p->getRef());
	strcat(sql, ",");
	strcat(sql, p->getNombre());
	strcat(sql, ",");
	strcat(sql, p->getInstalaciones());
	strcat(sql, ",");
	strcat(sql, p->getDireccion());
	strcat(sql, ",");
	strcat(sql, p->getMunicipio());
	strcat(sql, ",");
	strcat(sql, p->getCodMunicipio());
	strcat(sql, ",");
	strcat(sql, p->getProvincia());
	strcat(sql, ",");
	strcat(sql, p->getCodProv());
	strcat(sql, ",");
	strcat(sql, p->getTel());
	strcat(sql, ");");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/
	return 0;
}

static int cambiarNombrePoli(char *db, Polideportivo *p, char* nuevoNombre)
{
	/*
	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "UPDATE Polideportivo SET Nombre='";
	strcat(sql, nuevoNombre);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/
	return 0;
}

static int cambiarDireccionPoli(char *db, Polideportivo *p, char* nuevaDir)
{
	/*
	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "UPDATE Polideportivo SET Direccion='";
	strcat(sql, nuevaDir);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/return 0;
}

static int cambiarTelefonoPoli(char *db, Polideportivo *p, char* nuevoTelefono)
{
	/*
	sqlite3_stmt *stmt;

	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "UPDATE Polideportivo SET Tel='";
	strcat(sql, nuevoTelefono);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;
	
	return SQLITE_OK;
	*/return 0;
}

static int cambiarMuniPoli(char *db, Polideportivo *p, char* nuevoMunicipio)
{
	return 0;/*
	sqlite3_stmt *stmt;

	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "UPDATE Polideportivo SET Municipio='";
	strcat(sql, nuevoMunicipio);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/
}

static int cambiarCodMuniPoli(char *db, Polideportivo *p, char* nuevoCodMunicipio)
{
	return 0;/*
	sqlite3_stmt *stmt;
	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "UPDATE Polideportivo SET Cod_mun='";
	strcat(sql, nuevoCodMunicipio);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/
}

static int cambiarProvPoli(char *db, Polideportivo *p, char* nuevaProvincia)
{
	return 0;/*
	sqlite3_stmt *stmt;

	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "UPDATE Polideportivo SET Provincia='";
	strcat(sql, nuevaProvincia);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/
}

static int cambiarCodProvPoli(char *db, Polideportivo *p, char* nuevaCodProvincia)
{
	return 0;/*
	sqlite3_stmt *stmt;

	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "UPDATE Polideportivo SET Cod_prov='";
	strcat(sql, nuevaCodProvincia);
	strcat(sql, "';");

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/
}

static int VisualizarPoli(char *db)
{
	return 0;/*
	sqlite3_stmt *stmt;

	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "Select * from Polideportivo";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/
}

static int borrarBD(char *db)
{
	/*
	sqlite3_stmt *stmt;

	
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	char sql[] = "Drop database db";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout<<"Error preparing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"SQL query prepared (SELECT)\n"<<endl;

	cout<<"\n"<<endl;
	cout<<"\n"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout<<"Error finalizing statement (SELECT)\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Prepared statement finalized (SELECT)\n"<<endl;

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
	
	return SQLITE_OK;
	*/return 0;
}
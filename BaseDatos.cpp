#include "BaseDatos.h"
#include <string.h>

#include "cliente.h"
#include "usuario.h"
#include "adminServer.h"

#include <iostream>
#include <string.h>

using namespace std;



int insertarUsuario(sqlite3 *db, Usuario *u){
	sqlite3_stmt *stmt;

	char sql[50] = "INSERT INTO USUARIO VALUES(";
	
	strcat(sql, u->getNombre());
	strcat(sql, ",");
	strcat(sql, u->getApe());
	strcat(sql, ",");
	strcat(sql, u->getFnac());
	strcat(sql, ",");
	strcat(sql, u->getGenero());
	strcat(sql, ",");
	strcat(sql, u->getDni());
	strcat(sql, ",");
	strcat(sql, u->getDir());
	strcat(sql, ",");
	strcat(sql, u->getTel());
	strcat(sql, ",");
	strcat(sql, u->getNombreUsuario());
	strcat(sql, ",");
	strcat(sql, u->getContrasenya());
	strcat(sql, ");");
	

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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

}

int selectUsuario(sqlite3 *db, Usuario *u, Usuario* nombreUsuario) {
	sqlite3_stmt *stmt;

	char sql[] = "select DNI, Nombre, Apellidos, Fecha, Genero, Direccion, Tel, nombreUsuario, Contrasenya, Cod_cuota from Usuario where nombreUsuario = '";
	strcat(sql, u->getNombreUsuario());
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

int selectMaxRef(sqlite3 *db) {
	char* ref = "0000";
	sqlite3_stmt *stmt;

	char sql[] = "select MAX(Ref) from  Polideportivo";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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

	return SQLITE_OK;
}

int selectAdmin(sqlite3 *db, Administrador *a, char* nombreUsuario) {
	sqlite3_stmt *stmt;

	char sql[] = "select Nombre, Contrasenya from Administrador where nombreUsuario = '";
	strcat(sql, nombreUsuario);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

int insertarAdmin(sqlite3 *db, Administrador *a) {
	sqlite3_stmt *stmt;

	char sql[] = "INSERT INTO ADMINISTRADOR VALUES(";
	strcat(sql, a->getNombreUsuario());
	strcat(sql, ",");
	strcat(sql, a->getContrasenya());
	strcat(sql, ");");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}


int insertarCliente(sqlite3 *db, Cliente *c) {
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Cliente VALUES(";
	strcat(sql, c->getNombreUsuario());
	strcat(sql, ",");
	strcat(sql, c->getContrasenya());
	strcat(sql, ");");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

int selectCliente(sqlite3 *db, Cliente *c, char* nombreUsuario) {
	sqlite3_stmt *stmt;
	
	char sql[] = "select Nombre, Contrasenya from Cliente where nombreUsuario = '";
	strcat(sql, nombreUsuario);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

int crearReserva(sqlite3 *db, Reserva *r) {
	sqlite3_stmt *stmt;

	char sql[] = "INSERT INTO Reserva VALUES(";
	strcat(sql, r->Cod);
	strcat(sql, ",");
	strcat(sql, r->Hora);
	strcat(sql, ",");
	strcat(sql, r->Tipo);
	strcat(sql, ",");
	strcat(sql, r->Precio);
	strcat(sql, ",");
	strcat(sql, r->Cod_poli);
	strcat(sql, ");");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int borrarPoli(sqlite3 *db, char* nombre) {
	sqlite3_stmt *stmt;

	char sql[] = "Delete from Polideportivo where Nombre = '";
	strcat(sql, nombre);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int insertarPoli(sqlite3 *db, Polideportivo *p)
{
	sqlite3_stmt *stmt;

	char sql[] = "INSERT INTO Polideportivo VALUES(";
	strcat(sql, p->ref);
	strcat(sql, ",");
	strcat(sql, p->nombre);
	strcat(sql, ",");
	strcat(sql, p->instalaciones);
	strcat(sql, ",");
	strcat(sql, p->direccion);
	strcat(sql, ",");
	strcat(sql, p->municipio);
	strcat(sql, ",");
	strcat(sql, p->codMunicipio);
	strcat(sql, ",");
	strcat(sql, p->provincia);
	strcat(sql, ",");
	strcat(sql, p->codProv);
	strcat(sql, ",");
	strcat(sql, p->tel);
	strcat(sql, ");");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int cambiarNombrePoli(sqlite3 *db, Polideportivo *p, char* nuevoNombre)
{
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Polideportivo SET Nombre='";
	strcat(sql, nuevoNombre);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int cambiarDireccionPoli(sqlite3 *db, Polideportivo *p, char* nuevaDir)
{
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Polideportivo SET Direccion='";
	strcat(sql, nuevaDir);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int cambiarTelefonoPoli(sqlite3 *db, Polideportivo *p, char* nuevoTelefono)
{
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Polideportivo SET Tel='";
	strcat(sql, nuevoTelefono);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int cambiarMuniPoli(sqlite3 *db, Polideportivo *p, char* nuevoMunicipio)
{
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Polideportivo SET Municipio='";
	strcat(sql, nuevoMunicipio);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int cambiarCodMuniPoli(sqlite3 *db, Polideportivo *p, char* nuevoCodMunicipio)
{
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Polideportivo SET Cod_mun='";
	strcat(sql, nuevoCodMunicipio);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int cambiarProvPoli(sqlite3 *db, Polideportivo *p, char* nuevaProvincia)
{
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Polideportivo SET Provincia='";
	strcat(sql, nuevaProvincia);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}

static int cambiarCodProvPoli(sqlite3 *db, Polideportivo *p, char* nuevaCodProvincia)
{
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Polideportivo SET Cod_prov='";
	strcat(sql, nuevaCodProvincia);
	strcat(sql, "';");

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
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
}
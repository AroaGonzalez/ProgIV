#ifndef BASEDATOS_H
#define BASEDATOS_H
#include "menu.h"
#include "sqlite3.h"
#include "usuario.h"
#include "adminServer.h"
#include "cliente.h"
#include "reserva.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class BaseDatos
{
    public:
        //hay que hacer constructores
        //BaseDatos(char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya);
        //BaseDatos(const BaseDatos &bd);
        //virtual ~BaseDatos();

        static int insertarUsuario(sqlite3 *db, Usuario *u);

        static int selectUsuario(sqlite3 *db, Usuario *u, char* nombreUsuario);

        static int selectAdmin(sqlite3 *db, Administrador *a, char* nombreUsuario);

        static int insertarAdmin(sqlite3 *db, Administrador *a);

        static int selectCliente(sqlite3 *db, Cliente *c, char* nombreUsuario);

        static int insertarCliente(sqlite3 *db, Cliente *c);

        static int crearReserva(sqlite3 *db, Reserva *r);

        static int selectMaxRef(sqlite3 *db, char* ref);

        static int borrarPoli(sqlite3 *db, char* nombre);
};


#endif
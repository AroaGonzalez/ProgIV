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
#define MAX_LINE 30
#define DNI_LINE 8

class BaseDatos
{
    public:
        static int insertarUsuario(sqlite3 *db, Usuario *u);

        static int selectUsuario(sqlite3 *db, Usuario *u, char* nombreUsuario);

        static int selectAdmin(sqlite3 *db, Administrador *a, char* nombreUsuario);

        static int insertarAdmin(sqlite3 *db, Administrador *a);

        static int selectCliente(sqlite3 *db, Cliente *c, char* nombreUsuario);

        static int insertarCliente(sqlite3 *db, Cliente *c);

        static int crearReserva(sqlite3 *db, Reserva *r);
};


#endif
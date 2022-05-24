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

int insertarUsuario(sqlite3 *db, Usuario u);

int selectUsuario(sqlite3 *db, Usuario *u, char* nombreUsuario);

int insertarAdmin(sqlite3 *db, Administrador *a);

int insertarCliente(sqlite3 *db, Cliente *c);

int crearReserva(sqlite3 *db, Reserva *r);

#endif
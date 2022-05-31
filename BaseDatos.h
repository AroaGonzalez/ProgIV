#ifndef BASEDATOS_H
#define BASEDATOS_H

//#include "sqlite3.h"
#include "usuario.h"
#include "adminServer.h"
#include "cliente.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class BaseDatos
{

    public:

    //HEMOS QUITADO TODOS LOS SQLITES POQUE SI NO NO COMPILA

        static int selectAdmin(char *db, Administrador *a, char* nombreUsuario);

        static int insertarAdmin(char *db, Administrador *a);

        static int selectCliente(char *db, Cliente *c, char* nombreUsuario);

        static int insertarCliente(char *db, Cliente *c);

        static int selectMaxRef(char *db);

        static int insertarPoli(char *db, Polideportivo *p);

        static int borrarPoli(char *db, char* nombre);

        static int cambiarNombrePoli(char *db, Polideportivo *p, char* nuevoNombre);

        static int cambiarDireccionPoli(char *db, Polideportivo *p, char* nuevaDir);

        static int cambiarTelefonoPoli(char *db, Polideportivo *p, char* nuevoTelefono);

        static int cambiarMuniPoli(char *db, Polideportivo *p, char* nuevoMunicipio);

        static int cambiarCodMuniPoli(char *db, Polideportivo *p, char* nuevoCodMunicipio);

        static int cambiarProvPoli(char *db, Polideportivo *p, char* nuevaProvincia);

        static int cambiarCodProvPoli(char *db, Polideportivo *p, char* nuevaCodProvincia);

        static int VisualizarPoli(char *db);

        static int borrarBD(char *db);
};


#endif
#ifndef _CLIENTE_H_
#define _CLIENTE_H_
#include "menu.h"
#define MAX_LINE 30
#define DNI_LINE 8

//CLIENTE MENU

char cMostrarMenuGestPoli1();

Usuario cMostrarMenuRegUsu();

Cliente cMostrarMenuIniSes();

char cMostrarMenuMenuPrinc();

char cMostrarMenuGestReserv();

char cMostrarMenuModifDat();

    Usuario cMostrarMenuModifDatDir();

    Usuario cMostrarMenuModifDatTCout();

    Usuario cMostrarMenuModifDatNomUsu();

    Usuario cMostrarMenuModifDatContr();

char cMostrarMenuContactPoli();

//CLIENTE CONTROL

int cGestionPolideportivos();

int cRegistroUsuario();

int cIniciarSesion();

#endif
#ifndef _ADMINSERVER_H_
#define _ADMINSERVER_H_
#include "menu.h"
#define MAX_LINE 30
#define DNI_LINE 8



//ADMINSERVER MENU

char sMostrarMenuGestPoli1();

Usuario sMostrarMenuRegUsu();

char sMostrarMenuIniSes();

char sMostrarMenuMenuPrinc();

char sMostrarMenuImportDat();

char sMostrarMenuBorrarBD();

//ADMINSERVER CONTROL

int sGestionPolideportivos();

int sRegistroUsuario();

int sIniciarSesion();

#endif
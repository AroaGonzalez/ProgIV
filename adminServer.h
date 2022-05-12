#ifndef _ADMINSERVER_H_
#define _ADMINSERVER_H_
#include "menu.h"
#define MAX_LINE 30
#define DNI_LINE 8

typedef struct
{
    char nombreUsuario [MAX_LINE];
    char contrasenya [MAX_LINE];

}Administrador;

//ADMINSERVER MENU

char sMostrarMenuGestPoli1();

//Usuario sMostrarMenuRegUsu();

char sMostrarMenuIniSes();

char sMostrarMenuMenuPrinc();

char sMostrarMenuImportDat();

char sMostrarMenuBorrarBD();

//ADMINSERVER CONTROL

int sGestionPolideportivos();

int sRegistroUsuario();

int sIniciarSesion();

#endif
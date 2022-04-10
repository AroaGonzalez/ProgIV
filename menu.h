#ifndef _MENU_H_
#define _MENU_H_

void limpiarEntrada(char *str, int max_line);

//ADMINSERVER MENU

char sMostrarMenuGestPoli1();

char sMostrarMenuRegUsu();

char sMostrarMenuIniSes();

char sMostrarMenuMenuPrinc();

char sMostrarMenuImportDat();

char sMostrarMenuBorrarBD();

//ADMINSERVER CONTROL

int sGestionPolideportivos();

int sRegistroUsuario();

int sIniciarSesion();


//SERVIDOR

void mostrarMenuServerEspera();

void mostrarMenuClienteConn();

int fecha();


//CLIENTE MENU

char cMostrarMenuGestPoli1();

char cMostrarMenuRegUsu();

char cMostrarMenuIniSes();

char cMostrarMenuMenuPrinc();

char cMostrarMenuGestReserv();

char cMostrarMenuModifDat();

    char cMostrarMenuModifDatDir();

    char cMostrarMenuModifDatTCout();

    char cMostrarMenuModifDatNomUsu();

    char cMostrarMenuModifDatContr();

char cMostrarMenuContactPoli();

//CLIENTE CONTROL

int cGestionPolideportivos();

int cRegistroUsuario();

int cIniciarSesion();

//ADMINSERVER + CLIENTE

char gMostrarMenuGestPoli2();

char gMostrarMenuListPoli();

char gMostrarMenuListPoliMuni();

char gMostrarMenuAnyadirPoli();

char gMostrarMenuModifPoli();

char gMostrarMenuBorrarPoli();



#endif

//comment prueba
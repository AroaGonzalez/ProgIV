#ifndef _MENU_H_
#define _MENU_H_
#define MAX_LINE 30
#define DNI_LINE 8

typedef struct
{
    char nombre [MAX_LINE];
    char apellido [MAX_LINE];
    char fNac [MAX_LINE];
    char genero [MAX_LINE];
    int DNI [DNI_LINE];
    char direccion [MAX_LINE];
    char cuota [MAX_LINE];
    char nombreUsuario [MAX_LINE];
    char contrasenya [MAX_LINE];

}Usuario;

typedef struct
{
    char nombreUsuario [MAX_LINE];
    char contrasenya [MAX_LINE];

}Cliente;

typedef struct
{
    
}Cuota;




void limpiarEntrada(char *str, int max_line);

//ADMINSERVER MENU

char sMostrarMenuGestPoli1();

Usuario sMostrarMenuRegUsu();

Cliente sMostrarMenuIniSes();

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

Usuario cMostrarMenuRegUsu();

Cliente cMostrarMenuIniSes();

char cMostrarMenuMenuPrinc();

char cMostrarMenuGestReserv();

char cMostrarMenuModifDat();

    Usuario cMostrarMenuModifDatDir();

    char cMostrarMenuModifDatTCout();

    Cliente cMostrarMenuModifDatNomUsu();

    Cliente cMostrarMenuModifDatContr();

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
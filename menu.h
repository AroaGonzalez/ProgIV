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
    char nombreUsuario [MAX_LINE];
    char contrasenya [MAX_LINE];

}Administrador;

typedef struct
{
    int Cod[MAX_LINE];
    char Nombre[MAX_LINE];
    float Precio[MAX_LINE];
    char Tipo[MAX_LINE];
}Cuota;

typedef struct
{
    char *ref;
    char *nombre;
    char **instalaciones;
    char *direccion;
    char *municipio;
    char* codMunicipio;
    char *provincia;
    char* codProv;
    char* tel;
}Polideportivo;

typedef struct
{
    int Cod[MAX_LINE];
    int Hora[MAX_LINE];
    char Tipo[MAX_LINE];
    float Precio[MAX_LINE];
    int Cod_poli[MAX_LINE];
}Reserva;


//POLIDEPORTIVO
void InicializarPoli(Polideportivo *p, char *ref, char* nombre, char** instalaciones, char *direccion, char* municipio, char* codMunicipio, char* provincia, char* codProv, char* tel);

//Limpiar entradas
void limpiarEntrada(char *str, int max_line);

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

    Usuario cMostrarMenuModifDatTCout();

    Usuario cMostrarMenuModifDatNomUsu();

    Usuario cMostrarMenuModifDatContr();

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
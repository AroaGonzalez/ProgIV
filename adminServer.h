#ifndef _ADMINSERVER_H_
#define _ADMINSERVER_H_
#include "menu.h"
#include "usuario.h"

class Administrador
{
    private:
        char* nombreUsuario;
        char* contrasenya;
    
    public:
        Administrador();
        Administrador(char* nombreUsuario, char* contrasenya); 
        Administrador(const Administrador &a); 
        virtual ~Administrador();

        char* getNombreUsuario();
        char* setNombreUsu(char* nombreUsu);
        char* getContrasenya();
        char* setContrasenya(char* contrasenya);

        static char sMostrarMenuGestPoli1();

        static void sMostrarMenuRegUsu();

        static char sMostrarMenuIniSes();

        static char sMostrarMenuMenuPrinc();

        static char sMostrarMenuImportDat();

        static void sMostrarMenuBorrarBD();

        //ADMINSERVER CONTROL

        static int sGestionPolideportivos();

        static int sRegistroUsuario();

        static int sIniciarSesion();

        static char gMostrarMenuGestPoli2();

        static void gMostrarMenuListPoli();

        static void gMostrarMenuListPoliMuni();

        static void gMostrarMenuAnyadirPoli();

        static char gMostrarMenuModifPoli();

        static void gMostrarMenuBorrarPoli();
};

#endif
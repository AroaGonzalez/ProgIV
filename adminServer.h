#ifndef _ADMINSERVER_H_
#define _ADMINSERVER_H_

#include "usuario.h"

class Administrador:public Usuario
{
    private:
        char* a;
    
    public:
        Administrador();
        Administrador(char* a);
        Administrador(const Administrador &a); 
        ~Administrador();

        char* getA();
        char* setA(char* a);

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
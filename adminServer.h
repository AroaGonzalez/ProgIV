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

        Administrador(char* nombreUsuario, char* contrasenya); 
        Administrador(const Administrador &a); 
        virtual ~Administrador();

        char* getNombreUsuario();
        char* setNombreUsu(char* nombreUsu);
        char* getContrasenya();
        char* setContrasenya(char* contrasenya);

        char sMostrarMenuGestPoli1();

        void sMostrarMenuRegUsu();

        char sMostrarMenuIniSes();

        char sMostrarMenuMenuPrinc();

        char sMostrarMenuImportDat();

        void sMostrarMenuBorrarBD();

        //ADMINSERVER CONTROL

        int sGestionPolideportivos();

        int sRegistroUsuario();

        int sIniciarSesion();

        char gMostrarMenuGestPoli2();

        void gMostrarMenuListPoli();

        char gMostrarMenuListPoliMuni();
};

#endif
#ifndef _CLIENTE_H_
#define _CLIENTE_H_


#include "polideportivo.h"

class Cliente
{

    private:
        char* nombreUsuario;
        char* contrasenya;

    public:

        Cliente(char* nombreUsuario, char* contrasenya); 
        Cliente(const Usuario &u); 
        virtual ~Cliente();

        char* getNombreUsuario();
        char* setNombreUsu(char* nombreUsu);
        char* getContrasenya();
        char* setContrasenya(char* contrasenya);

        void limpiarEntrada(char *str, int max_line);

        void leerPolideportivos(Polideportivo* p[], char* fichero);

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

};

#endif
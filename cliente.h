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

        static char cMostrarMenuGestPoli1();

        static void cMostrarMenuRegUsu();

        static void cMostrarMenuIniSes();

        static char cMostrarMenuMenuPrinc();

        static char cMostrarMenuGestReserv();

        static char cMostrarMenuModifDat();

            static Usuario cMostrarMenuModifDatDir();

            static Usuario cMostrarMenuModifDatTCout();

            static Usuario cMostrarMenuModifDatNomUsu();

            static Usuario cMostrarMenuModifDatContr();

        static char cMostrarMenuContactPoli();

        //CLIENTE CONTROL

        static int cGestionPolideportivos();

        static int cRegistroUsuario();

        static int cIniciarSesion();

};

#endif
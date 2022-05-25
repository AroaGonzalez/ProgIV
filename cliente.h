#ifndef _CLIENTE_H_
#define _CLIENTE_H_


#include "polideportivo.h"

class Cliente: public Usuario
{

    private:
        char* nombreUsuario;
        char* contrasenya;

    public:
        Cliente(); //vacío
        Cliente(); //por defecto (falta por hacer)
        Cliente(); //copia (falta por hacer)
        ~Cliente(); //destructor (falta por hacer)

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
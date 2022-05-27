#ifndef _CLIENTE_H_
#define _CLIENTE_H_
#include "usuario.h"


#include "polideportivo.h"

class Cliente: public Usuario
{

    protected:
        char* centro;

    public:
        Cliente();
        Cliente(char* centro);
        Cliente(const Cliente &c); 
        virtual ~Cliente();

        char* getCentro();
        char* setCentro(char* centro);

        void limpiarEntrada(char *str, int max_line);

        void leerPolideportivos(Polideportivo* p[], char* fichero);

        static char cMostrarMenuGestPoli1();

        static char cMostrarMenuRegUsu();

        static char cMostrarMenuIniSes();

        static char cMostrarMenuMenuPrinc();

        static char cMostrarMenuGestReserv();

        static char cMostrarMenuModifDat();

            static Usuario cMostrarMenuModifDatDir();

            static Usuario cMostrarMenuModifDatTCout();

            static Usuario cMostrarMenuModifDatNomUsu();

            static Usuario cMostrarMenuModifDatContr();

        static char cMostrarMenuContactPoli();

        static char cMostrarMenuImportarDatos();

        static char cMostrarMenuBorrarBaseDatos();

        //CLIENTE CONTROL

        static int cGestionPolideportivos();

        static int cRegistroUsuario();

        static int cIniciarSesion();

        static int cMenuPrincipal();

        static int cGestionarReservas();

        static int cModifDatos();

        static int cContactarPolideportivos();

        static int cReservarEspacioDeportivo();

        static int cAnularReserva();

        static int cVisualizacionGeneral();

        static int cVisualizacionPorMunicipio();

        static int cAnyadirPolideportivo();

        static int cModificarPolideportivo();

        static int cEliminarPolideportivo();

        static int cGestionarPolideportivos();

        static int cImportarDatos();

        static int cBorrarBaseDatos();


};

#endif
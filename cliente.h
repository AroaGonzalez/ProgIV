#ifndef _CLIENTE_H_
#define _CLIENTE_H_
#include "usuario.h"


#include "polideportivo.h"

class Cliente
{

    private:
        char* nombreUsuario;
        char* contrasenya;

    public:
        Cliente();
        Cliente(char* nombreUsuario, char* contrasenya); 
        Cliente(const Cliente &c); 
        virtual ~Cliente();

        char* getNombreUsuario();
        char* setNombreUsu(char* nombreUsu);
        char* getContrasenya();
        char* setContrasenya(char* contrasenya);

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


};

#endif
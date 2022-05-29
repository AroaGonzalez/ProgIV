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

        static char cMostrarMenuRegUsu();

        static char cMostrarMenuMenuPrinc();

        static char cMostrarMenuGestReserv();

        static char cMostrarMenuModifDat();

            static void cMostrarMenuModifDatDir();

            static void cMostrarMenuModifDatTCout();    //NO SÉ QUÉ ES ESTO, JOPE :c

            static void cMostrarMenuModifDatNomUsu();

            static void cMostrarMenuModifDatContr();

        static char cMostrarMenuContactPoli();

        static char cMostrarMenuImportarDatos();

        static char cMostrarMenuBorrarBaseDatos();

        static char cMostrarMenuAnyadirPolideportivo();

        static char cMostrarMenuGestPoli2();

        static char cMostrarMenuVisualizacionGeneral();

        static char cMostrarMenuVisualizacionPorMunicipio();

        static char cMostrarMenuAnyadirPolideportivo();

        static char cMostrarMenuModificarPolideportivo();

            static void cMostrarMenuModifPoliRef();

            static void cMostrarMenuModifPoliInst();

            static void cMostrarMenuModifPoliTel();

        static char cMostrarMenuEliminarPolideportivo();




};

#endif
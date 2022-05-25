#include "cliente.h"
#include <iostream>
#include <string.h>
#include "sqlite3.h"
#include <stdlib.h>
#include "adminServer.h"
#include "BaseDatos.h"

extern "C"{
    #include "usuario.h"
}

using namespace std;


    void Cliente::leerPolideportivos(Polideportivo* p[], char* fichero)
    {
        FILE* file = fopen(fichero, "r");

        int contlinea;
        int charIndex;
        char **lineas;
        char c;
        Polideportivo* poli = (Polideportivo*) malloc(sizeof(Polideportivo)*4618);

        int puntoComa = 0;

        while ((c=fgetc(file)) != EOF)
        {

            if (c == '\n')
            {
                poli = p[contlinea];
                contlinea++;
                charIndex = 0;
                puntoComa = 0;

            }else if (c != ';')
            {
                
                lineas[contlinea][charIndex] = c;
                charIndex++;
        
            }else if(c == ';')
            {
                InicializarPoli(p[contlinea], p[contlinea]->ref, p[contlinea]->nombre, p[contlinea]->instalaciones, p[contlinea]->direccion, p[contlinea]->municipio, p[contlinea]->codMunicipio, p[contlinea]->provincia, p[contlinea]->codProv, p[contlinea]->tel);
                
                puntoComa++;
                if (puntoComa == 1)
                {
                    p[contlinea]->ref = lineas[0];

                }else if (puntoComa == 2)
                {
                    p[contlinea]->nombre = lineas[1];

                }else if (puntoComa == 3)
                {
                    p[contlinea]->instalaciones = lineas[2];

                }else if (puntoComa == 4)
                {
                    p[contlinea]->direccion = lineas[3];

                }else if (puntoComa == 5)
                {
                    p[contlinea]->municipio = lineas[4];

                }else if (puntoComa == 6)
                {
                    p[contlinea]->codMunicipio = lineas[5];

                }else if (puntoComa == 7)
                {
                    p[contlinea]->provincia = lineas[6];

                }else if (puntoComa == 8)
                {
                    p[contlinea]->codProv = lineas[7];

                }else if (puntoComa == 9)
                {
                    p[contlinea]->tel = lineas[8];
                }

            }
            
        }
    

    fclose(file);
}

char Cliente::cMostrarMenuGestPoli1()
{
    char linea [MAX_LINE];
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTION DE POLIDEPORTIVOS DE EUSKADI\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Bienvenido al programa que administra el servidor\n"<<endl;
    cout<<"Bienvenido al programa que administra el servidor\n"<<endl;
    cout<<"1. Iniciar sesion\n"<<endl;
    cout<<"2. Registrar usuario\n"<<endl;
    cout<<"3. Salir\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

Usuario Cliente::cMostrarMenuRegUsu()
{
    sqlite3 *db;
    Usuario u(char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya);

    char linea [MAX_LINE];

    cout<<"\n======================================\n"<<endl;
    cout<<"REGISTRO DE USUARIO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;
    
    char* nombreU;
    cout<<"-> Nombre: "<<endl;
    cin>>nombreU;

    char* apellidoU;
    cout<<"\n-> Apellido: "<<endl;
    cin>> apellidoU;

    char* DNIU;
    cout<<"\n-> DNI: "<<endl;
    cin>>DNIU;

    char* telU;
    cout<<"\n-> Telefono: "<<endl;
    cin>>telU;

    char* FNacU;
    cout<<"\n-> Fecha nacimiento: "<<endl;
    cin>>FNacU;

    char* generoU;
    cout<<"\n-> Genero: "<<endl;
    cin>>generoU;

    char* dirU;
    cout<<"\n-> Direccion: "<<endl;
    cin>>dirU;
   
    char* nomUsuU;
    cout<<"\n-> Nombre de usuario: "<<endl;
    cin>>nomUsuU;
    
    char* conU;
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>conU;

    Usuario u(nombreU, apellidoU, FNacU, generoU, DNIU, telU, dirU, nomUsuU, conU);

    cout<<"\nUsuario creado correctamente, pulsa enter para continuar "<<endl;
    insertarUsuario(db, u);
    
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    
    return *u;

}

Cliente Cliente::cMostrarMenuIniSes()
{
    Cliente *c;
    sqlite3 *db;

    char linea [MAX_LINE];

    cout<<"\n======================================\n"<<endl;
    cout<<"INICIO DE SESION\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n\n"<<endl;
    
    cout<<"-> Nombre de usuario: "<<endl;
    fgets(c->nombreUsuario, MAX_LINE, stdin);
    limpiarEntrada(c->nombreUsuario, MAX_LINE);
    
    cout<<"\n-> Contrasenya: "<<endl;
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    cout<<"\nPulsa enter para continuar "<<endl;
    insertarCliente(db, c);

    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    return *c;
}

char Cliente::cMostrarMenuMenuPrinc()
{
    char linea [MAX_LINE];
    cout<<"\n======================================\n"<<endl;
    cout<<"MENU PRINCIPAL\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Seleccione una opcion: \n\n"<<endl;
    cout<<"1. Gestionar reservas\n"<<endl;
    cout<<"2. Modificar datos personales\n"<<endl;
    cout<<"3. Contactar con otros polideportivos\n"<<endl;
    cout<<"4. Gestionar polideportivos\n"<<endl;
    cout<<"5. Volver\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char Cliente::cMostrarMenuGestReserv()
{
    char linea [MAX_LINE];
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTIONAR RESERVAS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"1. Reservar espacio deportivo\n"<<endl;
    cout<<"2. Anular reserva\n"<<endl;
    cout<<"3. Volver\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char Cliente::cMostrarMenuModifDat()
{
    char linea [MAX_LINE];
    cout<<"\n======================================\n"<<endl;
    cout<<"MODIFICAR DATOS PERSONALES\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Seleccione el dato que quiera modificar:\n\n"<<endl;
    
    cout<<"1. Direccion\n"<<endl;
    cout<<"2. Tipo de cuota\n"<<endl;
    cout<<"3. Nombre de usuario\n"<<endl;
    cout<<"4. Contrasenya\n"<<endl;
    cout<<"5. Volver\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    return *linea;
}

Usuario Cliente::cMostrarMenuModifDatDir()
{
    sqlite3 *db;
    Usuario *u;
    char linea [MAX_LINE];
    char* nombreDeUsuario;
    char* nuevaDireccion;

    cout<<"\nEscriba el nombre del usuario: "<<endl;
    cin>>nombreDeUsuario;

    selectUsuario(db, u, nombreDeUsuario);

    cout<<"\nNueva direccion: "<<endl;
    cin>>nuevaDireccion;
    *u->direccion = *nuevaDireccion; //EN DUDA!!!!!!!!!!!!!!!!!!!!!!1
    fgets(u->direccion, MAX_LINE, stdin);
    limpiarEntrada(u->direccion, MAX_LINE);
    cout<<"\nDireccion actualizada\n"<<endl;

    return *u;
}

 /*
Usuario Cliente::cMostrarMenuModifDatTCout()
{
    sqlite3 *db;
    Usuario *u;
   
    char linea [MAX_LINE];
    printf("\nNuevo tipo de cuota: ");
    fgets(u->cuota, MAX_LINE, stdin);
    limpiarEntrada(u->cuota, MAX_LINE);
    printf("\nTipo de cuota actualizado\n");
    *u->cuota = insertarUsuario(db, u->cuota);

    return *u;
}
*/

Usuario Cliente::cMostrarMenuModifDatNomUsu()
{
    Usuario *u;
    sqlite3 *db;
    char linea [MAX_LINE];
    char* nuevoNombreDeUsuario;

    cout<<"\nNuevo nombre de usuario: "<<endl;
    cin>>nuevoNombreDeUsuario;

    selectUsuario(db, u, nuevoNombreDeUsuario);
    *u->nombreUsuario = *nuevoNombreDeUsuario;

    fgets(u->nombreUsuario, MAX_LINE, stdin);
    limpiarEntrada(u->nombreUsuario, MAX_LINE);
    cout<<"\nNombre de usuario actualizado\n"<<endl;

    return *u;
}

Usuario Cliente::cMostrarMenuModifDatContr()
{
    Usuario *u;
    sqlite3 *db;
    char* nuevaContrasenya;

    char linea [MAX_LINE];
    cout<<"\nNueva contrasenya: "<<endl;
    cin>>nuevaContrasenya;

    selectUsuario(db, u, nuevaContrasenya);
    *u->contrasenya = *nuevaContrasenya;

    fgets(u->contrasenya, MAX_LINE, stdin);
    limpiarEntrada(u->contrasenya, MAX_LINE);
    printf("\nContrasenya actualizada\n");

    return *u;
}

char Cliente::cMostrarMenuContactPoli()
{
    char linea [MAX_LINE];
    cout<<"\n======================================\n"<<endl;
    cout<<"CONTACTAR CON OTROS POLIDEPORTIVOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    
    cout<<"-> Nombre del polideportivo: "<<endl;
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    int telef = 666666666;    
    printf("\nEl numero telefonico del polideportivo es: %i", telef);

    return *linea;}


int Cliente::cGestionPolideportivos()
{
    char opcion;

    do{
        opcion = cMostrarMenuGestPoli1();
        switch (opcion)
        {
        case '1':
            cIniciarSesion();
            break;

        case '2':
            cRegistroUsuario();
            break;

        default:
            break;
        }
    }while(opcion != '3');
}



int Cliente::cRegistroUsuario(void)
{

    cMostrarMenuRegUsu();

}

int Cliente::cIniciarSesion(void)
{

    cMostrarMenuIniSes();

}

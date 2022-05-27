#include "cliente.h"
#include <iostream>
#include <string.h>
#include "sqlite3.h"
#include <stdlib.h>
#include "adminServer.h"
#include "BaseDatos.h"
#include "usuario.h"

using namespace std;

Cliente::Cliente()
{

}

Cliente::Cliente(char* centro):Usuario(nombre, apellido, fNac, genero, DNI, tel, direccion, nombreUsuario, contrasenya)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->fNac = fNac;
    this->genero = genero;
    this->DNI = DNI;
    this->tel = tel;
    this->direccion = direccion;
    this->nombreUsuario = nombreUsuario;
    this->contrasenya = contrasenya;
    this->centro = centro;

}

Cliente::Cliente(const Cliente &c)
{
    this->centro = centro;
}

Cliente::~Cliente()
{

}

char* Cliente::getCentro()
{
    return this->centro;
}

char* Cliente::setCentro(char* centro)
{
    this->centro = centro;
}


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


//MENUS VISUALES

char Cliente::cMostrarMenuGestPoli1()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTION DE POLIDEPORTIVOS DE EUSKADI\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Bienvenido al programa que administra el servidor\n"<<endl;

    cout<<"1. Iniciar sesion\n"<<endl;
    cout<<"2. Registrar usuario\n"<<endl;
    cout<<"3. Salir\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;
    cGestionPolideportivos();
    return linea;
}

char Cliente::cMostrarMenuRegUsu()
{
    sqlite3 *db;

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

    char* centroU;
    cout<<"\n-> Centro: "<<endl;
    cin>>centroU;


    
}



char Cliente::cMostrarMenuIniSes()
{
    Cliente *c;
    sqlite3 *db;
    char* nombreDeUsuario;
    char* contrasenya;


    cout<<"\n======================================\n"<<endl;
    cout<<"INICIO DE SESION\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n\n"<<endl;
    
    cout<<"-> Nombre de usuario: "<<endl;
    cin>>nombreDeUsuario;
    c->setNombreUsu(nombreDeUsuario);
    BaseDatos::selectCliente(db, c, c->getNombreUsuario());
    
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>contrasenya;
    c->setContrasenya(contrasenya);
    BaseDatos::selectCliente(db, c, c->getContrasenya());
    
    cout<<"\nPulsa enter para continuar "<<endl;  

}

char Cliente::cMostrarMenuMenuPrinc()
{
    char linea;
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
    cin>>linea;
   
    return linea;
}

char Cliente::cMostrarMenuGestReserv()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTIONAR RESERVAS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"1. Reservar espacio deportivo\n"<<endl;
    cout<<"2. Anular reserva\n"<<endl;
    cout<<"3. Volver\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;
    
    return linea;
}

char Cliente::cMostrarMenuModifDat()
{
    char linea;
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
    cin>>linea;

    return linea;
}

Usuario Cliente::cMostrarMenuModifDatDir()
{
    sqlite3 *db;
    Usuario *u;

    char* nombreDeUsuario;
    char* nuevaDireccion;

    cout<<"\nEscriba el nombre del usuario: "<<endl;
    cin>>nombreDeUsuario;
    u->setNombreUsu(nombreDeUsuario);
    BaseDatos::selectUsuario(db, u, u->getNombreUsuario());

    cout<<"\nNueva direccion: "<<endl;
    cin>>nuevaDireccion;
    u->setDir(nuevaDireccion);
    cout<<"\nDireccion actualizada\n"<<endl;

    return *u;
}

Usuario Cliente::cMostrarMenuModifDatNomUsu()
{
    Usuario *u;
    sqlite3 *db;

    char* nuevoNombreDeUsuario;
    char* nombreDeUsuario;

    cout<<"\nEscriba el nombre del usuario: "<<endl;
    cin>>nombreDeUsuario;
    u->setNombreUsu(nombreDeUsuario);

    BaseDatos::selectUsuario(db, u, u->getNombreUsuario());

    cout<<"\nNuevo nombre de usuario: "<<endl;
    cin>>nuevoNombreDeUsuario;
    u->setNombreUsu(nuevoNombreDeUsuario);

    cout<<"\nNombre de usuario actualizado\n"<<endl;

    return *u;
}

Usuario Cliente::cMostrarMenuModifDatContr()
{
    Usuario *u;
    sqlite3 *db;

    char* nuevaContrasenya;
    char* nombreDeUsuario;

    cout<<"\nEscriba el nombre del usuario: "<<endl;
    cin>>nombreDeUsuario;
    u->setNombreUsu(nombreDeUsuario);

    BaseDatos::selectUsuario(db, u, u->getNombreUsuario());


    cout<<"\nNueva contrasenya: "<<endl;
    cin>>nuevaContrasenya;
    u->setContrasenya(nuevaContrasenya);

    cout<<"\nContrasenya actualizada\n"<<endl;

    return *u;
}

char Cliente::cMostrarMenuContactPoli()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"CONTACTAR CON OTROS POLIDEPORTIVOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    
    cout<<"-> Nombre del polideportivo: "<<endl;
    cin>>linea;
   
    int telef = 666666666;    
    cout<<"\nEl numero telefonico del polideportivo es: "<< telef<<endl;

    return linea;
}

int Cliente::cImportarDatos()
{
    cout<<"Importando datos: \n"<<endl;
} //no sé si está bien del todo




//MENUS POR DENTRO



int Cliente::cGestionPolideportivos()
{
    int opcion;

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

int Cliente::cIniciarSesion()
{
    
    //en este no son opciones, es coger datos:
    cMostrarMenuIniSes();
    //y luego me lleva a:
    cMenuPrincipal();

    //está regu, porque hay que enviarle la info de iniciar sesion a servidor para que se compruebe con la base de datos y decida a dónde ir.
    
}

int Cliente::cMenuPrincipal()
{
    
    int opcion;

    do{
        opcion = cMostrarMenuMenuPrinc();
        switch (opcion)
        {
        case '1':
            cModifDatos();
            break;

        case '2':
            cContactarPolideportivos();
            break;

        case '3':
            cContactarPolideportivos();
            break;

        case '4':
            cGestionPolideportivos();
            break;

        default:
            break;
        }
    }while(opcion != '3');
}
int Cliente::cGestionarReservas()
{}

int Cliente::cModifDatos()
{}

int Cliente::cContactarPolideportivos()
{}

int Cliente::cReservarEspacioDeportivo()
{}

int Cliente::cAnularReserva()
{}

int Cliente::cVisualizacionGeneral()
{}

int Cliente::cVisualizacionPorMunicipio()
{}

int Cliente::cAnyadirPolideportivo()
{}

int Cliente::cModificarPolideportivo()
{}

int Cliente::cEliminarPolideportivo()
{}

int Cliente::cGestionarPolideportivos()
{
    char opcion;

    do{
        opcion = cMostrarMenuMenuPrinc();
        switch (opcion)
        {
        case '1':
            cVisualizacionGeneral();
            break;

        case '2':
            cVisualizacionPorMunicipio();
            break;

        case '3':
            cAnyadirPolideportivo();
            break;

        case '4':
            cModificarPolideportivo();
            break;

        case '5':
            cEliminarPolideportivo();
            break;

        default:
            break;
        }
    }while(opcion != '3');
}







//NO SÉ QUÉ HABÍA QUE HACER
int Cliente::cImportarDatos()
{
    cImportarDatos();
}
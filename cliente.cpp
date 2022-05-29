#include "cliente.h"
#include <iostream>
#include <string.h>
#include "sqlite3.h"
#include <stdlib.h>
#include "adminServer.h"
#include "BaseDatos.h"
#include "usuario.h"
#include "poli.h"

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
    return linea;
}

char Cliente::cMostrarMenuRegUsu()
{

    Cliente *c;

    cout<<"\n======================================\n"<<endl;
    cout<<"REGISTRO DE USUARIO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;
    

    char* nombreU;
    cout<<"-> Nombre: "<<endl;
    cin>>nombreU;
    c->setNombreUsu(nombreU);       //HACER TODO ASÍ

    char* apellidoU;
    cout<<"\n-> Apellido: "<<endl;
    cin>> apellidoU;
    c->setApe(apellidoU);

    char* DNIU;
    cout<<"\n-> DNI: "<<endl;
    cin>>DNIU;
    c->setDni(DNIU);

    char* telU;
    cout<<"\n-> Telefono: "<<endl;
    cin>>telU;
    c->setTel(telU);

    char* FNacU;
    cout<<"\n-> Fecha nacimiento: "<<endl;
    cin>>FNacU;
    c->setFnac(FNacU);

    char* generoU;
    cout<<"\n-> Genero: "<<endl;
    cin>>generoU;
    c->setGenero(generoU);

    char* dirU;
    cout<<"\n-> Direccion: "<<endl;
    cin>>dirU;
    c->setDir(dirU);
   
    char* nomUsuU;
    cout<<"\n-> Nombre de usuario: "<<endl;
    cin>>nomUsuU;
    c->setNombreUsu(nomUsuU);
    
    char* conU;
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>conU;
    c->setContrasenya(conU);

    char* centroU;
    cout<<"\n-> Centro: "<<endl;
    cin>>centroU;
    c->setCentro(centroU);

    
}



char Cliente::cMostrarMenuIniSes()
{
    Cliente *c;
    char* nombreDeUsuario;
    char* contrasenya;


    cout<<"\n======================================\n"<<endl;
    cout<<"INICIO DE SESION\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n\n"<<endl;
    
    cout<<"-> Nombre de usuario: "<<endl;
    cin>>nombreDeUsuario;
    c->setNombreUsu(nombreDeUsuario);
    
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>contrasenya;
    c->setContrasenya(contrasenya);
    

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

void Cliente::cMostrarMenuModifDatDir()
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

}

void Cliente::cMostrarMenuModifDatNomUsu()
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

}

void Cliente::cMostrarMenuModifDatContr()
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

char Cliente::cMostrarMenuImportarDatos()
{
    cout<<"Importando datos,no cierre la aplicación ... \n"<<endl;      
    
    
                                                                    //FALTA ALGO EN SOCKETS

} 




char Cliente::cMostrarMenuBorrarBaseDatos()
{
    cout<<"Importando datos: \n"<<endl;
}


char Cliente::cMostrarMenuAnyadirPolideportivo()
{
    Polideportivo p;
    
    

    cout<<"\n======================================\n"<<endl;
    cout<<"ANYADIR POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;


    char *ref;
    cout<<"-> Referencia del polideportivo: "<<endl;
    cin>>ref;
    //p->set        ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR 
    
    
    char *nombre;
    cout<<"\n-> Nombre del polideportivo: "<<endl;
    cin>>nombre;
    
    char *instalaciones;
    cout<<"\n-> Instalaciones del polideportivo: "<<endl;
    cin>>instalaciones;

    char *direccion;
    cout<<"\n-> Direccion del polideportivo: "<<endl;
    cin>>direccion;

    char *municipio;
    cout<<"\n-> Municipio al que pertenece el polideportivo: "<<endl;
    cin>>municipio;

    char* codMunicipio;
    cout<<"\n-> Codigo del Municipio al que pertenece el polideportivo: "<<endl;
    cin>>codMunicipio;

    char *provincia;
    cout<<"\n-> Provincia a la que pertenece el polideportivo: "<<endl;
    cin>>provincia;

    char* codProv;
    cout<<"\n-> Codigo de provincia del polideportivo: "<<endl;
    cin>>codProv;

    char* tel;
    cout<<"\n-> Telefono del polideportivo: "<<endl;
    cin>>tel;


}

static char cMostrarMenuAnyadirPolideportivo()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTION DE POLIDEPORTIVOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Seleccione la opcion que desee:\n\n"<<endl;
    
    cout<<"1.- Visualización general\n"<<endl;
    cout<<"2.- Visualización por municipios\n"<<endl;
    cout<<"3.- Anyadir polideportivo\n"<<endl;
    cout<<"4.- Modificar poliderportivo\n"<<endl;
    cout<<"5.- Eliminar poliderportivo\n\n"<<endl;
    cout<<"6. Volver"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;


    return linea;
}


static char cMostrarMenuVisualizacionGeneral()
{
    cout<<"Mostrando polideportivos... \n"<<endl;


}


static char cMostraMenuVisualizacionPorMunicipio()
{
    Polideportivo p;
    char* municipio;
    cout<<"-> Inserte nombre del municipio a mostrar: "<<endl;
    cin>>municipio;
    //p.                                                                  <- habría que hacerlo pero polideportivo está en c
}

static char cMostrarMenuModificarPolideportivo()
{
                                                                            //NO SÉ CÓMO QUEREMOS HACER PARA MODIFICARLO :(
}

static char cMostrarMenuEliminarPolideportivo()
{
                                                                            //NO SÉ CÓMO QUEREMOS HACER PARA ELIMINARLO :(
}

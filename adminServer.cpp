#include "adminServer.h"
#include "BaseDatos.h"
#include "sqlite3.h"
#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "cliente.h"
#define MAX_LINE 30

#include <iostream>

using namespace std;

Administrador::Administrador(){}

Administrador::Administrador(char* a)
{
    this->a = a;
    
}
Administrador::Administrador(const Administrador &a)
{
    this->nombreUsuario = a.nombreUsuario;
    this->contrasenya = a.contrasenya;
}
Administrador::~Administrador()
{
}

char* Administrador::getA()
{
    return this->a;
}

char* Administrador::setA(char* a)
{
    this->a = a;
}

char Administrador::sMostrarMenuGestPoli1()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTION DE POLIDEPORTIVOS DE EUSKADI\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Bienvenido al programa que administra e servidor, elige el numero que correspone con la opción que necesitas\n\n"<<endl;
    cout<<"1. Iniciar sesion\n"<<endl;
    cout<<"2. Registrar usuario\n"<<endl;
    cout<<"3. Salir\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;

    return linea;
}

void Administrador::sMostrarMenuRegUsu()
{
    sqlite3 *db;

    char* nombreUsu;

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
    BaseDatos::insertarUsuario(db, &u);
}

char Administrador::sMostrarMenuIniSes()
{
    Administrador *a;
    sqlite3 *db;
    char* nombreDeUsuario;
    char* contrasenya;

    cout<<"\n======================================\n"<<endl;
    cout<<"INICIO DE SESION\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n\n"<<endl;
    
    cout<<"-> Nombre de usuario: "<<endl;
    cin>>nombreDeUsuario;
    a->setNombreUsu(nombreDeUsuario);
    BaseDatos::selectAdmin(db, a, a->getNombreUsuario());
    
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>contrasenya;
    a->setContrasenya(contrasenya);
    BaseDatos::selectAdmin(db, a, a->getContrasenya());
    
    cout<<"\nPulsa enter para continuar "<<endl;  
    
}

char Administrador::sMostrarMenuMenuPrinc()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"MENU PRINCIPAL\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Seleccione una opcion: \n\n"<<endl;

    cout<<"1. Importar datos desde fichero\n"<<endl;
    cout<<"2. Gestionar polideportivos\n"<<endl;
    cout<<"3. Borrar base de datos\n"<<endl;
    cout<<"4. Volver\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;

    return linea;
}

char Administrador::sMostrarMenuImportDat()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"IMPORTAR DATOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Importando datos, no cierre la aplicacion...\n\n"<<endl;
    cout<<"Datos correctamente importados, pulse enter para continuar\n"<<endl;
    cin>>linea;

    return linea;
}

void Administrador::sMostrarMenuBorrarBD()
{
    char* respuesta;
    cout<<"\n======================================\n"<<endl;
    cout<<"BORRAR BASE DE DATOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Estas seguro de que quieres borrar la base de datos? [s/n]: "<<endl;
    cin>>respuesta;
    
    cout<<"\nBase de datos eliminada, pulse enter para continuar "<<endl;
    
}

char Administrador::gMostrarMenuGestPoli2()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTIONAR POLIDEPORTIVOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"1. Visualzacion general\n"<<endl;
    cout<<"2. Visualizacion por municipios\n"<<endl;
    cout<<"3. Anyadir polideportivo\n"<<endl;
    cout<<"4. Modificar polideportivo\n"<<endl;
    cout<<"5. Eliminar polideportivo\n"<<endl;
    cout<<"6. Volver\n\n"<<endl;
    cout<<"Opcion: (inserta el numero)"<<endl;
    cin>>linea;
    return linea;
}

void Administrador::gMostrarMenuListPoli()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"LISTADO DE POLIDEPORTIVOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"AQUI DEBERIA APARECER MUCHA DATA DE POLIDEPORTIVOS IMPORTADA DE BD"<<endl;
    cout<<"\nPulsa enter para volver "<<endl;
    cin>>linea;
}

void Administrador::gMostrarMenuListPoliMuni()
{
    char a[] = "Algun Municipio";
    
    cout<<"\n======================================\n"<<endl;
    cout<<"LISTADO DE POLIDEPORTIVOS DE"<< a<<"\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"AQUI DEBERIA APARECER DATA DE POLIDEPORTIVOS DE UN MUNICIPIO IMPORTADA DE BD"<<endl;
    cout<<"\nPulsa enter para volver "<<endl;
 

}

void Administrador::gMostrarMenuAnyadirPoli()
{
    cout<<"\n======================================\n"<<endl;
    cout<<"ANYADIR POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros:\n"<<endl;
    
    char* ref;
    sqlite3 *db;

    BaseDatos::selectMaxRef(db);

    char* nombreP;
    cout<<"-> Nombre: "<<endl;
    cin>>nombreP;
    
    char* instalaciones;
    cout<<"\n-> Instalaciones: "<<endl;
    cin>>instalaciones;
    
    char* dirP;
    cout<<"\n-> Direccion: "<<endl;
    cin>>dirP;
    
    char* muni;
    cout<<"\n-> Municipio: "<<endl;
    cin>>muni;
    
    char* codM;
    cout<<"\n-> Codigo del municipio: "<<endl;
    cin>>codM;
    
    char* prov;
    cout<<"\n-> Provincia(1 -> Araba, 2 -> Bizkaia, 3 -> Gipuzkoa): "<<endl;
    cin>>prov;

    char* codProv;
    cout<<"\n-> Codigo de provincia: "<<endl;
    cin>>codProv;

    char* tel;
    cout<<"\n-> Telefono: "<<endl;
    cin>>tel;

    Polideportivo p(ref, nombreP, instalaciones, dirP, muni, codM, prov, codProv, tel);
    cout<<"\nPolideportivo anyadido, pulse enter para continuar"<<endl;
    
}

char Administrador::gMostrarMenuModifPoli()
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"MODIFICAR POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros:\n\n"<<endl;
    
    cout<<"1. Nombre\n"<<endl;
    cout<<"2. Instalaciones(separadas por #)\n"<<endl;
    cout<<"3. Direccion\n"<<endl;
    cout<<"4. Municipio\n"<<endl;
    cout<<"5. Codigo de municipio\n"<<endl;
    cout<<"6. Provincia\n"<<endl;
    cout<<"7. Codigo de provincia\n"<<endl;
    cout<<"8. Telefono\n"<<endl;
    cout<<"9. Volver\n\n"<<endl;
    cout<<"Opcion: (numero)"<<endl;
    cin>>linea;

    return linea;
}

void Administrador::gMostrarMenuBorrarPoli()
{
    Polideportivo *p;
    char* nombreP;
    cout<<"\n======================================\n"<<endl;
    cout<<"ELIMINAR POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;

    cout<<"\nEscriba el nombre del polideportivo a eliminar: "<<endl;
    cin>>nombreP;


    char* resp;
    cout<<"\nEstas seguro de que quieres borrar el polideportivo? [s/n]: "<<endl;
    cin>>resp;

    sqlite3 *db;
    if (resp == "s")
    {
        BaseDatos::borrarPoli(db, nombreP);
    }
    

    cout<<"\nPolideportivo eliminado, pulse enter para continuar\n"<<endl;
    
}


int Administrador::sGestionPolideportivos(void)
{
    char opcion;

    do{
        opcion = Administrador::sMostrarMenuGestPoli1();
        switch (opcion)
        {
        case '1':
            Administrador::sIniciarSesion();
            break;

        case '2':
            Administrador::sRegistroUsuario();
            break;

        default:
            break;
        }
    }while(opcion != '3');
}



int Administrador::sRegistroUsuario(void)
{

    Administrador::sMostrarMenuRegUsu();

}

int Administrador::sIniciarSesion(void)
{

    Administrador::sMostrarMenuIniSes();

}


#include "cliente.h"
#include <iostream>
#include <string.h>
//#include "sqlite3.h"
#include <stdlib.h>
#include "adminServer.h"
#include "BaseDatos.h"
#include "usuario.h"
#include "polideportivo.h"

using namespace std;

Cliente::Cliente()
{

}

Cliente::Cliente(char* centro, char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya)
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

void Cliente::falsoConstructor(char* centro, char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya)
{
    Cliente client(centro, nombre, apellido, fNac, genero, DNI, tel, direccion, nombreUsuario, contrasenya);
    *this = client;
}

char* Cliente::getCentro()
{
    return this->centro;
}

char* Cliente::setCentro(char* centro)
{
    this->centro = centro;
}


void Cliente::leerPolideportivos(Polideportivo* p, char* fichero)
{
    FILE* file = fopen(fichero, "r");

    int contlinea;
    int charIndex;
    char **lineas;
    char c;
    Polideportivo* poli = (Polideportivo*) malloc(sizeof(Polideportivo)*4618);

    int puntoComa = 0;

    char alex[100];
    int count = 0;
    int cond = 0;
    int estante = 0;
    int caja = 0;

    while ((c=fgetc(file)) != EOF)
    {
        
        if(c =='\n'){
            cond = 1;
        }
        if(cond == 1){
            while (cond == 1)
            {
                c = fgetc(file);
                if(c == ';'){

                    break;

                }

                if (c != '\n')
                {
                    alex[count++] = c;
                } else {

                    estante += 1;
                    break;


                }
                
                
            }
            alex[count] = '\0';
            
            if(caja == 0){
                poli[estante].setRef(alex);
            }


            count = 0;
            caja += 1;
            
        } else{

            c = fgetc(file);

        }

        

    }

    p = poli;
    fclose(file);
}


//MENUS VISUALES

int Cliente::cMostrarMenuGestPoli1()
{
    int linea;
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

void Cliente::cMostrarMenuRegUsu()
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
    cout<<"Rellene los siguientes parametros\n"<<endl;
    cout<<"PORFAVOR, INTRODUCE NOMBRE COMO NOMBRE Y PASS COMO CONTRASENYA\n"<<endl;
    
    cout<<"-> Nombre de usuario: "<<endl;
    cin>>nombreDeUsuario;
    c->setNombreUsu(nombreDeUsuario);
    
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>contrasenya;
    c->setContrasenya(contrasenya);
    

}




int Cliente::cMostrarMenuMenuPrinc()
{
    int linea;
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
    Cliente *c;

    char* nombreDeUsuario;
    char* nuevaDireccion;

    cout<<"\nEscriba el nombre del usuario: "<<endl;
    cin>>nombreDeUsuario;
    c->setNombreUsu(nombreDeUsuario);

    cout<<"\nNueva direccion: "<<endl;
    cin>>nuevaDireccion;
    c->setDir(nuevaDireccion);
    cout<<"\nDireccion actualizada\n"<<endl;

}

void Cliente::cMostrarMenuModifDatNomUsu()
{
    Usuario *c;

    char* nuevoNombreDeUsuario;
    char* nombreDeUsuario;

    cout<<"\nEscriba el nombre del usuario: "<<endl;
    cin>>nombreDeUsuario;
    c->setNombreUsu(nombreDeUsuario);

    cout<<"\nNuevo nombre de usuario: "<<endl;
    cin>>nuevoNombreDeUsuario;
    c->setNombreUsu(nuevoNombreDeUsuario);
    cout<<"\nNombre de usuario actualizado\n"<<endl;

}

void Cliente::cMostrarMenuModifDatContr()
{
    Usuario *c;

    char* nuevaContrasenya;
    char* nombreDeUsuario;

    cout<<"\nEscriba el nombre del usuario: "<<endl;
    cin>>nombreDeUsuario;
    c->setNombreUsu(nombreDeUsuario);


    cout<<"\nNueva contrasenya: "<<endl;
    cin>>nuevaContrasenya;
    c->setContrasenya(nuevaContrasenya);

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
    Polideportivo *p;
    
    

    cout<<"\n======================================\n"<<endl;
    cout<<"ANYADIR POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;


    char *ref;
    cout<<"-> Referencia del polideportivo: "<<endl;
    cin>>ref;
    p->setRef(ref);
    
    char *nombre;
    cout<<"\n-> Nombre del polideportivo: "<<endl;
    cin>>nombre;
    p->setNombre(nombre);
    
    char *instalaciones;
    cout<<"\n-> Instalaciones del polideportivo: "<<endl;
    cin>>instalaciones;
    p->setInstalaciones(instalaciones);

    char *direccion;
    cout<<"\n-> Direccion del polideportivo: "<<endl;
    cin>>direccion;
    p->setDireccion(direccion);

    char *municipio;
    cout<<"\n-> Municipio al que pertenece el polideportivo: "<<endl;
    cin>>municipio;
    p->setMunicipio(municipio);

    char* codMunicipio;
    cout<<"\n-> Codigo del Municipio al que pertenece el polideportivo: "<<endl;
    cin>>codMunicipio;
    p->setCodMunicipio(codMunicipio);

    char *provincia;
    cout<<"\n-> Provincia a la que pertenece el polideportivo: "<<endl;
    cin>>provincia;
    p->setProvincia(provincia);

    char* codProv;
    cout<<"\n-> Codigo de provincia del polideportivo: "<<endl;
    cin>>codProv;
    p->setCodProv(codProv);

    char* tel;
    cout<<"\n-> Telefono del polideportivo: "<<endl;
    cin>>tel;
    p->setTel(tel);


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


static void cMostrarMenuVisualizacionGeneral()
{
    cout<<"Mostrando polideportivos... \n"<<endl;
    

}


static void cMostraMenuVisualizacionPorMunicipio() //se envía el nombre para que devuelva un polideportivo
{
    Polideportivo *p;
    char* nombre;
    cout<<"-> Inserte nombre del municipio a mostrar: "<<endl;
    cin>>nombre;
    p->setNombre(nombre);                                                                // falta coger el polideportivo dado el nombre
}

static char cMostrarMenuModificarPolideportivo()
{
   
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"MODIFICAR DATOS DEL POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Seleccione el dato que quiera modificar:\n\n"<<endl;
    
    cout<<"1. Nombre\n"<<endl;
    cout<<"2. Direccion\n"<<endl;
    cout<<"3. Telefono\n"<<endl;
    cout<<"4. Municipio\n"<<endl;
    cout<<"5. Codigo de municipio\n"<<endl;
    cout<<"6. Provincia\n"<<endl;
    cout<<"7. Codigo de provincia\n"<<endl;
    cout<<"8. Volver\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;

    return linea;

}


static void cMostrarMenuModifPoliNom(){

    Polideportivo *p;

    char* nom;
    char* nomNuevo;

    cout<<"\nEscriba el codigo de referencia del polideportivo: "<<endl;
    cin>>nom;
    p->setRef(nom);

    cout<<"\nNuevo codigo de referencia del polideportivo: "<<endl;
    cin>>nomNuevo;
    p->setRef(nomNuevo);
    cout<<"\nCodigo de referencia del polideportivo actualizado\n"<<endl;


}       //ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL ESTA MAL 


static void cMostrarMenuModifPoliInst(){

    Polideportivo *p;

    char* ref;
    char* instalaciones;

    cout<<"\nEscriba el codigo de referencia del polideportivo: "<<endl;
    cin>>ref;
    p->setRef(ref);

    cout<<"\nNuevas instalaciones del polideportivo: "<<endl;
    cin>>instalaciones;
    p->setInstalaciones(instalaciones);
    cout<<"\nInstalaciones del polideportivo actualizado\n"<<endl;


}


static void cMostrarMenuModifPoliTel(){

    Polideportivo *p;

    char* ref;
    char* tel;

    cout<<"\nEscriba el codigo de referencia del polideportivo: "<<endl;
    cin>>ref;
    p->setRef(ref);

    cout<<"\nNuevo telefono del polideportivo: "<<endl;
    cin>>tel;
    p->setTel(tel);
    cout<<"\nTelefono del polideportivo actualizado\n"<<endl;


}







static void cMostrarMenuEliminarPolideportivo()
{

    Polideportivo *p;

    char* ref;

    cout<<"\nEscriba el codigo de referencia del polideportivo a eliminar: "<<endl;
    cin>>ref;
    p->setRef(ref);


}

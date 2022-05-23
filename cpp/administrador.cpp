#include "administrador.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "sqlite3.h"

using namespace std;

void Administrador::limpiarEntrada(char *str, int max_line)
{
    if((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
        while(getchar() != '\n');
}

char Administrador::sMostrarMenuGestPoli1()
{
    char linea [MAX_LINE];
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTION DE POLIDEPORTIVOS DE EUSKADI\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Bienvenido al programa que administra e servidor\n\n"<<endl;
    cout<<"1. Iniciar sesion\n"<<endl;
    cout<<"2. Registrar usuario\n"<<endl;
    cout<<"3. Salir\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    getline(cin, linea);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}


Usuario Administrador::sMostrarMenuRegUsu():Usuario(nombre)
{
    sqlite3 *db;
    Usuario u;
    char linea [MAX_LINE];

    cout<<"\n======================================\n"<<endl;
    cout<<"REGISTRO DE USUARIO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;
    
    char nombre;
    cout<<"-> Nombre: "<<endl;
    getline(cin, nombre);
    limpiarEntrada(u.nombre, MAX_LINE);
    *u.this->nombre = insertarUsuario(db, u.nombre);

    
    printf("\n-> Apellido: ");
    fgets(u.apellido, MAX_LINE, stdin);
    limpiarEntrada(u.apellido, MAX_LINE);
    *u.apellido = insertarUsuario(db, u.apellido);
    
    printf("\n-> DNI: ");
    fgets(*u.DNI, MAX_LINE, stdin);
    limpiarEntrada(*u.DNI, MAX_LINE);
    *u.DNI = insertarUsuario(db, *u.DNI);

    printf("\n-> Fecha nacimiento: ");
    fgets(u.fNac, MAX_LINE, stdin);
    limpiarEntrada(u.fNac, MAX_LINE);
    *u.fNac = insertarUsuario(db, u.fNac);

    printf("\n-> Genero: ");
    fgets(u.genero, MAX_LINE, stdin);
    limpiarEntrada(u.genero, MAX_LINE);
    *u.genero = insertarUsuario(db, u.genero);
    
    printf("\n-> Direccion: ");
    fgets(*u.direccion, MAX_LINE, stdin);
    limpiarEntrada(*u.direccion, MAX_LINE);
    *u.direccion = insertarUsuario(db, *u.direccion);
    
    /*
    printf("\n-> Tipo de cuota: ");
    fgets(*u.cuota, MAX_LINE, stdin);
    limpiarEntrada(u.cuota, MAX_LINE);
    *u.cuota = insertarUsuario(db, u.cuota);
    */

    printf("\n-> Nombre de usuario: ");
    fgets(*u.nombreUsuario, MAX_LINE, stdin);
    limpiarEntrada(*u.nombreUsuario, MAX_LINE);
    *u.nombreUsuario = insertarUsuario(db, *u.nombreUsuario);
    
    printf("\n-> Contrasenya: ");
    fgets(*u.contrasenya, MAX_LINE, stdin);
    limpiarEntrada(*u.contrasenya, MAX_LINE);
    *u.contrasenya = insertarUsuario(db, *u.contrasenya);

    printf("\nUsuario creado correctamente, pulsa enter para continuar ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    return u;
}

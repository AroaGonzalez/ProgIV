#include "cliente.h"
#include <iostream>
#include <string.h>
#include "sqlite3.h"
#include <stdlib.h>
#include "administrador.h"
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
                p[contlinea]->ref = lineas;

            }else if (puntoComa == 2)
            {
                p[contlinea]->nombre = lineas;

            }else if (puntoComa == 3)
            {
                p[contlinea]->instalaciones = lineas;

            }else if (puntoComa == 4)
            {
                p[contlinea]->direccion = lineas;

            }else if (puntoComa == 5)
            {
                p[contlinea]->municipio = lineas;

            }else if (puntoComa == 6)
            {
                p[contlinea]->codMunicipio = lineas;

            }else if (puntoComa == 7)
            {
                p[contlinea]->provincia = lineas;

            }else if (puntoComa == 8)
            {
                p[contlinea]->codProv = lineas;

            }else if (puntoComa == 9)
            {
                p[contlinea]->tel = lineas;
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
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


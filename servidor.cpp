#include "servidor.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <iostream>

using namespace std;


void Servidor::mostrarMenuServerEspera()
{
    cout<<"\n======================================\n"<<endl;
    cout<<"SERVIDOR\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Servidor lanzado correctamente"<<endl;
}

void Servidor::mostrarMenuClienteConn()
{
    cout<<"\nCliente conectado con exito!\n"<<endl;
}
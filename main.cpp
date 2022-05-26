#include "sqlite3.h"
#include "usuario.h"
#include "adminServer.h"
#include "cliente.h"
#include "reserva.h"
#include "polideportivo.h"
#include "BaseDatos.h"
#include "servidor.h"

#include <iostream>
using namespace std;

#include <string.h>
#define MAX_LINE 30
#define DNI_LINE 8


int menuLogIn (void)
{

    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"PROYECTO PROG IV (NOMBRE PROVISIONAL XD)\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Como deseas entrar? (Pulsa numero)"<<endl;
    
    cout<<"\n\n1. AdminServer\n"<<endl;
    cout<<"2. Servidor\n"<<endl;
    cout<<"3. Cliente\n"<<endl;
    cout<<"4. Salir\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;

    return linea;

}

int main(void)
{
    sqlite3 *db;

	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		cout<<"Error opening database\n"<<endl;
		return result;
	}

    cout<<"Database opened\n"<<endl;

    char opcion;

    Servidor c;

    do{
        opcion = menuLogIn();
        switch (opcion)
        {
        case '1':
            Administrador::sGestionPolideportivos();
            break;

        case '2':
            Servidor::mostrarMenuServerEspera();
            break;
        
        case '3':
            Cliente::cGestionPolideportivos();
            break;
        
        default:
            break;
        }
    }while(opcion != '4');

    result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		cout<<"Error opening database\n"<<endl;
		cout<<sqlite3_errmsg(db)<<endl;
		return result;
	}

	cout<<"Database closed\n"<<endl;
}
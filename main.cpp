#include "menu.h"
#include "sqlite3.h"
#include "usuario.h"
#include "adminServer.h"
#include "cliente.h"
#include "reserva.h"
#include "polideportivo.h"
#include "BaseDatos.h"

#include <iostream>
using namespace std;

#include <string.h>
#define MAX_LINE 30
#define DNI_LINE 8


int main1 (void)
{

    char linea [5];
    printf("\n======================================\n");
    printf("PROYECTO PROG IV (NOMBRE PROVISIONAL XD)\n");
    printf("======================================\n\n");
    printf("Como deseas entrar? ");
    
    printf("\n\n1. AdminServer\n");
    printf("2. Servidor\n");
    printf("3. Cliente\n");
    printf("4. Salir\n\n");
    printf("Opcion: ");
    fgets(linea, 5, stdin);
    limpiarEntrada(linea, 5);

    return *linea;

}

int main(void)
{
    sqlite3 *db;

	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

    printf("Database opened\n");

    char opcion;

    do{
        opcion = main1();
        switch (opcion)
        {
        case '1':
            sGestionPolideportivos();
            break;

        case '2':
            mostrarMenuServerEspera();
            break;
        
        case '3':
            cGestionPolideportivos();
            break;
        
        default:
            break;
        }
    }while(opcion != '4');

    result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Database closed\n") ;
}
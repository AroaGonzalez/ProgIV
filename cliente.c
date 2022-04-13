#include "menu.h"
#include <stdio.h>
#include <string.h>
#include "sqlite3.h"
#include <stdlib.h>

#define MAX_LINE 30
#define DNI_LINE 8

void leerPolideportivos(Polideportivo* p[], char* fichero)
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


char cMostrarMenuGestPoli1()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("GESTION DE POLIDEPORTIVOS DE EUSKADI\n");
    printf("======================================\n\n");
    printf("Bienvenido al programa que administra el servidor\n");
    printf("1. Iniciar sesion\n");
    printf("2. Registrar usuario\n");
    printf("3. Salir\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

Usuario cMostrarMenuRegUsu()
{
    sqlite3 *db;
    Usuario *u;
    char linea [MAX_LINE];

    printf("\n======================================\n");
    printf("REGISTRO DE USUARIO\n");
    printf("======================================\n\n");
    printf("Rellene los siguientes parametros\n");
    
    printf("-> Nombre: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(u->nombre, MAX_LINE);
    *u->nombre = insertarUsuario(db, linea);

    printf("\n-> Apellido: ");
    fgets(u->apellido, MAX_LINE, stdin);
    limpiarEntrada(u->apellido, MAX_LINE);
    *u->apellido = insertarUsuario(db, u->apellido);
    
    printf("\n-> DNI: ");
    fgets(u->DNI, MAX_LINE, stdin);
    limpiarEntrada(u->DNI, MAX_LINE);
    *u->DNI = insertarUsuario(db, u->DNI);

    printf("\n-> Fecha nacimiento: ");
    fgets(u->fNac, MAX_LINE, stdin);
    limpiarEntrada(u->fNac, MAX_LINE);
    *u->fNac = insertarUsuario(db, u->fNac);

    printf("\n-> Genero: ");
    fgets(u->genero, MAX_LINE, stdin);
    limpiarEntrada(u->genero, MAX_LINE);
    *u->genero = insertarUsuario(db, u->genero);
    
    printf("\n-> Direccion: ");
    fgets(u->direccion, MAX_LINE, stdin);
    limpiarEntrada(u->direccion, MAX_LINE);
    *u->direccion = insertarUsuario(db, u->direccion);
    
    printf("\n-> Tipo de cuota: ");
    fgets(u->cuota, MAX_LINE, stdin);
    limpiarEntrada(u->cuota, MAX_LINE);
    *u->cuota = insertarUsuario(db, u->cuota);
    
    printf("\n-> Nombre de usuario: ");
    fgets(u->nombreUsuario, MAX_LINE, stdin);
    limpiarEntrada(u->nombreUsuario, MAX_LINE);
    *u->nombreUsuario = insertarUsuario(db, u->nombreUsuario);
    
    printf("\n-> Contrasenya: ");
    fgets(u->contrasenya, MAX_LINE, stdin);
    limpiarEntrada(u->contrasenya, MAX_LINE);
    *u->contrasenya = insertarUsuario(db, u->contrasenya);

    printf("\nUsuario creado correctamente, pulsa enter para continuar ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    return *u;

}

Cliente cMostrarMenuIniSes()
{
    Cliente *c;
    sqlite3 *db;

    char linea [MAX_LINE];

    printf("\n======================================\n");
    printf("INICIO DE SESION\n");
    printf("======================================\n\n");
    printf("Rellene los siguientes parametros\n\n");
    
    printf("-> Nombre de usuario: ");
    fgets(c->nombreUsuario, MAX_LINE, stdin);
    limpiarEntrada(c->nombreUsuario, MAX_LINE);
    *c->nombreUsuario = insertarUsuario(db, c->nombreUsuario);
    
    printf("\n-> Contrasenya: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    *c->contrasenya = insertarUsuario(db, c->contrasenya);

    printf("\nPulsa enter para continuar ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    return *c;
}

char cMostrarMenuMenuPrinc()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("MENU PRINCIPAL\n");
    printf("======================================\n\n");
    printf("Seleccione una opcion: \n\n");
    printf("1. Gestionar reservas\n");
    printf("2. Modificar datos personales\n");
    printf("3. Contactar con otros polideportivos\n");
    printf("4. Gestionar polideportivos\n");
    printf("5. Volver\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char cMostrarMenuGestReserv()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("GESTIONAR RESERVAS\n");
    printf("======================================\n\n");
    printf("1. Reservar espacio deportivo\n");
    printf("2. Anular reserva\n");
    printf("3. Volver\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char cMostrarMenuModifDat()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("MODIFICAR DATOS PERSONALES\n");
    printf("======================================\n\n");
    printf("Seleccione el dato que quiera modificar:\n\n");
    
    printf("1. Direccion\n");
    printf("2. Tipo de cuota\n");
    printf("3. Nombre de usuario\n");
    printf("4. Contrasenya\n");
    printf("5. Volver\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    return *linea;
}

Usuario cMostrarMenuModifDatDir()
{
    sqlite3 *db;
    Usuario *u;
    char linea [MAX_LINE];

    printf("\nNueva direccion: ");
    fgets(u->direccion, MAX_LINE, stdin);
    limpiarEntrada(u->direccion, MAX_LINE);
    printf("\nDireccion actualizada\n");
    *u->direccion = insertarUsuario(db, u->direccion);

    return *u;
}

Usuario cMostrarMenuModifDatTCout()
{
    sqlite3 *db;
    Usuario *u;

    char linea [MAX_LINE];
    printf("\nNuevo tipo de cuota: ");
    fgets(u->cuota, MAX_LINE, stdin);
    limpiarEntrada(u->cuota, MAX_LINE);
    printf("\nTipo de cuota actualizado\n");
    *u->cuota = insertarUsuario(db, u->cuota);

    return *u;
}

Usuario cMostrarMenuModifDatNomUsu()
{
    Usuario *u;
    sqlite3 *db;
    char linea [MAX_LINE];

    printf("\nNuevo nombre de usuario: ");
    fgets(u->nombreUsuario, MAX_LINE, stdin);
    limpiarEntrada(u->nombreUsuario, MAX_LINE);
    printf("\nNombre de usuario actualizado\n");
    *u->nombreUsuario = insertarUsuario(db, u->nombreUsuario);

    return *u;
}

Usuario cMostrarMenuModifDatContr()
{
    Usuario *u;
    sqlite3 *db;

    char linea [MAX_LINE];
    printf("\nNueva contrasenya: ");
    fgets(u->contrasenya, MAX_LINE, stdin);
    limpiarEntrada(*u->contrasenya, MAX_LINE);
    printf("\nContrasenya actualizada\n");
    *u->contrasenya = insertarUsuario(db, u->contrasenya);

    return *u;
}

char cMostrarMenuContactPoli()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("CONTACTAR CON OTROS POLIDEPORTIVOS\n");
    printf("======================================\n\n");
    
    printf("-> Nombre del polideportivo: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    int telef = 666666666;    
    printf("\nEl numero telefonico del polideportivo es: %i", telef);

    return *linea;}


int cGestionPolideportivos(void)
{
    char opcion;

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



int cRegistroUsuario(void)
{

    cMostrarMenuRegUsu();

}

int cIniciarSesion(void)
{

    cMostrarMenuIniSes();

}


#include "menu.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINE 5

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

char cMostrarMenuRegUsu()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("REGISTRO DE USUARIO\n");
    printf("======================================\n\n");
    printf("Rellene los siguientes parametros\n");
    
    printf("-> Nombre: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Apellido: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> DNI: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Direccion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Tipo de cuota: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Nombre de usuario: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Contrasenya: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    printf("\nUsuario creado correctamente, pulsa enter para continuar ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    return *linea;
}

char cMostrarMenuIniSes()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("INICIO DE SESION\n");
    printf("======================================\n\n");
    printf("Rellene los siguientes parametros\n\n");
    
    printf("-> Nombre de usuario: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Contrasenya: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    printf("\nPulsa enter para continuar ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
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

char cMostrarMenuModifDatDir()
{
    char linea [MAX_LINE];
    printf("\nNueva direccion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    printf("\nDireccion actualizada\n");

    return *linea;
}

char cMostrarMenuModifDatTCout()
{
    char linea [MAX_LINE];
    printf("\nNuevo tipo de cuota: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    printf("\nTipo de cuota actualizado\n");

    return *linea;
}

char cMostrarMenuModifDatNomUsu()
{
    char linea [MAX_LINE];
    printf("\nNuevo nombre de usuario: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    printf("\nNombre de usuario actualizado\n");

    return *linea;
}

char cMostrarMenuModifDatContr()
{
    char linea [MAX_LINE];
    printf("\nNueva contrasenya: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    printf("\nContrasenya actualizada\n");

    return *linea;
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


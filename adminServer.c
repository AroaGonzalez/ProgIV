#include "menu.h"
#include "sqlite3.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINE 30

void limpiarEntrada(char *str, int max_line)
{
    if((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
        while(getchar() != '\n');
}

char sMostrarMenuGestPoli1()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("GESTION DE POLIDEPORTIVOS DE EUSKADI\n");
    printf("======================================\n\n");
    printf("Bienvenido al programa que administra e servidor\n\n");
    printf("1. Iniciar sesion\n");
    printf("2. Registrar usuario\n");
    printf("3. Salir\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

Usuario sMostrarMenuRegUsu()
{
    sqlite3 *db;
    Usuario *u;
    char linea [MAX_LINE];

    printf("\n======================================\n");
    printf("REGISTRO DE USUARIO\n");
    printf("======================================\n\n");
    printf("Rellene los siguientes parametros\n");
    
    printf("-> Nombre: ");
    fgets(u->nombre, MAX_LINE, stdin);
    limpiarEntrada(u->nombre, MAX_LINE);
    *u->nombre = insertarUsuario(db, u->nombre);

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

char sMostrarMenuIniSes()
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

char sMostrarMenuMenuPrinc()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("MENU PRINCIPAL\n");
    printf("======================================\n\n");
    printf("Bienvenido al programa que administra e servidor\n\n");
    printf("1. Importar datos desde fichero\n");
    printf("2. Gestionar polideportivos\n");
    printf("3. Borrar base de datos\n");
    printf("4. Volver\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char sMostrarMenuImportDat()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("IMPORTAR DATOS\n");
    printf("======================================\n\n");
    printf("Importando datos, no cierre la aplicacion...\n\n");
    printf("Datos correctamente importados, pulse enter para continuar\n");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char sMostrarMenuBorrarBD()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("BORRAR BASE DE DATOS\n");
    printf("======================================\n\n");
    printf("Estas seguro de que quieres borrar la base de datos? [s/n]: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    printf("\nBase de datos eliminada, pulse enter para continuar ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char gMostrarMenuGestPoli2()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("GESTIONAR POLIDEPORTIVOS\n");
    printf("======================================\n\n");
    printf("1. Visualzacion general\n");
    printf("2. Visualizacion por municipios\n");
    printf("3. Anyadir polideportivo\n");
    printf("4. Modificar polideportivo\n");
    printf("5. Eliminar polideportivo\n");
    printf("6. Volver\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char gMostrarMenuListPoli()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("LISTADO DE POLIDEPORTIVOS\n");
    printf("======================================\n\n");
    printf("AQUI DEBERIA APARECER MUCHA DATA DE POLIDEPORTIVOS IMPORTADA DE BD");
    printf("\nPulsa enter para volver ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char gMostrarMenuListPoliMuni()
{
    char a[] = "Algun Municipio";
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("LISTADO DE POLIDEPORTIVOS DE [%s]\n", a);
    printf("======================================\n\n");
    printf("AQUI DEBERIA APARECER DATA DE POLIDEPORTIVOS DE UN MUNICIPIO IMPORTADA DE BD");
    printf("\nPulsa enter para volver ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}

char gMostrarMenuAnyadirPoli()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("ANYADIR POLIDEPORTIVO\n");
    printf("======================================\n\n");
    printf("Rellene los siguientes parametros:\n");
    
    printf("-> Nombre: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Instalaciones(separadas por #): ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Direccion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Municipio: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Codigo del municipio: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    
    printf("\n-> Provincia(1 -> Araba, 2 -> Bizkaia, 3 -> Gipuzkoa): ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    printf("\n-> Codigo de provincia: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    printf("\n-> Telefono: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    printf("\nPolideportivo anyadido, pulse enter para continuar");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    return *linea;
}

char gMostrarMenuModifPoli()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("MODIFICAR POLIDEPORTIVO\n");
    printf("======================================\n\n");
    printf("Rellene los siguientes parametros:\n\n");
    
    printf("1. Nombre\n");
    printf("2. Instalaciones(separadas por #)\n");
    printf("3. Direccion\n");
    printf("4. Municipio\n");
    printf("5. Codigo de municipio\n");
    printf("6. Provincia\n");
    printf("7. Codigo de provincia\n");
    printf("8. Telefono\n");
    printf("9. Volver\n\n");
    printf("Opcion: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);

    return *linea;
}

char gMostrarMenuBorrarPoli()
{
    char linea [MAX_LINE];
    printf("\n======================================\n");
    printf("ELIMINAR POLIDEPORTIVO\n");
    printf("======================================\n\n");
    printf("\nEscriba el nombre del polideportivo a eliminar: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    printf("\nEstas seguro de que quieres borrar el polideportivo? [s/n]: ");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    printf("\nPolideportivo eliminado, pulse enter para continuar\n");
    fgets(linea, MAX_LINE, stdin);
    limpiarEntrada(linea, MAX_LINE);
    return *linea;
}


int sGestionPolideportivos(void)
{
    char opcion;

    do{
        opcion = sMostrarMenuGestPoli1();
        switch (opcion)
        {
        case '1':
            sIniciarSesion();
            break;

        case '2':
            sRegistroUsuario();
            break;

        default:
            break;
        }
    }while(opcion != '3');
}



int sRegistroUsuario(void)
{

    sMostrarMenuRegUsu();

}

int sIniciarSesion(void)
{

    sMostrarMenuIniSes();

}


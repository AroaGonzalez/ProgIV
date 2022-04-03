#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
}
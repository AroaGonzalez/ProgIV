#include "administrador.h"
#include <string.h>
#include <stdio.h>

void Administrador::limpiarEntrada(char *str, int max_line)
{
    if((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
        while(getchar() != '\n');
}
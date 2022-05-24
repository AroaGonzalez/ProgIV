#ifndef _USUARIO_H_
#define _USUARIO_H_
#define DNI_LINE 9
#define MAX_LINE 30
#define TEL_MAX 9
#include "cuota.h"

typedef struct
{
    char nombre [MAX_LINE];
    char apellido [MAX_LINE];
    char fNac [MAX_LINE];
    char genero [MAX_LINE];
    char DNI [DNI_LINE];
    char tel [TEL_MAX];
    char direccion [MAX_LINE];
    Cuota *cuota;
    char nombreUsuario [MAX_LINE];
    char contrasenya [MAX_LINE];

}Usuario;

#endif
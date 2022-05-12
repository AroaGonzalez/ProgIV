#ifndef _USUARIO_H_
#define _USUARIO_H_
#define DNI_LINE 8
#define MAX_LINE 30

typedef struct
{
    char *nombre [MAX_LINE];
    char *apellido [MAX_LINE];
    char *fNac [MAX_LINE];
    char *genero [MAX_LINE];
    int *DNI [DNI_LINE];
    char *direccion [MAX_LINE];
    Cuota *cuota [MAX_LINE];
    char *nombreUsuario [MAX_LINE];
    char *contrasenya [MAX_LINE];

}Usuario;

#endif
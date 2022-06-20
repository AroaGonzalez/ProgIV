#ifndef _USUARIO1_H_
#define _USUARIO1_H_

typedef struct
{
    char* nombre;
    char* apellido;
    char* fNac;
    char* genero;
    char* DNI;
    char* tel;
    char* direccion;
    char* nombreUsuario;
    char* contrasenya;

}Usuario1;

void generarUsuario(Usuario1*, char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya);

int comparaUsuario(char* nombreUsuario, char* contrasenya);

#endif
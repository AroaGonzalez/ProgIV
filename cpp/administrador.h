#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_

#define DNI_LINE 8
#define MAX_LINE 30
#include "usuario.h"


class Administrador: public Usuario
{
    private:
        char* nombreUsuario [MAX_LINE];
        char* contrasenya [MAX_LINE];

    public:
        Administrador(); //vacío
        Administrador(); //por defecto (falta por hacer)
        Administrador(); //copia (falta por hacer)
        ~Administrador(); //destructor (falta por hacer)

        void limpiarEntrada(char *str, int max_line);
};


#endif
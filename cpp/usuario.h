#ifndef _USUARIO_H_
#define _USUARIO_H_

#define DNI_LINE 8
#define MAX_LINE 30



class Usuario
{
private:
    char *nombre [MAX_LINE];
    char *apellido [MAX_LINE];
    char *fNac [MAX_LINE];
    char *genero [MAX_LINE];
    int *DNI [DNI_LINE];
    char *direccion [MAX_LINE];
    char *nombreUsuario [MAX_LINE];
    char *contrasenya [MAX_LINE];
public:
Usuario(); //vacío
Usuario(const char *nombre, const char *apellido, const char *fNac, const char *genero, const int *DNI, char *direccion, char *nombreUsuario, const char *contrasenya); //por defecto (falta por hacer)
Usuario(const Usuario& u); //copia (falta por hacer)
virtual ~Usuario(); //destructor (falta por hacer)
};

#endif
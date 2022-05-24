#ifndef _POLIDEPORTIVO_H_
#define _POLIDEPORTIVO_H_

#define MAX_LINE 30

typedef struct
{
    char *ref;
    char *nombre;
    char *instalaciones;
    char *direccion;
    char *municipio;
    char* codMunicipio;
    char *provincia;
    char* codProv;
    char* tel;
}Polideportivo;


//POLIDEPORTIVO
void InicializarPoli(Polideportivo *p, char *ref, char* nombre, char* instalaciones, char *direccion, char* municipio, char* codMunicipio, char* provincia, char* codProv, char* tel);


#endif
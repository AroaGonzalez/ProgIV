#ifndef _POLIDEPORTIVO1_H_
#define _POLIDEPORTIVO1_H_


typedef struct Polideportivo
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

void generarPoli(Polideportivo* p, char *ref, char *nombre, char *instalaciones, char *direccion, char *municipio, char* codMunicipio, char *provincia, char* codProv, char* tel);

int visualizarPoli();

int callback(void *, int, char **, char **);

int poliPorMunicipio(char* municipio);

int anyadirPoli(char *ref, char *nombre, char *instalaciones, char *direccion, char *municipio, char* codMunicipio, char *provincia, char* codProv, char* tel);

int editarPoli(char* nombrePoli, char *ref, char *nombre, char *instalaciones, char *direccion, char *municipio, char* codMunicipio, char *provincia, char* codProv, char* tel);

int deletePoli(char* nombre);

int deleteDB();


#endif

        
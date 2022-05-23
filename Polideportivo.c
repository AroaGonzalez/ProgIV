#include "menu.h"
#include "polideportivo.h"
#include <string.h>
#include <stdlib.h>

void InicializarPoli(Polideportivo *p, char *ref, char* nombre, char** instalaciones, char *direccion, char* municipio, char* codMunicipio, char* provincia, char* codProv, char* tel)
{


    p->ref = malloc(sizeof(char)*(strlen(ref)+1));
    p->nombre = malloc(sizeof(char)*(strlen(nombre)+1));

    int numInst = 0;

    for (int i = 0; i < strlen(*p->instalaciones); i++)
    {
        if (*p->instalaciones[i] == '#')
        {
            numInst++;
        }
    }
    numInst++;

    p->instalaciones = (char**) malloc(sizeof(char*)*numInst);

    char c1;
    int charIndex1 = 0;
    int contPalabra = 0;

    while ((c1=fgetc(*p->instalaciones)) != ';')
	{
        if (c1 == '#')
        {
            contPalabra++;
            p->instalaciones[contPalabra] = (char*)malloc(sizeof(char)*charIndex1);
            charIndex1 = 0;
        }else
        {
            charIndex1++;
        }
        
    }

    p->direccion = malloc(sizeof(char)*(strlen(direccion)+1));
    p->municipio = malloc(sizeof(char)*(strlen(municipio)+1));
    p->provincia = malloc(sizeof(char)*(strlen(provincia)+1));
    p->codMunicipio = malloc(sizeof(char)*(strlen(codMunicipio)+1));
    p->codProv = malloc(sizeof(char)*(strlen(codProv)+1));
    p->tel = malloc(sizeof(char)*(strlen(tel)+1));

    for (int i = 0; i < numInst -1; i++)
		free(p->instalaciones[i]);

	free(p->ref);
    free(p->nombre);
    free(p->instalaciones);
    free(p->direccion);
    free(p->municipio);
    free(p->provincia);
    free(p->codMunicipio);
    free(p->codProv);
    free(p->tel);

}

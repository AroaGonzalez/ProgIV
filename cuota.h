#ifndef _CUOTA_H_
#define _CUOTA_H_

#define MAX_LINE 30

typedef struct
{
    int Cod[MAX_LINE];
    char Nombre[MAX_LINE];
    float Precio[MAX_LINE];
    char Tipo[MAX_LINE];
}Cuota;

#endif
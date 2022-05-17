#ifndef _POLIDEPORTIVO_H_
#define _POLIDEPORTIVO_H_

#define MAX_LINE 30

typedef struct
{
    int Cod[MAX_LINE];
    int Hora[MAX_LINE];
    char Tipo[MAX_LINE];
    float Precio[MAX_LINE];
    int Cod_poli[MAX_LINE];
}Reserva;

#endif
#include <time.h>
#include <stdio.h>
#include "Logger.h"

void registro()
{
  time_t t;
  struct tm *tm;
  char fechayhora[100];

  t=time(NULL);
  tm=localtime(&t);
  strftime(fechayhora, 100, "%d/%m/%Y", tm);

    FILE* escribir = fopen("fichero.txt", "a");

  fprintf (escribir, "Hoy es: %s\n", fechayhora);
  fprintf(escribir, "\n");
  fclose(escribir);
}

void acciones(char* accion)
{
    FILE* escribir = fopen("fichero.txt", "a");
    fprintf(escribir, accion);
    fprintf(escribir, "\n");
    fclose(escribir);
}
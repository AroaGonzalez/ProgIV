
#include <stdio.h>
#include <string.h>
#include <time.h>

void mostrarMenuServerEspera()
{
    printf("\n======================================\n");
    printf("SERVIDOR\n");
    printf("======================================\n\n");
    printf("Servidor lanzado correctamente");
}

void mostrarMenuClienteConn()
{
    printf("\nCliente conectado con exito!\n");
}


//========================================================
//Una funcion que he sacado de internet, worth para cuando queramos poner la fecha en la que se conecta al server

int fecha()
{
  time_t t;
  struct tm *tm;
  char fechayhora[100];

  t=time(NULL);
  tm=localtime(&t);
  strftime(fechayhora, 100, "%d/%m/%Y", tm);
  printf ("Hoy es: %s\n", fechayhora);
}
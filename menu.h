#ifndef _MENU_H_
#define _MENU_H_

//Limpiar entradas
void limpiarEntrada(char *str, int max_line);




//SERVIDOR

void mostrarMenuServerEspera();

void mostrarMenuClienteConn();

int fecha();


//ADMINSERVER + CLIENTE

char gMostrarMenuGestPoli2();

char gMostrarMenuListPoli();

char gMostrarMenuListPoliMuni();

char gMostrarMenuAnyadirPoli();

char gMostrarMenuModifPoli();

char gMostrarMenuBorrarPoli();



#endif

//comment prueba
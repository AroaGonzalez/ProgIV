#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#define DNI_LINE 8
#define MAX_LINE 30
#include "usuario.h"
#include "cuota.h"

namespace Containers{

class Cliente: public Usuario
{
private:
Cuota *cuota [MAX_LINE];
public:
Cliente(); //vacío
Cliente(); //por defecto (falta por hacer)
Cliente(); //copia (falta por hacer)
~Cliente(); //destructor (falta por hacer)

};

}

#endif
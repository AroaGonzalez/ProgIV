#include "usuario.h"
#include <string.h>
#include <iostream>
using namespace std;

Usuario::Usuario(char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->fNac = fNac;
    this->genero = genero;
    this->DNI = DNI;
    this->tel = tel;
    this->direccion = direccion;
    this->nombreUsuario = nombreUsuario;
    this->contrasenya = contrasenya;
}

Usuario::Usuario(const Usuario &u)
{
    this->nombre = u.nombre;
    this->apellido = u.apellido;
    this->fNac = u.fNac;
    this->genero = u.genero;
    this->DNI = u.DNI;
    this->tel = u.tel;
    this->direccion = u.direccion;
    this->nombreUsuario = u.nombreUsuario;
    this->contrasenya = u.contrasenya;

}

Usuario::~Usuario()
{
}

char* Usuario::getNombre()
{
    return this->nombre;
}

char* Usuario::setNombre(char* nombre)
{
    this->nombre = nombre;
}

char* Usuario::getApe()
{
    return this->apellido;
}

char* Usuario::setApe(char* apell)
{
    this->apellido = apellido;
}

char* Usuario::getFnac()
{
    return this->fNac;
}

char* Usuario::setFnac(char* Fnac)
{
    this->fNac = Fnac;
}

char* Usuario::getGenero()
{
    return this->genero;
}

char* Usuario::setGenero(char* genero)
{
    this->genero = genero;
}

char* Usuario::getDni()
{
    return this->DNI;
}

char* Usuario::setDni(char* Dni)
{
    this->DNI = Dni;
}

char* Usuario::getTel()
{
    return this->tel;
}

char* Usuario::setTel(char* tel)
{
    this->tel = tel;
}

char* Usuario::getDir()
{
    return this->direccion;
}

char* Usuario::setDir(char* dir)
{
    this->direccion = dir;
}

char* Usuario::getNombreUsuario()
{
    return this->nombreUsuario;
}

char* Usuario::setNombreUsu(char* nombreUsu)
{
    this->nombreUsuario = nombreUsu;
}

char* Usuario::getContrasenya()
{
    return this->contrasenya;
}

char* Usuario::setContrasenya(char* contrasenya)
{
    this->contrasenya = contrasenya;
}
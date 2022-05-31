#include "usuario.h"
#include <string.h>
#include <iostream>
using namespace std;

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
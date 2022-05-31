#include "polideportivo.h" 
#include <iostream>
#include <string.h>
//#include "sqlite3.h"
#include <stdlib.h>
#include "adminServer.h"
#include "BaseDatos.h"



using namespace std;

Polideportivo::Polideportivo()
{

}

Polideportivo::Polideportivo(char *ref,
        char *nombre,
        char *instalaciones,
        char *direccion,
        char *municipio,
        char* codMunicipio,
        char *provincia,
        char* codProv,
        char* tel)
{


    this->ref = ref;
    this->nombre = nombre;
    this->instalaciones = instalaciones;
    this->direccion = direccion;
    this->instalaciones = instalaciones;
    this->municipio = municipio;
    this->codMunicipio = codMunicipio;
    this->provincia = provincia;
    this->codProv = codProv;
    this->tel = tel;


}

Polideportivo::Polideportivo(const Polideportivo &p)
{
    this->ref = ref;
    this->nombre = nombre;
    this->instalaciones = instalaciones;
    this->direccion = direccion;
    this->instalaciones = instalaciones;
    this->municipio = municipio;
    this->codMunicipio = codMunicipio;
    this->provincia = provincia;
    this->codProv = codProv;
    this->tel = tel;
}

Polideportivo::~Polideportivo()
{
    //delete[] Polideportivo;
}


char* Polideportivo::getRef()
{
    return this->ref;
}

char* Polideportivo::setRef(char* ref)
{
    this->ref = ref;
}

char* Polideportivo::getNombre()
{
    return this->nombre;
}

char* Polideportivo::setNombre(char* nombre)
{
    this->nombre = nombre;
}

char* Polideportivo::getInstalaciones()
{
    return this->instalaciones;
}

char* Polideportivo::setInstalaciones(char* instalaciones)
{
    this->instalaciones = instalaciones;
}


char* Polideportivo::getDireccion()
{
    return this->direccion;
}

char* Polideportivo::setDireccion(char* direccion)
{
    this->direccion = direccion;
}


char* Polideportivo::getMunicipio()
{
    return this->municipio;
}

char* Polideportivo::setMunicipio(char* municipio)
{
    this->municipio = municipio;

}

char* Polideportivo::getCodMunicipio()
{
    return this->codMunicipio;
}

char* Polideportivo::setCodMunicipio(char* CodMunicipio)
{
    this->codMunicipio = codMunicipio;
}


char* Polideportivo::getProvincia()
{
    return this->provincia;
}

char* Polideportivo::setProvincia(char* provincia)
{
    this->provincia = provincia;
}


char* Polideportivo::getCodProv()
{
    return this->codProv;
}

char* Polideportivo::setCodProv(char* codProv)
{
    this->codProv = codProv;
}


char* Polideportivo::getTel()
{
    return this->tel;
}

char* Polideportivo::setTel(char* tel)
{
    this->tel = tel;
}

void Polideportivo::falsoConstructor(char *ref,
        char *nombre,
        char *instalaciones,
        char *direccion,
        char *municipio,
        char* codMunicipio,
        char *provincia,
        char* codProv,
        char* tel)
        {
            Polideportivo poli(ref, nombre, instalaciones, direccion, municipio, codMunicipio, provincia, codProv, tel);
            *this = poli;
        }



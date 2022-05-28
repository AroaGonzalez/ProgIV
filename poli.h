#ifndef _POLIDEPORTIVO_H_
#define _POLIDEPORTIVO_H_

class Polideportivo{

    protected:
        char *ref;
        char *nombre;
        char *instalaciones;
        char *direccion;
        char *municipio;
        char* codMunicipio;
        char *provincia;
        char* codProv;
        char* tel;
    public:
        Polideportivo();

        Polideportivo(char *ref,
        char *nombre,
        char *instalaciones,
        char *direccion,
        char *municipio,
        char* codMunicipio,
        char *provincia,
        char* codProv,
        char* tel);

        Polideportivo(const Polideportivo &p); 

        virtual ~Polideportivo();

        char* getNombre();
        char* setNombre(char* nombre);

        char* getInstalaciones();
        char* setInstalaciones(char* instalaciones);

        char* getDireccion();
        char* setDireccion(char* direccion);

        char* getMunicipio();
        char* setMunicipio(char* municipio);

        char* getCodMunicipio();
        char* setCodMunicipio(char* codMunicipio);

        char* getProvincia();
        char* setProvincia(char* provincia);

        char* getCodProv();
        char* setCodProv(char* codProv);

        char* getTel();
        char* setTel(char* tel);


        


};




#endif
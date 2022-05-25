#ifndef _USUARIO_H_
#define _USUARIO_H_


class Usuario
{
    private:
        char* nombre;
        char* apellido;
        char* fNac;
        char* genero;
        char* DNI;
        char* tel;
        char* direccion;
        char* nombreUsuario;
        char* contrasenya;
    
    public:

        Usuario(char* nombre, char* apellido, char* fNac, char* genero, char* DNI, char* tel, char* direccion, char* nombreUsuario, char* contrasenya);
        Usuario(const Usuario &u);
        virtual ~Usuario();

        char* getNombre();
        char* setNombre(char* nombre);
        char* getApe();
        char* setApe(char* apell);
        char* getFnac();
        char* setFnac(char* Fnac);
        char* getGenero();
        char* setGenero(char* genero);
        char* getDni();
        char* setDni(char* Dni);
        char* getTel();
        char* setTel(char* tel);
        char* getDir();
        char* setDir(char* dir);
        char* getNombreUsuario();
        char* setNombreUsu(char* nombreUsu);
        char* getContrasenya();
        char* setContrasenya(char* contrasenya);
        
};


#endif
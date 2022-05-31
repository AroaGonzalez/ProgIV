drop database if exists PolideportivosEuskadi;
create database PolideportivosEuskadi;
use PolideportivosEuskadi;


create table Usuario(
DNI char(9) not null,
Nombre char(20),
Apellidos char(30),
Fecha char,
Genero char(1),
Direccion char(50),
Tel char(9) not null,
nombreUsuario char(20),
Contrasenya char(20),
primary key (DNI),
check (Genero in ('N','F','M')),
check(Tel like '_________')
);

create table Administrador(
Nombre char(20),
Contrasenya char(20),
primary key (Contrasenya)
);

create table Cliente(
Nombre char(20),
Contrasenya char(20),
primary key (Contrasenya)
);

create table Polideportivo(
    Ref char(5) not null,
    Nombre char(15),
    Instalaciones char,
    Direccion char,
    Municipio char,
    Cod_mun char,
    Provincia char,
    Cod-prov char,
    Tel char,
    primary key (Ref)
);




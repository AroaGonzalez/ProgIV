drop database if exists PolideportivosEuskadi;
create database PolideportivosEuskadi;
use PolideportivosEuskadi;

create table Usuario(
Nombre char(20),
Apellidos char(30),
Fecha char,
Genero char(1),
DNI char(9) not null,
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
Contrasenya varchar(20),
primary key (Contrasenya)
);

create table Cliente(
Nombre char(20),
Contrasenya varchar(20),
primary key (Contrasenya)
);

create table Sala(
Cod int(5) not null,
Nombre char(20) not null,
Piso int(2) not null,
Disponibilidad BOOL,
primary key (codigo)
);

create table Polideportivo( 
ref char(5) not null,
nombre char(10) not null,
instalaciones char,
direccion char,
municipio char,
codMunicipio char,
provincia char,
codProvincia char,
tel int(3) not null,
primary key (Cod)
);

create table Reserva(
Cod char(5) not null,
Hora char(2) not null,
Tipo char(15),
Precio char(2),
Cod_poli char(5),
primary key (Cod),
foreign key (Cod_poli) references Polideportivo(Cod) on delete cascade
);

INSERT into Usuario values ('Begoña', 'Suarez', '2000', 'F', '12345678C', 'Menendez y Pelayo 22', '633707221', 'anacardo18', 'pepitoje');
INSERT into Usuario values ('Vicccctor', 'Bilbao', '2000', 'M', '12345678C', 'Don quijote 3', '631234567', 'Vikturski', 'pepino123');
INSERT into Usuario values ('Aitttor', 'Guayo', '2002', 'M', '12345678C', 'San Juan 23', '633987543', 'aitorrcio', '12473c');

INSERT into Polideportivo values ('00001', 'Txurdinaga', '5 pistas de tenis, 6 frontones, 1 campo de futbol, 2 piscinas, 1 gimnasio', 'Parque txurdinaga', 'Bilbao', '111', 'Bizkaia', '222', '944333222');
INSERT into Polideportivo values ('00002', 'Atxuri', '1 piscina, 1 gimnasio', 'parque atxuri', 'Bilbao', '111', 'Bizkaia', '222', '944777888');
INSERT into Polideportivo values ('00003', 'El Fango', '4 pistas de tenis, 1 campo de futbol, 1 campo de rugby, 2 piscinas, 1 campo de beisbol', 'Recalde 22', 'Recalde', '213', 'Bizkaia', '222', '944333222');
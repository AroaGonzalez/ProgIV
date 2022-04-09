drop database if exists PolideportivosEuskadi;
create database PolideportivosEuskadi;
use PolideportivosEuskadi;

create table Cuota(
Cod int(3) not null,
Nombre char(15),
Precio int(3) not null,
Tipo char(20),
primary key (COD)
);

create table Usuario(
DNI int(8) not null,
Nombre char(20),
Apellidos char(30),
Fecha date,
Genero char(1),
Direccion varchar(50),
Tel int(9) not null,
nombreUsuario char(20),
Contrasenya varchar(20),
Cod_cuota int(3),
primary key (DNI),
foreign key (Cod_cuota) references Cuota(Cod) on delete cascade,
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
Cod int(5) not null,
nombre char(10) not null,
Telefono int(3) not null,
primary key (Cod)
);

create table Reserva(
Cod int(5) not null,
Hora int(2) not null,
Tipo char(15),
Precio int(2),
Cod_poli int(5),
primary key (Cod),
foreign key (Cod_poli) references Polideportivo(Cod) on delete cascade
);


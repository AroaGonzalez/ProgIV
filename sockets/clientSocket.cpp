// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "adminServer.h"
#include "BaseDatos.h"
#include "cliente.h"
#include "polideportivo.h"
#include "reserva.h"
#include "usuario.h"



#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) {

	Usuario u;
	char nombre[20], contrasenya[20], fNac[10], genero[10], DNI[9], tel[9], direccion[20], nombreUsuario[15], contrasenya[20];
	Cliente c;

	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	cout << "\nInitialising Winsock...\n" << endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << "Failed. Error Code : %d" << WSAGetLastError() << endl;
		return -1;
	}

	cout << "Initialised.\n" << endl;

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		cout << "Could not create socket : %d" << WSAGetLastError() << endl;
		WSACleanup();
		return -1;
	}

	cout << "Socket created.\n" << endl;

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		cout << "Connection error: %d" << WSAGetLastError() << endl;
		closesocket(s);
		WSACleanup();
		return -1;
	}

	cout << "Connection stablished with: %s (%d)\n" << inet_ntoa(server.sin_addr) <<
			ntohs(server.sin_port) << endl;

	// SEND and RECEIVE data
	

	//iniciar sesion


	//cout << "Introduzca su nombre de usuario: \n" << endl;
	//cin >> nombre;
	//cout << "Introduzca su contrasenya: \n" << endl;
	//cin >> contrasenya;
//
	//cout << "Sending request iniciar sesion... \n" << endl;
	//sprintf(sendBuff, "%s, %s", nombre, contrasenya); // introducimos nombre y contrasenya
	//send(s, sendBuff, sizeof(sendBuff), 0); // enviamos al servidor
//
	//cout << "Receiving iniciar sesion... \n" << endl;
	//recv(s, recvBuff, sizeof(recvBuff), 0);
	//cout << "Data received: "<< recvBuff << "\n" << endl;


	
	Cliente::cMostrarMenuIniSes();

	//registrar usario

	Cliente::cMostrarMenuRegUsu();
	//cout << "Introduzca su nombre real: \n" << endl;
	//cin >> nombre;
	//cout << "Introduzca su nueva contrasenya: \n" << endl;
	//cin >> contrasenya;
	//cout << "Introduzca su fecha de nacimiento: \n" << endl;
	//cin >> fNac;
	//cout << "Introduzca su genero: \n" << endl;
	//cin >> genero;
	//cout << "Introduzca su DNI: \n" << endl;
	//cin >> DNI;
	//cout << "Introduzca su telefono: \n" << endl;
	//cin >> tel;
	//cout << "Introduzca su direccion: \n" << endl;
	//cin >> direccion;
	//cout << "Introduzca el nombre de usuario deseado: \n" << endl;
	//cin >> nombreUsuario;
	//cout << "Introduzca la contraseña deseada: \n" << endl;
	//cin >> contrasenya;

	
	//gestionar polideportivos
	Cliente::cMostrarMenuGestPoli1();

	//mostrar meny principal
	Cliente::cMostrarMenuMenuPrinc();

	//mostrar menu de gestion de reservas
	Cliente::cMostrarMenuGestReserv();

	//menu modificar datos
	Cliente::cMostrarMenuModifDat();

	//menu modificar dat dir
	Cliente::cMostrarMenuModifDatDir();

	cout << "Sending request registrar usuario... \n" << endl;
	strcpy(sendBuff, "regUsu");
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "Receiving registrar usario... \n" << endl;
	recv(s, recvBuff, sizeof(recvBuff), 0);
	cout << "Data received: "<< recvBuff << "\n" << endl;
	

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
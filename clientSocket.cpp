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
#include "usuario.h"



#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) {

	Usuario u;
	char nombre[20], fNac[10], genero[10], DNI[9], tel[9], direccion[20], nombreUsuario[15], contrasenya[20];
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
	
	//GEST POLI EUSKADI

	int op1, op2, op3;
	int respuestaS;
	do{	
		op1 = Cliente::cMostrarMenuGestPoli1();
		sprintf(sendBuff, "%i", op1);
		send(s, sendBuff, sizeof(sendBuff), 0); //se envia
		switch (op1){
			case 1:
				Cliente::cMostrarMenuIniSes();
				sprintf(sendBuff, "%s", c.getNombreUsuario());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviado nombre usuarios
				sprintf(sendBuff, "%s", c.getContrasenya());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviada contrasenya usuarios
				
				recv(s, recvBuff, sizeof(recvBuff), 0);
				scanf(recvBuff, "%d", &respuestaS); //Recibe el resultado
				if (respuestaS == 1)
				{
					
					
					op2 = Cliente::cMostrarMenuMenuPrinc();
		sprintf(sendBuff, "%i", op2);
		send(s, sendBuff, sizeof(sendBuff), 0); //se envia
		do{
			switch (op2){
				case 1:
					Cliente::cMostrarMenuImportarDatos();

				case 2:
					
					


					op3 = Cliente::cMostrarMenuGestPoli1();			//DEBERÍA SER POLI2
					sprintf(sendBuff, "%i", op3);
					send(s, sendBuff, sizeof(sendBuff), 0); //se envia
					do{
						switch (op3){
						case 1:
							//Cliente::cMostrarMenuVisualizacionGeneral();
						case 2:
							//Cliente::cMostrarMenuVisualizacionPorMunicipio();
						case 3:
							Cliente::cMostrarMenuAnyadirPolideportivo();
						case 4:
							//Cliente::cMostrarMenuModificarPolideportivo();
						case 5:
							//Cliente::cMostrarMenuEliminarPolideportivo();
						case 6:
							op2 = 0;

						break;
						}

					}while(op3 != 0);







				case 3:
					Cliente::cMostrarMenuBorrarBaseDatos();

				case 4:
					op2 = 0;

				break;
			}
			



		}while(op2 != 0);




				} else { 
					cout << "acceso denegado, identificación incorrecta"<<endl;
					break; } //me lleva a cMostrarMenuGestPoli1(); de nuevo
				
			case 2:
				Cliente::cMostrarMenuRegUsu();
				sprintf(sendBuff, "%s", c.getNombre());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviado nombre
				sprintf(sendBuff, "%s", c.getApe());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviado apellido
				sprintf(sendBuff, "%s", c.getDni());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviado dni
				sprintf(sendBuff, "%s", c.getTel());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviado telefono
				sprintf(sendBuff, "%s", c.getFnac());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviada fecha de nacimiento
				sprintf(sendBuff, "%s", c.getGenero());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviado genero
				sprintf(sendBuff, "%s", c.getDir());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviada direccion
				sprintf(sendBuff, "%s", c.getNombreUsuario());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviado nombre de usuario
				sprintf(sendBuff, "%s", c.getContrasenya());
				send(s, sendBuff, sizeof(sendBuff), 0); //enviada contrasenya

				recv(s, recvBuff, sizeof(recvBuff), 0);
				scanf(recvBuff, "%d", &respuestaS); //Recibe el resultado

				if (respuestaS == 1)
				{
					cout<< "Cliente registrado correctamente."<<endl;
				} else {cout<< "Registro de cliente fallido."<<endl;}
				
				break; //me devuelve a gestpoli1();
			case 3:
				cout << "Cerrando programa... " << endl;
				op1 = 0;
			break;
			
		}
		



	}while (op1 != 0);
	
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
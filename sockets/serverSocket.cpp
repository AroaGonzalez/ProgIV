// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <iostream>
#include "adminServer.h"
#include "BaseDatos.h"
#include "cliente.h"
#include "polideportivo.h"
#include "reserva.h"
#include "usuario.h"
using namespace std;


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) {

	WSADATA wsaData;
	SOCKET conn_socket;
	SOCKET comm_socket;
	struct sockaddr_in server;
	struct sockaddr_in client;
	char sendBuff[512], recvBuff[512];

	//BaseDatos db("BaseDeDatos.db");
	sqlite3 *db;

	Cliente c("a");
	Polideportivo p;

	int option1, option2, option3, option4; //for the do and switch
	

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((conn_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//BIND (the IP/port with socket)
	if (bind(conn_socket, (struct sockaddr*) &server,
			sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	printf("Bind done.\n");

	//LISTEN to incoming connections (socket server moves to listening mode)
	if (listen(conn_socket, 1) == SOCKET_ERROR) {
		printf("Listen failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	//ACCEPT incoming connections (server keeps waiting for them)
	printf("Waiting for incoming connections...\n");
	int stsize = sizeof(struct sockaddr);
	comm_socket = accept(conn_socket, (struct sockaddr*) &client, &stsize);
	// Using comm_socket is able to send/receive data to/from connected client
	if (comm_socket == INVALID_SOCKET) {
		printf("accept failed with error code : %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}
	printf("Incomming connection from: %s (%d)\n", inet_ntoa(client.sin_addr),
			ntohs(client.sin_port));

	// Closing the listening sockets (is not going to be used anymore)
	closesocket(conn_socket);

	//SEND and RECEIVE data
	printf("Waiting for incoming messages from client... \n");
	do{
		char userName[15];
		char passW[15];
		int response0 = 0;
		int response1 = 1;
		char namePoli[15];
		char nombreU[15];
		char apellidoU[15];
		char dniU[15];
		char telU[15];
		char fNacU[15];
		char generoU[15];
		char dirU[15];
		char nombUsuU[15];
		char passU[15];
		char centroU[15];

		recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
		sscanf(recvBuff, "%s", &option1);
		switch (option1)
		{
		case 1:
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the User Name
			sprintf(userName, "%s", recvBuff); //saves the user name

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the password
			sprintf(passW, "%s", recvBuff); //saves the password

			
			
			if(strcmp(userName, "NOMBREDEFAULT") && strcmp(passW, "PASSWORDDEFAULT")){ //si el nombre y la contra son correctas (verificadas en la base de datos), accede al menu principal
				sprintf(sendBuff, "%s", response1);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0); //envia "Accepted, welcome" al cliente como respuesta a su petición
				
				do{
					recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva solicitud del cliente
					sscanf(recvBuff, "%s", &option2);
					switch (option2){
						case 1: //importar desde fichero
							break;
						
						case 2:

							do{
								recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva solicitud del cliente
								sscanf(recvBuff, "%s", &option2);
								switch (option3)
								{
								case 1: //visualizar polideportivos
									//db.visualizarPoli(); //visualizacion general de todos los Polideportivos
									break;
								case 2: //visualizar polideportivos por municipios
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el municipio
									char nombMuni[15];
									sprintf(nombMuni, "%s", recvBuff);
									//db.visualizarPoliMunicipio(nombMuni);
								break;
								case 3: //anyadir polideportivo
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el primer atributo de la clase polideportivo
									//hacerlo iwal a registarUsusario pero con los atributos de la clase Polideportivo
									//al final hacer un sendBuff para decirle si se ha podido anyadir el Poli bn o no, tal q asi
									sprintf(sendBuff, "%s", PATATA);
									send(comm_socket, sendBuff, sizeof(sendBuff), 0);

									break;
								case 4: //modificar polideportivo
									do{
										recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el codigo del dato que se quiera modificar
										sscanf(recvBuff, "%s", &option3);
										switch (option4)
										{
										case 1: //modificar nombre
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo nombre
											char nNombre[15];
											sprintf(nNombre, "%s", recvBuff);
											//db.modifPoli(nNombre);
											break;
										case 2: //modificar instalacciones
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva instalaccion
											char nInstalaccion[15];
											sprintf(nInstalaccion, "%s", recvBuff);
											//INSERTAR LA NUEVA INSTALACCION A LA LISTA DE INSTALACCIONES DE UN POLIDEPORTIVO
											//db.modifPoli();
											break;
										case 3: //modificar direccion
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive l nueva direccion
											char nDir[15];
											sprintf(nDir, "%s", recvBuff);
											//db.modifPoli();
											break;
										case 4: //modificar municipio
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo nombre del municipio
											char nMuni[15];
											sprintf(nMuni, "%s", recvBuff);
											//db.modifPoli();
											break;
										case 5: //modificar codigo de municipio
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo codigo de municipio
											char nCodMuni[15];
											sprintf(nCodMuni, "%s", recvBuff);
											//db.modifPoli();
											break;
										case 6: //modificar provincia
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva provincia
											char nProv[15];
											sprintf(nProv, "%s", recvBuff);
											//db.modifPoli();
											break;
										case 7: //modificar codigo de provincia
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo codigo de provincia
											char nCodProv[15];
											sprintf(nCodProv, "%s", recvBuff);
											//db.modifPoli();
											break;
										case 8: //modificar telefono
											recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo telefono
											char nTel[15];
											sprintf(nTel, "%s", recvBuff);
											//db.modifPoli();
											break;
										case 9: //Volver
											option4 = 0;
											break;
										}
									break;
									}while(option4 != 0);
								case 5: //borrar polideportivo
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nombre del polideportivo a borrar
									sprintf(namePoli, "%s", recvBuff); //guarda el nombre del polideportivo
									//db.borrarPoli(namePoli);
									break;
								case 6: //volver
									option3 = 0;
									break;
								
								}

							}while(option3 != 0);
						
						case 3: //Borrar base de datos

							break;

						case 4:
							option2 = 0;
							break;
					}
				}while(option2 != 0);
				
			}else{
			sprintf(sendBuff, "%s", response0);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0); //envia "Rejected, try again" al cliente como respuesta a su petición
			}
			break;
		case 2:
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the name
			sprintf(nombreU, "%s", recvBuff); //saves the name

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the apellido
			sprintf(apellidoU, "%s", recvBuff); //saves the apellido

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the DNI
			sprintf(dniU, "%s", recvBuff); //saves the DNI

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the telefono
			sprintf(telU, "%s", recvBuff); //saves the telefono

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the fecha de nacimiento
			sprintf(fNacU, "%s", recvBuff); //saves the fecha de nacimiento

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the genero
			sprintf(generoU, "%s", recvBuff); //saves the genero

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the direccion
			sprintf(dirU, "%s", recvBuff); //saves the direccion

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the user Name
			sprintf(nombUsuU, "%s", recvBuff); //saves the user name

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the password
			sprintf(passU, "%s", recvBuff); //saves the password

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the users centro
			sprintf(centroU, "%s", recvBuff); //saves the users centro

			c(nombreU, apellidoU, fNacU, generoU, dniU, telU, dirU, nombUsuU, passU, centroU);
			
    		BaseDatos::insertarCliente(db, &c);

			//DARLE UN OKAY A VIK (SEND 1 if correct)tal que asi
			sprintf(sendBuff, "%s", PATATA);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);

			break;

		case 3:
			option1 = 0;
			break;
		}

	}while (option1 != 0);
	// CLOSING the sockets and cleaning Winsock...
	cout << "Cerrando conexión" << endl;
	closesocket(comm_socket);
	WSACleanup();

return 0;
}



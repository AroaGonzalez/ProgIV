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

	Cliente c("a", "s");
	Polideportivo p;

	int option1; //for the do and switch
	int option2; //for the do and switch
	int option3; //for the do and switch

	

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
		char response0[20] = "Rejected, try again";
		char response1[18] = "Accepted, welcome";
		char namePoli[15];
		recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
		sscanf(recvBuff, "%i", &option1);
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
					sscanf(recvBuff, "%i", &option2);
					switch (option2)
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
					case 3: //insertar polideportivo
						recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive los valores separados por #
						sscanf(recvBuff, "%s#%s#%d#%s#%s#%f", p.codMunicipio, p.codProv,
								p.direccion, &p.instalaciones, p.municipio, p.nombre,
								p.provincia, p.ref, p.tel);
								//db.insertarPoli();
						break;
					case 4: //modificar polideportivo
						do{
							recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el codigo del dato que se quiera modificar
							sscanf(recvBuff, "%i", &option3);
							switch (option3)
							{
							case 1: //modificar nombre
								recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo nombre
								char nNombre[15];
								sprintf(nNombre, "%s", recvBuff);
								//db.modifPoli();
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
								sprintf(nCodMuni, "%i", recvBuff);
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
								sprintf(nCodProv, "%i", recvBuff);
								//db.modifPoli();
								break;
							case 8: //modificar telefono
								recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo telefono
								char nTel[15];
								sprintf(nTel, "%i", recvBuff);
								//db.modifPoli();
								break;
							case 9: //Volver
								option3 = 0;
								break;
							}
						break;
					}while(option3 != 0);
					case 5: //borrar polideportivo
						recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nombre del polideportivo a borrar
						sprintf(namePoli, "%s", recvBuff); //guarda el nombre del polideportivo
						//db.borrarPoli(namePoli);
						break;
					case 6:
						option2 = 0;
						break;
					
					}

				}while(option2 != 0);
				
				}else{
				sprintf(sendBuff, "%s", response0);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0); //envia "Rejected, try again" al cliente como respuesta a su petición
				}
			
			break;
		
		default:
			break;
		}

	}while (option1 != 0);
	// CLOSING the sockets and cleaning Winsock...
	closesocket(comm_socket);
	WSACleanup();

	return 0;
}



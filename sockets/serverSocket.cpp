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

	int optionDB;

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
		char option1;
		char userName[15];
		char passW[15];
		char response[10] = "Accepted";
		recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
		sscanf(recvBuff, "%i", &option1);
		switch (option1)
		{
		case 1:
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the User Name
			sprintf(userName, "%s", recvBuff); //saves the user name

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the password
			sprintf(passW, "%s", recvBuff); //saves the password
			
			if(strcmp(userName, "NOMBREDEFAULT") && strcmp(passW, "PASSWORDDEFAULT"))
			{ //si el nombre y la contra son correctas (verificadas en la base de datos), accede al menu principal
				sprintf(sendBuff, "%s", response);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0); //envia "Accepted" al cliente como respuesta a su petición
				
				do{
					recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva solicitud del cliente
					sscanf(recvBuff, "%i", &optionDB);
					switch (optionDB)
					{
					case 1: //insertar usuario
						recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive los valores separados por #
						sscanf(recvBuff, "%s#%s#%d#%s#%s#%f", p.codMunicipio, p.codProv,
								p.direccion, &p.instalaciones, p.municipio, p.nombre,
								p.provincia, p.ref, p.tel);
								
						break;
					
					default:
						break;
					}



				}
					
				
			}
			
			break;
		
		default:
			break;
		}
		
			if(strcmp(recvBuff, "")){

					int bytes = recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
					if (bytes > 0) {
						if (strcmp(recvBuff, "iniS") == 0) {//LOGIN
							printf("Receiving message... \n");
							printf("Data received: %s \n", recvBuff);

							printf("Sending reply... \n");
							strcpy(sendBuff, "ACK -> "); //la respuesta aqui
							strcat(sendBuff, recvBuff);
							send(comm_socket, sendBuff, sizeof(sendBuff), 0);
							printf("Data sent: %s \n", sendBuff);
						}else if (strcmp(recvBuff, "regUsu") == 0) {
							printf("Receiving message... \n");
							printf("Data received: %s \n", recvBuff);

							printf("Sending reply... \n");
							strcpy(sendBuff, "ACK -> "); //la respuesta aqui
							strcat(sendBuff, recvBuff);
							send(comm_socket, sendBuff, sizeof(sendBuff), 0);
							printf("Data sent: %s \n", sendBuff);
						}else if (strcmp(recvBuff, "gestR") == 0) {//MENU PRINCIPAL
							printf("Receiving message... \n");
							printf("Data received: %s \n", recvBuff);

							printf("Sending reply... \n");
							strcpy(sendBuff, "ACK -> "); //la respuesta aqui
							strcat(sendBuff, recvBuff);
							send(comm_socket, sendBuff, sizeof(sendBuff), 0);
							printf("Data sent: %s \n", sendBuff);
						}
				//if (strcmp(recvBuff, "endConn") == 0)//LAST MESSAGE, ASKING FOR CLOSING CONNECTION
				//	break;
				//}
			}
	}
	
	// CLOSING the sockets and cleaning Winsock...
	closesocket(comm_socket);
	WSACleanup();

	return 0;
}


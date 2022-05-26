// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include "adminServer.h"
#include "BaseDatos.h"
#include "cliente.h"
#include "menu.h"
#include "polideportivo.h"
#include "reserva.h"
#include "usuario.h"


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) {

	WSADATA wsaData;
	SOCKET conn_socket;
	SOCKET comm_socket;
	struct sockaddr_in server;
	struct sockaddr_in client;
	char sendBuff[512], recvBuff[512];

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
	do {
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
			}else if (strcmp(recvBuff, "modifDat") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "gestP") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "volverLogIn") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "resInst") == 0) {//GESTIONAR RESERVAS
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "anulRes") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "volverMenuPrincipal") == 0) {//VOLVER AL MENU PRINCIPAL
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "dir") == 0) {//MODIFICAR DATOS PERSONALES
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "cuota") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "nomUsu") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "contr") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "visGen") == 0) {//GESTION DE POLIDEPORTIVOS
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "visMuni") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "anyaPoli") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "modifPoli") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else if (strcmp(recvBuff, "elimPoli") == 0) {
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ACK -> "); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}else{
				printf("Receiving message... \n");
				printf("Data received: %s \n", recvBuff);

				printf("Sending reply... \n");
				strcpy(sendBuff, "ERROR"); //la respuesta aqui
				strcat(sendBuff, recvBuff);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Data sent: %s \n", sendBuff);
			}
		if (strcmp(recvBuff, "endConn") == 0)//LAST MESSAGE, ASKING FOR CLOSING CONNECTION
			break;
		}
	} while (1);

	// CLOSING the sockets and cleaning Winsock...
	closesocket(comm_socket);
	WSACleanup();

	return 0;
}


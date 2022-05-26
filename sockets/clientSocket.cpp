// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include "adminServer.h"
#include "BaseDatos.h"
#include "cliente.h"
#include "cuota.h"
#include "menu.h"
#include "polideportivo.h"
#include "reserva.h"
#include "usuario.h"



#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) {

	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	// SEND and RECEIVE data
	//LOGIN
	printf("Sending request iniciar sesion... \n");
	strcpy(sendBuff, "iniS");
	send(s, sendBuff, sizeof(sendBuff), 0);

	printf("Receiving iniciar sesion... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff); 

	printf("Sending request registrar usuario... \n");
	strcpy(sendBuff, "regUsu");
	send(s, sendBuff, sizeof(sendBuff), 0);

	printf("Receiving registrar usario... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);
	
	//MENU PRINCIPAL
	printf("Sending request gestionar reservas... \n");
	strcpy(sendBuff, "gestR");
	send(s, sendBuff, sizeof(sendBuff), 0);

	printf("Receiving gestionar reservas... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request modificar datos personales... \n");
	strcpy(sendBuff, "modifDat");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving modificar datos personales... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request gestionar polideportivos... \n");
	strcpy(sendBuff, "gestP");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving gestionar polideportivos... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request volver... \n");
	strcpy(sendBuff, "volverLogIn");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving volver... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	//GESTIONAR RESERVAS
	printf("Sending request reservar espacio deportivo... \n");
	strcpy(sendBuff, "resInst");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving reservar espacio deportivo... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request reservar anular reserva... \n");
	strcpy(sendBuff, "anulRes");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving reservar anular reserva... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	//VOLVER AL MENU PRINCIPAL
	printf("Sending request volver... \n");
	strcpy(sendBuff, "volverMenuPrincipal");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving reservar volver... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	//MODIFICAR DATOS PERSONALES
	printf("Sending request direccion... \n");
	strcpy(sendBuff, "dir");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving reservar direccion... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request cuota... \n");
	strcpy(sendBuff, "cuota");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving reservar cuota... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request nombre de usuario... \n");
	strcpy(sendBuff, "nomUsu");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving reservar nombre de usuario... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request contrasenya... \n");
	strcpy(sendBuff, "contr");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving reservar contrasenya... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	//GESTION DE POLIDEPORTIVOS
	printf("Sending request visualizacion general... \n");
	strcpy(sendBuff, "visGen");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving  visualizacion general... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request visualizacion por municipio... \n");
	strcpy(sendBuff, "visMuni");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving  visualizacion por municipio... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request anyadir polideportivo... \n");
	strcpy(sendBuff, "anyaPoli");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving anyadir polideportivo... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request moficicar polideportivo... \n");
	strcpy(sendBuff, "modifPoli");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving modificar polideportivo... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	printf("Sending request eliminar polideportivo... \n");
	strcpy(sendBuff, "elimPoli");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	printf("Receiving eliminar polideportivo... \n");
	recv(s, recvBuff, sizeof(recvBuff), 0);
	printf("Data received: %s \n", recvBuff);

	//LAST MESSAGE, ASKING FOR CLOSING CONNECTION
	printf("Sending close connection... \n");
	strcpy(sendBuff, "endConn");
	send(s, sendBuff, sizeof(sendBuff), 0);
	printf("Data sent: %s \n", sendBuff);

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}

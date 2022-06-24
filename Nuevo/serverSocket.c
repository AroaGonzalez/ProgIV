// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include "Polideportivo.h"
#include "Usuario1.h"
#include "Logger.h"


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
	//sqlite3 *db;


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

		char refP[15];
    	char nombreP[15];
    	char instalacionesP[100];
    	char direccionP[15];
    	char municipioP[15];
    	char codMunicipioP[15];
    	char provinciaP[15];
    	char codProvP[15];
    	char telP[15];

		registro();

		recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
		sscanf(recvBuff, "%i", &option1);
		switch (option1)
		{
		case 1:
			acciones("Inicio sesion"); // HACER ASI CON TODAS LAS ACCIONES SOLO NE SERVERSOCKET

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the User Name
			sprintf(userName, "%s", recvBuff); //saves the user name


			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the password
			sprintf(passW, "%s", recvBuff); //saves the password

			
			
			if(comparaUsuario(userName, passW) == 0){ //si el nombre y la contra son correctas (verificadas en la base de datos), accede al menu principal

				sprintf(sendBuff, "%i", response1);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0); //envia "Accepted, welcome" al cliente como respuesta a su petición
				
				do{
					recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva solicitud del cliente
					sscanf(recvBuff, "%s", &option2);
					switch (option2){
						case 1: //importar desde fichero
							
							printf("parece que ha habido un error, inténtelo mas tarde");					 //RDSHIJR COMMENTS PARA QUE SE NOTE QUE ESTA MAL
							
							break;
						
						case 2:

							do{
								recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva solicitud del cliente
								sscanf(recvBuff, "%s", &option3);
								switch (option3)
								{
								case 1: //visualizar polideportivos
			//						BaseDatos::VisualizarPoli(db); //visualizacion general de todos los Polideportivos
									visualizarPoli();

									sprintf(sendBuff, "%i", response1);
									send(comm_socket, sendBuff, sizeof(sendBuff), 0);

									break;
								case 2: //visualizar polideportivos por municipios
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el municipio
									char nombMuni[15];
									sprintf(nombMuni, "%s", recvBuff);
									poliPorMunicipio(nombMuni);
									//BaseDatos::visualizarPoliMunicipio(db, nombMuni);
								break;
								case 3: //anyadir polideportivo
			//						sprintf(refP, "%s", BaseDatos::selectMaxRef(db)); //saves the referencia
									
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nombre del polideportivo
									sprintf(nombreP, "%s", recvBuff); //saves the nombre

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive las instalaciones del polideportivo
									sprintf(instalacionesP, "%s", recvBuff); //saves the instalaciones

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el primer atributo de la clase polideportivo
									sprintf(direccionP, "%s", recvBuff); //saves the direccion

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el primer atributo de la clase polideportivo
									sprintf(municipioP, "%s", recvBuff); //saves the municipio

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el primer atributo de la clase polideportivo
									sprintf(codMunicipioP, "%s", recvBuff); //saves the codigo municipio

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el primer atributo de la clase polideportivo
									sprintf(provinciaP, "%s", recvBuff); //saves the provincia

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el primer atributo de la clase polideportivo
									sprintf(codProvP, "%s", recvBuff); //saves the codigo provincia

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el primer atributo de la clase polideportivo
									sprintf(telP, "%s", recvBuff); //saves the telefono

									anyadirPoli(refP, nombreP, instalacionesP, direccionP, municipioP, codMunicipioP, provinciaP, codProvP, telP);

				//					BaseDatos::insertarPoli(db, &p);

									sprintf(sendBuff, "%i", response1);
									send(comm_socket, sendBuff, sizeof(sendBuff), 0);

									break;
								case 4: //modificar polideportivo
									
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el codigo del dato que se quiera modificar
									char poli[15];
									sscanf(recvBuff, "%s", poli);

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo ref
									char nRef[15];
									sscanf(recvBuff, "%s", nRef);

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo nombre
									char nNombre[15];
									sscanf(recvBuff, "%s", nNombre);

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo nombre
									char nInst[15];
									sscanf(recvBuff, "%s", nInst);

									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva direccion
									char nDir[15];
									sscanf(recvBuff, "%s", nDir);
										
									//modificar municipio
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo nombre del municipio
									char nMuni[15];
									sscanf(recvBuff, "%s", nMuni);
										
									//modificar codigo de municipio
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo codigo de municipio
									char nCodMuni[15];
									sscanf(recvBuff, "%s", nCodMuni);
					
									//modificar provincia
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive la nueva provincia
									char nProv[15];
									sscanf(recvBuff, "%s", nProv);
										
									//modificar codigo de provincia
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo codigo de provincia
									char nCodProv[15];
									sscanf(recvBuff, "%s", nCodProv);
									
									//modificar telefono
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nuevo telefono
									char nTel[15];
									sscanf(recvBuff, "%s", nTel);
									
									editarPoli(poli, nRef, nNombre, nInst, nDir, nMuni, nCodMuni, nProv, nCodProv, nTel);
									
									sprintf(sendBuff, "%i", response1);
									send(comm_socket, sendBuff, sizeof(sendBuff), 0);
										
								case 5: //borrar polideportivo
									recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //recive el nombre del polideportivo a borrar
									sprintf(namePoli, "%s", recvBuff); //guarda el nombre del polideportivo
				//					BaseDatos::borrarPoli(db, namePoli);

									deletePoli(namePoli);

									sprintf(sendBuff, "%i", response1);
									send(comm_socket, sendBuff, sizeof(sendBuff), 0);

									break;
								case 6: //volver
									option3 = 0;
									break;
								
								}

							}while(option3 != 0);
						
						case 3: //Borrar base de datos
			//				BaseDatos::borrarBD(db);

							deleteDB();

							sprintf(sendBuff, "%i", response1);
							send(comm_socket, sendBuff, sizeof(sendBuff), 0);

							break;

						case 4:
							option2 = 0;
							break;
					}
				}while(option2 != 0);
				
			}else{
			sprintf(sendBuff, "%i", response0);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0); //envia 0 al cliente como respuesta a su petición
			}
			break;
		case 2:
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the name
			sscanf(recvBuff, "%s", nombreU); //saves the name

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the apellido
			sscanf(recvBuff, "%s", apellidoU); //saves the apellido

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the DNI
			sscanf(recvBuff, "%s", fNacU); //saves the DNI

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the telefono
			sscanf(recvBuff, "%s", generoU); //saves the telefono

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the fecha de nacimiento
			sscanf(recvBuff, "%s", dniU); //saves the fecha de nacimiento

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the genero
			sscanf(recvBuff, "%s", telU); //saves the genero

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the direccion
			sscanf(recvBuff, "%s", dirU); //saves the direccion

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the user Name
			sscanf(recvBuff, "%s", nombUsuU); //saves the user name

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the password
			sscanf(recvBuff, "%s", passU); //saves the password

			//recv(comm_socket, recvBuff, sizeof(recvBuff), 0); //receives the users centro
			//sscanf(recvBuff, "%s", centroU); //saves the users centro

			Usuario1 usu;

			generarUsuario(&usu, nombreU, apellidoU, fNacU, generoU, dniU, telU, dirU, nombUsuU, passU);

			anyadirUsuario(usu);
			
    //		BaseDatos::insertarCliente(db, &c);

			sprintf(sendBuff, "%i", response1);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);

			break;

		case 3:
			option1 = 0;
			break;
		}

	}while (option1 != 0);
	// CLOSING the sockets and cleaning Winsock...
	printf("Cerrando conexión\n");
	closesocket(comm_socket);
	WSACleanup();

return 0;
}



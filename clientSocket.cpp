// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string.h>
using namespace std;


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int cMostrarMenuGestPoli1(SOCKET s, char sendBuff[512], char recvBuff[512])
{
    int linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTION DE POLIDEPORTIVOS DE EUSKADI\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Bienvenido al programa que administra el servidor\n"<<endl;

    cout<<"1. Iniciar sesion\n"<<endl;
    cout<<"2. Registrar usuario\n"<<endl;
    cout<<"3. Salir\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;
	sprintf(sendBuff, "%i", linea);
    send(s, sendBuff, sizeof(sendBuff), 0);

	return linea;
}

void cMostrarMenuRegUsu(SOCKET s, char sendBuff[512], char recvBuff[512])
{

    cout<<"\n======================================\n"<<endl;
    cout<<"REGISTRO DE USUARIO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;
    

    char* nombreU;
    cout<<"-> Nombre: "<<endl;
    cin>>nombreU;
	sprintf(sendBuff, "%s", nombreU);
	send(s, sendBuff, sizeof(sendBuff), 0);
	

    char* apellidoU;
    cout<<"\n-> Apellido: "<<endl;
    cin>> apellidoU;
    sprintf(sendBuff, "%s", apellidoU);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* DNIU;
    cout<<"\n-> DNI: "<<endl;
    cin>>DNIU;
    sprintf(sendBuff, "%s", DNIU);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* telU;
    cout<<"\n-> Telefono: "<<endl;
    cin>>telU;
    sprintf(sendBuff, "%s", telU);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* FNacU;
    cout<<"\n-> Fecha nacimiento: "<<endl;
    cin>>FNacU;
    sprintf(sendBuff, "%s", FNacU);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* generoU;
    cout<<"\n-> Genero: "<<endl;
    cin>>generoU;
    sprintf(sendBuff, "%s", generoU);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* dirU;
    cout<<"\n-> Direccion: "<<endl;
    cin>>dirU;
	sprintf(sendBuff, "%s", dirU);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* nomUsuU;
    cout<<"\n-> Nombre de usuario: "<<endl;
    cin>>nomUsuU;
    sprintf(sendBuff, "%s", nomUsuU);
	send(s, sendBuff, sizeof(sendBuff), 0);
    
    char* conU;
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>conU;
    sprintf(sendBuff, "%s", conU);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* centroU;
    cout<<"\n-> Centro: "<<endl;
    cin>>centroU;
    sprintf(sendBuff, "%s", centroU);
	send(s, sendBuff, sizeof(sendBuff), 0);


}


void cMostrarMenuIniSes(SOCKET s, char sendBuff[512], char recvBuff[512])
{
    char* nombreDeUsuario;
    char* contrasenya;


    cout<<"\n======================================\n"<<endl;
    cout<<"INICIO DE SESION\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;
    
    cout<<"-> Nombre de usuario: "<<endl;
    cin>>nombreDeUsuario;
    sprintf(sendBuff, "%s", nombreDeUsuario);
	send(s, sendBuff, sizeof(sendBuff), 0);
    
    cout<<"\n-> Contrasenya: "<<endl;
    cin>>contrasenya;
    sprintf(sendBuff, "%s", contrasenya);
	send(s, sendBuff, sizeof(sendBuff), 0);
    
}

int cMostrarMenuMenuPrinc(SOCKET s, char sendBuff[512], char recvBuff[512])
{
    int linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"MENU PRINCIPAL\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Seleccione una opcion: \n\n"<<endl;
    cout<<"1. Modificar datos personales\n"<<endl;
    cout<<"2. Gestionar polideportivos\n"<<endl;
    cout<<"3. Volver\n\n"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>linea;
	sprintf(sendBuff, "%i", linea);
    send(s, sendBuff, sizeof(sendBuff), 0);

	return linea;
}


void cMostrarMenuModifDat(SOCKET s, char sendBuff[512], char recvBuff[512])
{
    char* dir, cuot, nombr, contr;

    cout<<"\n======================================\n"<<endl;
    cout<<"MODIFICAR DATOS PERSONALES\n"<<endl;
    cout<<"======================================\n\n"<<endl;

    cout<<"\nNueva nombre de usuario: "<<endl;
    cin>>nombr;
    sprintf(sendBuff, "%s", nombr);
	send(s, sendBuff, sizeof(sendBuff), 0);

    cout<<"\nNueva contrasenya: "<<endl;
    cin>>contr;
    sprintf(sendBuff, "%s", contr);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout<<"\nNueva direccion: "<<endl;
    cin>>dir;
    sprintf(sendBuff, "%s", dir);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout<<"\nNuevo tipo de cuota: "<<endl;
    cin>>cuot;
    sprintf(sendBuff, "%s", cuot);
	send(s, sendBuff, sizeof(sendBuff), 0);
}


void cMostrarMenuImportarDatos() ///////////////////////////////////////////////////////////////
{
    cout<<"Importando datos,no cierre la aplicación ... \n"<<endl;      
    
    
                                                                    //FALTA ALGO EN SOCKETS

} 


void cMostrarMenuBorrarBaseDatos()
{
    cout<<"Importando datos: \n"<<endl;
}

int cMostrarMenuGestPoli2(SOCKET s, char sendBuff[512], char recvBuff[512])
{
    char linea;
    cout<<"\n======================================\n"<<endl;
    cout<<"GESTION DE POLIDEPORTIVOS\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Seleccione la opcion que desee:\n\n"<<endl;
    
    cout<<"1.- Visualización general\n"<<endl;
    cout<<"2.- Visualización por municipios\n"<<endl;
    cout<<"3.- Anyadir polideportivo\n"<<endl;
    cout<<"4.- Modificar poliderportivo\n"<<endl;
    cout<<"5.- Eliminar poliderportivo\n\n"<<endl;
    cout<<"6. Volver"<<endl;
    cout<<"Opcion: "<<endl;

	cin>>linea;
	sprintf(sendBuff, "%i", linea);
    send(s, sendBuff, sizeof(sendBuff), 0);

	return linea;
}


void cMostrarMenuVisualizacionGeneral()
{
    cout<<"Mostrando polideportivos... \n"<<endl;
    

}


void cMostraMenuVisualizacionPorMunicipio(SOCKET s, char sendBuff[512], char recvBuff[512]) //se envía el nombre para que devuelva un polideportivo
{
    char* nombre;
    cout<<"-> Inserte nombre del municipio a mostrar: "<<endl;
    cin>>nombre;
    sprintf(sendBuff, "%s", nombre);
	send(s, sendBuff, sizeof(sendBuff), 0);
}

void cMostrarMenuAnyadirPolideportivo(SOCKET s, char sendBuff[512], char recvBuff[512])
{
    

    cout<<"\n======================================\n"<<endl;
    cout<<"ANYADIR POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    cout<<"Rellene los siguientes parametros\n"<<endl;


    char *ref;
    cout<<"-> Referencia del polideportivo: "<<endl;
    cin>>ref;
    sprintf(sendBuff, "%s", ref);
	send(s, sendBuff, sizeof(sendBuff), 0);
    
    char *nombre;
    cout<<"\n-> Nombre del polideportivo: "<<endl;
    cin>>nombre;
    sprintf(sendBuff, "%s", nombre);
	send(s, sendBuff, sizeof(sendBuff), 0);
    
    char *instalaciones;
    cout<<"\n-> Instalaciones del polideportivo: "<<endl;
    cin>>instalaciones;
    sprintf(sendBuff, "%s", instalaciones);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char *direccion;
    cout<<"\n-> Direccion del polideportivo: "<<endl;
    cin>>direccion;
    sprintf(sendBuff, "%s", direccion);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char *municipio;
    cout<<"\n-> Municipio al que pertenece el polideportivo: "<<endl;
    cin>>municipio;
    sprintf(sendBuff, "%s", municipio);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* codMunicipio;
    cout<<"\n-> Codigo del Municipio al que pertenece el polideportivo: "<<endl;
    cin>>codMunicipio;
    sprintf(sendBuff, "%s", codMunicipio);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char *provincia;
    cout<<"\n-> Provincia a la que pertenece el polideportivo: "<<endl;
    cin>>provincia;
    sprintf(sendBuff, "%s", provincia);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* codProv;
    cout<<"\n-> Codigo de provincia del polideportivo: "<<endl;
    cin>>codProv;
    sprintf(sendBuff, "%s", codProv);
	send(s, sendBuff, sizeof(sendBuff), 0);

    char* tel;
    cout<<"\n-> Telefono del polideportivo: "<<endl;
    cin>>tel;
    sprintf(sendBuff, "%s", tel);
	send(s, sendBuff, sizeof(sendBuff), 0);


}

void cMostrarMenuModificarPolideportivo(SOCKET s, char sendBuff[512], char recvBuff[512])
{
   char* nombre, dir, tel, muni, codMuni, prov, codProv;

    cout<<"\n======================================\n"<<endl;
    cout<<"MODIFICAR DATOS DEL POLIDEPORTIVO\n"<<endl;
    cout<<"======================================\n\n"<<endl;
    
    cout<<"Nombre: \n"<<endl;
	cin >> nombre;
	sprintf(sendBuff, "%s", nombre);
	send(s, sendBuff, sizeof(sendBuff), 0);

    cout<<"Direccion: \n"<<endl;
	cin >> dir;
	sprintf(sendBuff, "%s", nombre);
	send(s, sendBuff, sizeof(sendBuff), 0);

    cout<<"Telefono: \n"<<endl;
	cin >> tel;
	sprintf(sendBuff, "%s", tel);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout<<"Municipio: \n"<<endl;
	cin >> muni;
	sprintf(sendBuff, "%s", muni);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout<<"Codigo de municipio: \n"<<endl;
	cin >> codMuni;
	sprintf(sendBuff, "%s", codMuni);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout<<"Provincia: \n"<<endl;
	cin >> prov;
	sprintf(sendBuff, "%s", prov);
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout<<"Codigo de proviincia: \n"<<endl;
	cin >> codProv;
	sprintf(sendBuff, "%s", codProv);
	send(s, sendBuff, sizeof(sendBuff), 0);

}

void cMostrarMenuVisualizacionPorMunicipio(SOCKET s, char sendBuff[512], char recvBuff[512])
{
	char* muni;

    cout<<"\nEscriba el municipio de referencia del polideportivo a visualizar: "<<endl;
    cin>>muni;
    sprintf(sendBuff, "%s", muni);
	send(s, sendBuff, sizeof(sendBuff), 0);
}

void cMostrarMenuEliminarPolideportivo(SOCKET s, char sendBuff[512], char recvBuff[512])
{

    char* ref;

    cout<<"\nEscriba el codigo de referencia del polideportivo a eliminar: "<<endl;
    cin>>ref;
    sprintf(sendBuff, "%s", ref);
	send(s, sendBuff, sizeof(sendBuff), 0);

}



int main(int argc, char *argv[]) {

	char nombre[20], fNac[10], genero[10], DNI[9], tel[9], direccion[20], nombreUsuario[15], contrasenya[20];
	

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
		op1 = cMostrarMenuGestPoli1(s, sendBuff, recvBuff);
		sprintf(sendBuff, "%i", op1);
		send(s, sendBuff, sizeof(sendBuff), 0); //se envia
		switch (op1){
			case 1:
				cMostrarMenuIniSes(s, sendBuff, recvBuff);
				
				recv(s, recvBuff, sizeof(recvBuff), 0);
				scanf(recvBuff, "%d", &respuestaS); //Recibe el resultado
				if (respuestaS == 1)
				{
					op2 = cMostrarMenuMenuPrinc(s, sendBuff, recvBuff);
		            sprintf(sendBuff, "%i", op2);
		            send(s, sendBuff, sizeof(sendBuff), 0); //se envia
		do{
			switch (op2){
				case 1:
					cMostrarMenuImportarDatos();

				case 2:

					op3 = cMostrarMenuGestPoli2(s, sendBuff, recvBuff);			//DEBERÍA SER POLI2
					sprintf(sendBuff, "%i", op3);
					send(s, sendBuff, sizeof(sendBuff), 0); //se envia
					do{
						switch (op3){
						case 1:
							cMostrarMenuVisualizacionGeneral();
						case 2:
							cMostrarMenuVisualizacionPorMunicipio(s, sendBuff, recvBuff);
						case 3:
							cMostrarMenuAnyadirPolideportivo(s, sendBuff, recvBuff);
						case 4:
							cMostrarMenuModificarPolideportivo(s, sendBuff, recvBuff);
						case 5:
							cMostrarMenuEliminarPolideportivo(s, sendBuff, recvBuff);
						case 6:
							op2 = 0;

						break;
						}

					}while(op3 != 0);

				case 3:
					cMostrarMenuBorrarBaseDatos();

				case 4:
					op2 = 0;

				break;
			}

		}while(op2 != 0);
				} else { 
					cout << "acceso denegado, identificación incorrecta"<<endl;
					break; } //me lleva a cMostrarMenuGestPoli1(); de nuevo
				
			case 2:
				cMostrarMenuRegUsu(s, sendBuff, recvBuff);

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

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
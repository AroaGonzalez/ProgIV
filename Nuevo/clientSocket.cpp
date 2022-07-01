// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string.h>
using namespace std;

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int cMostrarMenuGestPoli1(SOCKET s, char *sendBuff, char *recvBuff)
{
    int linea;
    cout << "\n======================================\n"
         << endl;
    cout << "GESTION DE POLIDEPORTIVOS DE EUSKADI\n"
         << endl;
    cout << "======================================\n\n"
         << endl;
    cout << "Bienvenido al programa que administra el servidor\n"
         << endl;

    cout << "1. Iniciar sesion\n"
         << endl;
    cout << "2. Registrar usuario\n"
         << endl;
    cout << "3. Salir\n\n"
         << endl;
    cout << "Opcion: " << endl;
    cin >> linea;
    sprintf(sendBuff, "%i", linea);
    send(s, sendBuff, sizeof(sendBuff), 0);

    return linea;
}

void cMostrarMenuRegUsu(SOCKET s, char *sendBuff, char *recvBuff)
{

    cout << "\n======================================\n"
         << endl;
    cout << "REGISTRO DE USUARIO\n"
         << endl;
    cout << "======================================\n\n"
         << endl;
    cout << "Rellene los siguientes parametros\n"
         << endl;

    char nombreU[100];
    cout << "-> Nombre: " << endl;
    cin >> nombreU;
    sprintf(sendBuff, "%s", nombreU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char apellidoU[100];
    cout << "\n-> Apellido: " << endl;
    cin >> apellidoU;
    sprintf(sendBuff, "%s", apellidoU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char DNIU[100];
    cout << "\n-> DNI: " << endl;
    cin >> DNIU;
    sprintf(sendBuff, "%s", DNIU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char telU[100];
    cout << "\n-> Telefono: " << endl;
    cin >> telU;
    sprintf(sendBuff, "%s", telU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char FNacU[100];
    cout << "\n-> Fecha nacimiento: " << endl;
    cin >> FNacU;
    sprintf(sendBuff, "%s", FNacU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char generoU[100];
    cout << "\n-> Genero: " << endl;
    cin >> generoU;
    sprintf(sendBuff, "%s", generoU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char dirU[100];
    cout << "\n-> Direccion: " << endl;
    cin >> dirU;
    sprintf(sendBuff, "%s", dirU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char nomUsuU[100];
    cout << "\n-> Nombre de usuario: " << endl;
    cin >> nomUsuU;
    sprintf(sendBuff, "%s", nomUsuU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char conU[100];
    cout << "\n-> Contrasenya: " << endl;
    cin >> conU;
    sprintf(sendBuff, "%s", conU);
    send(s, sendBuff, sizeof(sendBuff), 0);

    // char centroU[100];
    // cout<<"\n-> Centro: "<<endl;
    // cin>>centroU;
    // sprintf(sendBuff, "%s", centroU);
    // send(s, sendBuff, sizeof(sendBuff), 0);
}

void cMostrarMenuIniSes(SOCKET s, char *sendBuff, char *recvBuff)
{
    char nombreDeUsuario[100];
    char contrasenya[100];

    cout << "\n======================================\n"
         << endl;
    cout << "INICIO DE SESION\n"
         << endl;
    cout << "======================================\n\n"
         << endl;
    cout << "Rellene los siguientes parametros\n"
         << endl;

    cout << "-> Nombre de usuario: " << endl;
    cin >> nombreDeUsuario;
    sprintf(sendBuff, "%s", nombreDeUsuario);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\n-> Contrasenya: " << endl;
    cin >> contrasenya;
    sprintf(sendBuff, "%s", contrasenya);
    send(s, sendBuff, sizeof(sendBuff), 0);
}

int cMostrarMenuMenuPrinc(SOCKET s, char *sendBuff, char *recvBuff)
{
    int linea;
    cout << "\n======================================\n"
         << endl;
    cout << "MENU PRINCIPAL\n"
         << endl;
    cout << "======================================\n\n"
         << endl;
    cout << "Seleccione una opcion: \n\n"
         << endl;
    cout << "1. Importar datos\n"
         << endl;
    cout << "2. Gestionar polideportivos\n"
         << endl;
    cout << "3. Volver\n\n"
         << endl;
    cout << "Opcion: " << endl;
    cin >> linea;
    sprintf(sendBuff, "%i", linea);
    send(s, sendBuff, sizeof(sendBuff), 0);

    return linea;
}

void cMostrarMenuModifDat(SOCKET s, char *sendBuff, char *recvBuff)
{
    char dir[100], cuot[100], nombr[100], contr[100];

    cout << "\n======================================\n"
         << endl;
    cout << "MODIFICAR DATOS PERSONALES\n"
         << endl;
    cout << "======================================\n\n"
         << endl;

    cout << "\nNueva nombre de usuario: " << endl;
    cin >> nombr;
    sprintf(sendBuff, "%s", nombr);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nNueva contrasenya: " << endl;
    cin >> contr;
    sprintf(sendBuff, "%s", contr);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nNueva direccion: " << endl;
    cin >> dir;
    sprintf(sendBuff, "%s", dir);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nNuevo tipo de cuota: " << endl;
    cin >> cuot;
    sprintf(sendBuff, "%s", cuot);
    send(s, sendBuff, sizeof(sendBuff), 0);
}

void cMostrarMenuImportarDatos() ///////////////////////////////////////////////////////////////
{
    cout << "Importando datos, no cierre la aplicacion ... \n"
         << endl;

    // FALTA ALGO EN SOCKETS
}

void cMostrarMenuBorrarBaseDatos()
{
    cout << "Importando datos: \n"
         << endl;
}

int cMostrarMenuGestPoli2(SOCKET s, char *sendBuff, char *recvBuff)
{
    int linea;
    cout << "\n======================================\n"
         << endl;
    cout << "GESTION DE POLIDEPORTIVOS\n"
         << endl;
    cout << "======================================\n\n"
         << endl;
    cout << "Seleccione la opcion que desee:\n\n"
         << endl;

    cout << "1.- Visualizacion general\n"
         << endl;
    cout << "2.- Visualizacion por municipios\n"
         << endl;
    cout << "3.- Anyadir polideportivo\n"
         << endl;
    cout << "4.- Modificar poliderportivo\n"
         << endl;
    cout << "5.- Eliminar poliderportivo\n"
         << endl;
    cout << "6. Volver\n" << endl;
    cout << "Opcion: " << endl;

    cin >> linea;
    sprintf(sendBuff, "%i", linea);
    send(s, sendBuff, sizeof(sendBuff), 0);

    return linea;
}

void cMostrarMenuVisualizacionGeneral()
{
    cout << "Mostrando polideportivos... \n"
         << endl;
}

void cMostraMenuVisualizacionPorMunicipio(SOCKET s, char *sendBuff, char *recvBuff) // se envía el nombre para que devuelva un polideportivo
{
    char nombre[100];
    cout << "-> Inserte nombre del municipio a mostrar: " << endl;
    cin >> nombre;
    sprintf(sendBuff, "%s", nombre);
    send(s, sendBuff, sizeof(sendBuff), 0);
}

void cMostrarMenuAnyadirPolideportivo(SOCKET s, char *sendBuff, char *recvBuff)
{

    cout << "\n======================================\n"
         << endl;
    cout << "ANYADIR POLIDEPORTIVO\n"
         << endl;
    cout << "======================================\n\n"
         << endl;
    cout << "Rellene los siguientes parametros\n"
         << endl;

    char ref[100];
    cout << "-> Referencia del polideportivo: " << endl;
    cin >> ref;
    sprintf(sendBuff, "%s", ref);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char nombre[100];
    cout << "\n-> Nombre del polideportivo: " << endl;
    cin >> nombre;
    sprintf(sendBuff, "%s", nombre);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char instalaciones[100];
    cout << "\n-> Instalaciones del polideportivo: " << endl;
    cin >> instalaciones;
    sprintf(sendBuff, "%s", instalaciones);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char direccion[100];
    cout << "\n-> Direccion del polideportivo: " << endl;
    cin >> direccion;
    sprintf(sendBuff, "%s", direccion);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char municipio[100];
    cout << "\n-> Municipio al que pertenece el polideportivo: " << endl;
    cin >> municipio;
    sprintf(sendBuff, "%s", municipio);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char codMunicipio[100];
    cout << "\n-> Codigo del Municipio al que pertenece el polideportivo: " << endl;
    cin >> codMunicipio;
    sprintf(sendBuff, "%s", codMunicipio);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char provincia[100];
    cout << "\n-> Provincia a la que pertenece el polideportivo: " << endl;
    cin >> provincia;
    sprintf(sendBuff, "%s", provincia);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char codProv[100];
    cout << "\n-> Codigo de provincia del polideportivo: " << endl;
    cin >> codProv;
    sprintf(sendBuff, "%s", codProv);
    send(s, sendBuff, sizeof(sendBuff), 0);

    char tel[100];
    cout << "\n-> Telefono del polideportivo: " << endl;
    cin >> tel;
    sprintf(sendBuff, "%s", tel);
    send(s, sendBuff, sizeof(sendBuff), 0);
    cout << endl;

}

void cMostrarMenuModificarPolideportivo(SOCKET s, char *sendBuff, char *recvBuff)
{
    char nombre[100], dir[100], tel[100], muni[100], codMuni[100], prov[100], codProv[100];

    cout << "\n======================================\n"
         << endl;
    cout << "MODIFICAR DATOS DEL POLIDEPORTIVO\n"
         << endl;
    cout << "======================================\n\n"
         << endl;

    cout << "Nombre:"
         << endl;
    cin >> nombre;
    sprintf(sendBuff, "%s", nombre);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nDireccion:"
         << endl;
    cin >> dir;
    sprintf(sendBuff, "%s", nombre);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nTelefono:"
         << endl;
    cin >> tel;
    sprintf(sendBuff, "%s", tel);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nMunicipio:"
         << endl;
    cin >> muni;
    sprintf(sendBuff, "%s", muni);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nCodigo de municipio:"
         << endl;
    cin >> codMuni;
    sprintf(sendBuff, "%s", codMuni);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nProvincia:"
         << endl;
    cin >> prov;
    sprintf(sendBuff, "%s", prov);
    send(s, sendBuff, sizeof(sendBuff), 0);

    cout << "\nCodigo de provincia:"
         << endl;
    cin >> codProv;
    sprintf(sendBuff, "%s", codProv);
    send(s, sendBuff, sizeof(sendBuff), 0);

}

void cMostrarMenuVisualizacionPorMunicipio(SOCKET s, char *sendBuff, char *recvBuff)
{
    char muni[100];

    cout << "\nEscriba la inicial del nombre del municipio del polideportivo a visualizar: " << endl;
    cin >> muni;
    sprintf(sendBuff, "%s", muni);
    send(s, sendBuff, sizeof(sendBuff), 0);
}

void cMostrarMenuEliminarPolideportivo(SOCKET s, char *sendBuff, char *recvBuff)
{

    char ref[100];

    cout << "\nEscriba el codigo de referencia del polideportivo a eliminar: " << endl;
    cin >> ref;
    sprintf(sendBuff, "%s", ref);
    send(s, sendBuff, sizeof(sendBuff), 0);

}

int main(int argc, char *argv[])
{

    char nombre[20], fNac[10], genero[10], DNI[9], tel[9], direccion[20], nombreUsuario[15], contrasenya[20];

    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in server;
    char sendBuff[512], recvBuff[512];

    cout << "\nInitialising Winsock...\n"
         << endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        cout << "Failed. Error Code : %d" << WSAGetLastError() << endl;
        return -1;
    }

    cout << "Initialised.\n"
         << endl;

    // SOCKET creation
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Could not create socket : %d" << WSAGetLastError() << endl;
        WSACleanup();
        return -1;
    }

    cout << "Socket created.\n"
         << endl;

    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    // CONNECT to remote server
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        cout << "Connection error: %d" << WSAGetLastError() << endl;
        closesocket(s);
        WSACleanup();
        return -1;
    }

    cout << "Connection stablished with: %s (%d)\n"
         << inet_ntoa(server.sin_addr) << ntohs(server.sin_port) << endl;

    // SEND and RECEIVE data

    // GEST POLI EUSKADI

    int op1, op2, op3;
    int respuestaS;
    do
    {
        op1 = cMostrarMenuGestPoli1(s, sendBuff, recvBuff);
        switch (op1)
        {
        case 1:
            cMostrarMenuIniSes(s, sendBuff, recvBuff);

            recv(s, recvBuff, sizeof(recvBuff), 0);
            sscanf(recvBuff, "%i", &respuestaS); // Recibe el resultado
            if (respuestaS == 1)
            {
                op2 = cMostrarMenuMenuPrinc(s, sendBuff, recvBuff);

                //do
                //{
                    switch (op2)
                    {
                    case 1:
                        cMostrarMenuImportarDatos();
                        break;

                    case 2:

                        op3 = cMostrarMenuGestPoli2(s, sendBuff, recvBuff);

                        //do
                        //{
                            switch (op3)
                            {
                            case 1:
                                cMostrarMenuVisualizacionGeneral();
                                break;
                            case 2:
                                cMostrarMenuVisualizacionPorMunicipio(s, sendBuff, recvBuff);
                                break;
                            case 3:
                                cMostrarMenuAnyadirPolideportivo(s, sendBuff, recvBuff);
                                break;
                            case 4:
                                cMostrarMenuModificarPolideportivo(s, sendBuff, recvBuff);
                                break;
                            case 5:
                                cMostrarMenuEliminarPolideportivo(s, sendBuff, recvBuff);
                                break;
                            case 6:
                                op3 = 0;
                                
                                break;
                            }

                        //} while (op3 != 0);

                    case 3:
                         op2 = 0;
                        
                        break;
                    }
               break;
                //} while (op2 != 0);
            }
            else
            {
                cout << "acceso denegado, identificacion incorrecta" << endl;
                break;
            } // me lleva a cMostrarMenuGestPoli1(); de nuevo
          break;
        case 2:
          if (op2 == 0)
          {
               op1 = 0;

               break;
          }
          
            cMostrarMenuRegUsu(s, sendBuff, recvBuff);

            recv(s, recvBuff, sizeof(recvBuff), 0);
            sscanf(recvBuff, "%i", &respuestaS); // Recibe el resultado

            if (respuestaS == 1)
            {
                cout << "Cliente registrado correctamente." << endl;
            }
            else
            {
                cout << "Registro de cliente fallido." << endl;
            }

            break; // me devuelve a gestpoli1();
        case 3:
            cout << "Cerrando programa... " << endl;
            op1 = 0;
            break;
        }

    } while (op1 != 0);

    // CLOSING the socket and cleaning Winsock...
    closesocket(s);
    WSACleanup();

    return 0;
}
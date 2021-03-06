#include <server/Server.h>
#include "Server.h"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

using namespace std;
using namespace server;

#define SOCKET_ERROR -1

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
typedef struct addrinfo ADDRINFO;
struct addrinfo * result;

SOCKADDR_IN server_sockaddr_in = {0};
SOCKADDR_IN client_sockaddr_in = {0};

namespace server {

    server::Server::Server(char* rHost, char* rPort){
        cout << "Starting server..." << endl;
        mHost = rHost;
        mPort = rPort;
    }

    int server::Server::Initialisation(){
        void* address;
/*         char ipstr[20];
        int lPort = atoi(mPort); */

        mSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if(mSock == SOCKET_ERROR){
            perror("ERROR: Failed to initialize server at socket creation");
            return SOCKET_ERROR;
        }

        if(getaddrinfo(mHost, mPort, NULL, &result) == SOCKET_ERROR){
            perror("ERROR: Failed to initialize server at getaddrinfo");
            return SOCKET_ERROR;
        }

        server_sockaddr_in = *(struct sockaddr_in *)result->ai_addr;
        address = &(server_sockaddr_in.sin_addr);

/*         inet_ntop(result->ai_family, address, ipstr, sizeof ipstr);
    
        server_sockaddr_in.sin_addr.s_addr = inet_addr(ipstr);
        server_sockaddr_in.sin_family = AF_INET;
        server_sockaddr_in.sin_port = htons(lPort); */

        if(bind(mSock, result->ai_addr, result->ai_addrlen) == -1){
            perror("ERROR: Failed to initialize server at bind");
            return SOCKET_ERROR;
        }

        cout << "Successfully initialized server" << endl;
    }

    int server::Server::Run(){
        char buffer[128] = {0};
        int new_client;
        socklen_t length = sizeof(client_sockaddr_in);

        if(listen(mSock, 10) == SOCKET_ERROR){
            perror("ERROR: Failed to listen");
            return SOCKET_ERROR;
        }

        cout << "Server is now listening on " << mHost << ":" << mPort << endl;

        while(1){
            new_client = accept(mSock, (sockaddr*)&client_sockaddr_in, &length);

            if(new_client != SOCKET_ERROR){
                cout << "New client connected" << endl;
                mPlayersConnected++;
                int ret = recv(new_client, buffer, 128, 0);
                memcpy(buffer, &mPlayersConnected, sizeof(mPlayersConnected));
                //sendto(mSock, buffer, sizeof(buffer), 0, (SOCKADDR*)&server_sockaddr_in, length)
                
                try{
                    send(mSock, buffer, sizeof(buffer), 0);
                }
                catch(const std::invalid_argument& e){
                    perror("ERROR: Failed to send data to client");
                    return SOCKET_ERROR;
                }
/*                 if(send(mSock, buffer, sizeof(buffer), 0) != SOCKET_ERROR){
                    cout << "Successfully sent data to client" << endl;
                }

                else{
                    perror("ERROR: Failed to send data to client");
                    return SOCKET_ERROR;
                } */
            }

            else{
                perror("ERROR: Failed to accept connection from client");
                return SOCKET_ERROR;
            }
            sleep(1);
        }

        return 0;
    }


}
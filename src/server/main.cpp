#include <server.h>
#include <iostream>
#include <string.h>

using namespace std;
using namespace server;

int main(int argc,char* argv[]){
    if(argc > 1){
        if(strcmp(argv[1], "listen") == 0){
            if(argv[2] == NULL || argv[3] == NULL){
                cout << "Please specify host and port" << endl;
                cout << "./bin/server network <host> <port>" << endl;
                return -1;
            }
            char* lHost = argv[2];
            char* lPort = argv[3];

            Server server(lHost, lPort);

            if(server.Initialisation() == -1){
                return -1;
            }
            
            server.Run();
        }


    }
    return 0;
}
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

void initialize_wsa(WSADATA *data) {
    printf("Initializing wsa...\n");
    int code = WSAStartup(MAKEWORD(2, 2), data); 
    if( code != 0) {
        printf("There was an error initializing WSA, please try again or check the source code in case of incompatibilities\n");
        exit(code);
    }
    printf("All correct\n");
}

int main(int argc, char** argv) {
    WSADATA data;
    initialize_wsa(&data);
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8081);
    
    bind(s, (struct sockaddr*)&addr , sizeof(addr));
    listen(s, 15);
    SOCKET client = accept(s, 0, 0);
    /*If everything goes well, we receive the data and route requests*/
    char request[500] = {0};
    char buffer[500] = {0};
    recv(client, request, 500, 0);
    
    if(memcmp(request, "GET / ", 6) == 0) {
        FILE* f = fopen("index.html", "r");
        fread(buffer, 1, 500, f);
        send(client, buffer, 500, 0);
    }
    else {
        printf("Here we are");
        closesocket(s);
        WSACleanup();
    }
}
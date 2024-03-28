#define WIN32_LEAN_AND_MEAN

#include<windows.h>
#include<winsock2.h>


#include<stdio.h>
#include<stdlib.h>

#pragma comment(lib,"ws2_32.lib")



#include "../include/error_handling.h"

 


int main(int argc,char* argv[])
{
    WSADATA wsadata;
    SOCKET hServerSock , hClntSock;
    SOCKADDR_IN servAddr,clntAddr;

    // WORD ver = MAKEWORD(2,2);
    // WSADATA dat;
    // int ret = WSAStartup(ver,&dat);
    // if(ret != 0){
    //     ErrorHandling("WSAStartup() error");
    // }

    int szClntAddr;


    char message[] = "hello World!";
    if(argc != 2){
        printf("Usage: %s <Port>\n",argv[0]);
        exit(1);
    }

    if(WSAStartup(MAKEWORD(2,2),&wsadata) != 0)
    {
        ErrorHandling("WSASatartup() error");
    }

    hServerSock = socket(AF_INET,SOCK_STREAM,0);
    if( INVALID_SOCKET == hServerSock)
        ErrorHandling("socket() error");
    
    memset(&servAddr,0,sizeof(SOCKADDR_IN));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.S_un.S_addr = htonl(ADDR_ANY);
    servAddr.sin_port = htons(atoi(argv[1]));

    if(bind(hServerSock,(SOCKADDR*)&servAddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        ErrorHandling("bind() error");
    }

    if(listen(hServerSock,5) == SOCKET_ERROR)
    {
        ErrorHandling("listen() error");
    }

    szClntAddr = sizeof(SOCKADDR_IN);
    hClntSock = accept(hServerSock,(SOCKADDR*)&clntAddr,&szClntAddr);
    if( INVALID_SOCKET == hClntSock)
    {
       ErrorHandling("accept() error");
    };

    send(hClntSock,message,sizeof(message),0);
    closesocket(hClntSock);
    closesocket(hServerSock);

    WSACleanup();
    return 0;
}
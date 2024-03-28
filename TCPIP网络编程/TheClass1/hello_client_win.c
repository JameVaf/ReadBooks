#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<windows.h>

#include "../include/error_handling.h"

#pragma comment(lib,"ws2_32.lib")


int main(int argc,char* argv[])
{
    WSADATA wsaData;
    SOCKET hSocket;
    SOCKADDR_IN servAddr;

    char message[30];
    int strLen;
    memset(message ,0, sizeof(message));

    if(argc != 3)
    {
        printf("Usage : %s <IP> <Port>\n",argv[0]);
        exit(1);
    }

    if(WSAStartup(MAKEWORD(2,2),&wsaData) != 0)
    {
        ErrorHandling("WSAStartup() error");
    }


    hSocket = socket(AF_INET,SOCK_STREAM,0);
    if(INVALID_SOCKET == hSocket){
        ErrorHandling("socket() error");
    }

    memset(&servAddr,0,sizeof(SOCKADDR_IN));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    servAddr.sin_port = htons(atoi(argv[2]));
    //printf("%s %s\n",argv[1],argv[2]);
    int ret = connect(hSocket,(SOCKADDR*)&servAddr,sizeof(SOCKADDR_IN));
    if(-1 == ret)
        ErrorHandling("connect() error");
      
    strLen = recv(hSocket,message,sizeof(message),0);

    if(-1 == strLen)
    {
        ErrorHandling("recv() error");
    }
    WSACleanup();
    printf("server message: %s\n",message);
    closesocket(hSocket);
    return 0;


}
#define WIN32_LEAN_AND_MEAN


#include<winsock2.h>
#include<windows.h>
#include<iostream>
#include "../include/error_handling.h"


#pragma comment(lib, "ws2_32.lib") 



int main(void){
    WORD ver = MAKEWORD(2,2);
    WSADATA dat;
    int ret = WSAStartup(ver,&dat);
    if(ret != 0){
        ErrorHandling("WSAStartup() error");
    }
        


    WSACleanup();
    return 0;
}

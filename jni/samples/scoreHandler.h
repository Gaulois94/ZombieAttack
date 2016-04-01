#ifndef DEF_SCOREHANDLER
#define DEF_SCOREHANDLER

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "logger.h"

#define SET_SCORE 0x01

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define PORT 9339
#define closesocket(param) close(param)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

typedef struct Client
{
	SOCKET socket;
	SOCKADDR_IN sin;
	socklen_t length;
}Client;


void updateScore(uint32_t score);

#endif

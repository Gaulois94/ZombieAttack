#include "scoreHandler.h"

void updateScore(uint32_t score)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN sin;
	socklen_t sinLength =  sizeof(sin);

	if(sock != SOCKET_ERROR)
	{
		if(inet_aton("172.18.87.58", &sin.sin_addr) == 0)
		{
			LOG_ERROR("INVALIDE ADRESS");
			return;
		}
		sin.sin_family = AF_INET;
		sin.sin_port = htons(PORT);

		printf("Try to connect to the server \n");
		if(connect(sock, (SOCKADDR*)&sin, sinLength) != SOCKET_ERROR)
		{
			score = htonl(score);
			char message[10];
			message[0] = SET_SCORE;
			message[1] = (score >> 24) & 0xff;
			message[2] = (score >> 16) & 0xff;
			message[3] = (score >> 8) & 0xff;
			message[4] = (score) & 0xff;

			send(sock, message, 5, 0);
		}
		else
			perror("Couldn't connect to the server");
	}
	else
		perror("Couldn't create the socket \n");
	LOG_ERROR("SUCCESS !");
	close(sock);
}

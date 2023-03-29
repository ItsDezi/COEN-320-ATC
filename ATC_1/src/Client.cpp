/*
 * Server.cpp
 *
 *  Created on: Mar. 27, 2023
 *      Author: Bisho
 */

#ifndef CLIENT_CPP_
#define CLIENT_CPP_

#include "MPData.cpp"
#define ATTACH_POINT "New_channel"

class Client {
public:
	pthread_t thread;

	Client(){};
	virtual ~Client(){};



	static void* clientRoutine(void* arg) {

		MPData* MsgToSendPointer = (MPData*)arg;
		MPData MsgToSend = *MsgToSendPointer;
		int server_coid; //server connection ID.

		if ((server_coid = name_open(ATTACH_POINT, 0)) == -1) {
			perror("Error occurred while attaching the channel");
		}

		if (MsgSend(server_coid, &MsgToSend, sizeof(MsgToSend), NULL,0) == -1) {
			printf("Error while sending the message from Client");
		}


		/* Close the connection */
		name_close(server_coid);
		return EXIT_SUCCESS;
	}

};
#endif

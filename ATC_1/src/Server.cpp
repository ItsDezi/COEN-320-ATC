/*
 * Server.cpp
 *
 *  Created on: Mar. 27, 2023
 *      Author: Bisho
 */

#ifndef SERVER_CPP_
#define SERVER_CPP_

#include "MPData.cpp"
#include <iostream>
#define ATTACH_POINT "New_channel"


class Server {
public:
	pthread_t thread;
	Server(){};
	virtual ~Server(){};

	static void* serverRoutine(void* args) {
		MPData* DataToUpdatePointer = (MPData*) args;
		MPData  DataToUpdate = *DataToUpdatePointer;

		name_attach_t *attach;
		MPData MsgToRecieve;
		int rcvid;

		if ((attach = name_attach(NULL, ATTACH_POINT, 0)) == NULL) {
			perror("Error occurred while creating the channel");
		}


		while (true) {

			rcvid = MsgReceive(attach->chid, &MsgToRecieve, sizeof(MsgToRecieve), NULL);


			if (rcvid == -1) {/* Error condition, exit */
				break;
			}

			if (rcvid == 0) {/* Pulse received */
				switch (MsgToRecieve.hdr.code) {
				case _PULSE_CODE_DISCONNECT:
					/*
					 * A client disconnected all its connections (called
					 * name_close() for each name_open() of our name) or
					 * terminated
					 */
					ConnectDetach(MsgToRecieve.hdr.scoid);
					break;
				case _PULSE_CODE_UNBLOCK:
					/*
					 * REPLY blocked client wants to unblock (was hit by
					 * a signal or timed out).  It's up to you if you
					 * reply now or later.
					 */
					break;
				default:
					/*
					 * A pulse sent by one of your processes or a
					 * _PULSE_CODE_COIDDEATH or _PULSE_CODE_THREADDEATH
					 * from the kernel?
					 */
					break;
				}
				continue;
			}

			/* name_open() sends a connect message, must EOK this */
			if (MsgToRecieve.hdr.type == _IO_CONNECT ) {
				MsgReply( rcvid, EOK, NULL, 0 );
				continue;
			}

			/* Some other QNX IO message was received; reject it */
			if (MsgToRecieve.hdr.type > _IO_BASE && MsgToRecieve.hdr.type <= _IO_MAX ) {
				MsgError( rcvid, ENOSYS );
				continue;
			}


			if (MsgToRecieve.hdr.type == 0x00) {

				// Aircraft to Radar. Only "aircraft" variable is Valid
				if (MsgToRecieve.hdr.subtype == 0x01) {
					cout << "Received ID  of Aircraft is " << MsgToRecieve.aircraft.ID<< endl;
				}
				// Radar to Computer System
				else if (MsgToRecieve.hdr.subtype == 0x02) {
					DataToUpdate = MsgToRecieve;
					cout << "all Aircrafts data are received " <<  endl;
				}
				// TODO: add other communications
				else{
					MsgError( rcvid, ENOSYS );
					continue;
				}
			}

			MsgReply(rcvid, EOK, 0, 0);
			sleep(200);
		}

		/* Remove the name from the space */
		name_detach(attach, 0);

		return NULL;
	}
};
#endif

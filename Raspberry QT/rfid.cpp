/*#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdbool.h>

#include "rfid.h"

enum RFIDerrnoEnumType RFIDerrno = RFID_ERR_OK;

int RFIDopen() {
	int RFIDserial = open("/dev/serial0", O_RDONLY | O_NOCTTY);
	if (RFIDserial == -1) {
		RFIDerrno = RFID_ERR_OPEN;
		return -1;
	}
	struct termios RFIDconfig;
	tcgetattr(RFIDserial, &RFIDconfig);	//wstępne wypełnienie struktury
	cfmakeraw(&RFIDconfig);			//ustaw na raw
	cfsetspeed(&RFIDconfig, B9600);	//speed 9600
	RFIDconfig.c_cflag &= ~CSIZE;		
	RFIDconfig.c_cflag |= CS8;			//data size 8
	RFIDconfig.c_cflag &= ~PARENB;		//no parity
	RFIDconfig.c_cflag &= ~CSTOPB;		//one stop bit
	RFIDconfig.c_cflag |= CLOCAL;
	RFIDconfig.c_cflag |= CREAD;
	RFIDconfig.c_cc[VTIME] = 0;
	RFIDconfig.c_cc[VMIN] = 14;
	tcsetattr(RFIDserial, TCSANOW, &RFIDconfig); //zastosuj
	return RFIDserial;
}
int RFIDcheck(int RFIDserial) {
	int ret;
	ioctl(RFIDserial, FIONREAD, &ret);
	return ret;
}

bool RFIDchecksum(char buffer[14]) {
	char rawTag[6];
	for (int i = 0; i < 6; i++) {
		char tmpStr[2];
		tmpStr[0] = buffer[i*2 + 1];
		tmpStr[1] = buffer[i*2 + 2];
		rawTag[i] = strtoul(tmpStr, NULL, 16);
	}
	char checksum = rawTag[0];
	for (int i = 1; i < 5; i++)
		checksum ^= rawTag[i];
	return checksum == rawTag[5];
}

char* RFIDread(int RFIDserial) {
	static char buffer[14]; //recived message
	read(RFIDserial, buffer, 14);
	if (buffer[0] != 2 || buffer[13] != 3) {
		RFIDerrno = RFID_ERR_FRAME;
		return NULL; //error: invalid start or end of message
	}
	if (!RFIDchecksum(buffer)) {
		RFIDerrno = RFID_ERR_CHECKSUM;
		return NULL; //error: invalid checksum
	}
	return buffer+1;
}

void RFIDclear(int RFIDserial) {
	tcflush(RFIDserial, TCIFLUSH);
}

void RFIDclose(int RFIDserial) {
	close(RFIDserial);
}*/

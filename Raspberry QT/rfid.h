#ifndef RFIH_H
#define RFID_H

enum RFIDerrnoEnumType{
	RFID_ERR_OK,
	RFID_ERR_OPEN,
	RFID_ERR_FRAME,
	RFID_ERR_CHECKSUM
};

extern enum RFIDerrnoEnumType RFIDerrno;

//otwiera połączenie z interfejsem szeregowym, zwraca deskryptor pliku (połączenia); w razie błędu zwraca NULL i ustawia 'RFIDerrno' na 'RFID_ERR_OPEN'
int RFIDopen();
//zwraca liczbę bajtów czekających na odczytanie w buforze wejściowym połączenia 'RFIDserial'; wymaga otwartego połączenia
int RFIDcheck(int RFIDserial);
//spradza poprawność ramki poprzez sumę kontrolną
bool RFIDchecksum(char buffer[14]);
//odczytuje z połączenia 'RFIDserial' numer przyłożonej karty (10 znaków); w razie błędu zwraca NULL i ustawia 'RFIDerrno' na 'RFID_ERR_FRAME' w razie błędu ramki bądź 'RFID_ERR_CHECKSUM' w razie niewłaściwej sumy kontrolnej
char* RFIDread(int RFIDserial);
//usuwa nieodczytaną zawartość bufora wejściowego połączenia 'RFIDserial'
void RFIDclear(int RFIDserial);
//zamyka połączenie z 'RFIDserial'
void RFIDclose(int RFIDserial);
#endif

#include "rfid.h"
#include <stdio.h>
#include <unistd.h>

int main() {
	
	int RFIDserial = RFIDopen(); //otwórz połączenie
	if (RFIDerrno == RFID_ERR_OPEN) { //jeżeli wystąpił błąd przy otwieraniu połączenia
		printf("Error while opening connection with serial!\n");
		return -1;
	}
	char* readMsg; //bufor na odczytane dane
	for (int i = 0; i < 60; i++) { //przez pół minuty odczytuj co pół sekundy
		int toRead = RFIDcheck(RFIDserial); //sprawdź ile znaków czeka na odczyt
		if (toRead >= 14) { //jeżeli na odczyt czeka conajmniej 14 znaków (cała wiadomość czytnika)
			printf("Recieved\n");
			readMsg = RFIDread(RFIDserial); //odczytaj wiadomość
			RFIDclear(RFIDserial); //wyczyść bufor wejściowy (na wypadek wielokrotnego odczytania tej samej karty)
			if (readMsg == NULL) { //jeżeli wystąpił błąd
				printf("Error: ");
				if (RFIDerrno == RFID_ERR_FRAME)
					printf("invalid frame\n"); //niewłaściwa ramka (błędny znak początku lub końca)
				else if (RFIDerrno == RFID_ERR_CHECKSUM)
				printf("invalid checksum\n"); //niewłaściwa suma kontrolna
			}
			else {
				for (int i = 0; i < 10; i++) //wypisz wiadomość (nie używać %s, to nie jest null-terminated string!)
					printf("%c", readMsg[i]);
				printf("\n");
			}
		}
		usleep(500000); //odczekaj pół sekundy
	}
	RFIDclose(RFIDserial); //zamknij połączenie
	printf("Program ended!\n");
	return 0;
}

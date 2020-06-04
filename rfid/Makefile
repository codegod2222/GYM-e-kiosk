rfid: clean rfid.o rfidexample.o
	@echo "Linking..."
	gcc -Wall rfid.o rfidexample.o -pedantic -o rfid
	rm -f rfid.o rfidexample.o

rfid.o:
	@echo "Compiling 'rfid'..."
	gcc -Wall rfid.c -c -pedantic -o rfid.o

rfidexample.o:
	@echo "Compiling 'rfidexample'..."
	gcc -Wall rfidexample.c -c -pedantic -o rfidexample.o

clean:
	@echo "Cleaning..."
	rm -f rfid.o rfid rfidexample.o

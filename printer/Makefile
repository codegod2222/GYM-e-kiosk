rfid: clean printer.o printerexample.o
	@echo "Linking..."
	gcc printer.o printerexample.o -lstdc++ -o printer
	@echo "Cleaning..."
	rm -f printer.o printerexample.o

printer.o:
	@echo "Compiling 'printer'..."
	gcc printer.cpp -c -o printer.o

printerexample.o:
	@echo "Compiling 'printerexample'..."
	gcc printerexample.cpp -c -pedantic -o printerexample.o

clean:
	@echo "Cleaning..."
	rm -f printer.o printer printerexample.o

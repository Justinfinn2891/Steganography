CC = g++
CFLAGS = -g -Wall -Wextra

default: steganography

steganography: main.o Steganography.o
	$(CC) $(CFLAGS) -o steganography main.o Steganography.o

Steganography.o: Steganography.cpp Steganography.h
	$(CC) $(CFLAGS) -c Steganography.cpp

main.o: main.cpp Steganography.h
	$(CC) $(CFLAGS) -c main.cpp

clean: $(RM) Steganography *.o *~ 

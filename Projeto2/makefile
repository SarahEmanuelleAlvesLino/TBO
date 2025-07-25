CC = g++
CFLAGS = -Wall -O2
TARGET = huffman

all: $(TARGET)

$(TARGET): main.o huffman.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o huffman.o

main.o: main.cpp huffman.h
	$(CC) $(CFLAGS) -c main.cpp

huffman.o: huffman.cpp huffman.h
	$(CC) $(CFLAGS) -c huffman.cpp

clean:
	rm -f *.o $(TARGET)

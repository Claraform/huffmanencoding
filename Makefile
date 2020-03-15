CC=g++
CCFLAGS=-std=c++11

default: huffencode.o HuffmanTree.o HuffmanNode.o
	$(CC) huffencode.o HuffmanTree.o HuffmanNode.o $(CCFLAGS) -o huffencode
        
huffencode.o: huffencode.cpp
	$(CC) $(CCFLAGS) huffencode.cpp -c

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	$(CC) $(CCFLAGS) HuffmanTree.cpp -c

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(CC) $(CCFLAGS) HuffmanNode.cpp -c

Test.o:	Test.cpp
	$(CC) $(CCFLAGS) Test.cpp -c

test: HuffmanNode.o HuffmanTree.o Test.o
	$(CC) $(CCFLAGS) HuffmanNode.o HuffmanTree.o Test.o -o test 

clean:
	rm -f *.o
	rm -f huffencode
                           

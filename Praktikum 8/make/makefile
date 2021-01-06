../programm/programm: ../code/main.cpp LinkedList.o LinkedListObject.o
	g++ -o ../programm/programm ../code/main.cpp LinkedList.o LinkedListObject.o

LinkedList.o: ../code/LinkedList/LinkedList.cpp ../code/LinkedList/LinkedList.h LinkedListObject.o
	g++ -c ../code/LinkedList/LinkedList.cpp

LinkedListObject.o: ../code/LinkedList/LinkedListObject/LinkedListObject.cpp ../code/LinkedList/LinkedListObject/LinkedListObject.h
	g++ -c ../code/LinkedList/LinkedListObject/LinkedListObject.cpp
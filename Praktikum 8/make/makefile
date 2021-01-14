../programm/programm: ../code/main.cpp LinkedList.o LinkedListObject.o Iterator.o
	g++ -o ../programm/programm ../code/main.cpp LinkedList.o LinkedListObject.o Iterator.o

LinkedList.o: ../code/LinkedList/LinkedList.cpp ../code/LinkedList/LinkedList.h LinkedListObject.o Iterator.o
	g++ -c ../code/LinkedList/LinkedList.cpp

LinkedListObject.o: ../code/LinkedList/LinkedListObject/LinkedListObject.cpp ../code/LinkedList/LinkedListObject/LinkedListObject.h
	g++ -c ../code/LinkedList/LinkedListObject/LinkedListObject.cpp

Iterator.o: ../code/LinkedList/LinkedListIterator/Iterator.cpp ../code/LinkedList/LinkedListIterator/Iterator.h
	g++ -c ../code/LinkedList/LinkedListIterator/Iterator.cpp
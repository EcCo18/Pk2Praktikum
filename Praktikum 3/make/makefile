../programm/programm: ../code/main.c dictonary.o
	gcc -o ../programm/programm ../code/main.c dictonary.o

dictonary.o: ../code/dictonary.c
	gcc -c ../code/dictonary.c

clean:
	rm *.o *.a ../programm/programm
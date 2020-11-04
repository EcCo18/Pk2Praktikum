../programm/programm: ../code/main.c libmy.a 
	gcc -o ../programm/programm ../code/main.c libmy.a 

libmy.a: asciiCode.o einMalEins.o intToBin.o
	ar r libmy.a intToBin.o asciiCode.o einMalEins.o

asciiCode.o: ../code/asciiCode.c 
	gcc -c ../code/asciiCode.c

einMalEins.o: ../code/einMalEins.c 
	gcc -c ../code/einMalEins.c 

intToBin.o: ../code/intToBin.c 
	gcc -c ../code/intToBin.c 
../programm/programm: ../code/main.cpp Bild.o Audio.o Medium.o
	g++ -o ../programm/programm ../code/main.cpp Bild.o Audio.o Medium.o

Bild.o: ../code/Bild.cpp ../code/Bild.h Medium.o
	g++ -c ../code/Bild.cpp

Audio.o: ../code/Audio.cpp ../code/Bild.h Medium.o
	g++ -c ../code/Audio.cpp

Medium.o: ../code/Medium.cpp ../code/Medium.h
	g++ -c ../code/Medium.cpp

clean: 
	rm *.a *.o
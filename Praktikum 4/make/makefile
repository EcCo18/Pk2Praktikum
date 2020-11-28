../programm/programm: ../code/main.cpp Dictionary.o DictionaryField.o
	g++ -o ../programm/programm ../code/main.cpp Dictionary.o DictionaryField.o

Dictionary.o: ../code/dictionary/dictionary.cpp ../code/dictionary/Dictionary.h DictionaryField.o
	g++ -c ../code/dictionary/dictionary.cpp

DictionaryField.o: ../code/dictionary/dictionaryField.cpp ../code/dictionary/DictionaryField.h
	g++ -c ../code/dictionary/dictionaryField.cpp

clean:
	rm *o ../programm/programm
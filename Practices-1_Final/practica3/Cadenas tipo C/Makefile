BIN=bin
OBJ=obj
INC=include
SRC=src
DAT=datos

#----------- Lista de dependencias ------------#

all: $(BIN)/ejecutable

bin/ejecutable : $(OBJ)/main.o $(OBJ)/palabras.o 
	g++ -o $(BIN)/ejecutable $(OBJ)/main.o $(OBJ)/palabras.o 

obj/main.o: $(SRC)/main.cpp $(INC)/palabras.h 
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

obj/palabras.o: $(SRC)/palabras.cpp $(INC)/palabras.h
	g++ -c $(SRC)/palabras.cpp -o $(OBJ)/palabras.o -I$(INC)

#------------ Limpieza -------------#

clean: mrproper
	echo 'Limpiando...'
	rm obj/*.o
	

mrproper: 
	rm bin/*

	

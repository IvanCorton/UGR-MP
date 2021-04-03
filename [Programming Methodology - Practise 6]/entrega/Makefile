BIN=bin
OBJ=obj
INC=include
SRC=src
DAT=datos

#----------- Lista de dependencias ------------#

all: $(BIN)/ejecutable

bin/ejecutable : $(OBJ)/main.o $(OBJ)/lienzo.o 
	g++ -g -o $(BIN)/ejecutable $(OBJ)/main.o $(OBJ)/lienzo.o 

obj/main.o: $(SRC)/main.cpp $(INC)/lienzo.h 
	g++ -g -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

obj/lienzo.o: $(SRC)/lienzo.cpp $(INC)/lienzo.h
	g++ -g -c $(SRC)/lienzo.cpp -o $(OBJ)/lienzo.o -I$(INC)

#------------ Limpieza -------------#

clean: mrproper
	echo 'Limpiando...'
	rm obj/*.o
	

mrproper: 
	rm bin/*

	

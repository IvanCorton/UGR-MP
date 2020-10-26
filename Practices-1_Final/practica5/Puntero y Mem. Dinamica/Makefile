BIN=bin
OBJ=obj
INC=include
SRC=src
DAT=datos

#----------- Lista de dependencias ------------#

all: $(BIN)/ejecutable

bin/ejecutable : $(OBJ)/main.o $(OBJ)/diccionario.o 
	g++ -o $(BIN)/ejecutable $(OBJ)/main.o $(OBJ)/diccionario.o 

obj/main.o: $(SRC)/main.cpp $(INC)/diccionario.h 
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

obj/diccionario.o: $(SRC)/diccionario.cpp $(INC)/diccionario.h
	g++ -c $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o -I$(INC)

#------------ Limpieza -------------#

clean: mrproper
	echo 'Limpiando...'
	rm obj/*.o
	

mrproper: 
	rm bin/*

	

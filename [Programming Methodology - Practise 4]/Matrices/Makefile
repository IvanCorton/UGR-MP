BIN=bin
OBJ=obj
INC=include
SRC=src
DAT=datos

#----------- Lista de dependencias ------------#

all: $(BIN)/ejecutable

bin/ejecutable : $(OBJ)/main.o $(OBJ)/calculo.o 
	g++ -o $(BIN)/ejecutable $(OBJ)/main.o $(OBJ)/calculo.o 

obj/main.o: $(SRC)/main.cpp $(INC)/calculo.h 
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

obj/calculo.o: $(SRC)/calculo.cpp $(INC)/calculo.h
	g++ -c $(SRC)/calculo.cpp -o $(OBJ)/calculo.o -I$(INC)

#------------ Limpieza -------------#

clean: mrproper
	echo 'Limpiando...'
	rm obj/*.o
	

mrproper: 
	rm bin/*

	

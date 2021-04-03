BIN=bin
OBJ=obj
INC=include
SRC=src
DAT=datos

#----------- Lista de dependencias ------------#

all: $(BIN)/ejecutable

bin/ejecutable : $(OBJ)/central.o $(OBJ)/punto2d.o $(OBJ)/circulo.o $(OBJ)/demo1.o
	g++ -o $(BIN)/ejecutable $(OBJ)/demo1.o

obj/demo1.o: $(SRC)/demo1.cpp 
	g++ -c $(SRC)/demo1.cpp -o $(OBJ)/demo1.o

obj/central.o: $(SRC)/punto2d.cpp $(INC)/punto2d.h
	g++ -c $(SRC)/punto2d.cpp -o $(OBJ)/central.o -I$(INC)

obj/punto2d.o: $(SRC)/punto2d.cpp include/punto2d.h
	g++ -c $(SRC)/punto2d.cpp -o $(OBJ)/punto2d.o -I$(INC)

obj/circulo.o: $(SRC)/circulo.cpp $(INC)/circulo.h $(INC)/punto2d.h
	g++ -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -I$(INC)

#------------ Limpieza -------------#

clean: 
	echo 'Limpiando...'
	rm obj/*.o

mrproper: clean
	rm bin/central bin/main

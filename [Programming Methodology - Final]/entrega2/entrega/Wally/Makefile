BIN=bin
OBJ=obj
INC=include
SRC=src
DAT=datos

#----------- Lista de dependencias ------------#

all: $(BIN)/Wally

bin/Wally : $(OBJ)/Wally.o $(OBJ)/pintar.o $(OBJ)/miniwin.o $(OBJ)/Punto2D.o $(OBJ)/PoliReg.o 
	g++ -g -o $(BIN)/Wally $(OBJ)/Wally.o $(OBJ)/pintar.o $(OBJ)/miniwin.o $(OBJ)/Punto2D.o $(OBJ)/PoliReg.o  -lX11 -pthread

obj/Wally.o: $(SRC)/Wally.cpp $(INC)/Pintar.h 
	g++ -g -c $(SRC)/Wally.cpp -o $(OBJ)/Wally.o -I$(INC)

obj/pintar.o: $(SRC)/Pintar.cpp $(INC)/Pintar.h $(INC)/Punto2D.h $(INC)/miniwin.h $(INC)/PoliReg.h
	g++ -g -c $(SRC)/Pintar.cpp -o $(OBJ)/pintar.o -I$(INC)

obj/miniwin.o: $(SRC)/miniwin.cpp $(INC)/miniwin.h
	g++ -g -c $(SRC)/miniwin.cpp -o $(OBJ)/miniwin.o -I$(INC)

obj/Punto2D.o: $(SRC)/Punto2D.cpp $(INC)/Punto2D.h
	g++ -g -c $(SRC)/Punto2D.cpp -o $(OBJ)/Punto2D.o -I$(INC)

obj/PoliReg.o: $(SRC)/PoliReg.cpp $(INC)/PoliReg.h $(INC)/Punto2D.h
	g++ -g -c $(SRC)/PoliReg.cpp -o $(OBJ)/PoliReg.o -I$(INC)


#------------ Limpieza -------------#

clean: 
	rm obj/*
	rm bin/*

	

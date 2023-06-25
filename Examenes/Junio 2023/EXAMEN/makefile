.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcomplejo.o tvectorcom.o tavlcom.o tabbcom.o tlistacom.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))
DEL = TESTS_UNITARIOS/*Prueba/*.out misalida.txt tad

tad:    src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<


tar: src lib include nombres.txt
	tar cvfz cuadjunio.tgz include src lib nombres.txt

clean:
	rm -f $(OBJ) $(DEL)

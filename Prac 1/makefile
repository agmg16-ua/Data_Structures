.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcomplejo.o tvectorcom.o tlistacom.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))
DEL = TESTS_UNITARIOS/TListaCom_PRUEBA/*.out TESTS_UNITARIOS/ComplejoPRUEBA/*.out TESTS_UNITARIOS/TVectorCom_PRUEBA/*.out 

tad:    src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<


clean:
	rm -f $(OBJ) $(DEL)
# Makefile for parallel simulated annealer

TARGET=canneal
LIBS:=$(LIBS) -lm
INC:=-I../../hooks

CXXFLAGS+=-DENABLE_THREADS -DENABLE_ZSIM_HOOKS -pthread

all:
	$(CXX) $(CXXFLAGS) $(INC) annealer_thread.cpp -c -o annealer_thread.o
	$(CXX) $(CXXFLAGS) $(INC) rng.cpp -c -o rng.o
	$(CXX) $(CXXFLAGS) $(INC) netlist.cpp -c -o netlist.o
	$(CXX) $(CXXFLAGS) $(INC) main.cpp -c -o main.o
	$(CXX) $(CXXFLAGS) $(INC) netlist_elem.cpp -c -o netlist_elem.o
	$(CXX) $(CXXFLAGS) $(INC) $(LDFLAGS) *.o $(LIBS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)

install:
	mkdir -p ../bin
	cp -f $(TARGET) ../bin/$(TARGET)


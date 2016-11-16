target: counter

.SUFFIXES:
.SUFFIXES: .idl .cc .hh .o .cpp

OBJS = \
	vector.o \
	counter.o

CXXFLAGS = -I.

vector: vector.o 
	g++ $^ -o $@ 

counter: counter.o
	g++ $^ -o $@ -lrt
clean:
	@rm -f $(OBJS) counter counter.o *~
	
	


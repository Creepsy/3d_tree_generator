sDir = src/
bDir = build/

all: $(bDir)object.o $(sDir)object.h $(bDir)components.o
	g++ $(sDir)generator.cpp -o generator $(bDir)object.o $(bDir)components.o

$(bDir)object.o: $(sDir)object.cpp
	g++ -c $(sDir)object.cpp -o $(bDir)object.o

$(bDir)components.o: $(sDir)components.cpp
	g++ -c $(sDir)components.cpp -o $(bDir)components.o
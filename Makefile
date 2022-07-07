CC=g++
CC_FLAGS= -std=c++11 -Wall -g
EXE=graph.exe
OBJ= graphUser.o graphBuilder.o

all:graph

graph: graphUser.o graphBuilder.o
	$(CC) -o graph graphUser.o graphBuilder.o

graphUser.o: graphUser.cpp
	$(CC) $(CC_FLAGS) -c graphUser.cpp

graphBuilder.o: graphBuilder.cpp
	$(CC) $(CC_FLAGS) -c graphBuilder.cpp

clean:
	rm -f $(EXE) $(OBJ)


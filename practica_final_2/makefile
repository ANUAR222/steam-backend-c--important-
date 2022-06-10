CC=g++
CFLAGS=-Wall -g
EXEC = main
obs =Date.o Game.o Review.o User.o GameList.o UserList.o
DEPS =Date.h Game.h Review.h User.h GameList.h UserList.h
SOURCES = $(shell ls *.cpp)
OBJS = $(SOURCES:%.cpp=%.o)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
main:
	g++ main.o Date.o Game.o Review.o User.o GameList.o UserList.o

.PHONY: clean

clean:
	rm *.o $(EXEC)

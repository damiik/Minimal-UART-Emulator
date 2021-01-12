TARGET = main
LIBS = -lm -lstdc++ -lncurses
CC = g++
CFLAGS = -O3 -std=c++11 -Wall -I/usr/include/

.PHONY: default all clean

default: $(TARGET)

all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp, *.h)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
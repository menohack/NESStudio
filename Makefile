CC = gcc
CFLAGS = `wx-config --cxxflags --libs` -lsfml-audio -g

all: Studio.h Studio.cpp main.cpp
	$(CC) main.cpp Studio.cpp $(CFLAGS) -o NESStudio

clean:
	rm -rf *.o NESStudio

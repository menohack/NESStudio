CC = gcc
CFLAGS = `wx-config --cxxflags --libs` -lsfml-audio -g

all: Studio.h Studio.cpp App.h App.cpp main.cpp
	$(CC) main.cpp App.cpp Studio.cpp $(CFLAGS) -o NESStudio

clean:
	rm -rf *.o NESStudio

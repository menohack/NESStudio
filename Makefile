CC = gcc
CFLAGS = `wx-config --cxxflags --libs`

all: Studio.h main.cpp
	$(CC) main.cpp $(CFLAGS) -o NESStudio

clean:
	rm -rf *.o NESStudio

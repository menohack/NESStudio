CC = gcc
CFLAGS = `wx-config --cxxflags --libs` -lsfml-audio -g
OBJS = Pulse.o Triangle.o Song.o

all: Studio.h Studio.cpp App.h App.cpp main.cpp $(OBJS)
	$(CC) main.cpp App.cpp Studio.cpp $(OBJS) $(CFLAGS) -o NESStudio

Pulse.o: Pulse.cpp Pulse.h Channel.h
	$(CC) Pulse.cpp $(CFLAGS) -c

Triangle.o: Triangle.cpp Triangle.h Channel.h
	$(CC) Triangle.cpp $(CFLAGS) -c

Song.o: Song.cpp Song.h
	$(CC) Song.cpp $(CFLAGS) -c

clean:
	rm -rf *.o NESStudio

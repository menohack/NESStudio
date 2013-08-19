#include "Song.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace NESStudio;
using namespace std;

void LoadNotes(char * notesFile, int ** notes, int * numNotes)
{
}

void LoadNoteLengths(char * lengthFile, int ** lengths, int * numLengths)
{
}

void Song::Load(char * songFile, char * notesFile, char * lengthFile);
{
	int * notes;
	int numNotes;
	LoadNotes(notesFile, &notes, &numNotes);

	int * lengths;
	int numLengths;
	LoadNoteLengths(lengthFile, &lengths, &numLengths);
	
	fstream stream(songFile);

	char buf[256];
	stream.getline(buf, 256);
	
	while (!stream.eof())
	{		
		//stream.getline(buf, 256);
		string s;
		stream >> s;
		if (s == ".byte")
		{
			stream >> s;

			//Note length 1011xxxx
			if (s[1] == 'B')
			{
				int index = s[2] - 'A';
			}
			//Loop counter 11xxxxxx
			else if (s[1] >= 'C')
			{
				;
			}
		}
	}
}

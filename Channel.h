#ifndef _CHANNEL_H
#define _CHANNEL_H

namespace NESStudio
{

enum Note
{
	C4 = 262,
	G4 = 196,
	C3 = 131,
};

class Channel
{
protected:
	double seconds;
	int count;
public:
	void virtual Init() = 0;
	void virtual Play(Note note) = 0;
	void virtual SetNoteLength(double seconds);
	void virtual SetLoopCount(int count);
};

}
#endif

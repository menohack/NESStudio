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
public:
	void virtual Init(Note note) = 0;
	void virtual Play() = 0;
};

}
#endif

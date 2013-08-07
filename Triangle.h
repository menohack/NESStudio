#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include <SFML/Audio.hpp>

#include "Channel.h"

using namespace sf;


namespace NESStudio
{


class Triangle
{
private:
	Int16 * samples;
	SoundBuffer buffer;
	Sound sound;
	unsigned numSamples;
public:
	Triangle();
	Triangle(Note note);

	~Triangle();

	void virtual Init(Note note);
	void virtual Play();

	static void MakeTriangleWave(Int16 * samples, unsigned numSamples, unsigned rate, unsigned volume);

	const static int SAMPLING_RATE = 44100;
};

}
#endif

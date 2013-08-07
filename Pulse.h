#ifndef _PULSE_H
#define _PULSE_H

#include <SFML/Audio.hpp>

#include "Channel.h"

using namespace sf;


namespace NESStudio
{


class Pulse
{
private:
	Int16 * samples;
	SoundBuffer buffer;
	Sound sound;
	unsigned numSamples;
public:
	Pulse();
	Pulse(Note note);

	~Pulse();

	void virtual Init(Note note);
	void virtual Play();

	static void MakePulseWave(Int16 * samples, unsigned numSamples, unsigned rate, unsigned volume);

	const static int SAMPLING_RATE = 44100;
};

}
#endif

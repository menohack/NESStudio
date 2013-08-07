#include "Pulse.h"

#include <math.h>

using namespace NESStudio;

void MakeSineWave(Int16 * samples, int numSamples, int rate, unsigned volume)
{
       for (int i = 0; i < numSamples; i++)
               samples[i] = volume * sin(((double)i / rate) * 2.0 * M_PI);
}

Pulse::Pulse()
{
}

Pulse::Pulse(Note note)
{
	Init(note);
}

void Pulse::Init(Note note)
{
	//a tenth of a second worth of sound
	numSamples = SAMPLING_RATE / 10;
	samples = new Int16[numSamples];

	MakePulseWave(samples, numSamples, SAMPLING_RATE/note, 4000);
	
	bool result = buffer.LoadFromSamples(samples, numSamples, 2, SAMPLING_RATE);

	if (!result)
		throw "Uh oh";

	sound.SetBuffer(buffer);
}

Pulse::~Pulse()
{
	delete [] samples;
}

void Pulse::MakePulseWave(Int16 * samples, unsigned numSamples, unsigned rate, unsigned volume)
{
	int i = 0;
	while (i < numSamples)
	{
		for (int p=0; p < rate/2 && i < numSamples; p++)
			samples[i++] = volume;
		for (int p=0; p < rate/2 && i < numSamples; p++)
			samples[i++] = -volume;
	}
}



void Pulse::Play()
{
	sound.Play();
}

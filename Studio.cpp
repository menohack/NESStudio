#include "Studio.h"

using namespace NESStudio;

void MakeSineWave(Int16 * samples, int numSamples, int rate)
{
	for (int i = 0; i < numSamples; i++)
		samples[i] = 32768 * sin(((double)i / rate) * 2.0 * M_PI);
}

Studio::Studio()
{

}

void Studio::Play()
{
	numSamples = 32 * 1024;
	samples = new Int16[numSamples];
	MakeSineWave(samples, numSamples, 32);
	buffer = new SoundBuffer();
	bool result =
	    buffer->LoadFromSamples(samples, numSamples, 2, numSamples);
	Sound *sound = new Sound;
	sound->SetBuffer(*buffer);
	sound->Play();
}

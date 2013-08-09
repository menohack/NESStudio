#include "Triangle.h"

#include <math.h>

using namespace NESStudio;

Triangle::Triangle()
{
}

Triangle::Triangle(Note note)
{
	Init(note);
}

void Triangle::Init(Note note)
{
	//a tenth of a second worth of sound
	numSamples = SAMPLING_RATE / 10;
	samples = new Int16[numSamples];

	MakeTriangleWave(samples, numSamples, SAMPLING_RATE/note, 16000);
	
	bool result = buffer.LoadFromSamples(samples, numSamples, 2, SAMPLING_RATE);

	if (!result)
		throw "Uh oh";

	sound.SetBuffer(buffer);
}

Triangle::~Triangle()
{
	delete [] samples;
}

void Triangle::MakeTriangleWave(Int16 * samples, unsigned numSamples, unsigned rate, unsigned volume)
{
	int i = 0;
	while (i < numSamples)
	{
		for (int p=0; p < rate/2 && i < numSamples; p++)
			samples[i++] = (2.0 * p/rate) * volume;
		for (int p=rate/2; p >= 0 && i < numSamples; p--)
			samples[i++] = (2.0 * p/rate) * volume;
	}
}



void Triangle::Play()
{
	sound.Play();
}

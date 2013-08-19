#include "Studio.h"

#include "Song.h"

using namespace NESStudio;

Studio::Studio()
{
	pulse1.Init(C4);
	pulse2.Init(G4);

	triangle.Init(C3);

	Song song;
	song.Load("BrinstarSQ1", "MusicNotes", "NoteLengths1");
}

void Studio::PlayPulse1()
{
	pulse1.Play();
}

void Studio::PlayPulse2()
{
	pulse2.Play();
}

void Studio::PlayTriangle()
{
	triangle.Play();
}

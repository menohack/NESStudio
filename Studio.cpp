#include "Studio.h"

using namespace NESStudio;

Studio::Studio()
{
	pulse1.Init(C4);
	pulse2.Init(G4);

	triangle.Init(C3);
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

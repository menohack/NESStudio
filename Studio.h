#ifndef _STUDIO_H
#define _STUDIO_H

#include "Pulse.h"
#include "Triangle.h"

using namespace sf;

namespace NESStudio
{

class Studio
{
private:
	Pulse pulse1, pulse2;
	Triangle triangle;

public:
	Studio();

	void PlayPulse1();
	void PlayPulse2();
	void PlayTriangle();
};

}
#endif

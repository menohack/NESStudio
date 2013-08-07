#include <SFML/Audio.hpp>
#include <math.h>

using namespace sf;

namespace NESStudio
{

class Studio
{
private:
	Int16 * samples;
	SoundBuffer * buffer;
	unsigned numSamples;
public:
	Studio();

	void Play();
};

}

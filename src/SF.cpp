#ifdef _WIN32
#pragma comment(lib, "sfml-graphics-s.lib")
#pragma comment(lib, "sfml-window-s.lib")
#pragma comment(lib, "sfml-system-s.lib")
#pragma comment(lib, "sfml-audio-s.lib")
#pragma comment(lib, "manual-link\\sfml-main.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "zlib.lib")
#pragma comment(lib, "ogg.lib")
#pragma comment(lib, "openal32.lib")
#pragma comment(lib, "flac.lib")
#pragma comment(lib, "vorbis.lib")
#pragma comment(lib, "vorbisfile.lib")
#pragma comment(lib, "vorbisenc.lib")

#endif

#include <SFML/Graphics.hpp>
#include "game.h"
using namespace std;
int main()
{
	Game sf;
	sf.run();
	return 0;
}

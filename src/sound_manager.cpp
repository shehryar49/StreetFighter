#include "sound_manager.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>


int SoundManager::load(const std::string& filename)
{
    sf::Music m;
    if(m.openFromFile(filename))
    {
        audios.push_back(m);
        return audios.size() - 1;
    }
    return -1;
}
void SoundManager::play(int id,bool looped)
{
    if(id >=0 && id < audios.size())
    {
        audios[id].play();
        audios[id].setLoop(looped);
    }
}
void SoundManager::stop(int id)
{
    if(id >=0 && id < audios.size())
    {
        audios[id].stop();
    }
}


#include "sound_manager.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>


int SoundManager::load(const std::string& filename)
{
    sf::Music* m = new sf::Music;
    if(m->openFromFile(filename))
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
        audios[id]->play();
        audios[id]->setLoop(looped);
    }
}
void SoundManager::stop(int id)
{
    if(id >=0 && id < audios.size())
    {
        audios[id]->stop();
    }
}
void SoundManager::setVolume(float volume)
{
    for(auto p: audios)
        p->setVolume(volume);
}
void SoundManager::setVolume(float volume,int id)
{
    if(id >= 0 && id < audios.size())
      audios[id]->setVolume(volume);
}
SoundManager::~SoundManager()
{
    for(auto m: audios)
      delete m;
}


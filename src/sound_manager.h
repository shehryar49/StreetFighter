#ifndef SOUND_MANAGER_H_
#define SOUND_MANAGER_H_

#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class SoundManager
{
private:
    std::vector<sf::Music*> audios;
public:
    
    int load(const std::string& filename);
    void play(int id,bool looped = false);
    void stop(int id);
    void setVolume(float);
    ~SoundManager();
};
#endif
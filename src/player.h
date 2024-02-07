#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include "animation_times.h"
class Player // Abstract class
{
public:
    Player();
    virtual bool processEvent(sf::Event &);
    virtual void update(float);
    virtual void render(sf::RenderWindow &);
    virtual void setPosition(float,float);
    virtual sf::FloatRect getGlobalBounds();
    virtual sf::FloatRect getLocalBounds();
    
    virtual void flipX();
    virtual ~Player();
protected:
    int health = 100;
};
#endif
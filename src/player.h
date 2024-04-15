#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include "constants.h"
class Player // Abstract class
{
public:
    Player();
    virtual bool processEvent(sf::Event &);//it's gonna be dead soon
    virtual void update(float);
    virtual void render(sf::RenderWindow &);
    virtual void setPosition(float,float);
    virtual sf::FloatRect getGlobalBounds();
    virtual sf::FloatRect getLocalBounds();
    
    virtual void flipX();
    virtual void moveLeft(float);
    virtual void moveRight(float);
    virtual void flippedMoveLeft(float);
    virtual void flippedMoveRight(float);
    
    virtual void punch1();
    virtual void punch2();
    virtual void punch3();
    virtual void kick1();
    virtual void kick2();
    virtual void kick3();
    virtual void jump();
    virtual void crouch();
    virtual void uncrouch();
    virtual void specialMove1();
    virtual void specialMove2();
    virtual void block();
    virtual void unblock();
    virtual bool isIdle();
    virtual ~Player();
protected:
    int health = 100; // player
    sf::Sprite player;
    sf::Image image;
    sf::Texture texture;
};
#endif
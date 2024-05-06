#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "constants.h"
class Player // Abstract class
{
public:
    Player();
    virtual void update(float);
    virtual void render(sf::RenderWindow &);
    
    void setPosition(float,float);
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    sf::Vector2f getPosition();
    void flipX();

    virtual void moveLeft(float);
    virtual void moveRight(float);
    virtual void flippedMoveLeft(float);
    virtual void flippedMoveRight(float);
    
    virtual bool punch1();
    virtual bool punch2();
    virtual bool punch3();
    virtual bool kick1();
    virtual bool kick2();
    virtual bool kick3();
    virtual bool jump();
    virtual bool crouch();
    virtual bool uncrouch();
    virtual bool specialMove1();
    virtual bool specialMove2();
    virtual bool block();
    virtual bool unblock();
    virtual void bodyHit();
    virtual bool isIdle();
    virtual bool isSuffering(); // Are ya suffering son?
    virtual bool isAttacking(); //I wish, I was the monster you think I am.
    virtual void knockout();
    virtual void victory();
    virtual ~Player();
public:
    float damage = 0;//health damage
    sf::Sprite player;
    sf::Sprite projectile;
    sf::Image image;
    sf::Texture texture;
    bool projectile_active = false;
};
#endif
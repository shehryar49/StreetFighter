#include "player.h"
#include <SFML/Graphics.hpp>

// Abstract class
// nothing to implement
Player::Player()
{
}
void Player::update(float dt)
{
}
void Player::render(sf::RenderWindow &win)
{
  win.draw(player);
}
void Player::setPosition(float x,float y)
{

}
sf::FloatRect Player::getGlobalBounds()
{
  return sf::FloatRect(); // just to avoid the goddamn  warning
}
sf::FloatRect Player::getLocalBounds()
{
  return sf::FloatRect(); // just to avoid the goddamn  warning
}
sf::Vector2f Player::getPosition()
{
    return sf::Vector2f();
}

void Player::flipX(){}
void Player::moveLeft(float){}
void Player::moveRight(float){}
void Player::flippedMoveLeft(float){}
void Player::flippedMoveRight(float){}
void Player::punch1(){}
void Player::punch2(){}
void Player::punch3(){}
void Player::kick1(){}
void Player::kick2(){}
void Player::kick3(){}
void Player::jump(){}
void Player::crouch(){}
void Player::uncrouch(){}
void Player::specialMove1(){}
void Player::specialMove2(){}
void Player::block(){}
void Player::unblock(){}
bool Player::isIdle(){ return false;}
Player::~Player(){}
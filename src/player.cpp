#include "player.h"
#include <SFML/Graphics.hpp>

// Abstract class
// nothing to implement
Player::Player()
{
}
bool Player::processEvent(sf::Event &win)
{
    return false;
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

void Player::flipX(){}
void Player::moveLeft(float){}
void Player::moveRight(float){}
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
Player::~Player(){}
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
void Player::flipX()
{
    
}
Player::~Player()
{
}
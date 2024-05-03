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
bool Player::punch1(){return false;}
bool Player::punch2(){return false;}
bool Player::punch3(){return false;}
bool Player::kick1(){return false;}
bool Player::kick2(){return false;}
bool Player::kick3(){return false;}
bool Player::jump(){return false;}
bool Player::crouch(){return false;}
bool Player::uncrouch(){return false;}
bool Player::specialMove1(){return false;}
bool Player::specialMove2(){return false;}
bool Player::block(){return false;}
bool Player::unblock(){return false;}
bool Player::isIdle(){ return false;}
bool Player::isSuffering(){return false;}
bool Player::isAttacking(){return false;}
void Player::bodyHit(){}
void Player::knockout(bool*){}
void Player::victory(){}
Player::~Player(){}
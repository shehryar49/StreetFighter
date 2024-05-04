//Written by Shahryar Ahmad
#include "guile.h"
#include "constants.h"
#include <SFML/Graphics/Rect.hpp>

#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)

//Hard coded sprite cuts

sf::IntRect Guile::IDLE_frames[6];
sf::IntRect Guile::moveright_frames[5];
sf::IntRect Guile::moveleft_frames[5];
sf::IntRect Guile::punch1_frames[3];
sf::IntRect Guile::punch2_frames[5];
sf::IntRect Guile::punch3_frames[7];
sf::IntRect Guile::kick1_frames[3];
sf::IntRect Guile::jmp_frames[8];
sf::IntRect Guile::kick2_frames[6];
sf::IntRect Guile::kick3_frames[6];
sf::IntRect Guile::crouching_frames[3];
sf::IntRect Guile::crouched_punch1_frames[2];
sf::IntRect Guile::crouched_punch2_frames[3];
sf::IntRect Guile::crouched_kick1_frames[5];
sf::IntRect Guile::crouched_kick2_frames[5];
sf::IntRect Guile::helicopter_kick_frames[12];
sf::IntRect Guile::tornado_kick_frames[10];
sf::IntRect Guile::body_hit_frames[3];
sf::IntRect Guile::knockout_frames[5];

Guile::Guile()
{
    img.loadFromFile("assets/guile.png");
    //img.createMaskFromColor(sf::Color(102, 119, 136,255));
    texture.loadFromImage(img);
    player.setTexture(texture);
    #define STOP !true
    IDLE_frames[0] = sf::IntRect(25,52,80,100);
    IDLE_frames[1] = sf::IntRect(115,52,80,100);
    IDLE_frames[2] = sf::IntRect(208,52,80,100);
    IDLE_frames[3] = sf::IntRect(300,52,80,100);
    IDLE_frames[4] = sf::IntRect(392,52,80,100);
    IDLE_frames[5] = sf::IntRect(483,52,80,100);
    //
    moveright_frames[0] = sf::IntRect(25,230,84,100);
    moveright_frames[1] = sf::IntRect(125,227,84,100);
    moveright_frames[2] = sf::IntRect(210,227,84,100);
    moveright_frames[3] = sf::IntRect(290,227,84,100);
    moveright_frames[4] = sf::IntRect(380,227,84,100);
    //
    moveleft_frames[0] = sf::IntRect(535,227,84,100);
    moveleft_frames[1] = sf::IntRect(635,227,84,100);
    moveleft_frames[2] = sf::IntRect(720,227,60,100);
    moveleft_frames[3] = sf::IntRect(800,227,60,100);
    moveleft_frames[4] = sf::IntRect(870,227,60,100);
    //
    punch1_frames[0] = sf::IntRect(23,555,70,100);
    punch1_frames[1] = sf::IntRect(112,555,100,100);
    punch1_frames[2] = sf::IntRect(232,555,80,100);
    //
    punch2_frames[0] = sf::IntRect(395,555,100,100);
    punch2_frames[1] = sf::IntRect(507,555,100,100);
    punch2_frames[2] = sf::IntRect(607,535,100,120);
    punch2_frames[3] = sf::IntRect(725,536,100,120);
    punch2_frames[4] = sf::IntRect(835,536,100,120);
    //
    kick1_frames[0] = sf::IntRect(20,725,80,100);
    kick1_frames[1] = sf::IntRect(100,725,80,100);
    kick1_frames[2] = sf::IntRect(190,725,120,100);
    //
    kick2_frames[0] = sf::IntRect(390,725,60,100);
    kick2_frames[1] = sf::IntRect(465,725,70,100);
    kick2_frames[2] = sf::IntRect(550,725,70,100);
    kick2_frames[3] = sf::IntRect(630,725,80,100);
    kick2_frames[4] = sf::IntRect(720,755,140,100);
    kick2_frames[5] = sf::IntRect(870,725,70,100);
    //
    kick3_frames[0] = sf::IntRect(585,900,70,100);
    kick3_frames[1] = sf::IntRect(660,900,70,100);
    kick3_frames[2] = sf::IntRect(745,900,100,100);
    kick3_frames[3] = sf::IntRect(845,895,100,100);
    kick3_frames[4] = sf::IntRect(955,900,70,100);
    kick3_frames[5] = sf::IntRect(1055,900,70,100);

    player.setTextureRect(IDLE_frames[0]);
    
    //player.setTextureRect(sf::IntRect(1055,900,70,100));
     
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}

bool Guile::punch1()
{
    if(IS_IDLE)
    {
      currFrame = 0;
      state = AnimationState::PUNCH1;
      return true;
    }
    else if(state == AnimationState::CROUCHED)
    {
      currFrame = 0;
      state = AnimationState::CROUCHED_PUNCH1;
      return true;
    }
    return false;
}
bool Guile::punch2()
{
    if(IS_IDLE)
    {
        currFrame = 0;
        state = AnimationState::PUNCH2;
        player.setPosition(player.getPosition().x,BOTTOMY - punch2_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1 );
        return true;
    }
    else if(state == AnimationState::CROUCHED)
    {
      currFrame = 0;
      state = AnimationState::CROUCHED_PUNCH2;
      return true;
    }
    return false;
}
bool Guile::punch3()
{
    if(IS_IDLE)
    {
      currFrame = 0;
      state = AnimationState::PUNCH3;
      return true;
    }
    return false;
}
bool Guile::kick1()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK1;
    frameIncrement = 1;
    return true;
  }
  else if(state == AnimationState::CROUCHED)
  {
    currFrame = 0;
    state = AnimationState::CROUCHED_KICK1;
    return true;
  }
  return false;
}
bool Guile::kick2()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK2;
    frameIncrement = 1;
    return true;
  }
  else if(state == AnimationState::CROUCHED)
  {
    currFrame = 0;
    state = AnimationState::CROUCHED_KICK2;
    return true;
  }
  return false;
}
bool Guile::kick3()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK3;
    frameIncrement = 1;
    return true;
  }
  return false;
}
void Guile::moveLeft(float limit)
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::moveLeft;
    this->limit = limit;
  }
}
void Guile::moveRight(float limit)
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::moveRight;
    this->limit = limit;
  }
}
bool Guile::jump()
{
  if(IS_IDLE)
  {
    state = AnimationState::JMP;
    currFrame = 0;
    JMPY = -40;
    delay_time = 0.05f;
    return true;
  }
  return false;
}
bool Guile::crouch()
{
  if(state == AnimationState::IDLE)
  {
    currFrame = 0;
    state = AnimationState::CROUCHING;
    return true;
  }
  return false;
}
bool Guile::uncrouch()
{
  if( state == AnimationState::CROUCHED || 
      state == AnimationState::CROUCHING ||
      state == AnimationState::CROUCHED_KICK1 ||
      state == AnimationState::CROUCHED_KICK2 ||
      state == AnimationState::CROUCHED_PUNCH1 ||
      state == AnimationState::CROUCHED_PUNCH2  
    )
  {
    state = AnimationState::FASTIDLE;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Guile::specialMove1()
{
  if(IS_IDLE)
  {
    JMPY = 0;
    currFrame = 0;
    state = AnimationState::TORNADO_KICK;
    return true;
  }
  return false;
}
bool Guile::isIdle()
{
  return state==AnimationState::IDLE;
}
bool Guile::isSuffering()
{
  return state == AnimationState::BODY_HIT;
//  return 
}
bool Guile::isAttacking()
{
  return (
    state == AnimationState::PUNCH1 ||
    state == AnimationState::PUNCH2 ||
    state == AnimationState::PUNCH3 ||
    state == AnimationState::KICK1 ||
    state == AnimationState::KICK2 ||
    state == AnimationState::KICK3 ||
    state == AnimationState::FASTIDLE_ATTACKING ||
    state == AnimationState::CROUCHED_KICK1 ||
    state == AnimationState::CROUCHED_KICK2 ||
    state == AnimationState::CROUCHED_PUNCH1 ||
    state == AnimationState::CROUCHED_PUNCH2 ||
    state == AnimationState::TORNADO_KICK
  );//IMPORTANT
}
void Guile::bodyHit()
{
  if(state != AnimationState::BODY_HIT)
  {
  state = AnimationState::BODY_HIT;
  player.setPosition(player.getPosition().x,BOTTOMY - body_hit_frames[0].height*PLAYER_SPRITE_Y_SCALE + 1 );
  currFrame = 0;
  }
}
void Guile::knockout(bool* b)
{
  currFrame = 0;
  state = AnimationState::KNOCKED_OUT;
  ptr = b;
}
void Guile::flippedMoveLeft(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_LEFT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Guile::flippedMoveRight(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_RIGHT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Guile::update(float dt)
{
    if(STOP)
      return;
    elapsed += dt;

    if ((elapsed >= (0.7f)) && state == AnimationState::IDLE)
    {
        if(currFrame == 0)
          frameIncrement = 1;
        else if(currFrame == 5)
          frameIncrement = -1;
        currFrame = (currFrame+frameIncrement); 
        player.setTextureRect(IDLE_frames[currFrame]);
        elapsed = 0;
    }
    else if (elapsed >= (0.08f) && (state == AnimationState::FASTIDLE || state == AnimationState::FASTIDLE_ATTACKING))
    {
        player.setTextureRect(IDLE_frames[0]);
        currFrame++;
        state = AnimationState::IDLE;
        elapsed = 0;
    }  
    else if(elapsed>=(0.08f) && state == AnimationState::moveRight)
    {
        player.setTextureRect(moveright_frames[currFrame++]);
        elapsed = 0;
        if(player.getPosition().x + 150 < limit) // window width is 800
          player.setPosition(player.getPosition().x+10,player.getPosition().y);
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=(0.08f) && state == AnimationState::moveLeft)
    {
        player.setTextureRect(moveleft_frames[currFrame++]);
        elapsed = 0;
        if(player.getPosition().x - 20 > limit) // window width is 800
          player.setPosition(player.getPosition().x-10,player.getPosition().y);
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::PUNCH1)
    {
        player.setTextureRect(punch1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f*2 && state == AnimationState::BODY_HIT)
    {
        player.setTextureRect(body_hit_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 2)
        { 
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::CROUCHED_PUNCH1)
    {
        player.setTextureRect(crouched_punch1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 2)
        { 
            state = AnimationState::CROUCHING;
            currFrame = 2;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::PUNCH2)
    {
        player.setPosition(player.getPosition().x,BOTTOMY - punch2_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1 );
        player.setTextureRect(punch2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            player.setPosition(player.getPosition().x,BOTTOMY - IDLE_frames[0].height*PLAYER_SPRITE_Y_SCALE + 1 );
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.8f && state == AnimationState::KNOCKED_OUT)
    {
        player.setTextureRect(knockout_frames[currFrame++]);
        if(player.getScale().x < 0)
          player.setPosition(player.getPosition().x+20,player.getPosition().y);
        else
          player.setPosition(player.getPosition().x-20,player.getPosition().y);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
            *ptr = true;
        }
    }
    
    else if(elapsed>=0.08f && state == AnimationState::CROUCHED_PUNCH2)
    {
        player.setTextureRect(crouched_punch2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
        { 
            state = AnimationState::CROUCHING;
            currFrame = 2;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::PUNCH3)
    {
        player.setTextureRect(punch3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 6)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed >= delay_time && state == AnimationState::DELAY)
    {
      state = lastState;
      elapsed = 0;
      delay_time = 0;
    }
    else if (elapsed >=  MOVE_TIME && state == AnimationState::JMP)
    { 
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x,player.getPosition().y+JMPY);
        elapsed = 0;
        currFrame++;

        if(currFrame == 4 && delay_time!=0) //start landing
        {
          lastState = AnimationState::JMP;
          JMPY *= -1;

          state = AnimationState::DELAY;
        }
        else if(currFrame == 8)
        {
          state = AnimationState::FASTIDLE;
          currFrame = 0;
        }
    }  
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHING)
    {
      player.setTextureRect(crouching_frames[currFrame++]);
      if(currFrame == 3)
      {
        state = AnimationState::CROUCHED;
        currFrame = 0;
      }
    }
    else if(elapsed>=0.08f && state == AnimationState::KICK1)
    {
        player.setTextureRect(kick1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::KICK2)
    {
        player.setTextureRect(kick2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::KICK3)
    {
        player.setTextureRect(kick3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=(MOVE_TIME) && state == AnimationState::FLIPPED_MOVE_LEFT)
    {
        currFrame = currFrame+1;
        player.setTextureRect(moveright_frames[currFrame]);
        elapsed = 0;
        if(player.getPosition().x - player.getGlobalBounds().width -20 > limit) // window width is 800
          player.setPosition(player.getPosition().x-10,player.getPosition().y);
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE; 
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=(MOVE_TIME) && state == AnimationState::FLIPPED_MOVE_RIGHT)
    {
        currFrame = currFrame+1;
        player.setTextureRect(moveleft_frames[currFrame]);
        elapsed = 0;
        if(player.getPosition().x + 20 < limit) // window width is 800
          player.setPosition(player.getPosition().x+10,player.getPosition().y);
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE; 
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::CROUCHED_KICK1)
    {
        player.setTextureRect(crouched_kick1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::CROUCHING;
            currFrame = 2;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::CROUCHED_KICK2)
    {
        player.setTextureRect(crouched_kick2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::CROUCHING;
            currFrame = 2;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME*1.5 && state == AnimationState::TORNADO_KICK)
    {
        
        player.setPosition(player.getPosition().x,BOTTOMY - tornado_kick_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1);
        player.setTextureRect(tornado_kick_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 6)
          JMPY = -10;
        else if(currFrame == 1)
          JMPY = 10;
        if(currFrame == 10)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
}
void Guile::setPosition(float x,float y)
{
    player.setPosition(x,y);
}
void Guile::flipX()
{
  player.setScale(-2.1,2.1);
}
void Guile::render(sf::RenderWindow &win)
{
    win.draw(player);
}
sf::FloatRect Guile::getGlobalBounds()
{
    return player.getGlobalBounds();
}
sf::FloatRect Guile::getLocalBounds()
{
    return player.getLocalBounds();
}
Guile::~Guile()
{
}

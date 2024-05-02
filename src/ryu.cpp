// Written by Shahryar Ahmad
#include "ryu.h"
#include "constants.h"
#include <SFML/Graphics/Rect.hpp>
#include <stdio.h>

#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)
#define STOP false
sf::IntRect Ryu::IDLE_frames[5];
sf::IntRect Ryu::moveright_frames[6];
sf::IntRect Ryu::moveleft_frames[6];
sf::IntRect Ryu::punch1_frames[2];
sf::IntRect Ryu::punch2_frames[3];
sf::IntRect Ryu::punch3_frames[5];
sf::IntRect Ryu::kick1_frames[3];
sf::IntRect Ryu::kick2_frames[3];
sf::IntRect Ryu::kick3_frames[5];
sf::IntRect Ryu::jmp_frames[7];
sf::IntRect Ryu::shoryuken_frames[6];
sf::IntRect Ryu::crouching_frames[3];
sf::IntRect Ryu::crouched_punch1_frames[2];
sf::IntRect Ryu::crouched_punch2_frames[3];
sf::IntRect Ryu::crouched_kick1_frames[3];
sf::IntRect Ryu::crouched_kick2_frames[5];
sf::IntRect Ryu::hadoken_frames[4];
sf::IntRect Ryu::hadoken_ball;
sf::IntRect Ryu::body_hit_frames[2];
sf::IntRect Ryu::knockout_frames[5];
Ryu::Ryu()
{

    img.loadFromFile("assets/ryu.png");
    //img.createMaskFromColor(sf::Color(70,112,104,255));
    texture.loadFromImage(img);
    player.setTexture(texture);

    IDLE_frames[0] = sf::IntRect(5, 5, 64, 100);
    IDLE_frames[1] = sf::IntRect(64+26, 5, 64, 100);
    IDLE_frames[2] = sf::IntRect(64+26+64+26, 5, 64, 100);
    IDLE_frames[3] = sf::IntRect(64+26+64+26+64+26, 5, 64, 100);
    IDLE_frames[4] = sf::IntRect(64+26+64+26+64+26+64+26, 5, 64, 100);
    
    moveright_frames[0] = sf::IntRect(0,120,68,100);
    moveright_frames[1] = sf::IntRect(68*1,120,68,100);
    moveright_frames[2] = sf::IntRect(68*2+20,120,68,100);
    moveright_frames[3] = sf::IntRect(68*3+50,120,68,100);
    moveright_frames[4] = sf::IntRect(68*3+140,120,68,100);
    moveright_frames[5] = sf::IntRect(68*5,120,68,100);
    
    punch1_frames[0] = sf::IntRect(20,263,68,100);
    punch1_frames[1] = sf::IntRect(40+68,263,94,100);

    kick1_frames[0] = sf::IntRect(600,260,70,100);
    kick1_frames[1] = sf::IntRect(690,260,70,100);
    kick1_frames[2] = sf::IntRect(780,260,110,100);
    
    jmp_frames[0] = sf::IntRect(0,830,70,110);
    jmp_frames[1] = sf::IntRect(90,823,70,110);
    jmp_frames[2] = sf::IntRect(160,800,70,100);
    jmp_frames[3] = sf::IntRect(240,790,70,90);
    jmp_frames[4] = sf::IntRect(310,800,70,80);
    jmp_frames[5] = sf::IntRect(380,810,70,90);
    jmp_frames[6] = sf::IntRect(460,820,60,130);
   
    moveleft_frames[0] = sf::IntRect(540,120,68,100);
    moveleft_frames[1] = sf::IntRect(625,120,68,100);
    moveleft_frames[2] = sf::IntRect(710,120,68,100);
    moveleft_frames[3] = sf::IntRect(790,120,68,100);
    moveleft_frames[4] = sf::IntRect(880,120,68,100);
    moveleft_frames[5] = sf::IntRect(970,120,68,100);

    punch2_frames[0] = sf::IntRect(250,263,68,100);
    punch2_frames[1] = sf::IntRect(332,263,72,100);
    punch2_frames[2] = sf::IntRect(430,263,110,100);

    kick2_frames[0] = sf::IntRect(10,651,70,100);
    kick2_frames[1] = sf::IntRect(80,651,70,100);
    kick2_frames[2] = sf::IntRect(160,651,90,100);
    
    shoryuken_frames[0] = sf::IntRect(20,1800,70,110);
    shoryuken_frames[1] = sf::IntRect(110,1800,70,110);
    shoryuken_frames[2] = sf::IntRect(190,1780,70,130);
    shoryuken_frames[3] = sf::IntRect(290,1780,70,130);
    shoryuken_frames[4] = sf::IntRect(360,1780,70,120);
    shoryuken_frames[5] = sf::IntRect(450,1800,70,110);
   
    kick3_frames[0] = sf::IntRect(630,640,70,120);
    kick3_frames[1] = sf::IntRect(710,640,70,120);
    kick3_frames[2] = sf::IntRect(780,630,70,120);
    kick3_frames[3] = sf::IntRect(870,650,100,100);
    kick3_frames[4] = sf::IntRect(970,650,70,100);
   
    punch3_frames[0] = sf::IntRect(230,513,70,100);
    punch3_frames[1] = sf::IntRect(320,513,70,100);
    punch3_frames[2] = sf::IntRect(410,513,90,100);
    punch3_frames[3] = sf::IntRect(510,513,70,100);
    punch3_frames[4] = sf::IntRect(600,513,100,100);

    crouching_frames[0] = sf::IntRect(20,1197,70,100);
    crouching_frames[1] = sf::IntRect(110,1197,70,100);
    crouching_frames[2] = sf::IntRect(190,1197,70,100);
    
    crouched_punch1_frames[0] = sf::IntRect(25,1308,75,100);
    crouched_punch1_frames[1] = sf::IntRect(115,1308,105,100);
    
    crouched_punch2_frames[0] = sf::IntRect(260,1308,90,100);
    crouched_punch2_frames[1] = sf::IntRect(350,1308,90,100);
    crouched_punch2_frames[2] = sf::IntRect(450,1308,90,100);

    crouched_kick1_frames[0] = sf::IntRect(20,1410,75,100);
    crouched_kick1_frames[1] = sf::IntRect(120,1410,105,100);
    crouched_kick1_frames[2] = sf::IntRect(240,1410,150,100);

    crouched_kick2_frames[0] = sf::IntRect(440,1410,70,100);
    crouched_kick2_frames[1] = sf::IntRect(530,1410,130,100);
    crouched_kick2_frames[2] = sf::IntRect(680,1410,70,100);
    crouched_kick2_frames[3] = sf::IntRect(770,1410,70,100);
    crouched_kick2_frames[4] = sf::IntRect(860,1410,70,100);

    body_hit_frames[0] = sf::IntRect(395,2080,70,100);
    body_hit_frames[1] = sf::IntRect(480,2080,70,100);

    hadoken_frames[0] = sf::IntRect(30,1535,80,100);
    hadoken_frames[1] = sf::IntRect(130,1535,90,100);
    hadoken_frames[2] = sf::IntRect(240,1535,90,100);
    hadoken_frames[3] = sf::IntRect(350,1535,120,100); 
    projectile.setTexture(texture);
    projectile.setTextureRect(sf::IntRect(550,1550,60,50));
    projectile.setScale(1.2,1.2);
    
    knockout_frames[0] = sf::IntRect(580,2100,90,100);
    knockout_frames[1] = sf::IntRect(890,2100,125,100);
    knockout_frames[2] = sf::IntRect(680,2190,125,100);
    knockout_frames[3] = sf::IntRect(845,2190,125,100);
    knockout_frames[4] = sf::IntRect(980,2195,135,100);

    player.setTextureRect(IDLE_frames[0]);
 
    player.setScale(sf::Vector2f(PLAYER_SPRITE_X_SCALE, PLAYER_SPRITE_Y_SCALE));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}
void Ryu::moveLeft(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::MOVE_LEFT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Ryu::moveRight(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::MOVE_RIGHT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Ryu::flippedMoveLeft(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_LEFT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Ryu::flippedMoveRight(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_RIGHT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
//
bool Ryu::punch1()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::PUNCH1;
    currFrame = -1;
    frameIncrement = 1;
    return true;
  }
  else if(state == AnimationState::CROUCHED)
  {
    state = AnimationState::CROUCHED_PUNCH1;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Ryu::punch2()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::PUNCH2;
    currFrame = -1;
    frameIncrement = 1;
    return true;
  }
  else if(state == AnimationState::CROUCHED)
  {
    state = AnimationState::CROUCHED_PUNCH2;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
void Ryu::bodyHit()
{
  state = AnimationState::BODY_HIT;
  currFrame = 0;
}
bool Ryu::punch3()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::PUNCH3;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
//Kicks
bool Ryu::kick1()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::KICK1;
    currFrame = -1;
    frameIncrement = 1;
    return true;
  }
  else if(state == AnimationState::CROUCHED)
  {
    state = AnimationState::CROUCHED_KICK1;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Ryu::kick2()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::KICK2;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  else if(state == AnimationState::CROUCHED)
  {
    state = AnimationState::CROUCHED_KICK2;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Ryu::kick3()
{
  if(state == AnimationState::IDLE)
  {
    player.setPosition(player.getGlobalBounds().left,BOTTOMY - (120*PLAYER_SPRITE_Y_SCALE) +1);
    state = AnimationState::KICK3;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
//
bool Ryu::jump()
{
    if(IS_IDLE)
    {
        state = AnimationState::JMP;
        currFrame = -1;
        frameIncrement = 1;
        pos = player.getPosition();
        return true;
    }
    return false;
}
bool Ryu::crouch()
{
  if(IS_IDLE)
  {
    state = AnimationState::CROUCHING;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Ryu::uncrouch()
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
bool Ryu::specialMove1()
{
    if(IS_IDLE)
    {
        state = AnimationState::SHORYUKEN;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}
bool Ryu::specialMove2()
{
    if(IS_IDLE)
    {
        state = AnimationState::HADOKEN;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}
bool Ryu::isIdle()
{
  return state == AnimationState::IDLE;
}
bool Ryu::isSuffering()
{
  return false;
}
bool Ryu::isAttacking()
{
  return (
    state == AnimationState::PUNCH1 ||
    state == AnimationState::PUNCH2 ||
    state == AnimationState::PUNCH3 ||
    state == AnimationState::KICK1 ||
    state == AnimationState::KICK2 ||
    state == AnimationState::KICK3 ||
    state == AnimationState::FASTIDLE_ATTACKING
  );
}
void Ryu::knockout(bool* b)
{
  ptr = b;
  state = AnimationState::KNOCKED_OUT;
  currFrame = 0;
}
//Updation based on animation state
void Ryu::update(float dt)
{
    if(STOP)
      return;
    elapsed += dt;
    if(projectile_active)
    {
        if(projectile.getPosition().x + 100 >= 800)
          projectile_active = false;
        else
          projectile.setPosition(projectile.getPosition().x + (100*dt),projectile.getPosition().y);
    }
    if ((elapsed >= (0.7f)) && state == AnimationState::IDLE)
    {
        if(currFrame == 0)
          frameIncrement = 1;
        else if(currFrame == 4)
          frameIncrement = -1;
        currFrame = (currFrame+frameIncrement); 
        player.setTextureRect(IDLE_frames[currFrame]);
        elapsed = 0;
    }
    else if (elapsed >= (MOVE_TIME) && (state == AnimationState::FASTIDLE || state == AnimationState::FASTIDLE_ATTACKING))
    {
        player.setTextureRect(IDLE_frames[0]);
        currFrame++;
        state = AnimationState::IDLE;
        elapsed = 0;
    }
    else if (elapsed >= (MOVE_TIME) && state == AnimationState::LAND)
    {
        currFrame--;
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x,player.getPosition().y+30);
        elapsed = 0;
        if(currFrame == 0) // landed
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }  
    else if(elapsed>=(MOVE_TIME) && state == AnimationState::MOVE_RIGHT)
    {
        currFrame = currFrame+1;
        player.setTextureRect(moveright_frames[currFrame]);
        elapsed = 0;
        if(player.getPosition().x + 150 < limit) // window width is 800
          player.setPosition(player.getPosition().x+10,player.getPosition().y);
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE; 
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

    else if(elapsed>=(MOVE_TIME) && state == AnimationState::MOVE_LEFT)
    {
        currFrame = currFrame+1;
        player.setTextureRect(moveleft_frames[currFrame]);
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
    else if(elapsed>=MOVE_TIME && state == AnimationState::PUNCH1)
    {
        currFrame = currFrame+1;
        player.setTextureRect(punch1_frames[currFrame]);
        elapsed = 0;
        if(currFrame == 1)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::PUNCH2)
    {
        currFrame = currFrame+1;
        player.setTextureRect(punch2_frames[currFrame]);
        elapsed = 0;
        if(currFrame == 2)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::PUNCH3)
    {
        player.setTextureRect(punch3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::BODY_HIT)
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
    else if(elapsed>=0.6f && state == AnimationState::KNOCKED_OUT)
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
    else if (elapsed >= MOVE_TIME && state == AnimationState::KICK1)
    {
        currFrame++; 
        player.setTextureRect(kick1_frames[currFrame]);
        elapsed = 0;
        if(currFrame == 2) //last frame rendered
        {
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::KICK2)
    {
        player.setTextureRect(kick2_frames[currFrame]);
        elapsed = 0;
        currFrame += frameIncrement;

        if(currFrame == 3)
        {
            currFrame = 2;
            frameIncrement = -1;
        }
        else if(currFrame == -1)
        {
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }

        
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::KICK3)
    {
        player.setPosition(player.getPosition().x,BOTTOMY - kick3_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1 );
        player.setTextureRect(kick3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5) //last frame rendered
        {
            player.setPosition(player.getPosition().x,BOTTOMY - IDLE_frames[0].height*PLAYER_SPRITE_Y_SCALE +1);
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::SHORYUKEN)
    {
        player.setTextureRect(shoryuken_frames[currFrame++]);
        player.setPosition(player.getPosition().x,player.getPosition().y-40);
        elapsed = 0;
        if(currFrame == 6) //last frame rendered
        {
          state = AnimationState::SHORYUKEN_LAND;
          currFrame = 0;
        }
    }
    else if(elapsed >= 0.06f && state == AnimationState::SHORYUKEN_LAND)
    {
        player.setPosition(player.getPosition().x,player.getPosition().y+40);
        elapsed = 0;
        currFrame++;
        if(currFrame == 6)
        {
            currFrame = 0;
            frameIncrement = 1;
            state = AnimationState::FASTIDLE;
        }
    }
    else if (elapsed >=  MOVE_TIME && state == AnimationState::JMP)
    {
        currFrame++; 
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x,player.getPosition().y-30);
        elapsed = 0;
        if(currFrame == 6) //last frame rendered
        {
            currFrame = 7;
            state = AnimationState::LAND;
        }
    }  
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHING)
    {
        player.setTextureRect(crouching_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
            state = AnimationState::CROUCHED;
        
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::FAST_CROUCHED)
    {
        elapsed = 0;
        state = AnimationState::CROUCHED;
        player.setTextureRect(crouching_frames[2]);
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_PUNCH1)
    {
        player.setTextureRect(crouched_punch1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 2)
        {
            state = AnimationState::FAST_CROUCHED;
            currFrame = 0;
        }
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_PUNCH2)
    {
        player.setTextureRect(crouched_punch2_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if(currFrame == 3)
        {
            frameIncrement = -1;
            currFrame = 2;
        }
        else if(currFrame == -1)
        {
            state = AnimationState::CROUCHED;
            player.setTextureRect(crouching_frames[2]);
        }
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_KICK1)
    {
        player.setTextureRect(crouched_kick1_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if(currFrame == 3)
        {
            frameIncrement = -1;
            currFrame = 2;
        }
        else if(currFrame == -1)
        {
            state = AnimationState::CROUCHED;
            player.setTextureRect(crouching_frames[2]);
        }
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_KICK2)
    {
        player.setTextureRect(crouched_kick2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        {
            state = AnimationState::FAST_CROUCHED;
        }
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::HADOKEN)
    {
        player.setTextureRect(hadoken_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 4)
        {
            projectile_active = true;
            projectile.setPosition(player.getPosition().x+220,player.getPosition().y+60);
            state = AnimationState::IDLE;
            currFrame = -1;
            frameIncrement = 1;
        }
    }
}
void Ryu::setPosition(float x,float y)
{
    player.setPosition(x,y);
}
void Ryu::flipX()
{
  player.setScale(-2.1,2.1);
}
sf::FloatRect Ryu::getGlobalBounds()
{
    return player.getGlobalBounds();
}
sf::FloatRect Ryu::getLocalBounds()
{
    return player.getLocalBounds();
}
sf::Vector2f Ryu::getPosition()
{
    return player.getPosition();
}
void Ryu::render(sf::RenderWindow &win)
{
    win.draw(player);
    if(projectile_active)
      win.draw(projectile);
}
Ryu::~Ryu()
{
}

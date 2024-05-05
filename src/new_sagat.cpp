//Written by U
#include "new_sagat.h"
#include "constants.h"
#include <SFML/Graphics/Rect.hpp>

#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)


sf::IntRect Sagat::IDLE_frames[5];
sf::IntRect Sagat::moveright_frames[4];
sf::IntRect Sagat::moveleft_frames[4];
sf::IntRect Sagat::punch1_frames[3];
sf::IntRect Sagat::punch2_frames[5]; 
sf::IntRect Sagat::kick1_frames[7]; // side kick
sf::IntRect Sagat::kick2_frames[7]; // low kick
sf::IntRect Sagat::kick3_frames[7];
sf::IntRect Sagat::jmp_frames[6]; 
sf::IntRect Sagat::crouching_frames[2];
sf::IntRect Sagat::crouched_punch1_frames[3];
sf::IntRect Sagat::body_hit_frames[4];
sf::IntRect Sagat::knockout_frames[4];
sf::IntRect Sagat::tiger_frames[3];
sf::IntRect Sagat::victory_frames[4];
Sagat::Sagat()
{
    img.loadFromFile("assets/players/sagat.png");
    img.createMaskFromColor(sf::Color(248, 0, 248, 255));
    texture.loadFromImage(img);
    player.setTexture(texture);


    IDLE_frames[0] = sf::IntRect(11, 20, 80, 124);
    IDLE_frames[1] = sf::IntRect(109, 20, 80, 124);
    IDLE_frames[2] = sf::IntRect(214, 20, 80, 124);
    IDLE_frames[3] = sf::IntRect(321, 20, 81, 124);
    IDLE_frames[4] = sf::IntRect(430, 20, 80, 124);

    moveright_frames[0] = sf::IntRect(10, 151, 78, 124);
    moveright_frames[1] = sf::IntRect(119, 151, 67, 124);
    moveright_frames[2] = sf::IntRect(231, 151, 69, 124);
    moveright_frames[3] = sf::IntRect(339, 151, 67, 124);

    moveleft_frames[0] = sf::IntRect(330, 150, 80, 124);
    moveleft_frames[1] = sf::IntRect(230, 150, 80, 124);
    moveleft_frames[2] = sf::IntRect(115, 150, 80, 124);
    moveleft_frames[3] = sf::IntRect(10, 150, 80, 124);

    punch1_frames[0] = sf::IntRect(20,455,100,124);
    punch1_frames[1] = sf::IntRect(155,455,130,124);
    punch1_frames[2] = sf::IntRect(310,455,100,124);
    //
    punch2_frames[0] = sf::IntRect(520,453,80,124);
    punch2_frames[1] = sf::IntRect(630,453,100,124);
    punch2_frames[2] = sf::IntRect(760,453,160,124);
    punch2_frames[3] = sf::IntRect(940,453,100,124);
    punch2_frames[4] = sf::IntRect(1060,453,80,124);
    //
    kick1_frames[0] = sf::IntRect(25,600,110,124);
    kick1_frames[1] = sf::IntRect(135,600,110,124);
    kick1_frames[2] = sf::IntRect(245,600,80,124);
    kick1_frames[3] = sf::IntRect(340,600,140,124);
    kick1_frames[4] = sf::IntRect(500,600,80,124);
    kick1_frames[5] = sf::IntRect(600,600,100,124);
    kick1_frames[6] = sf::IntRect(710,600,110,124);
    //
    kick2_frames[0] = sf::IntRect(25,773,110,124);
    kick2_frames[1] = sf::IntRect(135,773,110,124);
    kick2_frames[2] = sf::IntRect(245,773,80,124);
    kick2_frames[3] = sf::IntRect(360,773,140,124);
    kick2_frames[4] = sf::IntRect(500,773,80,124);
    kick2_frames[5] = sf::IntRect(600,773,100,124);
    kick2_frames[6] = sf::IntRect(710,773,110,124);
    //
    kick3_frames[0] = sf::IntRect(25,913,110,124);
    kick3_frames[1] = sf::IntRect(135,913,110,124);
    kick3_frames[2] = sf::IntRect(245,913,80,124);
    kick3_frames[3] = sf::IntRect(340,913,140,124);
    kick3_frames[4] = sf::IntRect(500,913,80,124);
    kick3_frames[5] = sf::IntRect(600,913,100,124);
    kick3_frames[6] = sf::IntRect(710,913,110,124);
    //
    jmp_frames[0] = sf::IntRect(19, 318, 79, 124);
    jmp_frames[1] = sf::IntRect(126, 300, 69, 135);
    jmp_frames[2] = sf::IntRect(237, 290, 74, 99);
    jmp_frames[3] = sf::IntRect(335, 292, 66, 79);
    jmp_frames[4] = sf::IntRect(426, 290, 74, 99);
    jmp_frames[5] = sf::IntRect(523, 300, 69, 135);
    //
    crouching_frames[0] = sf::IntRect(510,151,80,124);
    crouching_frames[1] = sf::IntRect(610,151,90,124);
    //
    crouched_punch1_frames[0] = sf::IntRect(590,1045,85,124);
    crouched_punch1_frames[1] = sf::IntRect(695,1045,140,124);
    crouched_punch1_frames[2] = crouched_punch1_frames[0];
    //
    body_hit_frames[0] = sf::IntRect(600,1830,80,124);
    body_hit_frames[1] = sf::IntRect(685,1830,80,124);
    body_hit_frames[2] = sf::IntRect(770,1830,80,124);
    body_hit_frames[3] = sf::IntRect(880,1830,80,124);
    //
    tiger_frames[0] = sf::IntRect(20,1180,80,124);
    tiger_frames[1] = sf::IntRect(130,1180,100,124);
    tiger_frames[2] = sf::IntRect(265,1180,155,124);
    //
    knockout_frames[0] = sf::IntRect(708,1700,120,124);
    knockout_frames[1] = sf::IntRect(830,1700,80,124);
    knockout_frames[2] = sf::IntRect(940,1692,105,124);
    knockout_frames[3] = sf::IntRect(1065,1695,153,124);
    //
    victory_frames[0] = sf::IntRect(262,1978,60,135);
    victory_frames[1] = sf::IntRect(352,1978,60,135);
    victory_frames[2] = sf::IntRect(449,1977,60,135);
    victory_frames[3] = sf::IntRect(539,1977,60,135);
    //
    projectile.setTexture(texture);
    projectile.setTextureRect(sf::IntRect(490,1205,40,40));
    projectile.setScale(1.3f,1.3f);
    
    #define STOP !true
    //player.setTextureRect(victory_frames[3]);
    player.setTextureRect(IDLE_frames[0]);
     
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}

bool Sagat::punch1()
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
bool Sagat::punch2()
{
    if(IS_IDLE)
    {
        currFrame = 0;
        state = AnimationState::PUNCH2;
        return true;
    }
    return false;
}

bool Sagat::kick1()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK1;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Sagat::kick2()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK2;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Sagat::kick3()
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
void Sagat::moveLeft(float limit)
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::moveLeft;
    this->limit = limit;
  }
}
void Sagat::moveRight(float limit)
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::moveRight;
    this->limit = limit;
  }
}
bool Sagat::jump()
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
bool Sagat::crouch()
{
  if(state == AnimationState::IDLE)
  {
    currFrame = 0;
    state = AnimationState::CROUCHING;
    return true;
  }
  return false;
}
bool Sagat::uncrouch()
{
  if( state == AnimationState::CROUCHED || 
      state == AnimationState::CROUCHING ||
      state == AnimationState::CROUCHED_PUNCH1
    )
  {
    state = AnimationState::FASTIDLE;
    currFrame = 0;
    frameIncrement = 1;
    return true;
  }
  return false;
}
bool Sagat::specialMove1()
{
  if(state == AnimationState::IDLE && !projectile_active)
  {
    state = AnimationState::TIGER;
    currFrame = 0;
  }
  return false;
}
bool Sagat::isIdle()
{
  return state==AnimationState::IDLE;
}
bool Sagat::isSuffering()
{
  return state == AnimationState::BODY_HIT;
//  return 
}
bool Sagat::isAttacking()
{
  return (
    state == AnimationState::PUNCH1 ||
    state == AnimationState::PUNCH2 ||
    state == AnimationState::KICK1 ||
    state == AnimationState::KICK2 ||
    state == AnimationState::KICK3 ||
    state == AnimationState::FASTIDLE_ATTACKING ||
    state == AnimationState::CROUCHED_PUNCH1
  );//IMPORTANT
}
void Sagat::bodyHit()
{
  if(state != AnimationState::BODY_HIT)
  {
  state = AnimationState::BODY_HIT;
  player.setPosition(player.getPosition().x,BOTTOMY - body_hit_frames[0].height*PLAYER_SPRITE_Y_SCALE + 1 );
  currFrame = 0;
  }
}
void Sagat::knockout()
{
  currFrame = 0;
  state = AnimationState::KNOCKED_OUT;
}
void Sagat::flippedMoveLeft(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_LEFT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Sagat::flippedMoveRight(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_RIGHT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Sagat::victory()
{
  player.setPosition(player.getPosition().x,BOTTOMY - victory_frames[0].height*PLAYER_SPRITE_Y_SCALE + 1 );
  state = AnimationState::VICTORY;
  currFrame = 0;
}
void Sagat::update(float dt)
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
    else if(elapsed>=(MOVE_TIME) && state == AnimationState::moveRight)
    {
        player.setTextureRect(moveright_frames[currFrame++]);
        elapsed = 0;
        if(player.getPosition().x + 150 < limit) // window width is 800
          player.setPosition(player.getPosition().x+10,player.getPosition().y);
        if(currFrame == 4)
        { 
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=(MOVE_TIME) && state == AnimationState::moveLeft)
    {
        //printf("rendering frame %d\n",currFrame);
        player.setTextureRect(moveleft_frames[currFrame++]);
        elapsed = 0;
        if(player.getPosition().x - 20 > limit) // window width is 800
          player.setPosition(player.getPosition().x-10,player.getPosition().y);
        if(currFrame == 4)
        { 
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::PUNCH1)
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
    else if(elapsed>=MOVE_TIME && state == AnimationState::BODY_HIT)
    {
        player.setTextureRect(body_hit_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 4)
        { 
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME*2 && state == AnimationState::VICTORY)
    {
        player.setTextureRect(victory_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 4)
        { 
            currFrame = 0;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::CROUCHED_PUNCH1)
    {
        player.setTextureRect(crouched_punch1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
        { 
            state = AnimationState::CROUCHING;
            currFrame = 1;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::PUNCH2)
    {
        player.setTextureRect(punch2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::TIGER)
    {
        player.setTextureRect(tiger_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
        { 
            projectile_active = true;
            projectile.setPosition(player.getPosition().x+220,player.getPosition().y+60);
            state = AnimationState::FASTIDLE;
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
        if(currFrame == 4)
          state = AnimationState::NONE;
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

        if(currFrame == 3 && delay_time!=0) //start landing
        {
          lastState = AnimationState::JMP;
          JMPY *= -1;
          state = AnimationState::DELAY;
        }
        else if(currFrame == 7)
        {
          state = AnimationState::FASTIDLE;
          player.setPosition(player.getPosition().x,player.getPosition().y-JMPY);
          currFrame = 0;
        }
    }  
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHING)
    {
      player.setTextureRect(crouching_frames[currFrame++]);
      if(currFrame == 2)
      {
        state = AnimationState::CROUCHED;
        currFrame = 0;
      }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::KICK1)
    {
        player.setTextureRect(kick1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 7)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::KICK2)
    {
        player.setTextureRect(kick2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 7)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::KICK3)
    {
        player.setTextureRect(kick3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 7)
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

}
void Sagat::setPosition(float x,float y)
{
    player.setPosition(x,y);
}
void Sagat::flipX()
{
  player.setScale(-2.1,2.1);
}
void Sagat::render(sf::RenderWindow &win)
{
    win.draw(player);
    if(projectile_active)
      win.draw(projectile);
}
sf::FloatRect Sagat::getGlobalBounds()
{
    return player.getGlobalBounds();
}
sf::FloatRect Sagat::getLocalBounds()
{
    return player.getLocalBounds();
}
Sagat::~Sagat()
{
}

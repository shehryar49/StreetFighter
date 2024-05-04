//Written by Shahryar Ahmad
#include "ken.h"
#include "constants.h"
#include <SFML/Graphics/Rect.hpp>

#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)

//Hard coded sprite cuts

sf::IntRect Ken::IDLE_frames[6] = {
    sf::IntRect(14, 14, 64, 100),
    sf::IntRect(82, 14, 64, 100),
    sf::IntRect(150, 14, 64, 100),
    sf::IntRect(215, 14, 64, 100),
    sf::IntRect(283, 14, 64, 100),
    sf::IntRect(345, 14, 64, 100)
};
sf::IntRect Ken::moveright_frames[6] = {
    sf::IntRect(16,145,60,100),
    sf::IntRect(78,145,60,100),
    sf::IntRect(145,145,60,100),
    sf::IntRect(217,145,60,100),
    sf::IntRect(288,145,60,100),
    sf::IntRect(350,145,60,100)
};
sf::IntRect Ken::moveleft_frames[6] = {
    sf::IntRect(448,145,68,100),
    sf::IntRect(515,145,68,100),
    sf::IntRect(580,145,68,100),
    sf::IntRect(648,145,68,100),
    sf::IntRect(713,145,68,100),
    sf::IntRect(780,145,68,100)
};
sf::IntRect Ken::punch1_frames[2] = {sf::IntRect(15,280,68,100), sf::IntRect(87,280,94,100)};

sf::IntRect Ken::punch2_frames[3] = {
    sf::IntRect(300,280,65,100),
    sf::IntRect(370,280,70,100),
    sf::IntRect(450,280,110,100)
};
sf::IntRect Ken::punch3_frames[7] = {
    sf::IntRect(265,568,60,100),
    sf::IntRect(335,568,60,100),
    sf::IntRect(395,568,90,100),
    sf::IntRect(490,568,70,100),
    sf::IntRect(560,568,90,100),
    sf::IntRect(655,568,60,100),
    sf::IntRect(715,568,65,100)
};
sf::IntRect Ken::kick1_frames[3] = { 
    sf::IntRect(15,415,60,100),
    sf::IntRect(85,415,60,100),
    sf::IntRect(155,415,115,100)
};
sf::IntRect Ken::jmp_frames[8] = {
    sf::IntRect(18,1595,60,100),
    sf::IntRect(78,1588,60,100),
    sf::IntRect(138,1540,60,100),
    sf::IntRect(198,1505,60,100),
    sf::IntRect(262,1500,50,100),
    sf::IntRect(320,1520,50,100),
    sf::IntRect(370,1560,60,100),
    sf::IntRect(430,1595,60,100)
};
sf::IntRect Ken::kick2_frames[3] = {
    sf::IntRect(15,730,60,100),
    sf::IntRect(85,730,50,100),
    sf::IntRect(140,730,80,100)
};
sf::IntRect Ken::kick3_frames[6] = {
    sf::IntRect(815,730,65,100),
    sf::IntRect(880,730,65,100),
    sf::IntRect(945,705,55,125),
    sf::IntRect(1000,715,100,115),
    sf::IntRect(1103,730,50,100),
    sf::IntRect(1160,730,60,100)
};
sf::IntRect Ken::crouching_frames[3] = {
  sf::IntRect(10,1115,60,100),
  sf::IntRect(75,1115,60,100),
  sf::IntRect(140,1115,60,100)
};
sf::IntRect Ken::crouched_punch1_frames[2] = {
  sf::IntRect(15,1280,70,100),
  sf::IntRect(90,1280,100,100)
};
sf::IntRect Ken::crouched_punch2_frames[3] = {
  sf::IntRect(315,1280,65,100),
  sf::IntRect(385,1280,65,100),
  sf::IntRect(460,1280,95,100)
};
sf::IntRect Ken::crouched_kick1_frames[5] = {
    sf::IntRect(330,1385,75,100), 
    sf::IntRect(410,1385,95,100),
    sf::IntRect(515,1385,145,100),
    sf::IntRect(670,1385,95,100),
    sf::IntRect(775,1385,70,100)
};
sf::IntRect Ken::crouched_kick2_frames[5] = {
  sf::IntRect(895,1385,50,100),
  sf::IntRect(950,1385,125,100),
  sf::IntRect(1080,1385,65,100),
  sf::IntRect(1150,1385,65,100),
  sf::IntRect(1220,1385,65,100)
};
sf::IntRect Ken::helicopter_kick_frames[12] = {
  sf::IntRect(15,2940,70,110),
  sf::IntRect(85,2905,70,110),
  sf::IntRect(155,2905,60,110),
  sf::IntRect(215,2910,100,110),
  sf::IntRect(320,2910,60,110),
  sf::IntRect(380,2910,100,110),
  sf::IntRect(480,2910,70,110),
  sf::IntRect(550,2910,60,110),
  sf::IntRect(610,2910,60,110),
  sf::IntRect(670,2910,65,110),
  sf::IntRect(735,2920,60,110),
  sf::IntRect(795,2945,60,110)
};
sf::IntRect Ken::tornado_kick_frames[10] = {
  sf::IntRect(15,2028,60,100),
  sf::IntRect(80,2020,60,110),
  sf::IntRect(140,2020,70,110),
  sf::IntRect(215,2025,60,100),
  sf::IntRect(275,2025,100,100),
  sf::IntRect(380,2025,60,100),
  sf::IntRect(450,2025,60,100),
  sf::IntRect(510,2025,60,100),
  sf::IntRect(570,2025,60,100),
  sf::IntRect(630,2028,60,100)
};
sf::IntRect Ken::body_hit_frames[3]={
    sf::IntRect(120,3235,60,100),
    sf::IntRect(185,3235,70,100)
};
sf::IntRect Ken::knockout_frames[5];
sf::IntRect Ken::victory_frames[4];
Ken::Ken()
{
    img.loadFromFile("assets/ken.png");
    img.createMaskFromColor(sf::Color(00,129,129,255));
    texture.loadFromImage(img);
    player.setTexture(texture);
    #define STOP !true
    knockout_frames[0] = sf::IntRect(20,3550,70,100);
    knockout_frames[1] = sf::IntRect(98,3550,125,100);
    knockout_frames[2] = sf::IntRect(225,3550,125,100);
    knockout_frames[3] = sf::IntRect(355,3540,125,100);
    knockout_frames[4] = sf::IntRect(485,3540,135,100);
    //
    victory_frames[0] = sf::IntRect(293,5073,60,100);
    victory_frames[1] = sf::IntRect(353,5073,60,100);
    victory_frames[2] = sf::IntRect(420,5073,60,100);
    victory_frames[3] = sf::IntRect(485,5050,60,123);

    player.setTextureRect(IDLE_frames[0]);

    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}

bool Ken::punch1()
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
bool Ken::punch2()
{
    if(IS_IDLE)
    {
        currFrame = 0;
        state = AnimationState::PUNCH2;
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
bool Ken::punch3()
{
    if(IS_IDLE)
    {
      currFrame = 0;
      state = AnimationState::PUNCH3;
      return true;
    }
    return false;
}
bool Ken::kick1()
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
bool Ken::kick2()
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
bool Ken::kick3()
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
void Ken::moveLeft(float limit)
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::moveLeft;
    this->limit = limit;
  }
}
void Ken::moveRight(float limit)
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::moveRight;
    this->limit = limit;
  }
}
bool Ken::jump()
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
bool Ken::crouch()
{
  if(state == AnimationState::IDLE)
  {
    currFrame = 0;
    state = AnimationState::CROUCHING;
    return true;
  }
  return false;
}
bool Ken::uncrouch()
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
bool Ken::specialMove1()
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
bool Ken::isIdle()
{
  return state==AnimationState::IDLE;
}
bool Ken::isSuffering()
{
  return state == AnimationState::BODY_HIT;
}
void Ken::victory()
{
  state = AnimationState::VICTORY;
  player.setPosition(player.getPosition().x,BOTTOMY - victory_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1 );
  currFrame = 0;
}
bool Ken::isAttacking()
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
void Ken::bodyHit()
{
  if(state != AnimationState::BODY_HIT)
  {
  state = AnimationState::BODY_HIT;
  player.setPosition(player.getPosition().x,BOTTOMY - body_hit_frames[0].height*PLAYER_SPRITE_Y_SCALE + 1 );
  currFrame = 0;
  }
}
void Ken::knockout(bool* b)
{
  currFrame = 0;
  state = AnimationState::KNOCKED_OUT;
  ptr = b;
}
void Ken::flippedMoveLeft(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_LEFT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Ken::flippedMoveRight(float f)
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::FLIPPED_MOVE_RIGHT;
      currFrame = -1;
      frameIncrement = 1;
      limit = f;
    }
}
void Ken::update(float dt)
{
    if(STOP)
      return;
    elapsed += dt;
    int disp = 10;
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
        if(currFrame == 6)
        { 
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=(0.08f) && state == AnimationState::moveLeft)
    {
        //printf("rendering frame %d\n",currFrame);
        player.setTextureRect(moveleft_frames[currFrame++]);
        elapsed = 0;
        if(player.getPosition().x - 20 > limit) // window width is 800
          player.setPosition(player.getPosition().x-10,player.getPosition().y);
        if(currFrame == 6)
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
        if(currFrame == 2)
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
        player.setTextureRect(punch2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
        { 
            state = AnimationState::FASTIDLE_ATTACKING;
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
    else if(elapsed>=MOVE_TIME*5 && state == AnimationState::VICTORY)
    {
        player.setPosition(player.getPosition().x,BOTTOMY - victory_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1 );
        player.setTextureRect(victory_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 4)
        { 
            currFrame = 3;
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
    else if(elapsed >= MOVE_TIME && state == AnimationState::KICK1)
    {
        player.setTextureRect(kick1_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if(currFrame == 3)
        {
            currFrame = 1;
            frameIncrement = -1;
        }
        else if(currFrame == -1)
        {
            currFrame = 0;
            frameIncrement = 1;
            state = AnimationState::FASTIDLE_ATTACKING;
        }
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::KICK2)
    {
        player.setTextureRect(kick2_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if(currFrame == 3)
        {
            currFrame = 1;
            frameIncrement = -1;
        }
        else if(currFrame == -1)
        {
            currFrame = 0;
            frameIncrement = 1;
            state = AnimationState::FASTIDLE_ATTACKING;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::KICK3)
    {
        player.setPosition(player.getPosition().x,BOTTOMY - kick3_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1 );
        player.setTextureRect(kick3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 6)
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
void Ken::setPosition(float x,float y)
{
    player.setPosition(x,y);
}
void Ken::flipX()
{
  player.setScale(-2.1,2.1);
}
void Ken::render(sf::RenderWindow &win)
{
    win.draw(player);
}
sf::FloatRect Ken::getGlobalBounds()
{
    return player.getGlobalBounds();
}
sf::FloatRect Ken::getLocalBounds()
{
    return player.getLocalBounds();
}
Ken::~Ken()
{
}

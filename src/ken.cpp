//Written by Shahryar Ahmad
#include "ken.h"
#include "constants.h"
#include <SFML/Graphics/Rect.hpp>

#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)

sf::IntRect Ken::IDLE_frames[6];
sf::IntRect Ken::moveright_frames[6];
sf::IntRect Ken::moveleft_frames[6];
sf::IntRect Ken::punch1_frames[2];
sf::IntRect Ken::punch2_frames[3];
sf::IntRect Ken::punch3_frames[7];
sf::IntRect Ken::kick1_frames[3];
sf::IntRect Ken::jmp_frames[8];
sf::IntRect Ken::kick2_frames[3];
sf::IntRect Ken::kick3_frames[6];
sf::IntRect Ken::crouching_frames[3];
sf::IntRect Ken::crouched_punch1_frames[2];
sf::IntRect Ken::crouched_punch2_frames[3];
sf::IntRect Ken::crouched_kick1_frames[5];
sf::IntRect Ken::crouched_kick2_frames[5];


Ken::Ken()
{
    img.loadFromFile("assets/ken.png");
    //img.createMaskFromColor(sf::Color(00,129,129,255));
    texture.loadFromImage(img);
    player.setTexture(texture);


    IDLE_frames[0] = sf::IntRect(14, 14, 64, 100);
    IDLE_frames[1] = sf::IntRect(82, 14, 64, 100);
    IDLE_frames[2] = sf::IntRect(150, 14, 64, 100);
    IDLE_frames[3] = sf::IntRect(215, 14, 64, 100);
    IDLE_frames[4] = sf::IntRect(283, 14, 64, 100);
    IDLE_frames[5] = sf::IntRect(345, 14, 64, 100);
    
    
    moveright_frames[0] = sf::IntRect(16,145,60,100);
    moveright_frames[1] = sf::IntRect(78,145,60,100);
    moveright_frames[2] = sf::IntRect(145,145,60,100);
    moveright_frames[3] = sf::IntRect(217,145,60,100);
    moveright_frames[4] = sf::IntRect(288,145,60,100);
    moveright_frames[5] = sf::IntRect(350,145,60,100);
    
    punch1_frames[0] = sf::IntRect(15,280,68,100);
    punch1_frames[1] = sf::IntRect(87,280,94,100);

    kick1_frames[0] = sf::IntRect(600,260,70,110);
    kick1_frames[1] = sf::IntRect(690,260,70,110);
    kick1_frames[2] = sf::IntRect(780,260,110,110);
    
    jmp_frames[0] = sf::IntRect(18,1595,60,100);
    jmp_frames[1] = sf::IntRect(78,1588,60,100);
    jmp_frames[2] = sf::IntRect(138,1540,60,100);
    jmp_frames[3] = sf::IntRect(198,1505,60,100);
    jmp_frames[4] = sf::IntRect(262,1500,50,100);
    jmp_frames[5] = sf::IntRect(320,1520,50,100);
    jmp_frames[6] = sf::IntRect(370,1560,60,100);
    jmp_frames[7] = sf::IntRect(430,1595,60,100);

    moveleft_frames[0] = sf::IntRect(448,145,68,100);
    moveleft_frames[1] = sf::IntRect(515,145,68,100);
    moveleft_frames[2] = sf::IntRect(580,145,68,100);
    moveleft_frames[3] = sf::IntRect(648,145,68,100);
    moveleft_frames[4] = sf::IntRect(713,145,68,100);
    moveleft_frames[5] = sf::IntRect(780,145,68,100);

    punch2_frames[0] = sf::IntRect(300,280,65,100);
    punch2_frames[1] = sf::IntRect(370,280,70,100);
    punch2_frames[2] = sf::IntRect(450,280,110,100);

    punch3_frames[0] = sf::IntRect(265,568,60,100);
    punch3_frames[1] = sf::IntRect(335,568,60,100);
    punch3_frames[2] = sf::IntRect(395,568,90,100);
    punch3_frames[3] = sf::IntRect(490,568,70,100);
    punch3_frames[4] = sf::IntRect(560,568,90,100);
    punch3_frames[5] = sf::IntRect(655,568,60,100);
    punch3_frames[6] = sf::IntRect(715,568,65,100);

    kick1_frames[0] = sf::IntRect(15,415,60,100);
    kick1_frames[1] = sf::IntRect(85,415,60,100);
    kick1_frames[2] = sf::IntRect(155,415,115,100);
    
    kick2_frames[0] = sf::IntRect(15,730,60,100);
    kick2_frames[1] = sf::IntRect(85,730,50,100);
    kick2_frames[2] = sf::IntRect(140,730,80,100);

    kick3_frames[0] = sf::IntRect(815,730,65,100);
    kick3_frames[1] = sf::IntRect(880,730,65,100);
    kick3_frames[2] = sf::IntRect(945,705,55,125);
    kick3_frames[3] = sf::IntRect(1000,715,100,115);
    kick3_frames[4] = sf::IntRect(1103,730,50,100);
    kick3_frames[5] = sf::IntRect(1160,730,60,100);
    
    crouching_frames[0] = sf::IntRect(10,1115,60,100);
    crouching_frames[1] = sf::IntRect(75,1115,60,100);
    crouching_frames[2] = sf::IntRect(140,1115,60,100);
    
    crouched_punch1_frames[0] = sf::IntRect(15,1280,70,100);
    crouched_punch1_frames[1] = sf::IntRect(90,1280,100,100);

    crouched_punch2_frames[0] = sf::IntRect(315,1280,65,100);
    crouched_punch2_frames[1] = sf::IntRect(385,1280,65,100);
    crouched_punch2_frames[2] = sf::IntRect(460,1280,95,100);

    crouched_kick1_frames[0] = sf::IntRect(330,1385,75,100); 
    crouched_kick1_frames[1] = sf::IntRect(410,1385,95,100);
    crouched_kick1_frames[2] = sf::IntRect(515,1385,145,100);
    crouched_kick1_frames[3] = sf::IntRect(670,1385,95,100);
    crouched_kick1_frames[4] = sf::IntRect(775,1385,70,100);

    crouched_kick2_frames[0] = sf::IntRect(895,1385,50,100);
    crouched_kick2_frames[1] = sf::IntRect(950,1385,125,100);
    crouched_kick2_frames[2] = sf::IntRect(1080,1385,65,100);
    crouched_kick2_frames[3] = sf::IntRect(1150,1385,65,100);
    crouched_kick2_frames[4] = sf::IntRect(1220,1385,65,100);
    #define STOP false
    //player.setTextureRect( sf::IntRect(1220,1385,65,100));
  
    player.setTextureRect(IDLE_frames[0]);
        
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}

void Ken::punch1()
{
    if(IS_IDLE)
    {
      currFrame = 0;
      state = AnimationState::PUNCH1;
    }
    else if(state == AnimationState::CROUCHED)
    {
      currFrame = 0;
      state = AnimationState::CROUCHED_PUNCH1;
    }
}
void Ken::punch2()
{
    if(IS_IDLE)
    {
        currFrame = 0;
        state = AnimationState::PUNCH2;
    }
    else if(state == AnimationState::CROUCHED)
    {
      currFrame = 0;
      state = AnimationState::CROUCHED_PUNCH2;
    }
}
void Ken::punch3()
{
    if(IS_IDLE)
    {
      currFrame = 0;
      state = AnimationState::PUNCH3;
    }
}
void Ken::kick1()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK1;
    frameIncrement = 1;
  }
  else if(state == AnimationState::CROUCHED)
  {
    currFrame = 0;
    state = AnimationState::CROUCHED_KICK1;
  }
}
void Ken::kick2()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK2;
    frameIncrement = 1;
  }
  else if(state == AnimationState::CROUCHED)
  {
    currFrame = 0;
    state = AnimationState::CROUCHED_KICK2;
  }
}
void Ken::kick3()
{
  if(IS_IDLE)
  {
    currFrame = 0;
    state = AnimationState::KICK3;
    frameIncrement = 1;
    
  }
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
void Ken::jump()
{
  if(IS_IDLE)
  {
    state = AnimationState::JMP;
    currFrame = 0;
    JMPY = -40;
    delay_time = 0.05f;
  }
}
void Ken::crouch()
{
  if(state == AnimationState::IDLE)
  {
    currFrame = 0;
    state = AnimationState::CROUCHING;
  }
}
void Ken::uncrouch()
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
  }
}
void Ken::update(float dt)
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
    else if (elapsed >= (0.08f) && state == AnimationState::FASTIDLE)
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
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
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
            state = AnimationState::FASTIDLE;
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
            state = AnimationState::FASTIDLE;
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
            state = AnimationState::FASTIDLE;
        }
    }
    else if(elapsed>=MOVE_TIME && state == AnimationState::KICK3)
    {

        player.setPosition(player.getPosition().x,BOTTOMY - kick3_frames[currFrame].height*PLAYER_SPRITE_Y_SCALE + 1 );
        player.setTextureRect(kick3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 6)
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

// Written by Shahryar Ahmad
#include "ryu.h"
#include <stdio.h>
#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)
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

    kick1_frames[0] = sf::IntRect(600,265,70,100);
    kick1_frames[1] = sf::IntRect(690,265,70,100);
    kick1_frames[2] = sf::IntRect(780,265,110,100);
    
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

    kick2_frames[0] = sf::IntRect(10,640,70,110);
    kick2_frames[1] = sf::IntRect(80,640,70,110);
    kick2_frames[2] = sf::IntRect(160,640,90,110);
    
    shoryuken_frames[0] = sf::IntRect(20,1800,70,110);
    shoryuken_frames[1] = sf::IntRect(110,1800,70,110);
    shoryuken_frames[2] = sf::IntRect(190,1780,70,130);
    shoryuken_frames[3] = sf::IntRect(290,1780,70,130);
    shoryuken_frames[4] = sf::IntRect(360,1780,70,120);
    shoryuken_frames[5] = sf::IntRect(450,1800,70,110);
   
    kick3_frames[0] = sf::IntRect(630,640,70,110);
    kick3_frames[1] = sf::IntRect(710,640,70,110);
    kick3_frames[2] = sf::IntRect(780,630,70,110);
    kick3_frames[3] = sf::IntRect(870,640,100,110);
    kick3_frames[4] = sf::IntRect(970,650,70,110);
   
    punch3_frames[0] = sf::IntRect(230,513,70,100);
    punch3_frames[1] = sf::IntRect(320,513,70,100);
    punch3_frames[2] = sf::IntRect(410,513,90,100);
    punch3_frames[3] = sf::IntRect(510,513,70,100);
    punch3_frames[4] = sf::IntRect(600,513,100,100);

    crouching_frames[0] = sf::IntRect(20,1195,70,100);
    crouching_frames[1] = sf::IntRect(110,1195,70,100);
    crouching_frames[2] = sf::IntRect(190,1195,70,100);
    
    crouched_punch1_frames[0] = sf::IntRect(20,1300,75,100);
    crouched_punch1_frames[1] = sf::IntRect(110,1300,105,100);
    
    crouched_punch2_frames[0] = sf::IntRect(260,1300,90,100);
    crouched_punch2_frames[1] = sf::IntRect(350,1300,90,100);
    crouched_punch2_frames[2] = sf::IntRect(450,1300,90,100);

    crouched_kick1_frames[0] = sf::IntRect(20,1410,75,100);
    crouched_kick1_frames[1] = sf::IntRect(120,1410,105,100);
    crouched_kick1_frames[2] = sf::IntRect(240,1410,150,100);

    crouched_kick2_frames[0] = sf::IntRect(440,1410,70,100);
    crouched_kick2_frames[1] = sf::IntRect(530,1410,130,100);
    crouched_kick2_frames[2] = sf::IntRect(680,1410,70,100);
    crouched_kick2_frames[3] = sf::IntRect(770,1410,70,100);
    crouched_kick2_frames[4] = sf::IntRect(860,1410,70,100);

    hadoken_frames[0] = sf::IntRect(30,1530,80,100);
    hadoken_frames[1] = sf::IntRect(130,1530,90,100);
    hadoken_frames[2] = sf::IntRect(240,1530,90,100);
    hadoken_frames[3] = sf::IntRect(350,1530,120,100); 
    gola.setTexture(texture);
    gola.setTextureRect(sf::IntRect(550,1550,60,50));
    gola.setScale(1.2,1.2);

    //player.setTextureRect(IDLE_frames[0]);
    player.setTextureRect(punch3_frames[1]);
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}
bool Ryu::processEvent(sf::Event &ev)
{

    if(ev.type == sf::Event::KeyPressed && state == AnimationState::CROUCHED)
    {
        if(ev.key.code == sf::Keyboard::A)
        {
          state = AnimationState::CROUCHED_PUNCH1;
          currFrame = 0;
          frameIncrement = 1;
        }
        else if(ev.key.code == sf::Keyboard::S)
        {
          state = AnimationState::CROUCHED_PUNCH2;
          currFrame = 0;
          frameIncrement = 1;
        }
        else if(ev.key.code == sf::Keyboard::Z)
        {
          state = AnimationState::CROUCHED_KICK1;
          currFrame = 0;
          frameIncrement = 1;
        }
        else if(ev.key.code == sf::Keyboard::X)
        {
          state = AnimationState::CROUCHED_KICK2;
          currFrame = 0;
          frameIncrement = 1;
        }
    }
    else if(ev.type == sf::Event::KeyReleased && (state == AnimationState::CROUCHED || state == AnimationState::CROUCHED_KICK1 || state == AnimationState::KICK2 || state == AnimationState::CROUCHED_PUNCH1 || state == AnimationState::CROUCHED_PUNCH2)
             && ev.key.code == sf::Keyboard::Down)
    {
      state = AnimationState::UNCROUCHING;
      currFrame = 2;
      frameIncrement = -1;
      return true;
    }
    return false;
}
//
void Ryu::moveLeft()
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::MOVE_LEFT;
      currFrame = -1;
      frameIncrement = 1;
    }
}
void Ryu::moveRight()
{
    if(state == AnimationState::IDLE)
    {
      state = AnimationState::MOVE_RIGHT;
      currFrame = -1;
      frameIncrement = 1;
    }
}
//
void Ryu::punch1()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::PUNCH1;
    currFrame = -1;
    frameIncrement = 1;
  }
}
void Ryu::punch2()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::PUNCH2;
    currFrame = -1;
    frameIncrement = 1;
  }
}
void Ryu::punch3()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::PUNCH3;
    currFrame = 0;
    frameIncrement = 1;
  }
}
//Kicks
void Ryu::kick1()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::KICK1;
    currFrame = -1;
    frameIncrement = 1;
  }
}
void Ryu::kick2()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::KICK2;
    currFrame = 0;
    frameIncrement = 1;
  }
}
void Ryu::kick3()
{
  if(state == AnimationState::IDLE)
  {
    state = AnimationState::KICK3;
    currFrame = 0;
    frameIncrement = 1;
  }
}
//
void Ryu::jump()
{
    if(IS_IDLE)
    {
        state = AnimationState::JMP;
        currFrame = -1;
        frameIncrement = 1;
        pos = player.getPosition();
         
    }
}
void Ryu::specialMove1()
{
    if(IS_IDLE)
    {
        state = AnimationState::SHORYUKEN;
        currFrame = 0;
        frameIncrement = 1;
    }
}
void Ryu::specialMove2()
{
    if(IS_IDLE)
    {
        state = AnimationState::HADOKEN;
        currFrame = 0;
        frameIncrement = 1;
    }
}

//Updation based on animation state
void Ryu::update(float dt)
{
    //return;
    elapsed += dt;
    if(hadoken)
    {
        if(gola.getPosition().x + 100 >= 800)
          hadoken = false;
        else
          gola.setPosition(gola.getPosition().x + (100*dt),gola.getPosition().y);
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
    else if (elapsed >= (0.08f) && state == AnimationState::FASTIDLE)
    {
        player.setTextureRect(IDLE_frames[0]);
        currFrame++;
        state = AnimationState::IDLE;
        elapsed = 0;
    }
    else if (elapsed >= (0.08f) && state == AnimationState::LAND)
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
    else if(elapsed>=(0.08f) && state == AnimationState::MOVE_RIGHT)
    {
        currFrame = currFrame+1;
        player.setTextureRect(moveright_frames[currFrame]);
        elapsed = 0;
        if(player.getPosition().x + 150 < 800) // window width is 800
          player.setPosition(player.getPosition().x+10,player.getPosition().y);
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=(0.08f) && state == AnimationState::MOVE_LEFT)
    {
        currFrame = currFrame+1;
        player.setTextureRect(moveleft_frames[currFrame]);
        elapsed = 0;
        if(player.getPosition().x - 20 > 0) // window width is 800
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
        currFrame = currFrame+1;
        player.setTextureRect(punch1_frames[currFrame]);
        elapsed = 0;
        if(currFrame == 1)
        { 
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::PUNCH2)
    {
        currFrame = currFrame+1;
        player.setTextureRect(punch2_frames[currFrame]);
        elapsed = 0;
        if(currFrame == 2)
        { 
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed>=0.08f && state == AnimationState::PUNCH3)
    {
        player.setTextureRect(punch3_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        { 
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::KICK1)
    {
        currFrame++; 
        player.setTextureRect(kick1_frames[currFrame]);
        elapsed = 0;
        if(currFrame == 2) //last frame rendered
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed >= 0.08f && state == AnimationState::KICK2)
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
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
        else
            player.setPosition(player.getPosition().x,player.getPosition().y+(-15*frameIncrement));
        
    }
    else if (elapsed >= 0.08f && state == AnimationState::KICK3)
    {
       // printf("rendering frame %d\n",currFrame);
        player.setTextureRect(kick3_frames[currFrame++]);
        player.setPosition(player.getPosition().x,player.getPosition().y-10);
        elapsed = 0;
        if(currFrame == 5) //last frame rendered
        {
            player.setPosition(player.getPosition().x,player.getPosition().y+50);
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if(elapsed >= 0.08f && state == AnimationState::SHORYUKEN)
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
    else if (elapsed >=  0.08f && state == AnimationState::JMP)
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
    else if(elapsed >= 0.08f && state == AnimationState::CROUCHING)
    {
        player.setTextureRect(crouching_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 3)
            state = AnimationState::CROUCHED;
        
    }
    else if(elapsed >= 0.08f && state == AnimationState::UNCROUCHING)
    {
        player.setTextureRect(crouching_frames[currFrame--]);
        elapsed = 0;
        if(currFrame == -1)
        {
            state = AnimationState::FASTIDLE;
            frameIncrement = 1;
            currFrame = 0;
        }
    }
    else if(elapsed >= 0.08f && state == AnimationState::FAST_CROUCHED)
    {
        elapsed = 0;
        state = AnimationState::CROUCHED;
        player.setTextureRect(crouching_frames[2]);
    }
    else if(elapsed >= 0.08f && state == AnimationState::CROUCHED_PUNCH1)
    {
        player.setTextureRect(crouched_punch1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 2)
        {
            state = AnimationState::FAST_CROUCHED;
        }
    }
    else if(elapsed >= 0.08f && state == AnimationState::CROUCHED_PUNCH2)
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
    else if(elapsed >= 0.08f && state == AnimationState::CROUCHED_KICK1)
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
    else if(elapsed >= 0.08f && state == AnimationState::CROUCHED_KICK2)
    {
        player.setTextureRect(crouched_kick2_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 5)
        {
            state = AnimationState::FAST_CROUCHED;
        }
    }
    else if(elapsed >= 0.08f && state == AnimationState::HADOKEN)
    {
        player.setTextureRect(hadoken_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 4)
        {
            hadoken = true;
            gola.setPosition(player.getPosition().x+220,player.getPosition().y+60);
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
void Ryu::render(sf::RenderWindow &win)
{
    win.draw(player);
    if(hadoken)
      win.draw(gola);
}
Ryu::~Ryu()
{
}

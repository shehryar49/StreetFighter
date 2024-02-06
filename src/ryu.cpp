// Written by Shahryar Ahmad
#include "ryu.h"

using namespace std;

sf::IntRect Ryu::IDLE_frames[5];
sf::IntRect Ryu::moveright_frames[6];
sf::IntRect Ryu::moveleft_frames[6];
sf::IntRect Ryu::punch1_frames[2];
sf::IntRect Ryu::punch2_frames[3];
sf::IntRect Ryu::kick1_frames[3];
sf::IntRect Ryu::kick2_frames[3];
sf::IntRect Ryu::jmp_frames[7];

Ryu::Ryu()
{
    img.loadFromFile("assets/ryu.png");
    //img.createMaskFromColor(sf::Color(70,112,104,255));
    texture.loadFromImage(img);
    player.setTexture(texture);

    IDLE_frames[0] = sf::IntRect(0, 0, 64, 110);
    IDLE_frames[1] = sf::IntRect(64+26, 0, 64, 110);
    IDLE_frames[2] = sf::IntRect(64+26+64+26, 0, 64, 110);
    IDLE_frames[3] = sf::IntRect(64+26+64+26+64+26, 0, 64, 110);
    IDLE_frames[4] = sf::IntRect(64+26+64+26+64+26+64+26, 0, 64, 110);
    
    moveright_frames[0] = sf::IntRect(0,120,68,110);
    moveright_frames[1] = sf::IntRect(68*1,120,68,110);
    moveright_frames[2] = sf::IntRect(68*2+20,120,68,110);
    moveright_frames[3] = sf::IntRect(68*3+50,120,68,110);
    moveright_frames[4] = sf::IntRect(68*3+140,120,68,110);
    moveright_frames[5] = sf::IntRect(68*5,120,68,110);
    
    punch1_frames[0] = sf::IntRect(20,260,68,110);
    punch1_frames[1] = sf::IntRect(40+68,260,94,110);

    kick1_frames[0] = sf::IntRect(600,260,70,110);
    kick1_frames[1] = sf::IntRect(690,260,70,110);
    kick1_frames[2] = sf::IntRect(780,260,110,110);
    
    jmp_frames[0] = sf::IntRect(0,830,70,110);
    jmp_frames[1] = sf::IntRect(90,823,70,110);
    jmp_frames[2] = sf::IntRect(160,800,70,100);
    jmp_frames[3] = sf::IntRect(240,790,70,90);
    jmp_frames[4] = sf::IntRect(310,800,70,80);
    jmp_frames[5] = sf::IntRect(380,810,70,90);
    jmp_frames[6] = sf::IntRect(460,820,60,130);
   
    moveleft_frames[0] = sf::IntRect(540,120,68,110);
    moveleft_frames[1] = sf::IntRect(625,120,68,110);
    moveleft_frames[2] = sf::IntRect(710,120,68,110);
    moveleft_frames[3] = sf::IntRect(790,120,68,110);
    moveleft_frames[4] = sf::IntRect(880,120,68,110);
    moveleft_frames[5] = sf::IntRect(970,120,68,110);

    punch2_frames[0] = sf::IntRect(250,260,68,110);
    punch2_frames[1] = sf::IntRect(332,260,68,110);
    punch2_frames[2] = sf::IntRect(430,260,110,110);

    kick2_frames[0] = sf::IntRect(10,640,70,110);
    kick2_frames[1] = sf::IntRect(80,640,70,110);
    kick2_frames[2] = sf::IntRect(160,640,90,110);

    player.setTextureRect(IDLE_frames[0]);
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}
bool Ryu::processEvent(sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed && state == AnimationState::IDLE)
    {
        if (ev.key.code == sf::Keyboard::Z)
        {
            state = AnimationState::KICK1;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if(ev.key.code == sf::Keyboard::X)
        {
            state = AnimationState::KICK2;
            currFrame = 0;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::Left)
        {
            state = AnimationState::MOVE_LEFT;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::Right)
        {
            state = AnimationState::MOVE_RIGHT;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::Up)
        {
            state = AnimationState::JMP;
            currFrame = -1;
            frameIncrement = 1;
            pos = player.getPosition();
            return true;
        }        
        else if (ev.key.code == sf::Keyboard::A)
        {
            state = AnimationState::PUNCH1;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::S)
        {
            state = AnimationState::PUNCH2;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if(ev.key.code == sf::Keyboard::Down)
        {
          //  state = AnimationState::CROUCHING;
            currFrame = 0;
        }
    }

    return false;
}
void Ryu::update(float dt)
{
    //return;
    elapsed += dt;
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
}
void Ryu::setPosition(float x,float y)
{
    player.setPosition(x,y);
}
void Ryu::flipX()
{
  player.setScale(-2.1,2.1);
}
void Ryu::render(sf::RenderWindow &win)
{
    win.draw(player);
}
Ryu::~Ryu()
{
}
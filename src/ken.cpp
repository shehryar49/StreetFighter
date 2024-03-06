#include "ken.h"

#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)
#define STOP !false

sf::IntRect Ken::IDLE_frames[6];
sf::IntRect Ken::moveright_frames[6];
sf::IntRect Ken::moveleft_frames[6];
sf::IntRect Ken::punch1_frames[2];
sf::IntRect Ken::punch2_frames[3];
sf::IntRect Ken::kick1_frames[3];
sf::IntRect Ken::jmp_frames[7];
Ken::Ken()
{
    img.loadFromFile("assets/ken.png");
    img.createMaskFromColor(sf::Color(70,112,104,255));
    texture.loadFromImage(img);
    player.setTexture(texture);
    // found out using trial and error
    // 64 pixel wide character
    // 26 pixel spacing
    IDLE_frames[0] = sf::IntRect(12, 14, 64, 100);
    IDLE_frames[1] = sf::IntRect(84, 14, 64, 100);
    IDLE_frames[2] = sf::IntRect(150, 14, 64, 100);
    IDLE_frames[3] = sf::IntRect(215, 14, 64, 100);
    IDLE_frames[4] = sf::IntRect(280, 14, 64, 100);
    IDLE_frames[5] = sf::IntRect(340, 14, 64, 100);
    
    
    moveright_frames[0] = sf::IntRect(0,120,68,110);
    moveright_frames[1] = sf::IntRect(68*1,120,68,110);
    moveright_frames[2] = sf::IntRect(68*2+20,120,68,110);
    moveright_frames[3] = sf::IntRect(68*3+50,120,68,110);
    moveright_frames[4] = sf::IntRect(68*3+140,120,68,110);
    moveright_frames[5] = sf::IntRect(68*5,120,68,110);
    
    punch1_frames[0] = sf::IntRect(15,280,68,100);
    punch1_frames[1] = sf::IntRect(87,280,94,100);

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
   
    moveleft_frames[0] = sf::IntRect(515,145,65,100);
    moveleft_frames[1] = sf::IntRect(645,145,68,100);
    moveleft_frames[2] = sf::IntRect(710,145,68,100);
    moveleft_frames[3] = sf::IntRect(790,145,68,100);
    moveleft_frames[4] = sf::IntRect(880,145,68,100);
    moveleft_frames[5] = sf::IntRect(970,145,68,100);

    punch2_frames[0] = sf::IntRect(300,280,65,100);
    punch2_frames[1] = sf::IntRect(370,280,70,100);
    punch2_frames[2] = sf::IntRect(450,280,110,100);
    
    player.setTextureRect(moveleft_frames[1]);
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
}
void Ken::punch2()
{
    if(IS_IDLE)
    {
        currFrame = 0;
        state = AnimationState::PUNCH2;
    }
}
void Ken::kick1()
{

}
void Ken::moveLeft()
{

}
void Ken::moveRight()
{

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
    
    else if(elapsed>=(0.08f) && state == AnimationState::moveRight)
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
    else if(elapsed>=(0.08f) && state == AnimationState::moveLeft)
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
        player.setTextureRect(punch1_frames[currFrame++]);
        elapsed = 0;
        if(currFrame == 2)
        { 
            state = AnimationState::FASTIDLE;
            currFrame = 0;
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

//written by Usman Ali
#include "sagat.h"
using namespace std;

sf::IntRect Sagat::IDLE_frames[5];
sf::IntRect Sagat::moveright_frames[4];
sf::IntRect Sagat::moveleft_frames[4]; 
sf::IntRect Sagat::punch1_frames[3];
sf::IntRect Sagat::punch2_frames[5];
sf::IntRect Sagat::punch3_frames[4];
sf::IntRect Sagat::kick1_frames[7];
sf::IntRect Sagat::kick2_frames[7];
sf::IntRect Sagat::kick3_frames[7];
sf::IntRect Sagat::jmp_frames[6];
sf::IntRect Sagat::crouch_frames[2];
sf::IntRect Sagat::uppercut_frames[10];
sf::IntRect Sagat::fireball_frames[5];


Sagat::Sagat()
{
    img.loadFromFile("assets/sagat.png");
   img.createMaskFromColor(sf::Color(248, 0, 248, 255)); 

    texture.loadFromImage(img);
    player.setTexture(texture);

    player.setPosition(100, 100);

    

    IDLE_frames[0] = sf::IntRect(11, 23, 80, 124);
    IDLE_frames[1] = sf::IntRect(109, 23, 80, 124);
    IDLE_frames[2] = sf::IntRect(214, 23, 80, 124);
    IDLE_frames[3] = sf::IntRect(321, 27, 81, 120);
    IDLE_frames[4] = sf::IntRect(430, 25, 80, 119);

    moveright_frames[0] = sf::IntRect(10, 153, 78, 125);
    moveright_frames[1] = sf::IntRect(119, 151, 67, 127);
    moveright_frames[2] = sf::IntRect(231, 148, 69, 130);
    moveright_frames[3] = sf::IntRect(339, 151, 67, 127);
  
    moveleft_frames[0] = sf::IntRect(321, 150, 80, 124);
    moveleft_frames[1] = sf::IntRect(218, 150, 80, 124);
    moveleft_frames[2] = sf::IntRect(115, 150, 80, 124);
    moveleft_frames[3] = sf::IntRect(12, 150, 80, 124);
  
    //ISSUES
    crouch_frames[0] = sf::IntRect(506, 179, 80, 124);  
    crouch_frames[1] = sf::IntRect(610, 211, 97,70);

    punch1_frames[0] = sf::IntRect(20, 461, 94, 117);
    punch1_frames[1] = sf::IntRect(153, 472, 137, 107);
    punch1_frames[2] = sf::IntRect(315, 461, 94, 117);

    punch2_frames[0] = sf::IntRect(520, 452, 84, 127);
    punch2_frames[1] = sf::IntRect(630, 461, 94, 127);
    punch2_frames[2] = sf::IntRect(755, 471, 170, 114);
    punch2_frames[3] = sf::IntRect(940, 461, 94, 127);
    punch2_frames[4] = sf::IntRect(430, 260, 84, 127);

    punch3_frames[0] = sf::IntRect(666, 1541, 119, 131);
    punch3_frames[1] = sf::IntRect(792, 1546, 93, 129);
    punch3_frames[2] = sf::IntRect(911, 1547, 94, 127);
    punch3_frames[3] = sf::IntRect(1035, 1566, 173, 108);


    //fire not going ahead
    fireball_frames[0] = sf::IntRect(19, 1179, 79, 127);
    fireball_frames[1] = sf::IntRect(132, 1194, 101, 113);
    fireball_frames[2] = sf::IntRect(264, 1202, 157, 107);
    fireball_frames[3] = sf::IntRect(452, 1210, 38, 38);
    fireball_frames[4] = sf::IntRect(488, 1208, 44, 40);


    //glitches a bit
    kick1_frames[0] = sf::IntRect(23, 597, 111, 131); 
    kick1_frames[1] = sf::IntRect(137, 597, 97, 129);  
    kick1_frames[2] = sf::IntRect(248, 601, 75, 127);  
    kick1_frames[3] = sf::IntRect(342, 615, 135, 113); 
    kick1_frames[4] = sf::IntRect(780, 601, 75, 127);  
    kick1_frames[5] = sf::IntRect(601, 597, 97, 129);  
    kick1_frames[6] = sf::IntRect(711, 597, 111, 131); 

    kick2_frames[0] = sf::IntRect(23, 770, 111, 131); 
    kick2_frames[1] = sf::IntRect(137, 770, 97, 129);  
    kick2_frames[2] = sf::IntRect(255, 772, 66, 127);  
    kick2_frames[3] = sf::IntRect(360, 786, 139, 113); 
    kick2_frames[4] = sf::IntRect(255, 772, 66, 127);  
    kick2_frames[5] = sf::IntRect(601, 770, 97, 129);  
    kick2_frames[6] = sf::IntRect(711, 770, 111, 131); 

    kick3_frames[0] = sf::IntRect(23, 910, 111, 131); 
    kick3_frames[1] = sf::IntRect(137, 910, 97, 129);  
    kick3_frames[2] = sf::IntRect(255, 914, 66, 127);
    kick3_frames[3] = sf::IntRect(356, 918, 123, 122);
    kick3_frames[4] = sf::IntRect(255, 914, 66, 127);
    kick3_frames[5] = sf::IntRect(601, 910, 97, 129);  
    kick3_frames[6] = sf::IntRect(711, 910, 111, 131); 

    jmp_frames[0] = sf::IntRect(19, 344, 79, 99);
    jmp_frames[1] = sf::IntRect(126, 300, 69, 135);
    jmp_frames[2] = sf::IntRect(237, 290, 74, 99);
    jmp_frames[3] = sf::IntRect(335, 292, 66, 79);
    jmp_frames[4] = sf::IntRect(426, 290, 74, 99);
    jmp_frames[5] = sf::IntRect(523, 300, 69, 135);

    //after landing,position increases and goes out of screen
    uppercut_frames[0] = sf::IntRect(22, 1390, 81, 99);
    uppercut_frames[1] = sf::IntRect(123, 1422, 94, 72);
    uppercut_frames[2] = sf::IntRect(244, 1414, 89, 76);
    uppercut_frames[3] = sf::IntRect(347, 1397, 110, 95);
    uppercut_frames[4] = sf::IntRect(474, 1379, 113, 110);
    uppercut_frames[5] = sf::IntRect(634, 1314, 57, 163);
    uppercut_frames[6] = sf::IntRect(722, 1351, 90, 82);
    uppercut_frames[7] = sf::IntRect(826, 1353, 92, 78);
    uppercut_frames[8] = sf::IntRect(941, 1346, 66, 137);
    uppercut_frames[9] = sf::IntRect(1035, 1390, 81, 99);


    

    player.setTextureRect(IDLE_frames[0]);
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}
bool Sagat::processEvent(sf::Event& ev)
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
        else if (ev.key.code == sf::Keyboard::X)
        {
            state = AnimationState::KICK2;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::C)
        {
            state = AnimationState::KICK3;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::Left)
        {
            state = AnimationState::moveLeft;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::Right)
        {
            state = AnimationState::moveRight;
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
        else if (ev.key.code == sf::Keyboard::Down)
        {
            state = AnimationState::CROUCH;
            currFrame = -1;
            frameIncrement = 1;
            pos = player.getPosition();
            return true;
        }
        else if (ev.key.code == sf::Keyboard::Q)
        {
            state = AnimationState::UPPERCUT;
            currFrame = -1;
            frameIncrement = 1;
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
        else if (ev.key.code == sf::Keyboard::D)
        {
            state = AnimationState::PUNCH3;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::W)
        {
            state = AnimationState::FIREBALL;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
    }
    else if (ev.type == sf::Event::KeyReleased && state == AnimationState::CROUCH && ev.key.code == sf::Keyboard::Down)
    {
        state = AnimationState::UNCROUCH;
        currFrame = 1;
        frameIncrement = -1;
    }
    return false;
}
void Sagat::update(float dt)
{
    //   return;
    elapsed += dt;
    if ((elapsed >= (0.7f)) && state == AnimationState::IDLE)
    {
        if (currFrame == 0)
            frameIncrement = 1;
        else if (currFrame == 4)
            frameIncrement = -1;
        currFrame = (currFrame + frameIncrement);
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
        player.setPosition(player.getPosition().x, player.getPosition().y + 30);
        elapsed = 0;
        if (currFrame == 0) // landed
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }

    else if (elapsed >= (0.08f) && state == AnimationState::moveRight)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(moveright_frames[currFrame]);
        elapsed = 0;
        if (player.getPosition().x + 150 < 800) // window width is 800
            player.setPosition(player.getPosition().x + 10, player.getPosition().y);
        if (currFrame == 3)
        {
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= (0.08f) && state == AnimationState::moveLeft)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(moveleft_frames[currFrame]);
        elapsed = 0;
        if (player.getPosition().x - 20 > 0) // window width is 800
            player.setPosition(player.getPosition().x - 10, player.getPosition().y);
        if (currFrame == 3)
        {
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::PUNCH1)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(punch1_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 2)
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::PUNCH2)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(punch2_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 3)
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::PUNCH3)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(punch3_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 3)
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
        if (currFrame == 6) //last frame rendered
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::KICK2)
    {
        currFrame++;
        player.setTextureRect(kick2_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 6) //last frame rendered
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::KICK3)
    {
        currFrame++;
        player.setTextureRect(kick3_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 6) //last frame rendered
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::JMP)
    {
        currFrame++;
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x, player.getPosition().y - 30);
        elapsed = 0;
        if (currFrame == 5) //last frame rendered
        {
            currFrame = 6;
            state = AnimationState::LAND;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::UPPERCUT)
    {
        player.setTextureRect(uppercut_frames[currFrame++]);
        player.setPosition(player.getPosition().x, player.getPosition().y - 40);
        elapsed = 0;
        if (currFrame == 9) //last frame rendered
        {
            state = AnimationState::UPPERCUT_LAND;
            currFrame = 0;
        }
    }
    else if (elapsed >= 0.08f && state == AnimationState::FIREBALL)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(fireball_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 4)
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.06f && state == AnimationState::UPPERCUT_LAND)
    {
        player.setPosition(player.getPosition().x, player.getPosition().y + 40);
        elapsed = 0;
        currFrame++;
        if (currFrame == 9)
        {
            currFrame = 0;
            frameIncrement = 1;
            state = AnimationState::FASTIDLE;
        }
        }
    else if (elapsed >= 0.08f && state == AnimationState::CROUCH)
    {
        player.setTextureRect(crouch_frames[currFrame++]);
        elapsed = 0;
        if (currFrame == 2)
            state = AnimationState::CROUCH;

    }
    else if (elapsed >= 0.08f && state == AnimationState::UNCROUCH)
    {
        player.setTextureRect(crouch_frames[currFrame--]);
        elapsed = 0;
        if (currFrame == -1)
        {
            state = AnimationState::FASTIDLE;
            frameIncrement = 1;
            currFrame = 0;
        }
        }

}
void Sagat::setPosition(float x, float y)
{
    player.setPosition(x, y);
}
void Sagat::flipX()
{
    player.setScale(-2.1, 2.1);
}
sf::FloatRect Sagat::getGlobalBounds()
{
    return player.getGlobalBounds();
}
sf::FloatRect Sagat::getLocalBounds()
{
    return player.getLocalBounds();
}

void Sagat::render(sf::RenderWindow& win)
{
    win.draw(player);
}
Sagat::~Sagat()
{
}
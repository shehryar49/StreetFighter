//written by Usman Ali
#include "sagat.h"
#include "constants.h"
#include <stdio.h>
using namespace std;


#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)
#define STOP false
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
sf::IntRect Sagat::crouched_punch1_frames[3];
sf::IntRect Sagat::crouched_punch2_frames[5];
//sf::IntRect Sagat::crouched_kick1_frames[5];

sf::IntRect Sagat::uppercut_frames[10];
sf::IntRect Sagat::fireball_frames[5];


Sagat::Sagat()
{
    img.loadFromFile("assets/sagat.png");
    img.createMaskFromColor(sf::Color(248, 0, 248, 255));
    texture.loadFromImage(img);
    player.setTexture(texture);
    //player.setPosition(100, 100);



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
    crouch_frames[1] = sf::IntRect(610, 211, 97, 70);

    crouched_punch1_frames[0] = sf::IntRect(587, 1102, 92, 69);
    crouched_punch1_frames[1] = sf::IntRect(692, 1103, 140, 69);
    crouched_punch1_frames[2] = sf::IntRect(851, 1102, 92, 69);

    crouched_punch2_frames[0] = sf::IntRect(563, 1229, 92, 80);
    crouched_punch2_frames[1] = sf::IntRect(671, 1232, 88, 77);
    crouched_punch2_frames[2] = sf::IntRect(790, 1249, 140, 57);
    crouched_punch2_frames[3] = sf::IntRect(948, 1249, 31, 35);
    crouched_punch2_frames[4] = sf::IntRect(984, 1248, 43, 39);


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


    gola.setTexture(texture);
    gola.setTextureRect(sf::IntRect(550, 1550, 60, 50));
    gola.setScale(1.2, 1.2);

    player.setTextureRect(IDLE_frames[0]);
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}

void Sagat::moveLeft()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::moveLeft;
        currFrame = -1;
        frameIncrement = 1;
    }
}
void Sagat::moveRight()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::moveRight;
        currFrame = -1;
        frameIncrement = 1;
    }
}
//PUNCHES
void Sagat::punch1()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::PUNCH1;
        currFrame = -1;
        frameIncrement = 1;
    }
    else if (state == AnimationState::CROUCHED)
    {
        state = AnimationState::CROUCHED_PUNCH1;
        currFrame = 0;
        frameIncrement = 1;
    }
}

void Sagat::punch2()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::PUNCH2;
        currFrame = -1;
        frameIncrement = 1;
    }
    else if (state == AnimationState::CROUCHED)
    {
        state = AnimationState::CROUCHED_PUNCH2;
        currFrame = 0;
        frameIncrement = 1;
    }
}

void Sagat::punch3()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::PUNCH3;
        currFrame = 0;
        frameIncrement = 1;
    }
}

//KICKS:

void Sagat::kick1()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::KICK1;
        currFrame = -1;
        frameIncrement = 1;
    }
    /*else if (state == AnimationState::CROUCHED)
    {
        state = AnimationState::CROUCHED_KICK1;
        currFrame = 0;
        frameIncrement = 1;
    }*/
}

void Sagat::kick2()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::KICK2;
        currFrame = 0;
        frameIncrement = 1;
    }
}

void Sagat::kick3()
{
    if (state == AnimationState::IDLE)
    {
        player.setPosition(player.getGlobalBounds().left, BOTTOMY - (120 * PLAYER_SPRITE_Y_SCALE) + 1);
        state = AnimationState::KICK3;
        currFrame = 0;
        frameIncrement = 1;
    }
}

//JUMPING CROUCHING/UNCROUCHING
void Sagat::jump()
{
    if (IS_IDLE)
    {
        state = AnimationState::JMP;
        currFrame = -1;
        frameIncrement = 1;
        pos = player.getPosition();

    }
}

void Sagat::crouch()
{
    if (IS_IDLE)
    {
        state = AnimationState::CROUCH;
        currFrame = 0;
        frameIncrement = 1;
    }
}

void Sagat::uncrouch()
{
    if (state == AnimationState::CROUCHED ||
        state == AnimationState::CROUCH ||
        state == AnimationState::CROUCHED_KICK1 ||
        state == AnimationState::CROUCHED_PUNCH1 ||
        state == AnimationState::CROUCHED_PUNCH2
        )
    {
        state = AnimationState::FASTIDLE;
        currFrame = 0;
        frameIncrement = 1;
    }
}


void Sagat::specialMove1()
{
    if (IS_IDLE)
    {
        state = AnimationState::UPPERCUT;
        currFrame = 0;
        frameIncrement = 1;
    }
}


//Updation based on animation state
void Sagat::update(float dt)
{
    if (STOP)
        return;
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
    else if (elapsed >= (MOVE_TIME) && state == AnimationState::FASTIDLE)
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
        player.setPosition(player.getPosition().x, player.getPosition().y + 30);
        elapsed = 0;
        if (currFrame == 0) // landed
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= (MOVE_TIME) && state == AnimationState::moveRight)
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
    else if (elapsed >= (MOVE_TIME) && state == AnimationState::moveLeft)
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
    else if (elapsed >= MOVE_TIME && state == AnimationState::PUNCH1)
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
    else if (elapsed >= MOVE_TIME && state == AnimationState::PUNCH2)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(punch2_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 4)
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::PUNCH3)
    {
        player.setTextureRect(punch3_frames[currFrame++]);
        elapsed = 0;
        if (currFrame == 4)
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::KICK1)
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
    else if (elapsed >= MOVE_TIME && state == AnimationState::KICK2)
    {
        player.setTextureRect(kick2_frames[currFrame]);
        elapsed = 0;
        currFrame += frameIncrement;

        if (currFrame == 7)
        {
            currFrame = 2;
            frameIncrement = -1;
        }
        else if (currFrame == -1)
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }


    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::KICK3)
    {
        player.setTextureRect(kick3_frames[currFrame++]);
        elapsed = 0;
        if (currFrame == 7) //last frame rendered
        {
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - IDLE_frames[0].height * PLAYER_SPRITE_Y_SCALE + 1);
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::UPPERCUT)
    {
        player.setTextureRect(uppercut_frames[currFrame++]);
        player.setPosition(player.getPosition().x, player.getPosition().y - 40);
        elapsed = 0;
        if (currFrame == 10) //last frame rendered
        {
            state = AnimationState::UPPERCUT_LAND;
            currFrame = 0;
        }
    }
    else if (elapsed >= 0.06f && state == AnimationState::UPPERCUT_LAND)
    {
        player.setPosition(player.getPosition().x, player.getPosition().y + 40);
        elapsed = 0;
        currFrame++;
        if (currFrame == 10)
        {
            currFrame = 0;
            frameIncrement = 1;
            state = AnimationState::FASTIDLE;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::JMP)
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
    else if (elapsed >= MOVE_TIME && state == AnimationState::CROUCH)
    {
        player.setTextureRect(crouch_frames[currFrame++]);
        elapsed = 0;
        if (currFrame == 2)
            state = AnimationState::CROUCHED;

    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::UNCROUCH)
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
    else if (elapsed >= MOVE_TIME && state == AnimationState::FAST_CROUCHED)
    {
        elapsed = 0;
        state = AnimationState::CROUCHED;
        player.setTextureRect(crouch_frames[1]);
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_PUNCH1)
    {
        player.setTextureRect(crouched_punch1_frames[currFrame++]);
        elapsed = 0;
        if (currFrame == 3)
        {
            state = AnimationState::FAST_CROUCHED;
            currFrame = 0;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_PUNCH2)
    {
        player.setTextureRect(crouched_punch2_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if (currFrame == 5)
        {
            frameIncrement = -1;
            currFrame = 2;
        }
        else if (currFrame == -1)
        {
            state = AnimationState::CROUCHED;
            player.setTextureRect(crouch_frames[1]);
        }
    }
    /*else if (elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_KICK1)
    {
        player.setTextureRect(crouched_kick1_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if (currFrame == 5)
        {
            frameIncrement = -1;
            currFrame = 2;
        }
        else if (currFrame == -1)
        {
            state = AnimationState::CROUCHED;
            player.setTextureRect(crouch_frames[1]);
        }
    }*/
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
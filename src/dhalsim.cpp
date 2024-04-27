//dhalsim character class: maryam
#include "dhalsim.h"
#include "constants.h"
#include<iostream>
using namespace std;

#define IS_IDLE (state == AnimationState::IDLE || state == AnimationState::FASTIDLE)
#define STOP false
sf::IntRect Dhalsim::IDLE_frames[6];
sf::IntRect Dhalsim::jmp_frames[6];
sf::IntRect Dhalsim::moveright_frames[7];
sf::IntRect Dhalsim::moveleft_frames[7];
sf::IntRect Dhalsim::punch1_frames[3];
sf::IntRect Dhalsim::punch2_frames[4];
sf::IntRect Dhalsim::punch3_frames[4];
sf::IntRect Dhalsim::kick1_frames[3];
sf::IntRect Dhalsim::kick2_frames[3];
sf::IntRect Dhalsim::kick3_frames[6];
sf::IntRect Dhalsim::crouching_frames[3];
sf::IntRect Dhalsim::crouched_punch1_frames[2];
sf::IntRect Dhalsim::crouched_punch2_frames[4];
sf::IntRect Dhalsim::crouched_kick1_frames[2];
sf::IntRect Dhalsim::block_frames[2];
sf::IntRect Dhalsim::victory1_frames[12];
sf::IntRect Dhalsim::knockout1_frames[4];
sf::IntRect Dhalsim::yogaflame_frames[20];
sf::IntRect Dhalsim::hit_taken_face_frames[2];
sf::IntRect Dhalsim::hit_taken_body_frames[2];

Dhalsim::Dhalsim()
{
    if (!img.loadFromFile("assets/dhalsim.png")) {
        cerr << "Err loading character";
        exit(EXIT_FAILURE);
    }
    img.createMaskFromColor(sf::Color(70, 112, 104, 255));
    texture.loadFromImage(img);
    player.setTexture(texture);

    IDLE_frames[0] = sf::IntRect(10, 0, 80, 110);  //(x-axis,y-axis,width of rect,height of rect)
    IDLE_frames[1] = sf::IntRect(90, 0, 80, 110);
    IDLE_frames[2] = sf::IntRect(90 + 90, 0, 75, 110);
    IDLE_frames[3] = sf::IntRect(90 + 90 + 90, 0, 80, 110);
    IDLE_frames[4] = sf::IntRect(90 + 90 + 90 + 90, 0, 85, 110);
    IDLE_frames[5] = sf::IntRect(90 + 90 + 90 + 90 + 90, 0, 85, 110);

    jmp_frames[0] = sf::IntRect(30, 990, 70, 100);
    jmp_frames[1] = sf::IntRect(30 + 90, 955, 70, 130);
    jmp_frames[2] = sf::IntRect(10 + 90 + 90, 955, 90, 130);
    jmp_frames[3] = sf::IntRect(20 + 90 + 90 + 90, 960, 70, 130);
    jmp_frames[4] = sf::IntRect(20 + 90 + 90 + 90 + 90, 950, 60, 130);
    jmp_frames[5] = sf::IntRect(20 + 90 + 90 + 90 + 90 + 90, 955, 60, 130);

    moveright_frames[0] = sf::IntRect(8 + 0, 125, 90, 110);
    moveright_frames[1] = sf::IntRect(10 + 90 * 1, 125, 90, 110);
    moveright_frames[2] = sf::IntRect(10 + 90 * 2, 125, 90, 110);
    moveright_frames[3] = sf::IntRect(10 + 90 * 3, 125, 90, 110);
    moveright_frames[4] = sf::IntRect(10 + 90 * 4, 125, 90, 110);
    moveright_frames[5] = sf::IntRect(10 + 90 * 5, 125, 90, 110);
    moveright_frames[6] = sf::IntRect(10 + 90 * 6, 125, 90, 110);

    moveleft_frames[0] = sf::IntRect(5 + 700, 125, 95, 110);
    moveleft_frames[1] = sf::IntRect(5 + 700 + 90 * 1, 125, 95, 110);
    moveleft_frames[2] = sf::IntRect(5 + 700 + 90 * 2, 125, 95, 110);
    moveleft_frames[3] = sf::IntRect(5 + 700 + 90 * 3, 125, 95, 110);
    moveleft_frames[4] = sf::IntRect(5 + 700 + 90 * 4, 125, 95, 110);
    moveleft_frames[5] = sf::IntRect(5 + 700 + 90 * 5, 125, 95, 110);
    moveleft_frames[6] = sf::IntRect(5 + 700 + 90 * 6, 125, 95, 110);

    punch1_frames[0] = sf::IntRect(10+0, 250, 100, 110);
    punch1_frames[1] = sf::IntRect(10+100*1, 250, 100, 110);
    punch1_frames[2] = sf::IntRect(10+100*2, 250, 160, 110);

    punch2_frames[0] = sf::IntRect(50 + 90 * 4, 250, 90, 110);
    punch2_frames[1] = sf::IntRect(50 + 90 * 5, 250, 100, 110);
    punch2_frames[2] = sf::IntRect(100 + 50 + 90 * 5, 250, 170, 110);
    punch2_frames[3] = sf::IntRect(170 + 100 + 50 + 90 * 5, 250, 240, 110);

    punch3_frames[0] = sf::IntRect(0, 375, 90, 110);
    punch3_frames[1] = sf::IntRect(90, 375, 100, 110);
    punch3_frames[2] = sf::IntRect(15+90+100, 375, 170, 110);
    punch3_frames[3] = sf::IntRect(15+90+100+170, 375, 240, 110);

    kick1_frames[0] = sf::IntRect(65+15 + 90 + 100 + 170 + 240, 375, 90, 110);
    kick1_frames[1] = sf::IntRect(65+15 + 90 + 100 + 170 + 240 + 90, 375, 130, 110);
    kick1_frames[2] = sf::IntRect(65+15 + 90 + 100 + 170 + 240 + 90 + 130, 375, 190, 110);

    kick2_frames[0] = sf::IntRect(0, 520, 90, 110);
    kick2_frames[1] = sf::IntRect(10+90, 520, 125, 110);
    kick2_frames[2] = sf::IntRect(10+90+125, 505, 200, 125);

    kick3_frames[0] = sf::IntRect(10+90+125+200+50,520,90,110);
    kick3_frames[1] = sf::IntRect(10+90+125+200+50+90,515,90,115);
    kick3_frames[2] = sf::IntRect(10+90+125+200+50+90+90,515,90,115);
    kick3_frames[3] = sf::IntRect(10+90+125+200+50+90+90+90,520,110,110);
    kick3_frames[4] = sf::IntRect(10+90+125+200+50+90+90+90+110,515,210,115);
    kick3_frames[5] = sf::IntRect(10+90+125+200+50+90+90+90+110+210,520,90,110);

    crouching_frames[0] = sf::IntRect(10, 1415, 90, 110);
    crouching_frames[1] = sf::IntRect(10+90*1, 1415, 90, 110);
    crouching_frames[2] = sf::IntRect(10+90*2, 1415, 90, 110);

    crouched_punch1_frames[0] = sf::IntRect(20 + 90+110+160+260, 1530, 90, 110);
    crouched_punch1_frames[1] = sf::IntRect(25 + 90+110+160+260+90, 1530, 130, 110);

    crouched_punch2_frames[0] = sf::IntRect(20, 1530, 90, 110);
    crouched_punch2_frames[1] = sf::IntRect(20 + 90, 1530, 110, 110);
    crouched_punch2_frames[2] = sf::IntRect(20 + 90+110, 1530, 160, 110);
    crouched_punch2_frames[3] = sf::IntRect(20 + 90+110+160, 1530, 210, 110);

    crouched_kick1_frames[0] = sf::IntRect(20 + 90 + 110 + 160 + 260+90+180, 1530, 90, 110);
    crouched_kick1_frames[1] = sf::IntRect(20 + 90 + 110 + 160 + 260 + 90+180+90, 1530, 170, 110);

    block_frames[0] = sf::IntRect(15+16+25+28+20+105+105+105, 2815, 90, 110);
    block_frames[1] = sf::IntRect(15+16+25+28+20+105+105+105+90, 2815, 90, 110);

    victory1_frames[0] = sf::IntRect(15, 2945, 105, 110);
    victory1_frames[1] = sf::IntRect(15+16+105, 2945, 105, 110);
    victory1_frames[2] = sf::IntRect(15+16+25+105+105, 2945, 105, 110);
    victory1_frames[3] = sf::IntRect(15+16+25+28+105+105+105, 2945, 125, 110);
    victory1_frames[4] = sf::IntRect(15+16+25+28+20+105+105+105+125, 2945, 125, 110);
    victory1_frames[5] = sf::IntRect(15+16+25+28+20+20+105+105+105+125+125, 2945, 135, 110);
    victory1_frames[6] = sf::IntRect(15+16+25+28+20+20+10+105+105+105+125+125+135, 2945, 140, 110);
    victory1_frames[7] = sf::IntRect(15+16+25+28+20+20+10+16+105+105+105+125+125+135+140, 2945, 125, 110);
    victory1_frames[8] = sf::IntRect(15+16+25+28+20+20+10+16+18+105+105+105+125+125+135+140+125, 2945, 125, 110);
    victory1_frames[9] = sf::IntRect(22, 3095, 105, 115);
    victory1_frames[10]= sf::IntRect(22 + 16 + 105, 3095, 105, 115);
    victory1_frames[11]= sf::IntRect(22 + 16 + 25 + 105 + 105, 3095, 105, 115);

    knockout1_frames[0] = sf::IntRect(25+90+90+90,2690,135,110);
    knockout1_frames[1] = sf::IntRect(25+25+90+90+90+135,2690,125,110);
    knockout1_frames[2] = sf::IntRect(25+25+25+90+90+90+135+125,2690,125,110);
    knockout1_frames[3] = sf::IntRect(25+25+25+15+90+90+90+135+125+125,2690,90,110);

    yogaflame_frames[0] = sf::IntRect(15,1790,90,110);
    yogaflame_frames[1] = sf::IntRect(15+15+90,1790,90,110);
    yogaflame_frames[2] = sf::IntRect(15+15+10+90+90,1790,90,110);
    yogaflame_frames[3] = sf::IntRect(15+15+10+15+90+90+90,1790,90,110);
    yogaflame_frames[4] = sf::IntRect(15+15+10+15+10+90+90+90+90,1790,90,110);
    yogaflame_frames[5] = sf::IntRect(15+15+10+15+10+15+90+90+90+90+90,1790,90,110);
    yogaflame_frames[6] = sf::IntRect(15+15+10+15+10+15+15+90+90+90+90+90+90,1790,100,110);
    yogaflame_frames[7] = sf::IntRect(15+15+10+15+10+15+15+15+90+90+90+90+90+90+100,1790,145,110);
    yogaflame_frames[8] = sf::IntRect(15+15+10+15+10+15+15+15+15+90+90+90+90+90+90+100+145,1790,150,110);
    yogaflame_frames[9] = sf::IntRect(15+15+10+15+10+15+15+15+15+15+90+90+90+90+90+90+100+145+150,1790,165,110);
    yogaflame_frames[10] =sf::IntRect(15, 1920, 170, 110);
    yogaflame_frames[11] =sf::IntRect(15+15+170, 1920, 175, 110);
    yogaflame_frames[12] =sf::IntRect(15+15+15+170+175, 1920, 180, 110);
    yogaflame_frames[13] =sf::IntRect(15+15+15+15+170+175+180, 1920, 180, 110);
    yogaflame_frames[14] =sf::IntRect(15+15+15+15+15+170+175+180+180, 1920, 175, 110);
    yogaflame_frames[15] =sf::IntRect(15+15+15+15+15+20+170+175+180+180+175, 1920, 175, 110);
    yogaflame_frames[16] =sf::IntRect(15+15+15+15+15+20+15+170+175+180+180+175+175, 1920, 170, 110);
    yogaflame_frames[17] =sf::IntRect(15, 2050, 165, 110);
    yogaflame_frames[18] =sf::IntRect(15+30+165, 2050, 155, 110);
    yogaflame_frames[19] =sf::IntRect(15+30+10+165+155, 2050, 155, 110);

    hit_taken_face_frames[0]= sf::IntRect(110 + 90 + 90 + 90, 2565, 90, 110);
    hit_taken_face_frames[1]= sf::IntRect(110 + 90 + 90 + 90 + 90, 2565, 90, 110);

    hit_taken_body_frames[0] = sf::IntRect(115 + 90+ 90 + 90 + 90+90, 2565, 90, 110);
    hit_taken_body_frames[1] = sf::IntRect(15+115 + 90 + 90 + 90 + 90+90+90, 2565, 90, 110);
                                   
    player.setTextureRect(IDLE_frames[0]);
    player.setScale(sf::Vector2f(PLAYER_SPRITE_X_SCALE, PLAYER_SPRITE_Y_SCALE));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}
bool Dhalsim::processEvent(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::BackSpace) {
            currFrame = 0;
            frameIncrement = 1;
            player.setPosition(player.getPosition().x, 365);
            player.setTextureRect(IDLE_frames[0]);
            state = AnimationState::IDLE;
        }
        if (state == AnimationState::IDLE) {
            //if (event.key.code == sf::Keyboard::Num1) {
            //    hit_taken_blanka_electricity();
            //    return true;
            //}
            if (event.key.code == sf::Keyboard::Num2) {
                hit_taken_face();
                return true;
            }
            //else if (event.key.code == sf::Keyboard::Num3) {
            //    hit_taken_body();
            //    return true;
            //}
            //else if (event.key.code == sf::Keyboard::Num4) {
            //    heavy_hit_taken_body();
            //    return true;
            //}
            //else if (event.key.code == sf::Keyboard::Num6) {
            //    face_body_combo_taken();
            //    return true;
            //}
            else if (event.key.code == sf::Keyboard::Num7) {
                knockout(1);
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num8) {
                victory(1);
                return true;
            }
            //else if (event.key.code == sf::Keyboard::Num9) {
            //    victory(2);
            //    return true;
            //}
            //else if (event.key.code == sf::Keyboard::Enter) {
            //    knockout(2);
            //    return true;
            //}
        }
        //else if (state == AnimationState::CROUCHING) {
        //    if (event.key.code == sf::Keyboard::Num5) {
        //        crouch_face_hit_taken();
        //        return true;
        //    }
        //}
    }
    return false;
}
bool Dhalsim::jump()
{
    if (IS_IDLE)
    {
        state = AnimationState::JMP;
        currFrame = -1;
        frameIncrement = 1;
        pos = player.getPosition();
        return true;

    }
    return false;
}
void Dhalsim::moveRight(float f)
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::moveRight;
        currFrame = -1;
        frameIncrement = 1;
        limit = f;
    }
}
void Dhalsim::flippedMoveRight(float f) {
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::flipped_move_right;
        currFrame = -1;
        frameIncrement = 1;
        limit = f;
    }
}
void Dhalsim::moveLeft(float f)
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::moveLeft;
        currFrame = -1;
        frameIncrement = 1;
        limit = f;
    }
}
void Dhalsim::flippedMoveLeft(float f) {
    if (state == AnimationState::IDLE) 
    {
        state = AnimationState::flipped_move_left;
        currFrame = -1;
        frameIncrement = 1;
        limit = f;
    }
}
bool Dhalsim::crouch()
{
    if (IS_IDLE)
    {
        state = AnimationState::CROUCHING;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}
bool Dhalsim::uncrouch()
{
    if (state == AnimationState::CROUCHED ||
        state == AnimationState::CROUCHING ||
        state == AnimationState::CROUCHED_KICK1 ||
        state == AnimationState::CROUCHED_PUNCH1 ||
        state == AnimationState::CROUCHED_PUNCH2
        )
    {
        state = AnimationState::FASTIDLE;
        currFrame = -1;
        frameIncrement = 1;
        elapsed = 0;
        return true;
    }
    return false;
}
bool Dhalsim::block()
{
    if (IS_IDLE)
    {
        state = AnimationState::BLOCKING;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}
bool Dhalsim::unblock()
{
    if (state == AnimationState::BLOCKED)
    {
        state = AnimationState::FASTIDLE;
        currFrame = -1;
        frameIncrement = 1;
        elapsed = 0;
        return true;
    }
    return false;
}
bool Dhalsim::punch1()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::PUNCH1;
        currFrame = -1;
        frameIncrement = 1;
        return true;
    }
    else if (state == AnimationState::CROUCHED)
    {
        state = AnimationState::CROUCHED_PUNCH1;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}
bool Dhalsim::punch2()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::PUNCH2;
        currFrame = -1;
        frameIncrement = 1;
        return true;
    }
    else if (state == AnimationState::CROUCHED)
    {
        state = AnimationState::CROUCHED_PUNCH2;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}

bool Dhalsim::punch3()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::PUNCH3;
        currFrame = -1;
        frameIncrement = 1;
        return true;
    }
    return false;
}

bool Dhalsim::kick1()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::KICK1;
        currFrame = -1;
        frameIncrement = 1;
        return true;
    }
    else if (state == AnimationState::CROUCHED)
    {
        state = AnimationState::CROUCHED_KICK1;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}

bool Dhalsim::kick2()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::KICK2;
        currFrame = -1;
        frameIncrement = 1;
        return true;
    }
    return false;
}
bool Dhalsim::kick3()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::KICK3;
        currFrame = 0;
        frameIncrement = 1;
        return true;
    }
    return false;
}
bool Dhalsim::specialMove1()
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::YOGA_FLAME;
        currFrame = -1;
        frameIncrement = 1;
        return true;
    }
    return true;
}
void Dhalsim::victory(int type=1) //to be set for winning condition
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::VICTORY_1;
        currFrame = -1;
        frameIncrement = 1;
    }
}
void Dhalsim::knockout(int type = 1) //to be set when bar becomes empty
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::KNOCKOUT_1;
        currFrame = 4;
        frameIncrement = 1;
    }
}
void Dhalsim::hit_taken_face() //to be set for hit face condition
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::HIT_TAKEN_FACE;
        currFrame = -1;
        frameIncrement = 1;
    }
}
void Dhalsim::bodyHit() //to be set for body hit condition
{
    if (state == AnimationState::IDLE)
    {
        state = AnimationState::HIT_TAKEN_BODY;
        currFrame = -1;
        frameIncrement = 1;
    }
}
void Dhalsim::update(float dt)
{
    elapsed += dt;
    if ((elapsed >= (IDLE_TIME)) && state == AnimationState::IDLE)
    {
        if (currFrame == 0)
            frameIncrement = 1;
        else if (currFrame == 5)
            frameIncrement = -1;
        currFrame = (currFrame + frameIncrement);
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
    else if ((elapsed >= (0.3)) && state == AnimationState::VICTORY_1)
    {
        if (currFrame == 0)
            frameIncrement = 1;
        else if (currFrame == 11)
            frameIncrement = -1;
        currFrame = (currFrame + frameIncrement);
        player.setTextureRect(victory1_frames[currFrame]);
        elapsed = 0;
    }
    else if (elapsed >= 0.15f && state == AnimationState::JMP)
    {
        currFrame++;
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x, player.getPosition().y - 30);
        elapsed = 0;
        if (currFrame == 5) //last frame rendered
        {
            currFrame = 2;
            state = AnimationState::LAND;
        }
    }
    else if (elapsed >= (0.2f) && state == AnimationState::LAND)
    {
        currFrame--;
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x, player.getPosition().y + 90);
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
        if (player.getPosition().x + 150 < limit) // window width is 800
            player.setPosition(player.getPosition().x + 10, player.getPosition().y);
        if (currFrame == 5)
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
        if (player.getPosition().x - 20 > limit) // window width is 800
            player.setPosition(player.getPosition().x - 10, player.getPosition().y);
        if (currFrame == 5)
        {
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= (MOVE_TIME) && state == AnimationState::flipped_move_left)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(moveright_frames[currFrame]);
        elapsed = 0;
        if (player.getPosition().x - player.getGlobalBounds().width - 20 > limit) // window width is 800
            player.setPosition(player.getPosition().x - 10, player.getPosition().y);
        if (currFrame == 5)
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= (MOVE_TIME) && state == AnimationState::flipped_move_right)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(moveleft_frames[currFrame]);
        elapsed = 0;
        if (player.getPosition().x + 20 < limit) // window width is 800
            player.setPosition(player.getPosition().x + 10, player.getPosition().y);
        if (currFrame == 5)
        {
            state = AnimationState::FASTIDLE;
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
            state = AnimationState::RETREAT1;
        }
    }
    else if (elapsed >= (0.2f) && state == AnimationState::RETREAT1)
    {
        currFrame--;
        player.setTextureRect(punch1_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 1) 
        {
            state = AnimationState::FASTIDLE;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::PUNCH2)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(punch2_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 3)
        {
            state = AnimationState::RETREAT2;
        }
    }
    else if (elapsed >= (0.2f) && state == AnimationState::RETREAT2)
    {
        currFrame--;
        player.setTextureRect(punch2_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 1) 
        {
            state = AnimationState::FASTIDLE;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::PUNCH3)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(punch3_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 3)
        {
            state = AnimationState::RETREAT3;
        }
    }
    else if (elapsed >= (0.2f) && state == AnimationState::RETREAT3)
    {
        currFrame--;
        player.setTextureRect(punch3_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 1) 
        {
            state = AnimationState::FASTIDLE;
        }
    }
    else if (elapsed >= 0.15 && state == AnimationState::KICK1)
    {
        currFrame++;
        player.setTextureRect(kick1_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 2) //last frame rendered
        {
            state = AnimationState::FASTIDLE_ATTACKING;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.15 && state == AnimationState::KICK2)
    {
        currFrame++;
        player.setTextureRect(kick2_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 2) //last frame rendered
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.13 && state == AnimationState::KICK3)
    {
        currFrame++;
        player.setTextureRect(kick3_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 5) //last frame rendered
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::BLOCKING)
    {
        player.setTextureRect(block_frames[currFrame++]);
        elapsed = 0;
        if (currFrame == 2)
            state = AnimationState::BLOCKED;

    }
    //else if (elapsed >= MOVE_TIME && state == AnimationState::BLOCKED) //UNCROUCH_TIMER define then use
    //{
    //    state = AnimationState::UNBLOCKING;
    //    currFrame = 0;
    //    frameIncrement = 1;
    //    elapsed = 0;
    //}
    //else if (elapsed >= MOVE_TIME && state == AnimationState::UNBLOCKING)
    //{
    //    player.setTextureRect(block_frames[currFrame--]);
    //    elapsed = 0;
    //    if (currFrame == -1)
    //    {
    //        state = AnimationState::FASTIDLE;
    //        frameIncrement = 1;
    //        currFrame = 0;
    //    }
    //}
    else if (elapsed >= MOVE_TIME && state == AnimationState::CROUCHING)
    {
        player.setTextureRect(crouching_frames[currFrame++]);
        elapsed = 0;
        if (currFrame == 3)
            state = AnimationState::CROUCHED;

    }
    //else if (elapsed >= MOVE_TIME && state == AnimationState::CROUCHED) //UNCROUCH_TIMER
    //{
    //    state = AnimationState::UNCROUCHING;
    //    currFrame = 0;
    //    frameIncrement = 1;
    //    elapsed = 0;
    //}
    //else if (elapsed >= MOVE_TIME && state == AnimationState::UNCROUCHING)
    //{
    //    player.setTextureRect(crouching_frames[currFrame--]);
    //    elapsed = 0;
    //    if (currFrame == -1)
    //    {
    //        state = AnimationState::FASTIDLE;
    //        frameIncrement = 1;
    //        currFrame = 0;
    //    }
    //}
    else if(elapsed >= MOVE_TIME && state == AnimationState::FAST_CROUCHED)
    {
        elapsed = 0;
        state = AnimationState::CROUCHED;
        player.setTextureRect(crouching_frames[2]);
    }
    else if(elapsed >= MOVE_TIME && state == AnimationState::CROUCHED_PUNCH1)
    {
        player.setTextureRect(crouched_punch1_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if(currFrame == 1)
        {
            frameIncrement = -1;
            currFrame = 1;
        }
        else if(currFrame == -1)
        {
            state = AnimationState::CROUCHED;
            player.setTextureRect(crouching_frames[2]);
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
            currFrame = 3;
        }
        else if(currFrame == -1)
        {
            state = AnimationState::CROUCHED;
            player.setTextureRect(crouching_frames[2]);
        }
    }
    else if(elapsed >= 0.2 && state == AnimationState::CROUCHED_KICK1)
    {
        player.setTextureRect(crouched_kick1_frames[currFrame]);
        currFrame += frameIncrement;
        elapsed = 0;
        if(currFrame == 1)
        {
            frameIncrement = -1;
            currFrame = 1;
        }
        else if(currFrame == -1)
        {
            state = AnimationState::CROUCHED;
            player.setTextureRect(crouching_frames[2]);
        }
    }
    else if (elapsed >= MOVE_TIME && state == AnimationState::YOGA_FLAME)
    {
        currFrame++;
        player.setTextureRect(yogaflame_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 19) //last frame rendered
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if ((elapsed >= (MOVE_TIME)) && state == AnimationState::KNOCKOUT_1)
    {
        if (currFrame == 0)
        {
            frameIncrement = 0;
        }
        else if (currFrame == 4)
            frameIncrement = -1;
        currFrame = (currFrame + frameIncrement);
        player.setTextureRect(knockout1_frames[currFrame]);
        elapsed = 0;
    }
    else if (elapsed >= 0.2 && state == AnimationState::HIT_TAKEN_FACE)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(hit_taken_face_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 1)
        {
            state = AnimationState::FASTIDLE;
        }
    }
    else if (elapsed >= 0.2 && state == AnimationState::HIT_TAKEN_BODY)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(hit_taken_body_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 1)
        {
            state = AnimationState::FASTIDLE;
        }
    }
}
void Dhalsim::setPosition(float x, float y)
{
    player.setPosition(x, y);
}
void Dhalsim::render(sf::RenderWindow& win)
{
    win.draw(player);
}
void Dhalsim::flipX()
{
    player.setScale(-2.1, 2.1);
}
sf::FloatRect Dhalsim::getGlobalBounds()
{
    return player.getGlobalBounds();
}
sf::FloatRect Dhalsim::getLocalBounds()
{
    return player.getLocalBounds();
}
bool Dhalsim::isIdle() {
    return state == AnimationState::IDLE;
}
bool Dhalsim::isSuffering()
{
    return state == AnimationState::HIT_TAKEN_BODY;
}
bool Dhalsim::isAttacking()
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
Dhalsim::~Dhalsim()
{
}

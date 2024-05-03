//~Isbah - knowckout wav yet to be converted
#include "zangief.h"
#include "constants.h"
#include<iostream>
using namespace std;

#define IS_IDLE (curr_state == AnimationState::idle)

sf::IntRect Zangief::idle_frames[4];
sf::IntRect Zangief::move_right_frames[6];
sf::IntRect Zangief::move_left_frames[6];
sf::IntRect Zangief::light_punch_frames[4];
sf::IntRect Zangief::medium_punch_frames[7];
sf::IntRect Zangief::forward_light_punch_frames[7];
sf::IntRect Zangief::forward_medium_punch_frames[7];
sf::IntRect Zangief::crouch_light_punch_frames[2];
sf::IntRect Zangief::crouch_medium_punch_frames[5];
sf::IntRect Zangief::light_kick_frames[4];
sf::IntRect Zangief::medium_kick_frames[5];
sf::IntRect Zangief::heavy_kick_frames[3];
sf::IntRect Zangief::crouch_kick_frames[3];
sf::IntRect Zangief::jump_frames[7];
sf::IntRect Zangief::forward_light_kick_frames[5];
sf::IntRect Zangief::forward_heavy_kick_frames[9];
sf::IntRect Zangief::hit_taken_body_frames[3];
sf::IntRect Zangief::special_move[5];
sf::IntRect Zangief::victory1_frames[1];
sf::IntRect Zangief::victory2_frames[3];
sf::IntRect Zangief::victory3_frames[9];
sf::IntRect Zangief::knockout_frames[14];


Zangief::Zangief(){
    if(!image.loadFromFile("assets/zangief.png")){
        cerr<<"Err loading character";
        exit(EXIT_FAILURE);
    }//spritesheet
    image.createMaskFromColor(sf::Color(84,118,135,255));//removing background colour (84,118,135,255) //prev: (67,70,181,255)
    texture.loadFromImage(image);
    player.setTexture(texture);

    idle_frames[0] = sf::IntRect(15, 22, 102, 111);
    idle_frames[1] = sf::IntRect(123, 22, 95, 111);
    idle_frames[2] = sf::IntRect(223, 22, 95, 111);
    idle_frames[3] = sf::IntRect(320, 22, 94, 111);

    move_right_frames[0] = sf::IntRect(16, 175, 100, 111);
    move_right_frames[1] = sf::IntRect(120, 175, 95, 111);
    move_right_frames[2] = sf::IntRect(220, 175, 93, 111);
    move_right_frames[3] = sf::IntRect(320, 175, 100, 111);
    move_right_frames[4] = sf::IntRect(428, 175, 91, 111);
    move_right_frames[5] = sf::IntRect(524, 175, 90, 111);

    move_left_frames[0] = sf::IntRect(660,175, 95, 111);
    move_left_frames[1] = sf::IntRect(758,175, 91, 111);
    move_left_frames[2] = sf::IntRect(855,175, 85, 113); 
    move_left_frames[3] = sf::IntRect(949,172, 95, 113);
    move_left_frames[4] = sf::IntRect(1050,172, 87, 113);
    move_left_frames[5] = sf::IntRect(1142,172, 92, 113);

    light_punch_frames[0] = sf::IntRect(16,329,100,111);
    light_punch_frames[1] = sf::IntRect(125,329,130,111);
    light_punch_frames[2] = sf::IntRect(262,329,100,111);
    light_punch_frames[3] = sf::IntRect(370,329,103,111);

    forward_light_punch_frames[0] = sf::IntRect(520, 327, 102, 113);
    forward_light_punch_frames[1] = sf::IntRect(628, 329, 103, 111);
    forward_light_punch_frames[2] = sf::IntRect(738, 329, 134, 111);
    forward_light_punch_frames[3] = sf::IntRect(881, 329, 102, 111);
    forward_light_punch_frames[4] = sf::IntRect(738, 329, 134, 111);
    forward_light_punch_frames[5] = sf::IntRect(628, 329, 103, 111);
    forward_light_punch_frames[6] = sf::IntRect(520, 327, 102, 113);

    medium_punch_frames[0] = sf::IntRect(16,479,80,112);
    medium_punch_frames[1] = sf::IntRect(101,481,101,111);
    medium_punch_frames[2] = sf::IntRect(210,481,130,111);
    medium_punch_frames[3] = sf::IntRect(345,481,112,111);
    medium_punch_frames[4] = sf::IntRect(465,481,130,111);
    medium_punch_frames[5] = sf::IntRect(603,481,102,111);
    medium_punch_frames[6] = sf::IntRect(710,479,82,112);

    light_kick_frames[0] = sf::IntRect(14, 648, 95, 120);
    light_kick_frames[1] = sf::IntRect(116, 648, 91, 120);
    light_kick_frames[2] = sf::IntRect(212, 648, 122, 120);
    light_kick_frames[3] = sf::IntRect(116, 648, 91, 120);

    medium_kick_frames[0] = sf::IntRect(380, 648, 98, 120);
    medium_kick_frames[1] = sf::IntRect(483, 648, 101, 120);
    medium_kick_frames[2] = sf::IntRect(591, 648, 128, 120);
    medium_kick_frames[3] = sf::IntRect(483, 648, 101, 120);
    medium_kick_frames[4] = sf::IntRect(380, 648, 98, 120);

    heavy_kick_frames[0] = sf::IntRect(978, 648, 88, 120);
    heavy_kick_frames[1] = sf::IntRect(1072, 648, 147, 120);
    heavy_kick_frames[2] = sf::IntRect(1227, 648, 88, 120);

    forward_medium_punch_frames[0] = sf::IntRect(14,804,90,126);
    forward_medium_punch_frames[1] = sf::IntRect(109,810,110,118);
    forward_medium_punch_frames[2] = sf::IntRect(227,810,134,118);
    forward_medium_punch_frames[3] = sf::IntRect(367,810,117,118);
    forward_medium_punch_frames[4] = sf::IntRect(494,810,131,118);
    forward_medium_punch_frames[5] = sf::IntRect(634,810,112,118);
    forward_medium_punch_frames[6] = sf::IntRect(749,804,115,126);

    crouch_light_punch_frames[0] = sf::IntRect(12,2235,90,80);
    crouch_light_punch_frames[1] = sf::IntRect(102,2227,123,90);

    crouch_medium_punch_frames[0] = sf::IntRect(275,2225,90,90);
    crouch_medium_punch_frames[1] = sf::IntRect(365,2225,95,90);
    crouch_medium_punch_frames[2] = sf::IntRect(460,2225,125,90);
    crouch_medium_punch_frames[3] = sf::IntRect(585,2225,95,90);
    crouch_medium_punch_frames[4] = sf::IntRect(680,2225,95,90);

    crouch_kick_frames[0] = sf::IntRect(810,2225,105,90);
    crouch_kick_frames[1] = sf::IntRect(912,2220,153,95);
    crouch_kick_frames[2] = sf::IntRect(1067,2225,105,90);

    jump_frames[0] = sf::IntRect(435,2535,107,120);
    jump_frames[1] = sf::IntRect(550,2531,107,111);
    jump_frames[2] = sf::IntRect(664,2543,110,101);
    jump_frames[3] = sf::IntRect(781,2555,125,90);
    jump_frames[4] = sf::IntRect(664,2543,110,101);
    jump_frames[5] = sf::IntRect(550,2531,107,111);
    jump_frames[6] = sf::IntRect(435,2535,107,120);

    forward_light_kick_frames[0] = sf::IntRect(14, 1137, 89, 124);
    forward_light_kick_frames[1] = sf::IntRect(110, 1137, 100, 124);
    forward_light_kick_frames[2] = sf::IntRect(215, 1137, 135, 124);
    forward_light_kick_frames[3] = sf::IntRect(357, 1137, 103, 124);
    forward_light_kick_frames[4] = sf::IntRect(465, 1137, 93, 124);

    forward_heavy_kick_frames[0] = sf::IntRect(14, 1307, 92, 111);
    forward_heavy_kick_frames[1] = sf::IntRect(112, 1307, 80, 111);
    forward_heavy_kick_frames[2] = sf::IntRect(197, 1307, 83, 111);
    forward_heavy_kick_frames[3] = sf::IntRect(286, 1307, 98, 111);
    forward_heavy_kick_frames[4] = sf::IntRect(390, 1307, 105, 111);
    forward_heavy_kick_frames[5] = sf::IntRect(500, 1299, 125, 119);
    forward_heavy_kick_frames[6] = sf::IntRect(630, 1329, 124, 85);
    forward_heavy_kick_frames[7] = sf::IntRect(760, 1332, 93, 83);
    forward_heavy_kick_frames[8] = sf::IntRect(860, 1329, 96, 85);

    hit_taken_body_frames[0] = sf::IntRect(262, 4270, 100, 111);
    hit_taken_body_frames[1] = sf::IntRect(367, 4270, 112, 111);
    hit_taken_body_frames[2] = sf::IntRect(262, 4270, 100, 111);

    special_move[0] = sf::IntRect(14, 6785, 100, 120);
    special_move[1] = sf::IntRect(120, 6785, 67, 120);
    special_move[2] = sf::IntRect(189, 6785, 127, 120);
    special_move[3] = sf::IntRect(318, 6785, 65, 120);
    special_move[4] = sf::IntRect(387, 6788, 145, 120);

    victory1_frames[0] = sf::IntRect(14, 7168, 100, 120);

    victory2_frames[0] = sf::IntRect(160, 7125, 100, 160);
    victory2_frames[1] = sf::IntRect(260, 7125, 100, 160);
    victory2_frames[2] = sf::IntRect(360, 7125, 100, 160);

    victory3_frames[0] = sf::IntRect(501, 7168, 100, 119);
    victory3_frames[1] = sf::IntRect(603, 7168, 100, 119);
    victory3_frames[2] = sf::IntRect(705, 7168, 100, 119);
    victory3_frames[3] = sf::IntRect(804, 7168, 100, 119);
    victory3_frames[4] = sf::IntRect(903, 7168, 100, 119);
    victory3_frames[5] = sf::IntRect(1002, 7168, 100, 119);
    victory3_frames[6] = sf::IntRect(1101, 7168, 100, 119);
    victory3_frames[7] = sf::IntRect(1200, 7168, 100, 119);
    victory3_frames[8] = sf::IntRect(1299, 7168, 100, 119);

    knockout_frames[0] = sf::IntRect(14, 4588, 120, 107);
    knockout_frames[1] = sf::IntRect(14, 4975, 120, 80);
    knockout_frames[2] = sf::IntRect(134, 4596, 130, 100);
    knockout_frames[3] = sf::IntRect(264, 4810, 127, 70);
    knockout_frames[4] = sf::IntRect(394, 4810, 115, 70);
    knockout_frames[5] = sf::IntRect(264, 4810, 127, 70);
    knockout_frames[6] = sf::IntRect(394, 4810, 115, 70);
    knockout_frames[7] = sf::IntRect(648, 4810, 145, 70);
    knockout_frames[8] = sf::IntRect(755, 5900, 147, 50);
    knockout_frames[9] = sf::IntRect(667, 5566, 150, 45);
    knockout_frames[10] = sf::IntRect(815, 5528, 125, 100);
    knockout_frames[11] = sf::IntRect(945, 5528, 103, 100);
    knockout_frames[12] = sf::IntRect(1045, 5528, 97, 100);
    knockout_frames[13] = sf::IntRect(1143, 5500, 110, 111);

    player.setTextureRect(idle_frames[0]);
    player.setScale(sf::Vector2f(PLAYER_SPRITE_X_SCALE,PLAYER_SPRITE_Y_SCALE));
    curr_state = AnimationState::idle;
}

//movements
void Zangief::moveRight(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_right;
        limit = bound - player.getGlobalBounds().width;
    }
}
void Zangief::flippedMoveRight(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::flipped_move_right;
        limit = 500;//bound;
    }
}
void Zangief::moveLeft(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_left;
        limit = bound;
    }
}
void Zangief::flippedMoveLeft(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::flipped_move_left;
        limit = 500; 
    }
}
bool Zangief::jump() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::jump;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::jump_forward;
        return true;
    }
    else if (curr_state == AnimationState::move_left) {
        curr_frame = 0;
        curr_state = AnimationState::jump_backward;
        return true;
    }
    return false;
}
bool Zangief::crouch() {
    if (curr_state == AnimationState::idle) {
        curr_state = AnimationState::crouching;
        setPosition(player.getPosition().x, player.getPosition().y + 67);
        player.setTextureRect(sf::IntRect(234, 2720, 91, 79));
        return true;
    }
    return false;
}
bool Zangief::uncrouch() {
    if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        setPosition(player.getPosition().x, player.getPosition().y - 67);
        player.setTextureRect(idle_frames[curr_frame]);
        curr_state = AnimationState::idle;
        return true;
    }
    return false;
}
//hits dealt
bool Zangief::punch1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::light_punch_right;
        return true;
    }
    else if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        curr_state = AnimationState::crouch_light_punch;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_light_punch;
        return true;
    }
    return false;
}
bool Zangief::punch2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::medium_punch_right;
        return true;
    }
    else if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        curr_state = AnimationState::crouch_medium_punch;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_medium_punch;
        return true;
    }
    return false;
}
bool Zangief::kick1() {

    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::light_kick;
        return true;
    }
    else if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        curr_state = AnimationState::crouch_kick;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_light_kick;
        return true;
    }
    return false;
}
bool Zangief::kick2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::medium_kick;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_heavy_kick;
        return true;
    }
    return false;
}
bool Zangief::kick3() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::heavy_kick;
        return true;
    }
    return false;
}
bool Zangief::specialMove1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        count = 0;
        curr_state = AnimationState::special_move;
        return true;
    }
    return false;
}
void Zangief::bodyHit() {
    curr_frame = 0;
    curr_state = AnimationState::hit_taken_body;
}
void Zangief::victory(int type) {
    switch (type) {
    case 1:
        setPosition(player.getPosition().x, player.getPosition().y - 20);
        player.setTextureRect(victory1_frames[0]);
        curr_state = AnimationState::still;
        break;
    case 2:
        curr_frame = 0;
        count = 0;
        curr_state = AnimationState::victory_2;
        break;
    case 3:
        curr_frame = 0;
        curr_state = AnimationState::victory_3;
        break;
    }
}
void Zangief::knockout(bool* game_over){
    game_is_over = game_over;
    knockout(2);
}
void Zangief::knockout(int type) {
    switch (type) {
    case 1:
        curr_frame = 0;
        curr_state = AnimationState::knockout;
        break;
    case 2:
        curr_frame = 0;
        if(player.getScale().x < 0)
            curr_state = AnimationState::defeat_enemy;
        else
            curr_state = AnimationState::defeat_player;
        break;
    }
}
void Zangief::update(float time){
    time_elapsed += time;
    if (time_elapsed >= IDLE_TIME && curr_state == AnimationState::idle) {
        curr_frame = curr_frame + incr_to_next_frame;
        player.setTextureRect(idle_frames[curr_frame]);
        if (!curr_frame)
            incr_to_next_frame = 1;
        else if (curr_frame == 3)
            incr_to_next_frame = -1;
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 4)
                setPosition(player.getPosition().x, player.getPosition().y - 50);
            else if (curr_frame > 3 && curr_frame < 7)
                setPosition(player.getPosition().x, player.getPosition().y + 50);
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_forward) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 4)
            {
                if (player.getPosition().x + 25 <= 570)
                    setPosition(player.getPosition().x + 25, player.getPosition().y - 50);
                else 
                    setPosition(570, player.getPosition().y - 50);
            }
            else if (curr_frame > 3 && curr_frame < 7)
            {
                if(player.getPosition().x + 50 <= 570)
                    setPosition(player.getPosition().x + 50, player.getPosition().y + 50);
                else
                    setPosition(570, player.getPosition().y + 50);
            }
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::move_right) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 10 <= limit)
                setPosition(player.getPosition().x + 10, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
            player.setTextureRect(move_right_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::flipped_move_right) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 10 <= limit)
                setPosition(player.getPosition().x + 10, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
            player.setTextureRect(move_left_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::move_left) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x - 10 >= limit)
                setPosition(player.getPosition().x - 10, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
            player.setTextureRect(move_left_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::flipped_move_left) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x - 10 >= limit)
                setPosition(player.getPosition().x - 10, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
            player.setTextureRect(move_right_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::light_punch_right) {
        if (curr_frame == 4) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(light_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_light_punch) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(forward_light_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::medium_punch_right) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(medium_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::light_kick) {
        if (curr_frame == 4) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(light_kick_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::medium_kick) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(medium_kick_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::heavy_kick) {
        if (curr_frame == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(heavy_kick_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_medium_punch) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(forward_medium_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_light_punch) {
        if (curr_frame == 2)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                player.setTextureRect(sf::IntRect(234, 2720, 91, 79));
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
                curr_state = AnimationState::idle;
            }
        else {
            player.setTextureRect(crouch_light_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_medium_punch) {
        if (curr_frame == 5)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                player.setTextureRect(sf::IntRect(234, 2720, 91, 79));
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
                curr_state = AnimationState::idle;
            }
        else {
            player.setTextureRect(crouch_medium_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_kick) {
        if (curr_frame == 3)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                player.setTextureRect(sf::IntRect(234, 2720, 91, 79));
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            }
        else {
            player.setTextureRect(crouch_kick_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_light_kick) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 10 <= 570)
                setPosition(player.getPosition().x + 10, player.getPosition().y);
            player.setTextureRect(forward_light_kick_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_heavy_kick) {
        if (curr_frame == 9) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 10 <= 570)
                setPosition(player.getPosition().x + 10, player.getPosition().y);
            player.setTextureRect(forward_heavy_kick_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_backward) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 4){
                if (player.getPosition().x - 50 >= 0)
                    setPosition(player.getPosition().x - 50, player.getPosition().y - 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y - 50);
            }
            else if (curr_frame > 3 && curr_frame < 7){
                if (player.getPosition().x - 25 >= 0)
                    setPosition(player.getPosition().x - 25, player.getPosition().y + 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y + 50);
            }
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::hit_taken_body) {
        if (curr_frame == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(hit_taken_body_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::special_move) {
        if (curr_frame == 5 && count == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            setPosition(player.getPosition().x + 70, player.getPosition().y + 18);
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (!curr_frame)
                setPosition(player.getPosition().x, player.getPosition().y - 18);
            if (curr_frame == 5) {
                curr_frame = 1;
                setPosition(player.getPosition().x + 70, player.getPosition().y);
                count++;
                
            }
            if (curr_frame == 4 && player.getPosition().x - 70 <= 570)
                setPosition(player.getPosition().x - 70, player.getPosition().y);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (player.getPosition().x + 20 <= 570)
                    setPosition(player.getPosition().x + 20, player.getPosition().y);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (player.getPosition().x - 20 >= 0)
                    setPosition(player.getPosition().x - 20, player.getPosition().y);
            }
            player.setTextureRect(special_move[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.16f && curr_state == AnimationState::victory_2) {
        if (curr_frame == 3 && count == 3) {
            curr_state = AnimationState::still;
        }
        else {
            if (curr_frame == 3) {
                curr_frame = 1;
                count++;
            }
            player.setTextureRect(victory2_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.16f && curr_state == AnimationState::victory_3) {
        if (curr_frame == 9) {
            curr_state = AnimationState::still;
        }
        else {
            player.setTextureRect(victory3_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::knockout) {
        if (curr_frame == 14) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if ((curr_frame > 0 && curr_frame < 8) && player.getPosition().x - 40 >= 0)
                setPosition(player.getPosition().x - 60, player.getPosition().y);
            if (curr_frame == 2)
                setPosition(player.getPosition().x, player.getPosition().y - 36);
            else if (curr_frame == 3)
                setPosition(player.getPosition().x, player.getPosition().y + 136);
            else if (curr_frame == 4 || curr_frame == 6)
                setPosition(player.getPosition().x, 450);
            else if (curr_frame == 5)
                setPosition(player.getPosition().x, player.getPosition().y - 40);
            else if (curr_frame == 8)
                setPosition(player.getPosition().x, 500);
            else if (curr_frame == 10)
                setPosition(player.getPosition().x, player.getPosition().y - 78);
            else if (curr_frame == 13)
                setPosition(player.getPosition().x, player.getPosition().y - 57);
            player.setTextureRect(knockout_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::defeat_player) {
        if (curr_frame == 9) {
            curr_state = AnimationState::still;
        }
        else {
            if ((curr_frame > 0 && curr_frame < 8) && player.getPosition().x - 40 >= 0)
                setPosition(player.getPosition().x - 60, player.getPosition().y);
            if (curr_frame == 2)
                setPosition(player.getPosition().x, player.getPosition().y - 36);
            else if (curr_frame == 3)
                setPosition(player.getPosition().x, player.getPosition().y + 136);
            else if (curr_frame == 4 || curr_frame == 6)
                setPosition(player.getPosition().x, 450);
            else if (curr_frame == 5)
                setPosition(player.getPosition().x, player.getPosition().y - 40);
            else if (curr_frame == 8)
                setPosition(player.getPosition().x, 500);
            player.setTextureRect(knockout_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::defeat_enemy) {
        if (curr_frame == 9) {
            curr_state = AnimationState::still;
        }
        else {
            if ((curr_frame > 0 && curr_frame < 8) && player.getPosition().x + 60 <= WINDOW_WIDTH)
                setPosition(player.getPosition().x + 60, player.getPosition().y);
            if (curr_frame == 2)
                setPosition(player.getPosition().x, player.getPosition().y - 36);
            else if (curr_frame == 3)
                setPosition(player.getPosition().x, player.getPosition().y + 136);
            else if (curr_frame == 4 || curr_frame == 6)
                setPosition(player.getPosition().x, 450);
            else if (curr_frame == 5)
                setPosition(player.getPosition().x, player.getPosition().y - 40);
            else if (curr_frame == 8)
                setPosition(player.getPosition().x, 500);
            player.setTextureRect(knockout_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
}
void Zangief::setPosition(float x,float y){
    player.setPosition(x,y);
}
void Zangief::flipX(){
    player.setScale(-PLAYER_SPRITE_X_SCALE,PLAYER_SPRITE_Y_SCALE);
}
bool Zangief::isIdle() {
    return IS_IDLE;
}
bool Zangief::isSuffering(){
    return (curr_state==AnimationState::hit_taken_body);
}

bool Zangief::isAttacking(){
    return (curr_state==AnimationState::crouch_kick || curr_state==AnimationState::crouch_light_punch || curr_state==AnimationState::crouch_medium_punch || curr_state==AnimationState::forward_heavy_kick || curr_state==AnimationState::forward_light_kick || curr_state==AnimationState::forward_light_punch || curr_state==AnimationState::forward_medium_punch || curr_state==AnimationState::heavy_kick || curr_state==AnimationState::light_kick || curr_state==AnimationState::light_punch_right || curr_state==AnimationState::medium_kick || curr_state==AnimationState::medium_punch_right || curr_state==AnimationState::special_move);
}
void Zangief::render(sf::RenderWindow &window){
    window.draw(player);
}
sf::FloatRect Zangief::getGlobalBounds(){
    return player.getGlobalBounds();
}
sf::Vector2f Zangief::getPosition(){
    return player.getPosition();
}
Zangief::~Zangief(){
}
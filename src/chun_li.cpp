//~Isbah
#include "chun_li.h"
#include <iostream>
using namespace std;

sf::IntRect Chun_Li::idle_frames[4];
sf::IntRect Chun_Li::move_right_frames[12];
sf::IntRect Chun_Li::move_left_frames[12];
sf::IntRect Chun_Li::jump_frames[9];
sf::IntRect Chun_Li::punch1_frames[5];
sf::IntRect Chun_Li::punch3_frames[5];
sf::IntRect Chun_Li::punch5_frames[5];
sf::IntRect Chun_Li::kick1_frames[5];
sf::IntRect Chun_Li::kick2_frames[5];
sf::IntRect Chun_Li::kick4_frames[5];
sf::IntRect Chun_Li::victory1_frames[1];
sf::IntRect Chun_Li::victory2_frames[5];
sf::IntRect Chun_Li::victory3_frames[16];
sf::IntRect Chun_Li::hit_taken_body3_frames[7];
sf::IntRect Chun_Li::knockout_frames[12];
sf::IntRect Chun_Li::special1_frames[12];

Chun_Li::Chun_Li(){
    if(!image.loadFromFile("assets/chun-li.png")){
        cerr<<"Err loading character";
    }//spritesheet
    image.createMaskFromColor(sf::Color(24,140,140,255));//removing background colour (24,140,140,255)
    texture.loadFromImage(image);
    
    player.setTexture(texture);
    
    idle_frames[0] = sf::IntRect(15, 31, 74, 90);
    idle_frames[1] = sf::IntRect(95, 31, 74, 90);
    idle_frames[2] = sf::IntRect(175, 31, 74, 90);
    idle_frames[3] = sf::IntRect(255, 31, 74, 90);

    move_right_frames[0] = sf::IntRect(15, 160, 79, 90);
    move_right_frames[1] = sf::IntRect(101, 160, 72, 90);
    move_right_frames[2] = sf::IntRect(180, 158, 67, 92);
    move_right_frames[3] = sf::IntRect(251, 158, 65, 92);
    move_right_frames[4] = sf::IntRect(321, 159, 71, 91);
    move_right_frames[5] = sf::IntRect(397, 159, 77, 91);
    move_right_frames[6] = sf::IntRect(480, 159, 84, 91);
    move_right_frames[7] = sf::IntRect(569, 159, 79, 91);
    move_right_frames[8] = sf::IntRect(653, 159, 69, 91);
    move_right_frames[9] = sf::IntRect(729, 158, 64, 92);
    move_right_frames[10] = sf::IntRect(798, 159, 68, 91);
    move_right_frames[11] = sf::IntRect(868, 159, 74, 91);

    move_left_frames[0] = sf::IntRect(14, 290, 77, 90);
    move_left_frames[1] = sf::IntRect(95, 289, 65, 91);
    move_left_frames[2] = sf::IntRect(167, 287, 63, 93);
    move_left_frames[3] = sf::IntRect(235, 287, 65, 93);
    move_left_frames[4] = sf::IntRect(306, 288, 66, 91);
    move_left_frames[5] = sf::IntRect(378, 289, 67, 91);
    move_left_frames[6] = sf::IntRect(450, 290, 74, 90);
    move_left_frames[7] = sf::IntRect(529, 289, 68, 91);
    move_left_frames[8] = sf::IntRect(604, 288, 67, 92);
    move_left_frames[9] = sf::IntRect(676, 287, 65, 93);
    move_left_frames[10] = sf::IntRect(747, 288, 63, 92);
    move_left_frames[11] = sf::IntRect(815, 289, 65, 91);

    jump_frames[0] = sf::IntRect(14, 2360, 77, 90);
    jump_frames[1] = sf::IntRect(97, 2337, 49, 113);
    jump_frames[2] = sf::IntRect(152, 2363, 52, 87);
    jump_frames[3] = sf::IntRect(210, 2371, 54, 80);
    jump_frames[4] = sf::IntRect(270, 2379, 59, 73);
    jump_frames[5] = sf::IntRect(210, 2371, 54, 80);
    jump_frames[6] = sf::IntRect(152, 2363, 52, 87);
    jump_frames[7] = sf::IntRect(97, 2337, 49, 113);
    jump_frames[8] = sf::IntRect(14, 2360, 77, 90);
    
    punch1_frames[0] = sf::IntRect(14,425,82,92);
    punch1_frames[1] = sf::IntRect(100,425,104,92);
    punch1_frames[2] = sf::IntRect(210,415,87,102);
    punch1_frames[3] = sf::IntRect(100, 425, 104, 92);
    punch1_frames[4] = sf::IntRect(14, 425, 82, 92);

    punch3_frames[0] = sf::IntRect(14, 558, 105, 89);
    punch3_frames[1] = sf::IntRect(125, 558, 120, 89);
    punch3_frames[2] = sf::IntRect(250, 558, 132, 89);
    punch3_frames[3] = sf::IntRect(125, 558, 120, 89);
    punch3_frames[4] = sf::IntRect(14, 558, 105, 89);

    punch5_frames[0] = sf::IntRect(14, 685, 77, 94);
    punch5_frames[1] = sf::IntRect(97, 685, 77, 94);
    punch5_frames[2] = sf::IntRect(180, 685, 84, 94);
    punch5_frames[3] = sf::IntRect(97, 685, 77, 94);
    punch5_frames[4] = sf::IntRect(14, 685, 77, 94);

    kick1_frames[0] = sf::IntRect(10,955, 73, 100);
    kick1_frames[1] = sf::IntRect(89, 955, 75, 98);
    kick1_frames[2] = sf::IntRect(160, 950, 117, 103);
    kick1_frames[3] = sf::IntRect(89, 955, 75, 98);
    kick1_frames[4] = sf::IntRect(10, 955, 73, 100);

    kick2_frames[0] = sf::IntRect(10, 955, 73, 100);
    kick2_frames[1] = sf::IntRect(89, 955, 75, 98);
    kick2_frames[2] = sf::IntRect(628, 950, 117, 103);
    kick2_frames[3] = sf::IntRect(89, 955, 75, 98);
    kick2_frames[4] = sf::IntRect(10, 955, 73, 100);

    kick4_frames[0] = sf::IntRect(14, 1095, 98, 100);
    kick4_frames[1] = sf::IntRect(116, 1095, 91, 100);
    kick4_frames[2] = sf::IntRect(210, 1095, 70, 100);
    kick4_frames[3] = sf::IntRect(116, 1095, 91, 100);
    kick4_frames[4] = sf::IntRect(14, 1095, 98, 100);

    hit_taken_body3_frames[0] = sf::IntRect(520, 4287, 77, 95);
    hit_taken_body3_frames[1] = sf::IntRect(600, 4287, 77, 95);
    hit_taken_body3_frames[2] = sf::IntRect(679, 4287, 77, 95);
    hit_taken_body3_frames[3] = sf::IntRect(762, 4287, 77, 95);
    hit_taken_body3_frames[4] = sf::IntRect(679, 4287, 77, 95);
    hit_taken_body3_frames[5] = sf::IntRect(600, 4287, 77, 95);
    hit_taken_body3_frames[6] = sf::IntRect(520, 4287, 77, 95);

    victory1_frames[0] = sf::IntRect(14, 4132, 80, 100);

    victory2_frames[0] = sf::IntRect(135, 3962, 80, 103);
    victory2_frames[1] = sf::IntRect(214, 3962, 80, 103);
    victory2_frames[2] = sf::IntRect(290, 3962, 80, 103);
    victory2_frames[3] = sf::IntRect(366, 3962, 80, 103);
    victory2_frames[4] = sf::IntRect(442, 3962, 80, 103);

    victory3_frames[0] = sf::IntRect(14, 4100, 80, 132);
    victory3_frames[1] = sf::IntRect(94, 4100, 75, 132);
    victory3_frames[2] = sf::IntRect(165, 4100, 65, 132);
    victory3_frames[3] = sf::IntRect(228, 4100, 80, 132);
    victory3_frames[4] = sf::IntRect(310, 4100, 85, 132);
    victory3_frames[5] = sf::IntRect(392, 4100, 80, 132);
    victory3_frames[6] = sf::IntRect(310, 4100, 85, 132);
    victory3_frames[7] = sf::IntRect(228, 4100, 80, 132);
    victory3_frames[8] = sf::IntRect(637, 4100, 55, 132); //left
    victory3_frames[9] = sf::IntRect(693, 4100, 55, 132); //front
    victory3_frames[10] = sf::IntRect(749, 4100, 55, 132);//right
    victory3_frames[11] = sf::IntRect(693, 4100, 55, 132);
    victory3_frames[12] = sf::IntRect(637, 4100, 55, 132);
    victory3_frames[13] = sf::IntRect(693, 4100, 55, 132);
    victory3_frames[14] = sf::IntRect(749, 4100, 55, 132);
    victory3_frames[15] = sf::IntRect(1029, 4100, 60, 132);


    knockout_frames[0] = sf::IntRect(14, 4287, 80, 95);
    knockout_frames[1] = sf::IntRect(96, 4287, 80, 95);
    knockout_frames[2] = sf::IntRect(179, 4287, 91, 95);
    knockout_frames[3] = sf::IntRect(14, 4808, 130, 75);
    knockout_frames[4] = sf::IntRect(146, 4838, 130, 50);
    knockout_frames[5] = sf::IntRect(280, 4812, 100, 70);
    knockout_frames[6] = sf::IntRect(381, 4838, 130, 45);
    knockout_frames[7] = sf::IntRect(512, 4818, 130, 65);
    knockout_frames[8] = sf::IntRect(645, 4838, 143, 45);
    knockout_frames[9] = sf::IntRect(590, 4953, 140, 50);
    knockout_frames[10] = sf::IntRect(730, 4928, 110, 75);
    knockout_frames[11] = sf::IntRect(847, 4908, 80, 95);

    special1_frames[0] = sf::IntRect(14, 1525, 70, 107);
    special1_frames[1] = sf::IntRect(89, 1525, 73, 107);
    special1_frames[2] = sf::IntRect(169, 1525, 109, 107);
    special1_frames[3] = sf::IntRect(284, 1525, 124, 107);
    special1_frames[4] = sf::IntRect(415, 1525, 120, 107);
    special1_frames[5] = sf::IntRect(542, 1525, 139, 107);
    special1_frames[6] = sf::IntRect(686, 1525, 122, 107);
    special1_frames[7] = sf::IntRect(814, 1525, 152, 107);
    special1_frames[8] = sf::IntRect(975, 1525, 104, 107);
    special1_frames[9] = sf::IntRect(1084, 1525, 139, 107);
    special1_frames[10] = sf::IntRect(89, 1525, 73, 107);
    special1_frames[11] = sf::IntRect(14, 1525, 70, 107);

    player.setTextureRect(idle_frames[0]);//IntRect(left,top,width,height)
    player.setScale(sf::Vector2f(2.1, 2.1));
    curr_state = AnimationState::idle;
    curr_frame = 1;
    incr_to_next_frame = 1;
}
void Chun_Li::moveRight(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_right;
        limit = bound - player.getGlobalBounds().width;
    }
}
void Chun_Li::flippedMoveRight(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::flipped_move_right;
        limit = bound;
    }
}
void Chun_Li::moveLeft(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_left;
        limit = bound;
    }
}
void Chun_Li::flippedMoveLeft(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::flipped_move_left;
        limit = bound;
    }
}
bool Chun_Li::specialMove1() {
    if (curr_state == AnimationState::idle) {
        count = 0;
        curr_frame = 0;
        curr_state = AnimationState::special1;
        return true;
    }
    return false;
}
bool Chun_Li::isIdle() {
    return curr_state == AnimationState::idle;
}
bool Chun_Li::crouch() {
    if (curr_state == AnimationState::idle) {
        player.setTextureRect(sf::IntRect(179, 2012, 73, 69));
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::crouch;
        return true;
    }
    return true;
}
bool Chun_Li::uncrouch() {
    if (curr_state == AnimationState::crouch) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
        return true;
    }
    return false;
}
bool Chun_Li::jump() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::jump;
        return true;
    }
    if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::jump_right;
        return true;
    }
    if (curr_state == AnimationState::move_left) {
        curr_frame = 0;
        curr_state = AnimationState::jump_left;
        return true;
    }
    return false;
}
bool Chun_Li::punch1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::punch5;
        return true;
    }
    return false;
}
bool Chun_Li::punch2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::punch1;
        return true;
    }
    return false;
}
bool Chun_Li::punch3() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::punch3;
        return true;
    }
    return false;
}
bool Chun_Li::kick2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::kick1;
        return true;
    }
    return false;
}
bool Chun_Li::kick1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::kick4;
        return true;
    }
    return false;
}
bool Chun_Li::kick3() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::kick2;
        return true;
    }
    return false;
}
void Chun_Li::victory(int type) {
    switch (type) {
    case 1:
        player.setTextureRect(victory1_frames[0]);
        player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::still;
        break;
    case 2:
        curr_frame = 0;
        curr_state = AnimationState::victory2;
        break;
    case 3:
        curr_frame = 0;
        count = 0;
        curr_state = AnimationState::victory3;
    }
}
void Chun_Li::bodyHit(){
    curr_frame = 0;
    curr_state = AnimationState::hit_taken_body1;
}
void Chun_Li::knockout(bool* game_over){
    this->game_is_over = game_over;
    knockout(2);
}
void Chun_Li::knockout(int type) {
    switch (type) {
    case 1:
        curr_frame = 0;
        curr_state = AnimationState::knockout;
        break;
    case 2:
        curr_frame = 0;
        if (player.getScale().x < 0)
            curr_state = AnimationState::defeat_enemy;
        else
            curr_state = AnimationState::defeat_player;
    }
}
void Chun_Li::update(float time){
    time_elapsed += time;
    if (time_elapsed >= 0.8f && curr_state == AnimationState::idle){
        curr_frame += incr_to_next_frame;
        player.setTextureRect(idle_frames[curr_frame]);
        if (curr_frame == 0)
            incr_to_next_frame = 1;
        else if (curr_frame == 3)
            incr_to_next_frame = -1;
        time_elapsed = 0;//reset condition
        return;
    }
    if (time_elapsed >= MOVE_TIME/2.0 && curr_state == AnimationState::move_right) {
        if (curr_frame == 12) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 5 <= limit)
                setPosition(player.getPosition().x + 5, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
            player.setTextureRect(move_right_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME / 2.0 && curr_state == AnimationState::flipped_move_left) {
        if (curr_frame == 12) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x - 5 >= limit)
                setPosition(player.getPosition().x - 5, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
            player.setTextureRect(move_right_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME/2.0 && curr_state == AnimationState::move_left) {
        if (curr_frame == 12) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x - 5 >= limit)
                setPosition(player.getPosition().x - 5, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
           player.setTextureRect(move_left_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME / 2.0 && curr_state == AnimationState::flipped_move_right) {
        if (curr_frame == 12) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 5 <= limit)
                setPosition(player.getPosition().x + 5, player.getPosition().y);
            else
                setPosition(limit, player.getPosition().y);
            player.setTextureRect(move_left_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump) {
        if (curr_frame == 9) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if(curr_frame > 0 && curr_frame < 5)
                setPosition(player.getPosition().x, player.getPosition().y - 50);
            else if(curr_frame > 4)
                setPosition(player.getPosition().x, player.getPosition().y + 50);
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_right) {
        if (curr_frame == 9) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 5)
                setPosition(player.getPosition().x, player.getPosition().y - 50);
            else if (curr_frame > 4)
                setPosition(player.getPosition().x, player.getPosition().y + 50);
            if(player.getPosition().x + 40 <= 700)
                setPosition(player.getPosition().x + 40, player.getPosition().y);
            else
                setPosition(700, player.getPosition().y);
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_left) {
        if (curr_frame == 9) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 5)
                setPosition(player.getPosition().x, player.getPosition().y - 50);
            else if (curr_frame > 4)
                setPosition(player.getPosition().x, player.getPosition().y + 50);
            if (player.getPosition().x - 40 >=  0)
                setPosition(player.getPosition().x - 40, player.getPosition().y);
            else
                setPosition(0, player.getPosition().y);
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::hit_taken_body1) {
        if (curr_frame == 3) {
            curr_frame = 0;
            incr_to_next_frame = 0;
            player.setTextureRect(idle_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(hit_taken_body3_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::punch1) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(punch1_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::punch3) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(punch3_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::punch5) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(punch5_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::kick1) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(kick1_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::victory2) {
        if (curr_frame == 5) {
            //AnimationState::still;
        }
        else {
            player.setTextureRect(victory2_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::victory3) {
        if (curr_frame == 16) {
            //AnimationState::still;
        }
        else {
            player.setTextureRect(victory3_frames[curr_frame++]);
            if (curr_frame == 3 && count == 1)
                player.setPosition(player.getPosition().x + 15, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 4)
                player.setPosition(player.getPosition().x - 15, BOTTOMY - player.getGlobalBounds().height);
            else if (curr_frame == 9)
                player.setPosition(player.getPosition().x + 20, BOTTOMY - player.getGlobalBounds().height);
            else if (curr_frame == 5)
                player.setPosition(player.getPosition().x, player.getPosition().y - 100);
            else if (curr_frame == 6)
                player.setPosition(player.getPosition().x, player.getPosition().y);
            else if (curr_frame == 7)
                player.setPosition(player.getPosition().x, player.getPosition().y + 100);
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 7 && count == 0) {
                curr_frame = 2;
                count++;
            }
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::kick2) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(kick2_frames[curr_frame++]);
            if(curr_frame == 3)
                player.setPosition(player.getPosition().x - 35, BOTTOMY - player.getGlobalBounds().height);
            else if (curr_frame == 4)
                player.setPosition(player.getPosition().x + 35, BOTTOMY - player.getGlobalBounds().height);
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::kick4) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(kick4_frames[curr_frame++]);
            if (curr_frame == 3)
                player.setPosition(player.getPosition().x + 45, BOTTOMY - player.getGlobalBounds().height);
            else if (curr_frame == 4)
                player.setPosition(player.getPosition().x - 45, BOTTOMY - player.getGlobalBounds().height);
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::knockout) {
        if (curr_frame == 12) {
            curr_frame = 0;
            incr_to_next_frame = 0;
            player.setTextureRect(idle_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(knockout_frames[curr_frame++]);
            if (curr_frame < 9)
            {
                if (player.getPosition().x - 50 >= 0)
                    player.setPosition(player.getPosition().x - 50, player.getPosition().y);
                else
                    player.setPosition(0, player.getPosition().y);
            }
            if(curr_frame < 5 || curr_frame == 7)
                player.setPosition(player.getPosition().x, player.getPosition().y - 20);
            else if (curr_frame == 5)
                player.setPosition(player.getPosition().x, player.getPosition().y + 60);
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::defeat_player) {
        if (curr_frame == 9) {
            curr_state = AnimationState::still;
            *game_is_over = true;
        }
        else {
            player.setTextureRect(knockout_frames[curr_frame++]);
            if (curr_frame < 9)
            {
                if (player.getPosition().x - 50 >= 0)
                    player.setPosition(player.getPosition().x - 50, player.getPosition().y);
                else
                    player.setPosition(0, player.getPosition().y);
            }
            if (curr_frame < 5 || curr_frame == 7)
                player.setPosition(player.getPosition().x, player.getPosition().y - 20);
            else if (curr_frame == 5)
                player.setPosition(player.getPosition().x, player.getPosition().y + 60);
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::defeat_enemy) {
        if (curr_frame == 9) {
            curr_state = AnimationState::still;
            *game_is_over = true;
        }
        else {
            player.setTextureRect(knockout_frames[curr_frame++]);
            if (curr_frame < 9)
            {
                if (player.getPosition().x + 50 <= WINDOW_WIDTH)
                    player.setPosition(player.getPosition().x + 50, player.getPosition().y);
                else
                    player.setPosition(player.getPosition().x, player.getPosition().y);
            }
            if (curr_frame < 5 || curr_frame == 7)
                player.setPosition(player.getPosition().x, player.getPosition().y - 20);
            else if (curr_frame == 5)
                player.setPosition(player.getPosition().x, player.getPosition().y + 60);
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= MOVE_TIME/1.5 && curr_state == AnimationState::special1) {
        if (curr_frame == 12) {
            curr_frame = 0;
            player.setTextureRect(idle_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(special1_frames[curr_frame++]);
            if (curr_frame == 1)
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 3 && !count)
                player.setPosition(player.getPosition().x - 30, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 10 && count < 2) {
                curr_frame = 2;
                count++;
            }
            else if (curr_frame == 11 && count >= 2)
                player.setPosition(player.getPosition().x + 30, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
}
void Chun_Li::render(sf::RenderWindow &window){
    window.draw(player);
}
void Chun_Li::setPosition(float x, float y) {
    player.setPosition(x, y);
}
bool Chun_Li::isAttacking(){
    return (curr_state==AnimationState::kick1 || curr_state==AnimationState::kick2 || curr_state==AnimationState::kick4||
    curr_state==AnimationState::punch1 || curr_state==AnimationState::punch3 || curr_state==AnimationState::punch5 ||
    curr_state==AnimationState::special1);
}
bool Chun_Li::isSuffering(){
    return (curr_state==AnimationState::hit_taken_body1);
}
sf::FloatRect Chun_Li::getLocalBounds(){
    return player.getLocalBounds();
}
sf::FloatRect Chun_Li::getGlobalBounds(){
    return player.getGlobalBounds();
}
sf::Vector2f Chun_Li::getPosition() {
    return player.getPosition();
}
void Chun_Li::flipX() {
    player.setScale(-2.1,2.1);
}
Chun_Li::~Chun_Li(){}
//~Isbah
#include "balrog.h"
#include<iostream>
using namespace std;

sf::IntRect Balrog::idle_frames[6];
sf::IntRect Balrog::move_frames[6];
sf::IntRect Balrog::light_punch_frames[3];
sf::IntRect Balrog::medium_punch_frames[3];
sf::IntRect Balrog::heavy_punch_frames[3];
sf::IntRect Balrog::alt_light_punch_frames[3];
sf::IntRect Balrog::alt_medium_punch_frames[5];
sf::IntRect Balrog::alt_heavy_punch_frames[5];
sf::IntRect Balrog::jump_frames[7];
sf::IntRect Balrog::jump_punch_frames[9];
sf::IntRect Balrog::crouch_light_punch_frames[5];
sf::IntRect Balrog::crouch_medium_punch_frames[5];
sf::IntRect Balrog::special_move1[9];
sf::IntRect Balrog::special_move2[11];
sf::IntRect Balrog::light_hit_taken_face_frames[1];
sf::IntRect Balrog::hit_taken_face_frames[5];
sf::IntRect Balrog::hit_taken_body_frames[1];
sf::IntRect Balrog::medium_hit_taken_body_frames[3];
sf::IntRect Balrog::heavy_hit_taken_body_frames[5];
sf::IntRect Balrog::face_body_combo_taken_frames[8];

sf::IntRect Balrog::forward_light_punch_frames[7];
sf::IntRect Balrog::forward_medium_punch_frames[7];
sf::IntRect Balrog::hit_taken_blanka_electricity_frames[2];
sf::IntRect Balrog::crouch_face_hit_taken_frames[3];
sf::IntRect Balrog::victory1_frames[1];
sf::IntRect Balrog::victory2_frames[3];
sf::IntRect Balrog::victory3_frames[9];
sf::IntRect Balrog::knockout_frames[14];

Balrog::Balrog() {
    if (!image.loadFromFile("assets/Balrog.png")) {
        cerr << "Err loading character";
        exit(EXIT_FAILURE);
    }//spritesheet
    image.createMaskFromColor(sf::Color(149, 155, 149));
    texture.loadFromImage(image);
    player.setTexture(texture);

    idle_frames[0] = sf::IntRect(15, 220, 63, 112);
    idle_frames[1] = sf::IntRect(85, 220, 63, 112);
    idle_frames[2] = sf::IntRect(155, 220, 63, 112);
    idle_frames[3] = sf::IntRect(225, 220, 63, 112);
    idle_frames[4] = sf::IntRect(295, 220, 63, 112);
    idle_frames[5] = sf::IntRect(365, 220, 63, 112);

    move_frames[0] = sf::IntRect(15, 370,63, 112);
    move_frames[1] = sf::IntRect(85, 370, 63, 112);
    move_frames[2] = sf::IntRect(155, 370, 63, 112);
    move_frames[3] = sf::IntRect(225, 370, 63, 112);
    move_frames[4] = sf::IntRect(295, 370, 63, 112);
    move_frames[5] = sf::IntRect(365, 370, 63, 112);

    light_punch_frames[0] = sf::IntRect(14, 1297, 67, 111);
    light_punch_frames[1] = sf::IntRect(86, 1297, 83, 111);
    light_punch_frames[2] = sf::IntRect(14, 1297, 67, 111);

    medium_punch_frames[0] = sf::IntRect(15, 1148, 92, 111);
    medium_punch_frames[1] = sf::IntRect(113, 1128, 113, 131);
    medium_punch_frames[2] = sf::IntRect(15, 1148, 92, 111);

    heavy_punch_frames[0] = sf::IntRect(412, 833, 115, 107);
    heavy_punch_frames[1] = sf::IntRect(525, 833, 145, 107);
    heavy_punch_frames[2] = sf::IntRect(412, 833, 115, 107);

    alt_light_punch_frames[0] = sf::IntRect(15, 540, 79, 112);
    alt_light_punch_frames[1] = sf::IntRect(98, 540, 115, 112);
    alt_light_punch_frames[2] = sf::IntRect(15, 540, 79, 112);

    alt_medium_punch_frames[0] = sf::IntRect(15, 683, 82, 112);
    alt_medium_punch_frames[1] = sf::IntRect(102, 683, 112, 111);
    alt_medium_punch_frames[2] = sf::IntRect(217, 683, 190, 111);
    alt_medium_punch_frames[3] = sf::IntRect(102, 683, 112, 111);
    alt_medium_punch_frames[4] = sf::IntRect(15, 683, 82, 111);

    alt_heavy_punch_frames[0] = sf::IntRect(344, 540, 89, 112);
    alt_heavy_punch_frames[1] = sf::IntRect(436, 540, 115, 112);
    alt_heavy_punch_frames[2] = sf::IntRect(550, 518, 145, 134);
    alt_heavy_punch_frames[3] = sf::IntRect(436, 540, 115, 112);
    alt_heavy_punch_frames[4] = sf::IntRect(344, 540, 89, 112);

    jump_frames[0] = sf::IntRect(14, 1975, 67, 97);
    jump_frames[1] = sf::IntRect(84, 1971, 67, 100);
    jump_frames[2] = sf::IntRect(154, 1925, 67, 80);
    jump_frames[3] = sf::IntRect(224, 1925, 67, 66);
    jump_frames[4] = sf::IntRect(154, 1925, 67, 80);
    jump_frames[5] = sf::IntRect(84, 1971, 67, 100);
    jump_frames[6] = sf::IntRect(14, 1975, 67, 97);

    jump_punch_frames[0] = sf::IntRect(14, 2112, 67, 97);
    jump_punch_frames[1] = sf::IntRect(84, 2108, 67, 101);
    jump_punch_frames[2] = sf::IntRect(155, 2130, 80, 78);
    jump_punch_frames[3] = sf::IntRect(404, 2125, 100, 84);
    jump_punch_frames[4] = sf::IntRect(340, 2125, 60, 88);
    jump_punch_frames[5] = sf::IntRect(404, 2125, 100, 84);
    jump_punch_frames[6] = sf::IntRect(155, 2130, 80, 78);
    jump_punch_frames[7] = sf::IntRect(84, 2108, 67, 101);
    jump_punch_frames[8] = sf::IntRect(14, 2112, 67, 97);

    crouch_light_punch_frames[0] = sf::IntRect(12, 1805, 57, 80);
    crouch_light_punch_frames[1] = sf::IntRect(74, 1805, 75, 80);
    crouch_light_punch_frames[2] = sf::IntRect(154, 1805, 140, 80);
    crouch_light_punch_frames[3] = sf::IntRect(74, 1805, 75, 80);
    crouch_light_punch_frames[4] = sf::IntRect(12, 1805, 57, 80);

    crouch_medium_punch_frames[0] = sf::IntRect(480, 1805, 67, 80);
    crouch_medium_punch_frames[1] = sf::IntRect(546, 1798, 92, 87);
    crouch_medium_punch_frames[2] = sf::IntRect(642, 1753, 115, 132);
    crouch_medium_punch_frames[3] = sf::IntRect(546, 1798, 92, 87);
    crouch_medium_punch_frames[4] = sf::IntRect(480, 1805, 67, 80);

    special_move1[0] = sf::IntRect(14, 2270, 90, 108);
    special_move1[1] = sf::IntRect(110, 2270, 101, 108);
    special_move1[2] = sf::IntRect(214, 2283, 190, 95);
    special_move1[3] = sf::IntRect(410, 2267, 90, 111);
    special_move1[4] = sf::IntRect(506, 2267, 68, 111);
    special_move1[5] = sf::IntRect(617, 2270, 72, 108);
    special_move1[6] = sf::IntRect(690, 2270, 117, 108);
    special_move1[7] = sf::IntRect(808, 2248, 132, 130);
    special_move1[8] = sf::IntRect(946, 2270, 93, 108);

    special_move2[0] = sf::IntRect(14, 2425, 56, 103);
    special_move2[1] = sf::IntRect(72, 2425, 64, 103);
    special_move2[2] = sf::IntRect(140, 2430, 80, 98);
    special_move2[3] = sf::IntRect(225, 2445, 91, 83);
    special_move2[4] = sf::IntRect(322, 2425, 53, 103);
    special_move2[5] = sf::IntRect(380, 2423, 76, 105);
    special_move2[6] = sf::IntRect(461, 2420, 93, 108);
    special_move2[7] = sf::IntRect(555, 2420, 101, 108);
    special_move2[8] = sf::IntRect(663, 2433, 187, 95);
    special_move2[9] = sf::IntRect(855, 2415, 89, 113);
    special_move2[10] = sf::IntRect(952, 2415, 67, 113);

    light_hit_taken_face_frames[0] = sf::IntRect(14, 2717, 68, 118);

    hit_taken_face_frames[0] = sf::IntRect(14, 2717, 68, 118);
    hit_taken_face_frames[1] = sf::IntRect(202, 2717, 75, 118);
    hit_taken_face_frames[2] = sf::IntRect(281, 2717, 78, 118);
    hit_taken_face_frames[3] = sf::IntRect(202, 2717, 75, 118);
    hit_taken_face_frames[4] = sf::IntRect(14, 2717, 68, 118);

    hit_taken_body_frames[0] = sf::IntRect(400, 2737, 68, 98);
    
    medium_hit_taken_body_frames[0] = sf::IntRect(400, 2737, 68, 98);
    medium_hit_taken_body_frames[1] = sf::IntRect(770, 2737, 72, 98);
    medium_hit_taken_body_frames[2] = sf::IntRect(400, 2737, 68, 98);

    heavy_hit_taken_body_frames[0] = sf::IntRect(400, 2737, 68, 98);
    heavy_hit_taken_body_frames[1] = sf::IntRect(770, 2737, 72, 98);
    heavy_hit_taken_body_frames[2] = sf::IntRect(847, 2742, 75, 98);
    heavy_hit_taken_body_frames[3] = sf::IntRect(770, 2737, 72, 98);
    heavy_hit_taken_body_frames[4] = sf::IntRect(400, 2737, 68, 98);

    face_body_combo_taken_frames[0] = sf::IntRect(14, 2717, 68, 118);
    face_body_combo_taken_frames[1] = sf::IntRect(202, 2717, 75, 118);
    face_body_combo_taken_frames[2] = sf::IntRect(14, 2717, 68, 118);
    face_body_combo_taken_frames[3] = sf::IntRect(400, 2737, 68, 98);
    face_body_combo_taken_frames[4] = sf::IntRect(770, 2737, 72, 98);
    face_body_combo_taken_frames[5] = sf::IntRect(847, 2742, 75, 98);
    face_body_combo_taken_frames[6] = sf::IntRect(770, 2737, 72, 98);
    face_body_combo_taken_frames[7] = sf::IntRect(400, 2737, 68, 98);

    forward_light_punch_frames[0] = sf::IntRect(520, 327, 102, 113);
    forward_light_punch_frames[1] = sf::IntRect(628, 329, 103, 111);
    forward_light_punch_frames[2] = sf::IntRect(738, 329, 134, 111);
    forward_light_punch_frames[3] = sf::IntRect(881, 329, 102, 111);
    forward_light_punch_frames[4] = sf::IntRect(738, 329, 134, 111);
    forward_light_punch_frames[5] = sf::IntRect(628, 329, 103, 111);
    forward_light_punch_frames[6] = sf::IntRect(520, 327, 102, 113);

    forward_medium_punch_frames[0] = sf::IntRect(14, 804, 90, 126);
    forward_medium_punch_frames[1] = sf::IntRect(109, 810, 110, 125);
    forward_medium_punch_frames[2] = sf::IntRect(227, 810, 134, 125);
    forward_medium_punch_frames[3] = sf::IntRect(367, 810, 117, 125);
    forward_medium_punch_frames[4] = sf::IntRect(494, 810, 131, 125);
    forward_medium_punch_frames[5] = sf::IntRect(634, 810, 112, 125);
    forward_medium_punch_frames[6] = sf::IntRect(749, 804, 115, 126);

    hit_taken_blanka_electricity_frames[0] = sf::IntRect(124, 5821, 115, 130);
    hit_taken_blanka_electricity_frames[1] = sf::IntRect(14, 5826, 105, 125);

    crouch_face_hit_taken_frames[0] = sf::IntRect(152, 4452, 97, 92);
    crouch_face_hit_taken_frames[1] = sf::IntRect(252, 4452, 97, 92);
    crouch_face_hit_taken_frames[2] = sf::IntRect(152, 4452, 97, 92);


    victory1_frames[0] = sf::IntRect(14, 7168, 100, 120);

    victory2_frames[0] = sf::IntRect(160, 7125, 100, 170);
    victory2_frames[1] = sf::IntRect(260, 7125, 100, 170);
    victory2_frames[2] = sf::IntRect(360, 7125, 100, 170);

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
    player.setScale(sf::Vector2f(1.9, 1.9));
    curr_state = AnimationState::idle;
}

//movements
void Balrog::moveRight() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_right;
    }
}
void Balrog::moveLeft() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 5;
        curr_state = AnimationState::move_left;
    }
}
void Balrog::jump() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::jump;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::jump_forward;
    }
    else if (curr_state == AnimationState::move_left) {
        curr_frame = 0;
        curr_state = AnimationState::jump_backward;
    }
}
void Balrog::crouch() {
    if (curr_state == AnimationState::idle) {
        curr_state = AnimationState::crouching;
        player.setTextureRect(sf::IntRect(14, 1639, 65, 76));
        player.setPosition(player.getGlobalBounds().left - 20, BOTTOMY - player.getGlobalBounds().height);
    }
    else if (curr_state == AnimationState::blocking) {
        player.setTextureRect(sf::IntRect(312, 2598, 68, 81));
        player.setPosition(player.getGlobalBounds().left + 35, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::crouch_blocking;
    }
}
void Balrog::uncrouch() {
    if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[curr_frame]);
        player.setPosition(player.getGlobalBounds().left + 20, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
    }
    else if (curr_state == AnimationState::crouch_blocking) {
        player.setTextureRect(sf::IntRect(14, 2565, 80, 115));
        player.setPosition(player.getGlobalBounds().left - 35, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::blocking;
    }
}
void Balrog::block() {
    if (curr_state == AnimationState::idle) {
        player.setTextureRect(sf::IntRect(14, 2565, 80, 115));
        player.setPosition(player.getGlobalBounds().left - 55, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::blocking;
    }
    else if (curr_state == AnimationState::crouching) {
        player.setTextureRect(sf::IntRect(312, 2598, 68, 81));
        player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::crouch_blocking;
    }
}
void Balrog::unblock() {
    if (curr_state == AnimationState::crouch_blocking) {
        curr_state = AnimationState::crouching;
        player.setTextureRect(sf::IntRect(14, 1639, 65, 76));
        player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
    }
    else if (curr_state == AnimationState::blocking) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        player.setPosition(player.getGlobalBounds().left + 55, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
    }
}
//hits dealt
void Balrog::punch1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::light_punch_right;
    }
    else if (curr_state == AnimationState::light_punch_right) {
        combo = true;
    }
    else if (curr_state == AnimationState::jump && curr_frame <= 1) { // cant have them jump punching at apex of jump must be at/near start
        curr_state = AnimationState::jump_punch;
    }
    else if (curr_state == AnimationState::jump_forward && curr_frame <= 1) { // cant have them jump punching at apex of jump must be at/near start
        curr_state = AnimationState::forward_jump_punch;
    }
    else if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        curr_state = AnimationState::crouch_light_punch;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_light_punch;
    }
}
void Balrog::punch2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::medium_punch_right;
    }
    else if (curr_state == AnimationState::medium_punch_right) {
        combo = true;
    }
    else if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        curr_state = AnimationState::crouch_medium_punch;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_medium_punch;
    }
}
void Balrog::punch3() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::heavy_punch_right;
    }
    else if (curr_state == AnimationState::heavy_punch_right) {
        combo = true;
    }
}
void Balrog::specialMove1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::special_move1;
    }
}
void Balrog::specialMove2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::special_move2;
    }
}
////hits taken
//void Balrog::hit_taken_blanka_electricity() {
//    curr_frame = 0;
//    count = 0;
//    curr_state = AnimationState::hit_taken_blanka_electricity;
//}
void Balrog::light_hit_taken_face() {
    curr_frame = 0;
    curr_state = AnimationState::light_hit_taken_face;
}
void Balrog::heavy_hit_taken_face() {
    curr_frame = 0;
    curr_state = AnimationState::heavy_hit_taken_face;
}
void Balrog::hit_taken_body() {
    curr_frame = 0;
    curr_state = AnimationState::hit_taken_body;
}
void Balrog::medium_hit_taken_body() {
    curr_frame = 0;
    curr_state = AnimationState::medium_hit_taken_body;
}
void Balrog::heavy_hit_taken_body() {
    curr_frame = 0;
    curr_state = AnimationState::heavy_hit_taken_body;
}
void Balrog::face_body_combo_taken() {
    curr_frame = 0;
    curr_state = AnimationState::face_body_combo_taken;
}
//void Balrog::crouch_face_hit_taken() {
//    curr_frame = 0;
//    curr_state = AnimationState::crouch_face_hit_taken;
//}
//void Balrog::victory(int type) {
//    switch (type) {
//    case 1:
//        setPosition(player.getPosition().x, player.getPosition().y - 20);
//        player.setTextureRect(victory1_frames[0]);
//        curr_state = AnimationState::still;
//        break;
//    case 2:
//        curr_frame = 0;
//        count = 0;
//        curr_state = AnimationState::victory_2;
//        break;
//    case 3:
//        curr_frame = 0;
//        curr_state = AnimationState::victory_3;
//        break;
//    }
//}
//void Balrog::knockout(int type) {
//    switch (type) {
//    case 1:
//        curr_frame = 0;
//        curr_state = AnimationState::knockout;
//        break;
//    case 2:
//        curr_frame = 0;
//        curr_state = AnimationState::defeat;
//        break;
//    }
//}
bool Balrog::processEvent(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::BackSpace) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setPosition(player.getPosition().x, 365);
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        if (curr_state == AnimationState::idle) {
            //if (event.key.code == sf::Keyboard::Num1) {
            //    hit_taken_blanka_electricity();
            //    return true;
            //}
            if (event.key.code == sf::Keyboard::Num2) {
                light_hit_taken_face();
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num3) {
                heavy_hit_taken_face();
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num4) {
                hit_taken_body();
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num5) {
                medium_hit_taken_body();
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num6) {
                heavy_hit_taken_body();
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num7) {
                face_body_combo_taken();
                return true;
            }
            /*else if (event.key.code == sf::Keyboard::Num7) {
                knockout(1);
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num8) {
                victory(1);
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num9) {
                victory(2);
                return true;
            }
            else if (event.key.code == sf::Keyboard::Num0) {
                victory(3);
                return true;
            }
            else if (event.key.code == sf::Keyboard::Enter) {
                knockout(2);
                return true;
            }*/
        }
       /* else if (curr_state == AnimationState::crouching) {
            if (event.key.code == sf::Keyboard::Num5) {
                crouch_face_hit_taken();
                return true;
            }
        }*/
    }
    return false;
}
void Balrog::update(float time) {
    time_elapsed += time;
    if (time_elapsed >= IDLE_TIME && curr_state == AnimationState::idle) {
        curr_frame = curr_frame + incr_to_next_frame;
        player.setTextureRect(idle_frames[curr_frame]);
        if (!curr_frame)
            incr_to_next_frame = 1;
        else if (curr_frame == 5)
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
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
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
                if (player.getPosition().x + 25 <= 570)
                    setPosition(player.getPosition().x + 25, player.getPosition().y - 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y - 50);
            else if (curr_frame > 3 && curr_frame < 7)
                if (player.getPosition().x + 50 <= 570)
                    setPosition(player.getPosition().x + 50, player.getPosition().y + 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y + 50);
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
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 10 <= 570)
                setPosition(player.getPosition().x + 10, player.getPosition().y);
            player.setTextureRect(move_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::move_left) {
        if (curr_frame == -1) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x - 10 >= 0)
                setPosition(player.getPosition().x - 10, player.getPosition().y);
            player.setTextureRect(move_frames[curr_frame--]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::light_punch_right) {
        if (curr_frame == 3) {
            if (combo) {
                curr_frame = 0;
                combo = false;
                curr_state = AnimationState::alt_light_punch;
                player.setTextureRect(alt_light_punch_frames[curr_frame++]);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
            }
        }
        else
            player.setTextureRect(light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::heavy_punch_right) {
        if (curr_frame == 3) {
            if (combo) {
                curr_frame = 0;
                combo = false;
                curr_state = AnimationState::alt_heavy_punch;
                player.setTextureRect(alt_heavy_punch_frames[curr_frame++]);
                player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
            }
        }
        else {
            player.setTextureRect(heavy_punch_frames[curr_frame++]);
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_light_punch) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            player.setTextureRect(forward_light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::medium_punch_right) {
        if (curr_frame == 3) {
            if (combo) {
                curr_frame = 0;
                combo = false;
                curr_state = AnimationState::alt_medium_punch;
                player.setTextureRect(alt_medium_punch_frames[curr_frame++]);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
            }
        }
        else {
            player.setTextureRect(medium_punch_frames[curr_frame++]);
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::hit_taken_blanka_electricity) {
        if (curr_frame == 2 and count == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            setPosition(player.getPosition().x, player.getPosition().y + 20);
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (count == 0 && curr_frame == 0) {
                setPosition(player.getPosition().x, player.getPosition().y - 20);
            }
            if (curr_frame == 2) {
                curr_frame = 0;
                count++;
            }
            player.setTextureRect(hit_taken_blanka_electricity_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::alt_light_punch) {
        if (curr_frame == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            player.setTextureRect(alt_light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::alt_heavy_punch) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(alt_heavy_punch_frames[curr_frame++]);
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::alt_medium_punch) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            player.setTextureRect(alt_medium_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_medium_punch) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            setPosition(player.getPosition().x, player.getPosition().y + 15);
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (!curr_frame)
                setPosition(player.getPosition().x, player.getPosition().y - 15);
            player.setTextureRect(forward_medium_punch_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_light_punch) {
        if (curr_frame == 5)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                player.setTextureRect(sf::IntRect(14, 1639, 65, 76));
                player.setPosition(player.getGlobalBounds().left - 30, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
                curr_state = AnimationState::idle;
            }
        else {
            player.setTextureRect(crouch_light_punch_frames[curr_frame++]);
            if(curr_frame == 1)
                player.setPosition(player.getGlobalBounds().left + 30, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 3)
                player.setPosition(player.getPosition().x - 18, player.getPosition().y);
            if (curr_frame == 4)
                player.setPosition(player.getPosition().x + 18, player.getPosition().y);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_medium_punch) {
        if (curr_frame == 5)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                player.setTextureRect(sf::IntRect(14, 1639, 65, 76));
                player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
                curr_state = AnimationState::idle;
            }
        else {
            player.setTextureRect(crouch_medium_punch_frames[curr_frame++]);
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_punch) {
    if (curr_frame == 9) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
        player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
    }
    else {
        if (curr_frame > 0 && curr_frame < 4)
            setPosition(player.getPosition().x, player.getPosition().y - 40);
        else if (curr_frame > 4 && curr_frame < 8)
            setPosition(player.getPosition().x, player.getPosition().y + 40);
        player.setTextureRect(jump_punch_frames[curr_frame++]);
    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_jump_punch) {
    if (curr_frame == 9) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
        player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
    }
    else {
        if (curr_frame > 0 && curr_frame < 4)
            if (player.getPosition().x + 25 <= 570)
                setPosition(player.getPosition().x + 25, player.getPosition().y - 50);
            else
                setPosition(player.getPosition().x, player.getPosition().y - 50);
        else if (curr_frame > 4 && curr_frame < 8)
            if (player.getPosition().x + 50 <= 570)
                setPosition(player.getPosition().x + 50, player.getPosition().y + 50);
            else
                setPosition(player.getPosition().x, player.getPosition().y + 50);
        player.setTextureRect(jump_punch_frames[curr_frame++]);
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
            if (curr_frame > 0 && curr_frame < 4)
                if (player.getPosition().x - 50 >= 0)
                    setPosition(player.getPosition().x - 50, player.getPosition().y - 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y - 50);
            else if (curr_frame > 3 && curr_frame < 7)
                if (player.getPosition().x - 25 >= 0)
                    setPosition(player.getPosition().x - 25, player.getPosition().y + 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y + 50);
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::light_hit_taken_face) {
        if (curr_frame == 1) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
            player.setPosition(player.getGlobalBounds().left + 30, BOTTOMY - player.getGlobalBounds().height);
        }
        else {
            player.setTextureRect(light_hit_taken_face_frames[curr_frame++]);
            player.setPosition(player.getGlobalBounds().left - 30, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::heavy_hit_taken_face) {
    if (curr_frame == 5) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
        player.setPosition(player.getGlobalBounds().left + 30, BOTTOMY - player.getGlobalBounds().height);
    }
    else {
        player.setTextureRect(hit_taken_face_frames[curr_frame++]);
        if (curr_frame==1)
            player.setPosition(player.getGlobalBounds().left-30, BOTTOMY - player.getGlobalBounds().height);
        else
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::hit_taken_body) {
        if (curr_frame == 1) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
            player.setPosition(player.getGlobalBounds().left + 30, BOTTOMY - player.getGlobalBounds().height);
        }
        else {
            player.setTextureRect(hit_taken_body_frames[curr_frame++]);
            player.setPosition(player.getGlobalBounds().left -30, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::medium_hit_taken_body) {
    if (curr_frame == 3) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
        player.setPosition(player.getGlobalBounds().left +30, BOTTOMY - player.getGlobalBounds().height);
    }
    else {
        player.setTextureRect(medium_hit_taken_body_frames[curr_frame++]);
        if (curr_frame == 1)
            player.setPosition(player.getGlobalBounds().left - 30, BOTTOMY - player.getGlobalBounds().height);
        else
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::heavy_hit_taken_body) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
            player.setPosition(player.getGlobalBounds().left +30, BOTTOMY - player.getGlobalBounds().height);
        }
        else {
            player.setTextureRect(heavy_hit_taken_body_frames[curr_frame++]);
            if (curr_frame == 1)
                player.setPosition(player.getGlobalBounds().left - 30, BOTTOMY - player.getGlobalBounds().height);
            else
                player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_face_hit_taken) {
        if (curr_frame == 3) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                setPosition(player.getPosition().x, player.getPosition().y + 25);
                player.setTextureRect(sf::IntRect(234, 2720, 91, 79));
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                setPosition(player.getPosition().x, player.getPosition().y - 42);
                curr_state = AnimationState::idle;
            }
        }
        else {
            if (!curr_frame)
                setPosition(player.getPosition().x, player.getPosition().y - 25);
            player.setTextureRect(crouch_face_hit_taken_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::face_body_combo_taken) {
        if (curr_frame == 8) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getGlobalBounds().left + 30, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(face_body_combo_taken_frames[curr_frame++]);
            if (curr_frame == 1)
                player.setPosition(player.getGlobalBounds().left - 30, BOTTOMY - player.getGlobalBounds().height);
            else
                player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::special_move1) {
        if (curr_frame == 9) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(special_move1[curr_frame++]);
            player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 4)
                player.setPosition(player.getPosition().x + 80, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::special_move2) {
    if (curr_frame == 11) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
    }
    else {
        player.setTextureRect(special_move2[curr_frame++]);
        player.setPosition(player.getGlobalBounds().left, BOTTOMY - player.getGlobalBounds().height);
        if (curr_frame == 1)
            player.setPosition(player.getPosition().x - 13, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 2)
            player.setPosition(player.getPosition().x - 15, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 3)
            player.setPosition(player.getPosition().x - 58, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 4)
            player.setPosition(player.getPosition().x - 18, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 7)
            player.setPosition(player.getPosition().x + 35, BOTTOMY - player.getGlobalBounds().height);
        else if (curr_frame == 10)
            player.setPosition(player.getPosition().x + 80, BOTTOMY - player.getGlobalBounds().height);




    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= 0.16f && curr_state == AnimationState::victory_2) {
        if (curr_frame == 3 and count == 3) {
            curr_state = AnimationState::still;
        }
        else {
            if (curr_frame == 3) {
                curr_frame = 1;
                count++;
            }
            if (!curr_frame and !count)
                setPosition(player.getPosition().x, player.getPosition().y - 100);
            player.setTextureRect(victory2_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.16f && curr_state == AnimationState::victory_3) {
        if (curr_frame == 9) {
            curr_state = AnimationState::still;
        }
        else {
            if (!curr_frame)
                setPosition(player.getPosition().x, player.getPosition().y - 18);
            player.setTextureRect(victory3_frames[curr_frame++]);
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
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::defeat) {
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
}
void Balrog::setPosition(float x, float y)
{
    player.setPosition(x, y);
}
void Balrog::flipX()
{
    player.setScale(-2.1, 2.1);
}
void Balrog::render(sf::RenderWindow& window) {
    window.draw(player);
}
Balrog::~Balrog() {
}
sf::FloatRect Balrog::getGlobalBounds()
{
    return player.getGlobalBounds();
}
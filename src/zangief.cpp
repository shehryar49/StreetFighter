#include "zangief.h"
#include<iostream>
using namespace std;

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

Zangief::Zangief(){
    if(!image.loadFromFile("assets/zangief.png")){
        cerr<<"Err loading character";
        exit(EXIT_FAILURE);
    }//spritesheet
    //image.createMaskFromColor(sf::Color(84,118,135,255));//removing background colour (84,118,135,255) //prev: (67,70,181,255)
    texture.loadFromImage(image);
    zangief.setTexture(texture);

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
    forward_medium_punch_frames[1] = sf::IntRect(109,810,110,125);
    forward_medium_punch_frames[2] = sf::IntRect(227,810,134,125);
    forward_medium_punch_frames[3] = sf::IntRect(367,810,117,125);
    forward_medium_punch_frames[4] = sf::IntRect(494,810,131,125);
    forward_medium_punch_frames[5] = sf::IntRect(634,810,112,125);
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

    forward_light_kick_frames[0] = sf::IntRect(14,)

    zangief.setTextureRect(idle_frames[0]);
    zangief.setScale(sf::Vector2f(2.1,2.1));
    curr_state = AnimationState::idle;
}

bool Zangief::processEvent(sf::Event &event){
    if(event.type == sf::Event::KeyPressed){
        if (curr_state == AnimationState::idle) {
            if (event.key.code == sf::Keyboard::Right) {
                curr_frame = 0;
                curr_state = AnimationState::move_right;
                return true;
            }
            else if (event.key.code == sf::Keyboard::Left) {
                curr_frame = 0;
                curr_state = AnimationState::move_left;
                return true;
            }
            else if (event.key.code == sf::Keyboard::A) {
                curr_frame = 0;
                curr_state = AnimationState::light_punch_right;
                return true;
            }
            else if (event.key.code == sf::Keyboard::S) {
                curr_frame = 0;
                curr_state = AnimationState::medium_punch_right;
                return true;
            }
            else if (event.key.code == sf::Keyboard::Z) {
                curr_frame = 0;
                curr_state = AnimationState::light_kick;
                return true;
            }
            else if (event.key.code == sf::Keyboard::X) {
                curr_frame = 0;
                curr_state = AnimationState::medium_kick;
                return true;
            }
            else if (event.key.code == sf::Keyboard::C) {
                curr_frame = 0;
                curr_state = AnimationState::heavy_kick;
                return true;
            }
            else if (event.key.code == sf::Keyboard::E) {
                curr_state = AnimationState::hit_taken_blanka_electricity;
                slot = 14;
                zangief.setTextureRect(sf::IntRect(slot, 38 * 152 + 50, 105, 125));
                slot += 110;
                count++;
            }
            else if (event.key.code == sf::Keyboard::Down) {
                curr_state = AnimationState::crouching;
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 67);
                zangief.setTextureRect(sf::IntRect(234, 2720, 91, 79));
                return true;
            }
            else if (event.key.code == sf::Keyboard::LShift) {
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 10);
                zangief.setTextureRect(sf::IntRect(15,4118,85,106));
                curr_state = AnimationState::blocking;
                return true;
            }
            else if (event.key.code == sf::Keyboard::Up) {
                curr_frame = 0;
                curr_state = AnimationState::jump;
                return true;
            }
        }
        else if (curr_state == AnimationState::crouching) {
            if (event.key.code == sf::Keyboard::LShift) {
                curr_state = AnimationState::crouch_blocking;
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 19);
                zangief.setTextureRect(sf::IntRect(148, 4155, 85, 70));
                return true;
            }
            else if (event.key.code == sf::Keyboard::A) {
                curr_frame = 0;
                curr_state = AnimationState::crouch_light_punch;
                return true;
            }
            else if (event.key.code == sf::Keyboard::S) {
                curr_frame = 0;
                curr_state = AnimationState::crouch_medium_punch;
                return true;
            }
            else if (event.key.code == sf::Keyboard::Z) {
                curr_frame = 0;
                curr_state = AnimationState::crouch_kick;
                return true;
            }
        }
        else if (curr_state == AnimationState::blocking) {
            if (event.key.code == sf::Keyboard::Down) {
                curr_state = AnimationState::crouch_blocking;
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 76);
                zangief.setTextureRect(sf::IntRect(148, 4155, 85, 70));
                return true;
            }
        }
        else if (curr_state == AnimationState::move_right) {
            if (event.key.code == sf::Keyboard::A) {
                curr_frame = 0;
                curr_state = AnimationState::forward_light_punch;
                return true;
            }
            else if (event.key.code == sf::Keyboard::S) {
                curr_frame = 0;
                curr_state = AnimationState::forward_medium_punch;
                return true;
            }
            else if (event.key.code == sf::Keyboard::Up) {
                curr_frame = 0;
                curr_state = AnimationState::jump_forward;
                return true;
            }
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (curr_state == AnimationState::crouching) {
            if (event.key.code == sf::Keyboard::Down) {
                curr_frame = 0;
                incr_to_next_frame = 1;
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 67);
                zangief.setTextureRect(idle_frames[curr_frame]);
                curr_state = AnimationState::idle;
            }
        }
        else if (curr_state == AnimationState::crouch_blocking) {
            if (event.key.code == sf::Keyboard::LShift) {
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 19);
                zangief.setTextureRect(sf::IntRect(234, 2720, 91, 79));
                curr_state = AnimationState::crouching;
                return true;
            }
            else if (event.key.code == sf::Keyboard::Down) {
                curr_state = AnimationState::blocking;
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 76);
                zangief.setTextureRect(sf::IntRect(15, 4118, 85, 106));
                return true;
            }
        }
        else if (curr_state == AnimationState::blocking) {
            if (event.key.code == sf::Keyboard::LShift) {
                curr_frame = 0;
                incr_to_next_frame = 1;
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 10);
                zangief.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
                return true;
            }
        }
        return true;
    }
    return false;
}

void Zangief::update(float time){
    time_elapsed += time;
    if (time_elapsed >= 0.8f && curr_state == AnimationState::idle) {
        curr_frame = curr_frame + incr_to_next_frame;
        zangief.setTextureRect(idle_frames[curr_frame]);
        if (!curr_frame)
            incr_to_next_frame = 1;
        else if (curr_frame == 3)
            incr_to_next_frame = -1;
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::jump) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 4)
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 50);
            else if (curr_frame > 3 && curr_frame < 7)
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 50);
            zangief.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::jump_forward) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 4)
                if (zangief.getPosition().x + 25 <= 570)
                    setPosition(zangief.getPosition().x + 25, zangief.getPosition().y - 50);
                else 
                    setPosition(zangief.getPosition().x, zangief.getPosition().y - 50);
            else if (curr_frame > 3 && curr_frame < 7)
                if(zangief.getPosition().x + 50 <= 570)
                    setPosition(zangief.getPosition().x + 50, zangief.getPosition().y + 50);
                else
                    setPosition(zangief.getPosition().x, zangief.getPosition().y + 50);
            zangief.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::move_right) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (zangief.getPosition().x + 10 <= 570)
                setPosition(zangief.getPosition().x + 10, zangief.getPosition().y);
            zangief.setTextureRect(move_right_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::move_left) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (zangief.getPosition().x - 10 >= 0)
                setPosition(zangief.getPosition().x - 10, zangief.getPosition().y);
            zangief.setTextureRect(move_left_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::light_punch_right) {
        if (curr_frame == 4) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            zangief.setTextureRect(light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::forward_light_punch) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            zangief.setTextureRect(forward_light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::medium_punch_right) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            zangief.setTextureRect(medium_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::hit_taken_blanka_electricity) {
        if (count <= 6) {
            if (count & 1) {
                zangief.setTextureRect(sf::IntRect(slot, 38 * 152 + 45, 115, 130));
                slot = 14;
                count++;
            }
            else {
                zangief.setTextureRect(sf::IntRect(slot, 38 * 152 + 50, 105, 125));
                slot += 110;
                count++;
            }
        }
        else {
            count = 0;
            slot = 12;
            curr_state = AnimationState::idle;
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::light_kick) {
        if (curr_frame == 4) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            zangief.setTextureRect(light_kick_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::medium_kick) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            zangief.setTextureRect(medium_kick_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::heavy_kick) {
        if (curr_frame == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            zangief.setTextureRect(heavy_kick_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::forward_medium_punch) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            setPosition(zangief.getPosition().x, zangief.getPosition().y + 15);
            zangief.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (!curr_frame)
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 15);
            zangief.setTextureRect(forward_medium_punch_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::crouch_light_punch) {
        if (curr_frame == 2)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                zangief.setTextureRect(sf::IntRect(234, 2720, 91, 79));
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                zangief.setTextureRect(idle_frames[0]);
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 67);
                curr_state = AnimationState::idle;
            }
        else
            zangief.setTextureRect(crouch_light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::crouch_medium_punch) {
        if (curr_frame == 5)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 10);
                zangief.setTextureRect(sf::IntRect(234, 2720, 91, 79));
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                zangief.setTextureRect(idle_frames[0]);
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 57);
                curr_state = AnimationState::idle;
            }
        else {
            if (curr_frame == 0)
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 10);
            zangief.setTextureRect(crouch_medium_punch_frames[curr_frame++]);

        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= 0.08f && curr_state == AnimationState::crouch_kick) {
        if (curr_frame == 3)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 10);
                zangief.setTextureRect(sf::IntRect(234, 2720, 91, 79));
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                zangief.setTextureRect(idle_frames[0]);
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 57);
                curr_state = AnimationState::idle;
            }
        else {
            if (curr_frame == 0)
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 10);
            else if (curr_frame == 1)
                setPosition(zangief.getPosition().x, zangief.getPosition().y - 3);
            else if (curr_frame == 2)
                setPosition(zangief.getPosition().x, zangief.getPosition().y + 3);
            zangief.setTextureRect(crouch_kick_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
}
void Zangief::setPosition(float x,float y)
{
    zangief.setPosition(x,y);
}
void Zangief::flipX()
{
    zangief.setScale(-2.1,2.1);
}
void Zangief::render(sf::RenderWindow &window){
    window.draw(zangief);
}
Zangief::~Zangief(){
}

//~Isbah
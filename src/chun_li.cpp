#include "chun_li.h"
#include<iostream>
using namespace std;

sf::IntRect Chun_Li::idle_frames[4];
sf::IntRect Chun_Li::move_right_frames[12];
sf::IntRect Chun_Li::move_left_frames[12];
sf::IntRect Chun_Li::jump_frames[9];

Chun_Li::Chun_Li(){
    if(!image.loadFromFile("assets/Chunli.png")){
        cerr<<"Err loading character";
    }//spritesheet
    //image.createMaskFromColor(sf::Color(24,140,140,255));//removing background colour (24,140,140,255)
    texture.loadFromImage(image);
    chun_li.setTexture(texture);
    
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
    
    chun_li.setTextureRect(idle_frames[0]);//IntRect(left,top,width,height)
    chun_li.setScale(sf::Vector2f(2.1,2.1));
}

bool Chun_Li::processEvent(sf::Event &event){
    if(event.type == sf::Event::KeyPressed){
        if (curr_state == AnimationState::idle) {
            if (event.key.code == sf::Keyboard::Right) {
                curr_frame = 0;
                curr_state = AnimationState::move_right;
                return true;
            }
            if (event.key.code == sf::Keyboard::Left) {
                curr_frame = 0;
                curr_state = AnimationState::move_left;
                return true;
            }
            if (event.key.code == sf::Keyboard::Down) {
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y + 48);
                chun_li.setTextureRect(sf::IntRect(179,2012,73,69));
                curr_state = AnimationState::crouch;
                return true;
            }
            if (event.key.code == sf::Keyboard::LShift) {
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y + 5);
                chun_li.setTextureRect(sf::IntRect(96, 3839, 85, 88));
                curr_state = AnimationState::block;
                return true;
            }
            if (event.key.code == sf::Keyboard::Up) {
                curr_frame = 0;
                curr_state = AnimationState::jump;
                return true;
            }
        }
        else if (curr_state == AnimationState::block) {
            if (event.key.code == sf::Keyboard::Down) {
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y + 41);
                chun_li.setTextureRect(sf::IntRect(389, 3857, 76, 70));
                curr_state = AnimationState::crouch_block;
                return true;
            }
        }
        else if (curr_state == AnimationState::crouch) {
            if (event.key.code == sf::Keyboard::LShift) {
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y - 2);
                chun_li.setTextureRect(sf::IntRect(389, 3857, 76, 70));
                curr_state = AnimationState::crouch_block;
                return true;
            }
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (curr_state == AnimationState::crouch) {
            if (event.key.code == sf::Keyboard::Down) {
                curr_frame = 0;
                incr_to_next_frame = 1;
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y - 48);
                chun_li.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
                return true;
            }
        }
        else if (curr_state == AnimationState::block) {
            if (event.key.code == sf::Keyboard::LShift) {
                curr_frame = 0;
                incr_to_next_frame = 1;
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y - 5);
                chun_li.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
                return true;
            }
        }
        else if (curr_state == AnimationState::crouch_block) {
            if (event.key.code == sf::Keyboard::Down) {
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y - 41);
                chun_li.setTextureRect(sf::IntRect(96, 3839, 85, 88));
                curr_state = AnimationState::block;
                return true;
            }
            if (event.key.code == sf::Keyboard::LShift) {
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y + 2);
                chun_li.setTextureRect(sf::IntRect(179, 2012, 73, 69));
                curr_state = AnimationState::crouch;
                return true;
            }
        }
    }
    return false;
}
void Chun_Li::update(float time){
    time_elapsed += time;
    if (time_elapsed >= 0.8f && curr_state == AnimationState::idle){
        curr_frame += incr_to_next_frame;
        chun_li.setTextureRect(idle_frames[curr_frame]);
        if (curr_frame == 0)
            incr_to_next_frame = 1;
        else if (curr_frame == 3)
            incr_to_next_frame = -1;
        time_elapsed = 0;//reset condition
        return;
    }
    if (time_elapsed >= 0.04f && curr_state == AnimationState::move_right) {
        if (curr_frame == 12) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            chun_li.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (chun_li.getPosition().x + 5 <= 650)
                setPosition(chun_li.getPosition().x + 5, chun_li.getPosition().y);
            chun_li.setTextureRect(move_right_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= 0.04f && curr_state == AnimationState::move_left) {
        if (curr_frame == 12) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            chun_li.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
           if (chun_li.getPosition().x - 5 >= 0)
                setPosition(chun_li.getPosition().x - 5, chun_li.getPosition().y);
           chun_li.setTextureRect(move_left_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    if (time_elapsed >= 0.062f && curr_state == AnimationState::jump) {
        if (curr_frame == 9) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            chun_li.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if(curr_frame > 0 && curr_frame < 5)
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y - 24);
            else if(curr_frame > 4)
                setPosition(chun_li.getPosition().x, chun_li.getPosition().y + 24);
            chun_li.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
}
void Chun_Li::render(sf::RenderWindow &window){
    window.draw(chun_li);
}
void Chun_Li::setPosition(float x, float y) {
    chun_li.setPosition(x, y);
}
sf::FloatRect Chun_Li::getLocalBounds(){
    return chun_li.getLocalBounds();
}
sf::FloatRect Chun_Li::getGlobalBounds(){
    return chun_li.getGlobalBounds();
}
void Chun_Li::flipX() {
    chun_li.setScale(-2.3,2.3);
}
Chun_Li::~Chun_Li(){}
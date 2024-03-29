//~Isbah
#include "chun_li.h"
#include<iostream>
using namespace std;

sf::IntRect Chun_Li::idle_frames[4];
sf::IntRect Chun_Li::move_right_frames[12];
sf::IntRect Chun_Li::move_left_frames[12];
sf::IntRect Chun_Li::jump_frames[9];

Chun_Li::Chun_Li(){
    if(!image.loadFromFile("assets/chun-li.png")){
        cerr<<"Err loading character";
    }//spritesheet
    //image.createMaskFromColor(sf::Color(24,140,140,255));//removing background colour (24,140,140,255)
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
    
    player.setTextureRect(idle_frames[0]);//IntRect(left,top,width,height)
    player.setScale(sf::Vector2f(2.1,2.1));
}
void Chun_Li::moveLeft() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_left;
    }
}
void Chun_Li::moveRight() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_right;
    }
}
void Chun_Li::block() {
    if (curr_state == AnimationState::idle) {
        player.setTextureRect(sf::IntRect(96, 3839, 85, 88));
        setPosition(player.getPosition().x,BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::block;
    }
    else if (curr_state == AnimationState::crouch) {
        player.setTextureRect(sf::IntRect(389, 3857, 76, 70));
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::crouch_block;
    }
}
void Chun_Li::unblock() {
    if (curr_state == AnimationState::block) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
    }
    else if (curr_state == AnimationState::crouch_block) {
        player.setTextureRect(sf::IntRect(179, 2012, 73, 69));
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::crouch;
    }
}
void Chun_Li::crouch() {
    if (curr_state == AnimationState::idle) {
        player.setTextureRect(sf::IntRect(179, 2012, 73, 69));
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::crouch;
    }
    else if (curr_state == AnimationState::block) {
        player.setTextureRect(sf::IntRect(389, 3857, 76, 70));
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::crouch_block;
    }
}
void Chun_Li::uncrouch() {
    if (curr_state == AnimationState::crouch) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
    }
    else if (curr_state == AnimationState::crouch_block) {
        player.setTextureRect(sf::IntRect(96, 3839, 85, 88));
        setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::block;
    }
}
bool Chun_Li::processEvent(sf::Event &event){
    if(event.type == sf::Event::KeyPressed){
    }
    return false;
}
void Chun_Li::jump() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::jump;
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
            if (player.getPosition().x + 5 <= 650)
                setPosition(player.getPosition().x + 5, player.getPosition().y);
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
           if (player.getPosition().x - 5 >= 0)
                setPosition(player.getPosition().x - 5, player.getPosition().y);
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
}
void Chun_Li::render(sf::RenderWindow &window){
    window.draw(player);
}
void Chun_Li::setPosition(float x, float y) {
    player.setPosition(x, y);
}
sf::FloatRect Chun_Li::getLocalBounds(){
    return player.getLocalBounds();
}
sf::FloatRect Chun_Li::getGlobalBounds(){
    return player.getGlobalBounds();
}
void Chun_Li::flipX() {
    player.setScale(-2.3,2.3);
}
Chun_Li::~Chun_Li(){}
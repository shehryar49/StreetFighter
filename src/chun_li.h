//~Isbah
#ifndef CHUNLI_H_
#define CHUNLI_H_
#include "player.h"
#include<iostream>

class Chun_Li : public Player {
private:
    float time_elapsed = 0;
    enum class AnimationState {
        idle,
        move_right,
        move_left,
        jump,
        block,
        crouch,
        crouch_block,
    };
    static sf::IntRect idle_frames[4];
    static sf::IntRect move_right_frames[12];
    static sf::IntRect move_left_frames[12];
    static sf::IntRect jump_frames[9];

    AnimationState curr_state;
    int curr_frame = 0;
    int incr_to_next_frame = 1;
    int count = 0; //for repetitive moves
public:
    Chun_Li();
    void update(float);
    void render(sf::RenderWindow&);
    void setPosition(float, float);
    sf::FloatRect getLocalBounds();
    sf::FloatRect getGlobalBounds();
    bool processEvent(sf::Event&);
    void flipX();
    //movements
    void moveLeft();
    void moveRight();
    void jump();
    void crouch();
    void uncrouch();
    void block();
    void unblock();
    ~Chun_Li();
};
#endif
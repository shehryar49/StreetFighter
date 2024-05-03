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
        still,
        move_right,
        move_left,
        jump,
        jump_right,
        jump_left,
        crouch,
        flipped_move_right,
        flipped_move_left,
        punch1,
        punch3,
        punch5,
        victory2,
        victory3,
        hit_taken_body1,
        special1,
        knockout,
        defeat_player,
        defeat_enemy,
        kick1,
        kick2,
        kick4,  
    };

    // movement
    static sf::IntRect idle_frames[4];
    static sf::IntRect move_right_frames[12];
    static sf::IntRect move_left_frames[12];
    static sf::IntRect jump_frames[9];

    // hits dealt
    static sf::IntRect punch1_frames[5]; // numbering based on sprite order so i remember what we have to work on
    static sf::IntRect punch3_frames[5];
    static sf::IntRect punch5_frames[5];
    static sf::IntRect kick1_frames[5]; // numbering based on sprite order so i remember what we have to work on
    static sf::IntRect kick2_frames[5];
    static sf::IntRect kick4_frames[5];
    static sf::IntRect special1_frames[12];
    
    // victory
    static sf::IntRect victory1_frames[1];
    static sf::IntRect victory2_frames[5];
    static sf::IntRect victory3_frames[16];

    //hits taken
    static sf::IntRect hit_taken_body3_frames[7];
    static sf::IntRect knockout_frames[12];

    AnimationState curr_state;
    int curr_frame = 0;
    int incr_to_next_frame = 1;
    int count = 0; //for repetitive moves
    float limit = 0;
    bool* game_is_over;
    
public:
    Chun_Li();
    void update(float);
    void render(sf::RenderWindow&);
    void setPosition(float, float);
    sf::FloatRect getLocalBounds();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();
    bool processEvent(sf::Event&);
    void flipX();
    //movements
    void moveLeft(float);
    void moveRight(float);
    bool jump();
    bool crouch();
    bool uncrouch();
    //punches
    bool punch1();
    bool punch2();
    bool punch3();
    //kicks
    bool kick1();
    bool kick2();
    bool kick3();
    //special
    bool specialMove1();
    //victory
    void victory(int);
    //hits taken
    void bodyHit();
    void knockout(int);
    void knockout(bool*);
    //AI
    bool isIdle();
    bool isSuffering();
    bool isAttacking();
    void flippedMoveLeft(float);
    void flippedMoveRight(float);
    ~Chun_Li();
};
#endif
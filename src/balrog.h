//~Isbah
#ifndef BALROG_H_
#define BALROG_H_
#include "player.h"
#include<iostream>

class Balrog : public Player {
private:
    float time_elapsed = 0;
    enum class AnimationState {
        idle,//no key -
        //--------------------------------------movement-----------------------------------------------//
        move_right, //Right Arrow
        move_left, //Left Arrow
        jump, //Up Arrow
        jump_forward,//Right Arrow then Up Arrow 
        jump_backward, //Left Arrow then Up Arrow
        crouching, //Hold Down Arrow
        blocking, //Hold LShift
        crouch_blocking, //Hold LShift + Down Arrow
        //--------------------------------------punches-----------------------------------------------//
        light_punch_right, //A
        medium_punch_right, //S
        heavy_punch_right, //D
        alt_light_punch, //A + A
        alt_medium_punch, //S + S
        alt_heavy_punch, //D + D
        jump_punch, //Up Arrow Key + A
        forward_jump_punch, //Right Arrow Key + Up Arrow Key + A
        crouch_light_punch, //Hold Down Arrow then Press A (can leave Down Arrow mid animation)
        crouch_medium_punch,//Hold Down Arrow then Press S (can leave Down Arrow mid animation)

        forward_light_punch, //Right Arrow Key then A
        forward_medium_punch, //Right Arrow Key then S
        //-------hits taken (should prolly be call-able functions instead of key-event updates)-------//
        light_hit_taken_face, //2
        heavy_hit_taken_face, //3
        hit_taken_body,//4
        medium_hit_taken_body,//5
        heavy_hit_taken_body,//6
        face_body_combo_taken,//7
        crouch_face_hit_taken,//8 (must be crouching - can uncrouch mid animation)
        medium_crouch_face_hit_taken,//9
        heaavy_crouch_face_hit_taken,//0

        hit_taken_blanka_electricity, //1
        knockout, //7
        //---------------------------------------victory----------------------------------------------//
        //victory_1 is on 8
        victory_2,//9
        victory_3,//0
        //---------------------------------------defeat----------------------------------------------//
        defeat, //Enter
        //-------------------------------------special move------------------------------------------//
        special_move1, // Q
        special_move2, // W
        //---------------------------------------nothing--------------------------------------------//
        still,
    };
    AnimationState curr_state;
    static sf::IntRect idle_frames[6];
    static sf::IntRect move_frames[6];
    static sf::IntRect light_punch_frames[3];
    static sf::IntRect medium_punch_frames[3];
    static sf::IntRect heavy_punch_frames[3];
    static sf::IntRect alt_light_punch_frames[3];
    static sf::IntRect alt_medium_punch_frames[5];
    static sf::IntRect alt_heavy_punch_frames[5];
    static sf::IntRect jump_frames[7];
    static sf::IntRect jump_punch_frames[9];
    static sf::IntRect crouch_light_punch_frames[5];
    static sf::IntRect crouch_medium_punch_frames[5];
    static sf::IntRect special_move1[9];
    static sf::IntRect special_move2[11];
    static sf::IntRect light_hit_taken_face_frames[1];
    static sf::IntRect hit_taken_face_frames[5];
    static sf::IntRect hit_taken_body_frames[1];
    static sf::IntRect medium_hit_taken_body_frames[3];
    static sf::IntRect heavy_hit_taken_body_frames[5];
    static sf::IntRect face_body_combo_taken_frames[8];

    static sf::IntRect forward_light_punch_frames[7];
    static sf::IntRect forward_medium_punch_frames[7];
    static sf::IntRect hit_taken_blanka_electricity_frames[2];
    static sf::IntRect crouch_face_hit_taken_frames[3];
    static sf::IntRect victory1_frames[1];
    static sf::IntRect victory2_frames[3];
    static sf::IntRect victory3_frames[9];
    static sf::IntRect knockout_frames[14];

    int curr_frame = -1;
    int incr_to_next_frame = 1;
    int count = 0; //for repetitive moves
    bool combo = false;
    
public:
    Balrog();
    void update(float);
    void render(sf::RenderWindow&);
    void setPosition(float, float);
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
    ////hits dealt
    void punch1();
    void punch2();
    void punch3();
    void specialMove1(); //punch combo
    void specialMove2(); //another punch combo because what else can he do
    ////hits taken
    //void hit_taken_blanka_electricity();
    void light_hit_taken_face();
    void heavy_hit_taken_face();
    void hit_taken_body();
    void medium_hit_taken_body();
    void heavy_hit_taken_body();
    void face_body_combo_taken();
    //void crouch_face_hit_taken();
    //void knockout(int);
    //void victory(int);
    ~Balrog();
};

#endif

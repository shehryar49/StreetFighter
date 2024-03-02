//~Isbah
#ifndef ZANGIEF_H_
#define ZANGIEF_H_
#include "player.h"
#include<iostream>

class Zangief: public Player {
private:
    sf::Texture texture;
    sf::Sprite zangief;
    sf::Image image;
    float time_elapsed = 0;
    enum class AnimationState{
        idle,//no key -
        //--------------------------------------movement-----------------------------------------------//
        move_right, //Right Arrow
        move_left, //Left Arrow
        blocking, //Hold LShift
        crouching, //Hold Down Arrow
        crouch_blocking, //Hold LShift + Down Arrow
        jump, //Up Arrow
        jump_forward,//Right Arrow then Up Arrow 
        jump_backward, //Left Arrow then Up Arrow
        //--------------------------------------punches-----------------------------------------------//
        light_punch_right, //A
        medium_punch_right, //S
        forward_light_punch, //Right Arrow Key then A
        forward_medium_punch, //Right Arrow Key then S
        crouch_light_punch, //Hold Down Arrow then Press A (can leave Down Arrow mid animation)
        crouch_medium_punch,//Hold Down Arrow then Press S (can leave Down Arrow mid animation)
        //---------------------------------------kicks------------------------------------------------//
        light_kick, //Z
        medium_kick, //X
        heavy_kick, //C
        crouch_kick,//Hold Down Arrow then Press J (can leave Down Arrow mid animation)
        forward_light_kick, //Right Arrow + Z
        forward_heavy_kick, //Right Arrow + C
        //-------hits taken (should prolly be call-able functions instead of key-event updates)-------//
        hit_taken_blanka_electricity, //1
        hit_taken_face, //2
        hit_taken_body,//3
        heavy_hit_taken_body,//4
        crouch_face_hit_taken,//5 (must be crouching - can uncrouch mid animation)
        face_body_combo_taken,//6
        knockout, //7
        //---------------------------------------victory----------------------------------------------//
        //victory_1 is on 8
        victory_2,//9
        victory_3,//0
        //---------------------------------------defeat----------------------------------------------//
        defeat, //Enter
        //-------------------------------------special move------------------------------------------//
        special_move, // Q (Can press/hold Left or Right after Q to move Left and Right)
        //---------------------------------------nothing--------------------------------------------//
        still,
    };
    AnimationState curr_state;
    static sf::IntRect idle_frames[4];
    static sf::IntRect move_right_frames[6];
    static sf::IntRect move_left_frames[6];
    static sf::IntRect light_punch_frames[4];
    static sf::IntRect medium_punch_frames[7];
    static sf::IntRect forward_light_punch_frames[7];
    static sf::IntRect forward_medium_punch_frames[7];
    static sf::IntRect crouch_light_punch_frames[2];
    static sf::IntRect crouch_medium_punch_frames[5];
    static sf::IntRect light_kick_frames[4];
    static sf::IntRect medium_kick_frames[5];
    static sf::IntRect heavy_kick_frames[3];
    static sf::IntRect crouch_kick_frames[3];
    static sf::IntRect jump_frames[7];
    static sf::IntRect forward_light_kick_frames[5];
    static sf::IntRect forward_heavy_kick_frames[9];
    static sf::IntRect hit_taken_blanka_electricity_frames[2];
    static sf::IntRect hit_taken_face_frames[3];
    static sf::IntRect hit_taken_body_frames[3];
    static sf::IntRect heavy_hit_taken_body_frames[4];
    static sf::IntRect crouch_face_hit_taken_frames[3];
    static sf::IntRect face_body_combo_taken_frames[6];
    static sf::IntRect special_move[5];
    static sf::IntRect victory1_frames[1];
    static sf::IntRect victory2_frames[3];
    static sf::IntRect victory3_frames[9];
    static sf::IntRect knockout_frames[14];

    int curr_frame = -1;
    int incr_to_next_frame = 1;
    int count = 0; //for repetitive moves
    int slot = 0;
public:
    Zangief();
    void update(float);
    bool processEvent(sf::Event&);
    void render(sf::RenderWindow&);
    void setPosition(float,float);
    void flipX();
    //hits
    void hit_taken_blanka_electricity();
    void hit_taken_face();
    void hit_taken_body();
    void heavy_hit_taken_body();
    void crouch_face_hit_taken();
    void face_body_combo_taken();
    void knockout(int);
    void victory(int);
    ~Zangief();
};

#endif

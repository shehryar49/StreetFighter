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
        block,
        crouch,
        crouch_block,
        punch1,
        punch3,
        punch5,
        victory2,
        victory3,
        hit_taken_face1,
        hit_taken_face2,
        hit_taken_body1,
        hit_taken_body2,
        hit_taken_body3,
        hit_taken_face_body,
        knockout,

        //to be implemented
        punch2,
        punch4,
        punch6,
        punch7,

        kick1,
        kick2,
        kick3,
        kick4,
        kick5,
        kick6,
        kick7,
        kick8,
        kick9,
        kick10,
    };
    static sf::IntRect idle_frames[4];
    static sf::IntRect move_right_frames[12];
    static sf::IntRect move_left_frames[12];
    static sf::IntRect jump_frames[9];

    static sf::IntRect punch1_frames[5];
    static sf::IntRect punch2_frames[5];
    static sf::IntRect punch3_frames[5]; //she has 7 punches .. i will focus on implementing 3 rn then the rest if i get more time
    static sf::IntRect punch4_frames[5];
    static sf::IntRect punch5_frames[5];
    static sf::IntRect punch6_frames[3];
    static sf::IntRect punch7_frames[6];

    static sf::IntRect kick1_frames[5];
    static sf::IntRect kick2_frames[5];
    static sf::IntRect kick3_frames[6]; // she has 10 kicks ..i will focus on implementing 3 rn then the rest if i get more time
    static sf::IntRect kick4_frames[5];
    static sf::IntRect kick5_frames[7];
    static sf::IntRect kick6_frames[8];
    static sf::IntRect kick7_frames[8];
    static sf::IntRect kick8_frames[12];
    static sf::IntRect kick9_frames[16];
    //static sf::IntRect kick10_frames[]; //will count frames later

    static sf::IntRect victory1_frames[1];
    static sf::IntRect victory2_frames[5];
    static sf::IntRect victory3_frames[16];

    //hits
    static sf::IntRect hit_taken_face1_frames[5];
    static sf::IntRect hit_taken_face2_frames[3];

    static sf::IntRect hit_taken_body1_frames[3];
    static sf::IntRect hit_taken_body2_frames[5];
    static sf::IntRect hit_taken_body3_frames[7];

    static sf::IntRect hit_taken_face_body_combo_frames[8];

    static sf::IntRect knockout_frames[12];

    AnimationState curr_state;
    int curr_frame = 0;
    int incr_to_next_frame = 1;
    int count = 0; //for repetitive moves
    float limit = 0;
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
    //void flippedMoveLeft(float);
    //void flippedMoveRight(float);
    void jump();
    void crouch();
    void uncrouch();
    void block();
    void unblock();
    //punches
    void punch1();
    void punch2();
    void punch3();
    //kicks
    void kick1();
    void kick2();
    void kick3();
    //victory
    void victory(int);
    //hits taken
    void hit_taken_face(int);
    void hit_taken_body(int);
    void hit_taken_face_body_combo();
    void knockout(int);
    ~Chun_Li();
};
#endif
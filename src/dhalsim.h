//dhalsim character class: maryam
#ifndef DHALSIM_H_
#define DHALSIM_H_
#include "player.h"

#include<iostream>
class Dhalsim : public Player
{
private:
    sf::Texture texture;
    sf::Sprite player;
    sf::Image img;
    sf::Vector2f pos; // to save before jumping
    float elapsed = 0;
    enum class AnimationState
    {
        //-------------idle
        IDLE,
        FASTIDLE,
        FASTIDLE_ATTACKING,
        //-------------jump
        JMP, 
        LAND,
        //-------------move
        moveRight, 
        moveLeft, 
        flipped_move_right,
        flipped_move_left,
        //-------------punches

        PUNCH1, //Low Punch(Jab)
        RETREAT1, //move back after punch 1
        PUNCH2, //Medium(Strong) Punch
        RETREAT2, //move back after punch 2
        PUNCH3, //Heavy(Fierce) Punch
        RETREAT3, //move back after punch 3

        //-------------kicks
        KICK1,
        KICK2, 
        KICK3,

        //-------------crouch
        CROUCHING, 
        UNCROUCHING, //standing up
        CROUCHED,
        FAST_CROUCHED,
        CROUCHED_PUNCH1,//Low Punch
        CROUCHED_PUNCH2,//Medium(Strong) Punch
        CROUCHED_KICK1,

        //-------------block
        BLOCKING,
        BLOCKED,
        UNBLOCKING,

        //-------------special move
        YOGA_FLAME,

        //--------------victory
        VICTORY_1,//to be set when player wins

        //--------------lose
        KNOCKOUT_1,//to be set when bar becomes red - player
        KNOCKOUT_2,//enemy
        //--------------hits taken (to be set when player takes a hit)
        HIT_TAKEN_FACE, //2
        HIT_TAKEN_BODY//3
    };
    AnimationState state;
    static sf::IntRect IDLE_frames[6];
    static sf::IntRect jmp_frames[6];
    static sf::IntRect moveright_frames[7];
    static sf::IntRect moveleft_frames[7];
    static sf::IntRect punch1_frames[3];
    static sf::IntRect punch2_frames[4];
    static sf::IntRect punch3_frames[4];
    static sf::IntRect kick1_frames[3]; 
    static sf::IntRect kick2_frames[3]; 
    static sf::IntRect kick3_frames[6];
    static sf::IntRect crouching_frames[3];
    static sf::IntRect crouched_punch1_frames[2];
    static sf::IntRect crouched_punch2_frames[4];
    static sf::IntRect crouched_kick1_frames[2];
    static sf::IntRect block_frames[2];
    static sf::IntRect victory1_frames[12];
    static sf::IntRect knockout1_frames[4];
    static sf::IntRect yogaflame_frames[20];
    static sf::IntRect hit_taken_face_frames[2];
    static sf::IntRect hit_taken_body_frames[2];

    int currFrame = 0;
    int frameIncrement = 1;
    float limit;
    bool* game_is_over;
public:
    Dhalsim();
    void update(float);
    bool processEvent(sf::Event&);
    void render(sf::RenderWindow&);
    void setPosition(float, float);
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    void flipX();
    void moveLeft(float);
    void moveRight(float);
    void flippedMoveLeft(float);
    void flippedMoveRight(float);
    bool punch1();
    bool punch2();
    bool punch3();
    bool kick1();
    bool kick2();
    bool kick3();
    bool jump();
    bool crouch();
    bool uncrouch();
    bool block();
    bool unblock();
    void victory(int);
    void knockout(int);
    bool specialMove1(); //yoga flame
    void hit_taken_face();
    void bodyHit();
    bool isIdle();
    bool isSuffering();//taking hits or not
    bool isAttacking();
    void knockout(bool*);
    ~Dhalsim();
};
#endif


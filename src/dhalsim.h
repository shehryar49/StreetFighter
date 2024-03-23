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
        //-------------jump
        JMP, 
        LAND,
        //-------------move
        moveRight, 
        moveLeft, 
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

        //--------------victory
        VICTORY_1//to be set when player wins
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

    int currFrame = 0;
    int frameIncrement = 1;
public:
    Dhalsim();
    void update(float);
    bool processEvent(sf::Event&);
    void render(sf::RenderWindow&);
    void setPosition(float, float);
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    void flipX();
    void moveLeft();
    void moveRight();
    void punch1();
    void punch2();
    void punch3();
    void kick1();
    void kick2();
    void kick3();
    void jump();
    void crouch();
    void uncrouch();
    void block();
    void unblock();
    void victory(int);
    ~Dhalsim();
};
#endif


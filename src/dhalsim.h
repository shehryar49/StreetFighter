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
        IDLE,
        JMP, //Up arrow key
        LAND,
        FASTIDLE,
        moveRight, //Right arrow key
        moveLeft, //Left arrow key
        PUNCH1, //Low Punch(Jab) A key
        RETREAT1, //move back after punch 1
        PUNCH2, //Medium Punch S key
        RETREAT2, //move back after punch 2
        CROUCHING, //Down arrow key
        UNCROUCHING, //standing up
        CROUCHED,
        FAST_CROUCHED,
    };
    AnimationState state;
    static sf::IntRect IDLE_frames[6];
    static sf::IntRect jmp_frames[6];
    static sf::IntRect moveright_frames[7];
    static sf::IntRect moveleft_frames[7];
    static sf::IntRect punch1_frames[3];
    static sf::IntRect punch2_frames[4];
    static sf::IntRect crouching_frames[3];

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
    //void punch3();
    //void kick1();
    //void kick2();
    //void kick3();
    void jump();
    void crouch();
    void uncrouch();
    ~Dhalsim();
};
#endif


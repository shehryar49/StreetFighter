// Written by Shahryar Ahmad
#ifndef RYU_H_
#define RYU_H_
#include "player.h"
class Ryu : public Player
{
private:

    sf::Sprite gola;
    sf::Image img;
    sf::Vector2f pos; // to save before jumping
    float elapsed = 0;
    enum class AnimationState
    {
        IDLE,
        FASTIDLE,
        MOVE_RIGHT,
        MOVE_LEFT,
        PUNCH1,
        PUNCH2,
        PUNCH3,
        KICK1, // sidekick
        KICK2, // low kick
        KICK3, 
        JMP,
        LAND,
        SHORYUKEN,
        SHORYUKEN_LAND,
        CROUCHING,
        UNCROUCHING, //standing up
        CROUCHED,
        FAST_CROUCHED,
        CROUCHED_PUNCH1,
        CROUCHED_PUNCH2,
        CROUCHED_KICK1,
        CROUCHED_KICK2, //sweep
        HADOKEN
    };
    AnimationState state;
    //'Frames' actually might not be the right word
    // but who's gonna stop me?
    static sf::IntRect IDLE_frames[5];
    static sf::IntRect moveright_frames[6];
    static sf::IntRect moveleft_frames[6];  
    static sf::IntRect punch1_frames[2];
    static sf::IntRect punch2_frames[3]; 
    static sf::IntRect punch3_frames[5];
    static sf::IntRect kick1_frames[3]; // side kick
    static sf::IntRect kick2_frames[3]; // low kick
    static sf::IntRect kick3_frames[5];
    static sf::IntRect jmp_frames[7]; 
    static sf::IntRect shoryuken_frames[6]; 
    static sf::IntRect crouching_frames[3];
    static sf::IntRect crouched_punch1_frames[2];
    static sf::IntRect crouched_punch2_frames[3];
    static sf::IntRect crouched_kick1_frames[3];
    static sf::IntRect crouched_kick2_frames[5];
    static sf::IntRect hadoken_ball;
    static sf::IntRect hadoken_frames[4];
    int currFrame = 0;
    int frameIncrement = 1;
    bool hadoken = false; // hadoken travelling
public:
    Ryu();
    void update(float);
    bool processEvent(sf::Event &);
    void render(sf::RenderWindow &);
    void setPosition(float,float);
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
    //void crouch();
    //void uncrouch();
    void specialMove1(); //shoryuken
    void specialMove2(); //hadoken
    ~Ryu();
};
#endif

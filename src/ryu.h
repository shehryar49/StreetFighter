// Written by Shahryar Ahmad
#ifndef RYU_H_
#define RYU_H_
#include "player.h"
#include <SFML/Graphics/Rect.hpp>
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
        FASTIDLE_ATTACKING,
        MOVE_RIGHT,
        MOVE_LEFT,
        FLIPPED_MOVE_RIGHT,
        FLIPPED_MOVE_LEFT,
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
        HADOKEN,
        BODY_HIT,
        KNOCKED_OUT
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
    static sf::IntRect body_hit_frames[2];
    static sf::IntRect knockout_frames[5];
    int currFrame = 0;
    int frameIncrement = 1;
    bool hadoken = false; // hadoken travelling
    float limit;
public:
    Ryu();
    void update(float);
    void render(sf::RenderWindow &);
    void setPosition(float,float);
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    sf::Vector2f getPosition();
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
    bool specialMove1(); //shoryuken
    bool specialMove2(); //hadoken
    bool isIdle();
    void bodyHit();
    bool isSuffering();
    bool isAttacking();
    ~Ryu();
};
#endif

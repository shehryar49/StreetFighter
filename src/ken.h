//Written by Shahryar Ahmad
#ifndef KEN_H_
#define KEN_H_
#include "player.h"
#include "ryu.h"
#include <SFML/Graphics/Rect.hpp>
class Ken : public Player
{
private:
    sf::Image img;
    sf::Vector2f pos; // to save before jumping
    float elapsed = 0;
    enum class AnimationState
    {
        IDLE,
        FASTIDLE,
        FASTIDLE_ATTACKING,
        moveRight,
        moveLeft,
        PUNCH1,
        PUNCH2,
        PUNCH3,
        KICK1,
        KICK2,
        KICK3,
        JMP,
        DELAY,
        CROUCHING,
        CROUCHED,
        CROUCHED_PUNCH1,
        CROUCHED_PUNCH2,
        CROUCHED_KICK1,
        CROUCHED_KICK2,
        HELICOPTER_KICK,
        TORNADO_KICK,
        BODY_HIT,
        FLIPPED_MOVE_LEFT,
        FLIPPED_MOVE_RIGHT,
        KNOCKED_OUT
    };
    AnimationState state;
    //'Frames' actually might not be the right word
    // but who's gonna stop me?
    static sf::IntRect IDLE_frames[6];
    static sf::IntRect moveright_frames[6];
    static sf::IntRect moveleft_frames[6];  
    static sf::IntRect punch1_frames[2];
    static sf::IntRect punch2_frames[3]; 
    static sf::IntRect punch3_frames[7];
    static sf::IntRect kick1_frames[3]; // side kick
    static sf::IntRect kick2_frames[3]; // low kick
    static sf::IntRect kick3_frames[6];
    static sf::IntRect jmp_frames[8]; 
    static sf::IntRect crouching_frames[3];
    static sf::IntRect crouched_punch1_frames[2];
    static sf::IntRect crouched_punch2_frames[3];
    static sf::IntRect crouched_kick1_frames[5];
    static sf::IntRect crouched_kick2_frames[5];
    static sf::IntRect helicopter_kick_frames[12];
    static sf::IntRect tornado_kick_frames[10];
    static sf::IntRect body_hit_frames[3];
    static sf::IntRect knockout_frames[5];
    int currFrame = 0;
    int frameIncrement = 1;
    float JMPY = -30;
    float delay_time = 0;
    float limit;
    AnimationState lastState;
public:
    Ken();
    void update(float);
    void render(sf::RenderWindow &);
    void setPosition(float,float);
    void flipX();
    bool punch1();
    bool punch2();
    bool punch3();
    bool kick1();
    bool kick2();
    bool kick3();
    void moveLeft(float);
    void moveRight(float);
    void flippedMoveLeft(float);
    void flippedMoveRight(float);
    bool jump();
    bool crouch();
    bool uncrouch();
    bool specialMove1();
    bool isIdle();
    bool isSuffering();//taking hits or not
    bool isAttacking();
    void bodyHit();
    void knockout();

    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    ~Ken();
};
#endif
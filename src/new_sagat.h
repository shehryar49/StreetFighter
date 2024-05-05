//Written by Usman 
#ifndef SAGAT_H_
#define SAGAT_H_
#include "player.h"
#include "ryu.h"
#include <SFML/Graphics/Rect.hpp>
class Sagat : public Player
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
        KICK1,
        KICK2,
        KICK3,
        JMP,
        DELAY,
        CROUCHING,
        CROUCHED,
        CROUCHED_PUNCH1,
        BODY_HIT,
        FLIPPED_MOVE_LEFT,
        FLIPPED_MOVE_RIGHT,
        KNOCKED_OUT,
        TIGER,
        VICTORY,
        NONE //does not update anything
    };

    AnimationState state;
    //'Frames' actually might not be the right word
    // but who's gonna stop me?
    static sf::IntRect IDLE_frames[5];
    static sf::IntRect moveright_frames[4];
    static sf::IntRect moveleft_frames[4];  
    static sf::IntRect punch1_frames[3]; // notorious elbow strike of muay thai 
    static sf::IntRect punch2_frames[5]; 
    static sf::IntRect kick1_frames[7];
    static sf::IntRect kick2_frames[7];
    static sf::IntRect kick3_frames[7];
    static sf::IntRect jmp_frames[6]; 
    static sf::IntRect crouching_frames[2];
    static sf::IntRect crouched_punch1_frames[3];
    static sf::IntRect body_hit_frames[4];
    static sf::IntRect knockout_frames[4];
    static sf::IntRect tiger_frames[3];
    static sf::IntRect victory_frames[4];
    int currFrame = 0;
    int frameIncrement = 1;
    float JMPY = -30;
    float delay_time = 0;
    float limit;
    AnimationState lastState;
public:
    Sagat();
    void update(float);
    void render(sf::RenderWindow &);
    void setPosition(float,float);
    void flipX();
    bool punch1();
    bool punch2();
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
    void victory();
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    ~Sagat();
};
#endif
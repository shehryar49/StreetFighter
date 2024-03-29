//Written by Shahryar Ahmad
#ifndef KEN_H_
#define KEN_H_
#include "player.h"
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
        CROUCHED
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
    void punch1();
    void punch2();
    void punch3();
    void kick1();
    void kick2();
    void kick3();
    void moveLeft(float);
    void moveRight(float);
    void jump();
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    ~Ken();
};
#endif
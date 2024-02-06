// Written by Shahryar Ahmad
#ifndef RYU_H_
#define RYU_H_
#include "player.h"
class Ryu : public Player
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
        FASTIDLE,
        MOVE_RIGHT,
        MOVE_LEFT,
        PUNCH1,
        PUNCH2,
        KICK1, // sidekick
        KICK2, // low kick
        KICK3, 
        JMP,
        LAND,
        SHORYUKEN,
        SHORYUKEN_LAND
    };
    AnimationState state;
    //'Frames' actually might not be the right word
    // but who's gonna stop me?
    static sf::IntRect IDLE_frames[5];
    static sf::IntRect moveright_frames[6];
    static sf::IntRect moveleft_frames[6];  
    static sf::IntRect punch1_frames[2];
    static sf::IntRect punch2_frames[3]; 
    static sf::IntRect kick1_frames[3]; // side kick
    static sf::IntRect kick2_frames[3]; // low kick
    static sf::IntRect kick3_frames[5];
    static sf::IntRect jmp_frames[7]; 
    static sf::IntRect shoryuken_frames[6]; 
    
    int currFrame = 0;
    int frameIncrement = 1;
public:
    Ryu();
    void update(float);
    bool processEvent(sf::Event &);
    void render(sf::RenderWindow &);
    void setPosition(float,float);
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    void flipX();
    ~Ryu();
};
#endif
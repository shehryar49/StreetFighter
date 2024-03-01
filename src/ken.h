#ifndef KEN_H_
#define KEN_H_
#include "player.h"
class Ken : public Player
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
        moveRight,
        moveLeft,
        PUNCH1,
        PUNCH2,
        KICK1,
        JMP,
        LAND
    };
    AnimationState state;
    //'Frames' actually might not be the right word
    // but who's gonna stop me?
    static sf::IntRect IDLE_frames[6];
    static sf::IntRect moveright_frames[6];
    static sf::IntRect moveleft_frames[6];  
    static sf::IntRect punch1_frames[2];
    static sf::IntRect punch2_frames[3]; 
    static sf::IntRect kick1_frames[3]; // side kick
    static sf::IntRect jmp_frames[7]; 
    
    int currFrame = 0;
    int frameIncrement = 1;
public:
    Ken();
    void update(float);
    bool processEvent(sf::Event &);
    void render(sf::RenderWindow &);
    void setPosition(float,float);
    void flipX();
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    ~Ken();
};
#endif
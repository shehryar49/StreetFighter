//written by Usman Ali
#ifndef SAGAT_H_
#define SAGAT_H_
#include "player.h"
class Sagat : public Player
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
        PUNCH3,
        KICK1,
        KICK2,
        KICK3,
        JMP,
        CROUCH,
        UNCROUCH,
        FIREBALL,
        UPPERCUT,
        UPPERCUT_LAND,
        LAND
    };
    AnimationState state;

    static sf::IntRect IDLE_frames[5];
    static sf::IntRect moveright_frames[4];
    static sf::IntRect moveleft_frames[4]; 
    static sf::IntRect punch1_frames[3];
    static sf::IntRect punch2_frames[5];
    static sf::IntRect punch3_frames[4];
    static sf::IntRect fireball_frames[5];
    static sf::IntRect kick1_frames[7];
    static sf::IntRect kick2_frames[7];
    static sf::IntRect kick3_frames[7];
    static sf::IntRect jmp_frames[6];
    static sf::IntRect crouch_frames[2];
    static sf::IntRect uppercut_frames[10];



    int currFrame = 0;
    int frameIncrement = 1;
public:
    Sagat();
    void update(float);
    bool processEvent(sf::Event&);
    void render(sf::RenderWindow&);
    void setPosition(float, float);
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getLocalBounds();
    void flipX();
    ~Sagat();
};
#endif
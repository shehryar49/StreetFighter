#include "dhalsim.h"
#include<iostream>
using namespace std;

sf::IntRect Dhalsim::IDLE_frames[6];
sf::IntRect Dhalsim::jmp_frames[6];
sf::IntRect Dhalsim::moveright_frames[7];
sf::IntRect Dhalsim::punch2_frames[4];
Dhalsim::Dhalsim()
{
    if (!img.loadFromFile("assets/dhalsim.png")) {
        cerr << "Err loading character";
        exit(EXIT_FAILURE);
    }
    img.createMaskFromColor(sf::Color(70, 112, 104, 255));
    texture.loadFromImage(img);
    player.setTexture(texture);

    IDLE_frames[0] = sf::IntRect(0, 0, 90, 110);
    IDLE_frames[1] = sf::IntRect(90, 0, 90, 110);
    IDLE_frames[2] = sf::IntRect(90 + 90, 0, 90, 110);
    IDLE_frames[3] = sf::IntRect(90 + 90 + 90, 0, 90, 110);
    IDLE_frames[4] = sf::IntRect(90 + 90 + 90 + 90, 0, 90, 110);
    IDLE_frames[5] = sf::IntRect(90 + 90 + 90 + 90 + 90, 0, 90, 110);

    jmp_frames[0] = sf::IntRect(10, 980, 90, 130);
    jmp_frames[1] = sf::IntRect(10 + 90, 955, 90, 130);
    jmp_frames[2] = sf::IntRect(10 + 90 + 90, 940, 90, 130);
    jmp_frames[3] = sf::IntRect(10 + 90 + 90 + 90, 960, 90, 130);
    jmp_frames[4] = sf::IntRect(10 + 90 + 90 + 90 + 90, 950, 90, 130);
    jmp_frames[5] = sf::IntRect(10 + 90 + 90 + 90 + 90 + 90, 955, 90, 130);

    moveright_frames[0] = sf::IntRect(8 + 0, 125, 90, 110);
    moveright_frames[1] = sf::IntRect(10 + 90 * 1, 125, 90, 110);
    moveright_frames[2] = sf::IntRect(10 + 90 * 2, 125, 90, 110);
    moveright_frames[3] = sf::IntRect(10 + 90 * 3, 125, 90, 110);
    moveright_frames[4] = sf::IntRect(10 + 90 * 4, 125, 90, 110);
    moveright_frames[5] = sf::IntRect(10 + 90 * 5, 125, 90, 110);
    moveright_frames[6] = sf::IntRect(10 + 90 * 6, 125, 90, 110);

    punch2_frames[0] = sf::IntRect(50 + 90 * 4, 250, 90, 110);
    punch2_frames[1] = sf::IntRect(50 + 90 * 5, 250, 100, 110);
    punch2_frames[2] = sf::IntRect(100 + 50 + 90 * 5, 250, 170, 110);
    punch2_frames[3] = sf::IntRect(170 + 100 + 50 + 90 * 5, 250, 240, 110);

    player.setTextureRect(IDLE_frames[0]);
    player.setScale(sf::Vector2f(2.1, 2.1));
    player.setPosition(0, 0);
    state = AnimationState::IDLE;
    frameIncrement = 1;
}
bool Dhalsim::processEvent(sf::Event& ev)
{
    if (ev.type == sf::Event::KeyPressed && state == AnimationState::IDLE)
    {

        if (ev.key.code == sf::Keyboard::Up)
        {
            state = AnimationState::JMP;
            currFrame = -1;
            frameIncrement = 1;
            pos = player.getPosition();
            return true;
        }
        else if (ev.key.code == sf::Keyboard::Right)
        {
            state = AnimationState::moveRight;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
        else if (ev.key.code == sf::Keyboard::S)
        {
            state = AnimationState::PUNCH2;
            currFrame = -1;
            frameIncrement = 1;
            return true;
        }
    }
    return false;
}
void Dhalsim::update(float dt)
{
    elapsed += dt;
    if ((elapsed >= (0.8f)) && state == AnimationState::IDLE)
    {
        if (currFrame == 0)
            frameIncrement = 1;
        else if (currFrame == 5)
            frameIncrement = -1;
        currFrame = (currFrame + frameIncrement);
        player.setTextureRect(IDLE_frames[currFrame]);
        elapsed = 0;
    }
    else if (elapsed >= (0.08f) && state == AnimationState::FASTIDLE)
    {
        player.setTextureRect(IDLE_frames[0]);
        currFrame++;
        state = AnimationState::IDLE;
        elapsed = 0;
    }
    else if (elapsed >= 0.2f && state == AnimationState::JMP)
    {
        currFrame++;
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x, player.getPosition().y - 30);
        elapsed = 0;
        if (currFrame == 5) //last frame rendered
        {
            currFrame = 2;
            state = AnimationState::LAND;
        }
    }
    else if (elapsed >= (0.2f) && state == AnimationState::LAND)
    {
        currFrame--;
        player.setTextureRect(jmp_frames[currFrame]);
        player.setPosition(player.getPosition().x, player.getPosition().y + 90);
        elapsed = 0;
        if (currFrame == 0) // landed
        {
            state = AnimationState::FASTIDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= (0.08f) && state == AnimationState::moveRight)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(moveright_frames[currFrame]);
        elapsed = 0;
        if (player.getPosition().x + 150 < 800) // window width is 800
            player.setPosition(player.getPosition().x + 10, player.getPosition().y);
        if (currFrame == 5)
        {
            state = AnimationState::FASTIDLE; // transitions quickly in 100dt instead of 900dt
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    else if (elapsed >= 0.1f && state == AnimationState::PUNCH2)
    {
        currFrame = currFrame + 1;
        player.setTextureRect(punch2_frames[currFrame]);
        elapsed = 0;
        if (currFrame == 2)
        {
            state = AnimationState::IDLE;
            currFrame = 0;
            frameIncrement = 1;
        }
    }
    //return;
}
void Dhalsim::setPosition(float x, float y)
{
    player.setPosition(x, y);
}
void Dhalsim::render(sf::RenderWindow& win)
{
    win.draw(player);
}
void Dhalsim::flipX()
{
    player.setScale(-2.1, 2.1);
}
Dhalsim::~Dhalsim()
{
}
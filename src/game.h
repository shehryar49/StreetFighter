#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "player.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Game
{
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Clock clock;
    Player *player;
    Player* enemy;
    enum class GameState
    {
      MENU,
      PLAYING
    };
    void playIntro(void);
    void pollEvents();
    void update(float);
    void setStage();
    void playMusic(const char* filename);
    GameState state;
    sf::Music bgm; //play all bgm through 1 var so that we dont get conflicts (doesnt apply to move sounds...they can play over bgm...make separate local vars for them)
public:
    Game();
    void run();
    ~Game();
};
#endif
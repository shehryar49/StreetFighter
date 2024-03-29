#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
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
    
    sf::RectangleShape health1;
    sf::RectangleShape health2;
    sf::RectangleShape damage;
    sf::RectangleShape playerDamage;
    float enemyDamage = 0;
    enum class GameState
    {
      MENU,
      PLAYING
    };
    void playIntro(void);
    void pollEvents();
    void update(float);
    void setStage(int*);
    void playMusic(const char* filename);
    int showMenu();
    void showTerminal();
    int* selectScreen();
    std::string execCommand(const std::string&);
    GameState state;
    sf::Music bgm; //play all bgm through 1 var so that we dont get conflicts (doesnt apply to move sounds...they can play over bgm...make separate local vars for them)
    int playerSelected = 0;
    int enemySelected = 0;
public:
    Game();
    void run();
    ~Game();
};
#endif
#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>
#include "player.h"
#include "sound_manager.h"
#include "constants.h"

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
    SoundManager smg;
    
    void playIntro(void);
    void pollEvents();
    void update(float);
    void setStage(int*);
    int showMenu();
    void showTerminal();
    int* selectScreen();
    std::string execCommand(const std::string&);
    void showCredits();

    //sf::Music bgm; //play all bgm through 1 var so that we dont get conflicts (doesnt apply to move sounds...they can play over bgm...make separate local vars for them)
    //^---- not anymore
    int playerSelected = 0;
    int enemySelected = 0;
    //Identifiers for various sounds
    int intro_music = -1;
    int player_selectionbgm_music = -1;
    int player_lockin_music = -1;
    int player_selected_music = -1;
    int vs_music = -1;
    int fight_bgm = -1;
    int terminal_music = -1;
    //small attack voice lines
    //int player_sma = -1;
    //int enemy_sma = -1;
    int player_voice_lines[6] = {-1,-1,-1,-1,-1,-1}; // initialize!!
    int enemy_voice_lines[6] = {-1,-1,-1,-1,-1,-1};;
    //index to voiceline mapping (list will grow when hit_taken functions are called by game class later)
    // 0 - small atk
    // 1 - medium atk
    // 2 - heavy atk
    // 3 - jump
    // 4 - special1
    // 5 - special2

public:
    Game();
    void run();
    void testRun(); //for testing
    ~Game();
};
#endif
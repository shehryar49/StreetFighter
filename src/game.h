#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>
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
    Player *player = nullptr;
    Player* enemy = nullptr;
    
    sf::RectangleShape health1;
    sf::RectangleShape health2;
    sf::RectangleShape enemyDamage;
    sf::RectangleShape playerDamage;
    SoundManager smg; // to manage all sounds
    
    void playIntro();
    void pollEvents();
    void update(float);
    void setStage(int*);
    int showMenu();
    void showTerminal();
    int* selectScreen();
    std::string execCommand(const std::string&); // sets the state of Game, so it needs to be a member
    void showCredits();
    void setVoiceLines(int c, std::string);
    void gameOver();
    int player_selected = 0;
    int enemy_selected = 0;
    //Identifiers for various sounds
    int intro_music = -1;
    int player_selectionbgm_music = -1;
    int player_lockin_music = -1;
    int player_selected_music = -1;
    int vs_music = -1;
    int fight_bgm = -1;
    int terminal_music = -1;

    int player_voice_lines[11] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; // initialize!!
    int enemy_voice_lines[11] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    //index to voiceline mapping (list will grow when hit_taken functions are called by game class later)
    // 0 - small atk
    // 1 - medium atk
    // 2 - heavy atk
    // 3 - jump
    // 4 - special1
    // 5 - special2
    // 6 - bodyHit
    // 7 - knockout
    // 8 - victory
    // 9 - defeat
    // 10 - sys call win
    
    // Fonts
    sf::Font font_crunchchips;
    sf::Font font_hack;
    // Other states
    bool game_over = false;
    bool await_game_over = false; 
    bool ai_bot = true;

    sf::Text timer;
    float time_remaining = 120; 

    unsigned int fps = 0; //0 means infinite 
public:
    Game();
    void run();
    void testRun(); //for testing
    ~Game();
};

#endif
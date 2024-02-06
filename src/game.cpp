#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "game.h"
#include "ryu.h"
#include "zangief.h"
#include "chun_li.h"
#include "dhalsim.h"
#include "ken.h"

using namespace std;
// private
void Game::pollEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else
            player->processEvent(event);
    }
}
void Game::update(float dt)
{
    player->update(dt);
    enemy->update(dt);
}
void Game::playIntro()
{
    window.clear();
    window.display();
    sf::Texture frames[796];
    string name;
    for (int i = 0; i < 796; i++)
    {
        name = std::to_string(i + 1);
        name = "assets/intro/intro" + name + ".jpeg";
        frames[i].loadFromFile(name);

    }
    cout << "loaded images" << endl;
    // all frames loaded
    sf::Sprite s;
    s.setScale(1.7, 1.7);
    int i = 0;
    window.setFramerateLimit(30); //run at 30fps
    bgm.openFromFile("assets/intro/intro.ogg");

    bgm.setLoop(true);
    bgm.play();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                window.setFramerateLimit(0);
                return;
            }
        }
        s.setTexture(frames[i]);

        window.clear();
        window.draw(s);
        window.display();
        i++;
        if (i == 796)
        {
            i = 0;
            bgm.play();
        }
    }
    window.setFramerateLimit(0);
}
// Public
Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Street Fighter")
{
    //playIntro();
    //key was pressed, so we are back after playing intro

    //player = new Chun_Li();
    //player = new Zangief();
    player = new Ryu();
    //player->setPosition(120,300);
    //player = new Ken();
    //player = new Dhalsim();
    
    //enemy = new Chun_Li();
    //enemy = new Ken();
    //enemy = new Dhalsim();
    //enemy = new Zangief();
    enemy = new Ryu();
    setStage();
}
void Game::run()
{
    while (window.isOpen())
    {
        pollEvents();
        float dt = clock.restart().asSeconds();
        update(dt);
        window.clear(sf::Color::Black);
        window.draw(background);
        player->render(window);
        enemy->render(window);
        window.display();
    }
}

void Game::playMusic(const char* filename) {
    if (bgm.getStatus() == sf::Music::Playing)
        bgm.stop(); //if any music was playing before
    if (!(bgm.openFromFile(filename)))
        perror("Error loading assets\n");
    bgm.setVolume(10);
    bgm.setLoop(true); //infinitely play song on loop
    bgm.play();
}

void Game::setStage() {
    enemy->flipX();
    Ryu* ryu_enemy = nullptr;
    if ((ryu_enemy = dynamic_cast <Ryu*>(enemy))) {
        //enemy->setPosition(650,365); //ryu_stage_y_coordinate = 365, enemy_x_coordinate = 650
        
        // note this
        //IMPORTANT
        player->setPosition(120,WINDOW_HEIGHT - (player->getGlobalBounds().height) - 5);
        enemy->setPosition(650,WINDOW_HEIGHT - (enemy->getGlobalBounds().height) - 5);
        ///
        backgroundTexture.loadFromFile("assets/Ryu Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.4, 2.8);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(150, 0, 600, 230));
        playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Zangief* zangief_enemy = nullptr;
    if ((zangief_enemy = dynamic_cast<Zangief*>(enemy))) {
        enemy->setPosition(650, 365); //zangief_stage_y_coordinate = 365, enemy_x_coordinate = 650
        player->setPosition(120, 365);
        backgroundTexture.loadFromFile("assets/Zangief Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.2,2.5);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(100,0,800,400));
        //playMusic("assets/SFX/Theme_of_Zangief.wav");
        playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Dhalsim* dhalsim_enemy = nullptr;
    if ((dhalsim_enemy = dynamic_cast<Dhalsim*>(enemy))) {
        enemy->setPosition(650, 365); //dhalsim_stage_y_coordinate = 365, enemy_x_coordinate = 650
        player->setPosition(120, 365);
        backgroundTexture.loadFromFile("assets/Dhalsim Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.2, 2.5);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(50, 0, 800, 400));
        //playMusic("assets/SFX/Theme_of_Dhalsim.wav");
          playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Ken* ken_enemy = nullptr;
    if ((ken_enemy = dynamic_cast<Ken*>(enemy))) {
        enemy->setPosition(650, 355); //ken_stage_y_coordinate = 355, enemy_x_coordinate = 650
        player->setPosition(120, 355);
        backgroundTexture.loadFromFile("assets/Ken Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.4,3.0);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(100, 0, 800, 400));
        //playMusic("assets/SFX/Theme_of_Ken.wav");
          playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Chun_Li* chun_li_enemy = nullptr;
    if ((chun_li_enemy = dynamic_cast<Chun_Li*>(enemy))) {
        enemy->setPosition(650, 355); //ken_stage_y_coordinate = 355, enemy_x_coordinate = 650
        player->setPosition(120, 355);
        backgroundTexture.loadFromFile("assets/ChunLi Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.2, 2.6);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(65, 0, 800, 400));
        //playMusic("assets/SFX/Theme_of_Chun-li.wav");
          playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
}
Game::~Game()
{
    delete player;
}
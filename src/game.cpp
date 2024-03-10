#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <string>
#include "game.h"
#include "menu.h"
#include "ryu.h"
#include "zangief.h"
#include "chun_li.h"
#include "dhalsim.h"
#include "ken.h"
#include "sagat.h"

using namespace std;
// private
void Game::pollEvents()
{
    sf::Event event;
    int i = 0;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if(event.type==sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::Left:
                  player->moveLeft();
                  break;
                case sf::Keyboard::Right:
                  player->moveRight();
                  break;
                case sf::Keyboard::Up:
                  player->jump();
                  break;
                case sf::Keyboard::Down:
                  player->crouch();
                  break;
                case sf::Keyboard::Q:
                  player->specialMove1();
                  break;
                case sf::Keyboard::W:
                  player->specialMove2();
                  break;
                case sf::Keyboard::A:
                  player->punch1();
                  break;
                case sf::Keyboard::S:
                  player->punch2();
                  break;
                case sf::Keyboard::D:
                  player->punch3();
                  break;
                case sf::Keyboard::Z:
                  player->kick1();
                  break;
                case sf::Keyboard::X:
                  player->kick2();
                  break;
                case sf::Keyboard::C:
                  player->kick3();
                  break;
                default:  
                  break;
            }
        }
        else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
          player->uncrouch();
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
    s.setScale(1.7f, 1.7f);
    int i = 0;
    window.setFramerateLimit(30); //run at 30fps
    bgm.openFromFile("assets/intro/intro.ogg");

    bgm.setLoop(true);
    bgm.play();
    bgm.setVolume(0);
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
                bgm.stop();
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
    bgm.stop();
}
int Game::showMenu()
{
  const char* entries[] = {"Play","Credits","Quit"};
  Menu m(entries,3);
  while(window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else
        {
          int i = m.pollEvent(event);
          if(i >= 0)
            return i;
        }
    }
    window.clear(sf::Color::White);
    m.render(window);
    window.display();
  }  
  return 2;
}
Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Street Fighter",sf::Style::Titlebar | sf::Style::Close)
{
  player = nullptr;
  enemy = nullptr;
  health1.setSize(sf::Vector2f(300,25));
  health2.setSize(sf::Vector2f(300,25));
  health1.setFillColor(sf::Color(255,255,0));
  health2.setFillColor(sf::Color(255,255,0));
  health1.setPosition(0,0);
  health2.setPosition(500,0);
}

void Game::run()
{
    window.setFramerateLimit(60);
    //playIntro();
    //key was pressed, so we are back after playing intro
    //int option = showMenu(); 
    //some option was selected from the menu
    //if(option == 1 || option == 2)
    //  return;
    //option 0 is play
    
    //player = new Chun_Li();
    //player = new Zangief();
    //player = new Ryu();
    player = new Ken();
    player = new Zangief();
    //player = new Ryu();
    //player->setPosition(120,300);
    //player = new Ken();
    //player = new Dhalsim();
    //player = new Sagat();
    //enemy = new Chun_Li();
    //enemy = new Ken();
    //enemy = new Dhalsim();
    //enemy = new Zangief();
    enemy = new Ryu();
    
    setStage();
    while (window.isOpen())
    {
        pollEvents();
        float dt = clock.restart().asSeconds();
        update(dt);
        window.clear(sf::Color::Black);
        window.draw(background);
        window.draw(health1);
        window.draw(health2);
        player->render(window);
        enemy->render(window);
        window.display();
    }
}

void Game::playMusic(const char* filename) 
{
    if (bgm.getStatus() == sf::Music::Playing)
        bgm.stop(); //if any music was playing before
    if (!(bgm.openFromFile(filename)))
        perror("Error loading assets\n");
    bgm.setVolume(0);
    bgm.setLoop(true); //infinitely play song on loop
    bgm.play();
}

void Game::setStage() 
{
    enemy->flipX();
    Ryu* ryu_enemy = nullptr;
    if ((ryu_enemy = dynamic_cast <Ryu*>(enemy))) 
    {
        //calculation
        // topY + height - 1 = bottomY
        // topY = bottomY - height + 1
        // note this
        //IMPORTANT

        player->setPosition(120,BOTTOMY - (player->getGlobalBounds().height) + 1 );
        enemy->setPosition(650,BOTTOMY - (enemy->getGlobalBounds().height) + 1 );
        ///
        backgroundTexture.loadFromFile("assets/Ryu Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.4f, 2.8f);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(150, 0, 600, 230));
        playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Zangief* zangief_enemy = nullptr;
    if ((zangief_enemy = dynamic_cast<Zangief*>(enemy)))
    {
        enemy->setPosition(650, 365); //zangief_stage_y_coordinate = 365, enemy_x_coordinate = 650
        player->setPosition(120, 365);
        backgroundTexture.loadFromFile("assets/Zangief Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(2.1f,2.5f);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(280,0,800,400));
        //playMusic("assets/SFX/Theme_of_Zangief.wav");
        playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Dhalsim* dhalsim_enemy = nullptr;
    if ((dhalsim_enemy = dynamic_cast<Dhalsim*>(enemy))) 
    {
        enemy->setPosition(650, 365); //dhalsim_stage_y_coordinate = 365, enemy_x_coordinate = 650
        player->setPosition(120, 365);
        backgroundTexture.loadFromFile("assets/Dhalsim Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.2f, 2.5f);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(50, 0, 800, 400));
        //playMusic("assets/SFX/Theme_of_Dhalsim.wav");
          playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Ken* ken_enemy = nullptr;
    if ((ken_enemy = dynamic_cast<Ken*>(enemy)))
    {
        enemy->setPosition(650, 355); //ken_stage_y_coordinate = 355, enemy_x_coordinate = 650
        player->setPosition(120, 355);
        backgroundTexture.loadFromFile("assets/Ken Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.4f,3.0f);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(100, 0, 800, 400));
        //playMusic("assets/SFX/Theme_of_Ken.wav");
          playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Chun_Li* chun_li_enemy = nullptr;
    if ((chun_li_enemy = dynamic_cast<Chun_Li*>(enemy))) 
    {
        enemy->setPosition(650, 355); //ken_stage_y_coordinate = 355, enemy_x_coordinate = 650
        player->setPosition(120, 355);
        backgroundTexture.loadFromFile("assets/ChunLi Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.2f, 2.8f);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(65, 0, 800, 400));
        //playMusic("assets/SFX/Theme_of_Chun-li.wav");
         playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
    Sagat* sagat_enemy = nullptr;
    if ((sagat_enemy = dynamic_cast <Sagat*>(enemy))) 
    {
        player->setPosition(120,WINDOW_HEIGHT - (player->getGlobalBounds().height) - 5);
        enemy->setPosition(650,WINDOW_HEIGHT - (enemy->getGlobalBounds().height) - 5);
        backgroundTexture.loadFromFile("assets/Ryu Stage.png");
        background.setTexture(backgroundTexture);
        background.setScale(1.4f, 2.8f);
        background.setPosition(0, 0);
        background.setTextureRect(sf::IntRect(150, 0, 600, 230));
        playMusic("assets/SFX/Theme_of_Ryu.ogg");
        return;
    }
}
Game::~Game()
{
    if(player)
      delete player;
    if(enemy)
      delete enemy;
}

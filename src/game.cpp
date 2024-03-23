#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cctype>
#include <string>
#include "constants.h"
#include "game.h"
#include "menu.h"
#include "ryu.h"
#include "zangief.h"
#include "chun_li.h"
#include "dhalsim.h"
#include "ken.h"
#include "sagat.h"
#include "balrog.h"

using namespace std;

vector<string> split(const string& s,char x)
{
  vector<string> parts;
  size_t len = s.length();
  size_t start = 0;
  for(size_t i = 0;i<len;i++)
  {
    if(s[i] == x)
    {
      //copy part s.substr(start,i-start)
      parts.push_back(s.substr(start,i - start));
      start = i+1;
    }
  }
  parts.push_back(s.substr(start,len - start));
  return parts;
}
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
                  player->moveLeft(0);
                  break;
                case sf::Keyboard::Right:
                  player->moveRight(enemy->getGlobalBounds().left);
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
                case sf::Keyboard::LShift:
                  player->block();
                  break;
                default:
                    player->processEvent(event); //remove later need it rn
                  break;
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Down:
                    player->uncrouch();
                    break;
                case sf::Keyboard::LShift:
                    player->unblock();
                    break;
                default:
                    break;
            }
        }
    }
    
    
}
void Game::update(float dt)
{
    static float elapsed = 0;
    elapsed += dt;
    player->update(dt);
    if(true && player->getGlobalBounds().intersects(enemy->getGlobalBounds()))
    {
     // cout << "damage" << endl;
      if(enemyDamage <= 99.9f)
        enemyDamage += 0.1;
      damage.setSize(sf::Vector2f(enemyDamage*3,25));
      elapsed = 0;
    }
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
std::string Game::execCommand(const std::string& command)
{
  if(command == "")
    return "";
  vector<string> parts = split(command,' ');
  
  //remove extra space from each word
  for(size_t i=0;i<parts.size();i++)
  {
    string& word = parts[i];
    while(word.length()>1 && word[0] == ' ')
      word.erase(word.begin());
    while(word.length()>1 && word.back() == ' ')
      word.pop_back();
  }
  //Execute da command
  if(parts[0] == "set")
  {
    if(parts.size() != 3)
      return "usage: set option value";
    if(parts[1] == "volume")
    {
      int vol = atoi(parts[2].c_str());
      return "Volume set to "+parts[2];
    }
    else if(parts[1] == "fps")
    {
      int fps = atoi(parts[2].c_str());
      return "FPS set to "+parts[2];
    }
    return "Invalid syntax! Fallback to GUI if you are a noob.";
  }
  return "Invalid syntax! Fallback to GUI if you are a noob.";
}
void Game::showTerminal()
{
  sf::Text text;
  sf::Text introText;
  sf::Text outputText;
  sf::Text cursor;

  sf::Font f;
  f.loadFromFile("assets/Hack-Regular.ttf");
  introText.setFont(f);
  introText.setCharacterSize(14);
  introText.setString("In a world full of GUI users, be a CLI user. Welcome master!");
  introText.setStyle(sf::Text::Style::Regular);
  introText.setPosition(5,0);
  introText.setFillColor(sf::Color::Green);

  outputText.setFont(f);
  outputText.setFillColor(sf::Color::Green);
  outputText.setCharacterSize(14);
  outputText.setString("command output will appear here");
  outputText.setPosition(5,25);

  text.setFont(f);
  text.setString("shell> ");
  text.setCharacterSize(14);
  text.setPosition(5,50);
  text.setFillColor(sf::Color::Green);

  cursor.setFont(f);
  cursor.setString("_");
  cursor.setCharacterSize(14);
  cursor.setPosition(60,50);
  cursor.setFillColor(sf::Color::Green);

  std::string command;
  sf::Clock clock;
  float elapsed = 0;
  bool showCursor = true;
  while (window.isOpen())
  {
    float dt = clock.restart().asSeconds();
    elapsed += dt;
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::TextEntered)
        {
          if (event.text.unicode < 128 && (isalpha(event.text.unicode) || isdigit(event.text.unicode) || event.text.unicode == 32))
          {
            command += static_cast<char>(event.text.unicode);
            text.setString(text.getString() + static_cast<char>(event.text.unicode) );
            cursor.setPosition(cursor.getPosition().x+8,cursor.getPosition().y);
          }
          if(event.text.unicode == 13)//newline
          {
            std::string res = execCommand(command);
            command = "";
            text.setString("shell> ");
            cursor.setPosition(60,50);
            outputText.setString(res);
          }
        }

    }
    window.clear();
    if(elapsed >= 700*dt)
    {
      //toggle cursor
      showCursor = !showCursor;
      elapsed = 0;
    }

    window.draw(introText);
    if(showCursor)
      window.draw(cursor);
    window.draw(outputText);
    window.draw(text);
    window.display();
  }
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

  damage.setSize(sf::Vector2f(0,25));
  damage.setFillColor(sf::Color::Red);
  damage.setPosition(500,0);
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
    
    //player = new Balrog();
    //player = new Chun_Li();
    //player = new Dhalsim();
    player = new Ken();
    //player = new Ryu();
    //player = new Sagat();
    //player = new Zangief();

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
        window.draw(damage);
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

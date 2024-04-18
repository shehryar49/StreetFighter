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
#include "credits.h"
#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#endif

using namespace std;

#define COL_WIDTH 50
#define ROW_HEIGHT 79

vector<string> split(const string& s,char x)
{
  vector<string> parts;
  size_t len = s.length();
  size_t start = 0;
  for(size_t i = 0;i<len;i++)
  {
    if(s[i] == x)
    {
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
    static bool AIBOT = false;
    elapsed += dt;
    player->update(dt);
    if(player->getGlobalBounds().intersects(enemy->getGlobalBounds()))
    {
      if(enemyDamage <= 99.9f)
        enemyDamage += 0.1;
      damage.setSize(sf::Vector2f(enemyDamage*3,25));
      elapsed = 0;
    }
    if(AIBOT && enemy->isIdle())
    {
      float a  = enemy->getGlobalBounds().left - enemy->getGlobalBounds().width;
      float b = player->getGlobalBounds().left + player->getGlobalBounds().width - 1;
      if(a > b - 80)
      {
        enemy->flippedMoveLeft(b);
      }
      int r = rand() % 250;
      if(r == 0)
        enemy->punch1();
      else if(r == 1)
        enemy->punch2();
      else if(r == 2)
        enemy->punch3();
      else if(r == 3)
        enemy->kick1();
      else if(r == 4)
        enemy->kick2();
      //kick3 needs some fixing
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
    //bgm.play();
    bgm.setVolume(40);
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
            //bgm.play();
        }
    }
    window.setFramerateLimit(0);
    bgm.stop();
}

int* Game::selectScreen(){
    int* choices = new int[2];

    sf::Music selector, lockIN, bgm;
    selector.openFromFile("assets/SFX/CMN_HUD_0.wav");
    lockIN.openFromFile("assets/SFX/CMN_HUD_1.wav");
    bgm.openFromFile("assets/SFX/Player Select.wav");
    bgm.setLoop(true);
    //bgm.play();
    sf::Image img;
    if (!img.loadFromFile("assets/Stage Select.png")) 
    {
        cerr << "Error openning file";
        exit(EXIT_FAILURE);
    }
    img.createMaskFromColor(sf::Color(0, 0, 96, 255));
    sf::Texture txtr;
    txtr.loadFromImage(img);
    sf::Sprite map, characters, playerHover, playerName, playerPicture, enemyHover, enemyName, enemyPicture, flag, enemyFlag, selectionName, vs, oneP, twoP;
    sf::IntRect characterNames[12];
    characterNames[0] = sf::IntRect(86, 93, 80, 15);
    characterNames[1] = sf::IntRect(354, 93, 80, 15);
    characterNames[2] = sf::IntRect(629, 93, 80, 15);
    characterNames[3] = sf::IntRect(903, 93, 80, 15);
    characterNames[4] = sf::IntRect(1166, 93, 80, 15);
    characterNames[5] = sf::IntRect(1451, 93, 80, 15);
    characterNames[6] = sf::IntRect(94, 315, 80, 15);
    characterNames[7] = sf::IntRect(349, 315, 80, 15);
    characterNames[8] = sf::IntRect(627, 312, 80, 15);
    characterNames[9] = sf::IntRect(895, 312, 80, 15);
    characterNames[10] = sf::IntRect(1169, 313, 80, 15);
    characterNames[11] = sf::IntRect(1441, 312, 80, 15);

    sf::IntRect characterImages[12];
    characterImages[0] = sf::IntRect(6, 110, 100, 100);
    characterImages[1] = sf::IntRect(274, 110, 100, 100);
    characterImages[2] = sf::IntRect(555, 110, 100, 100);
    characterImages[3] = sf::IntRect(823, 113, 100, 100);
    characterImages[4] = sf::IntRect(1090, 115, 100, 100);
    characterImages[5] = sf::IntRect(1365, 115, 100, 100);
    characterImages[6] = sf::IntRect(6, 342, 100, 100);
    characterImages[7] = sf::IntRect(274, 342, 100, 100);
    characterImages[8] = sf::IntRect(555, 342, 100, 100);
    characterImages[9] = sf::IntRect(823, 343, 100, 100);
    characterImages[10] = sf::IntRect(1090, 343, 100, 100);
    characterImages[11] = sf::IntRect(1364, 343, 100, 100);

    sf::IntRect flags[12];
    flags[0] = sf::IntRect(477, 499, 20, 22); //japan - bottom jap ryu
    flags[1] = sf::IntRect(477, 499, 20, 22); //japan - uper jap e.Honda
    flags[2] = sf::IntRect(477, 499 + 31, 20, 22); //brazil - blanka
    flags[3] = sf::IntRect(477 + 36, 499, 20, 22); //bottom right usa  - guile
    flags[4] = sf::IntRect(477 + 36, 499, 20, 22); //bottom left usa  - balrog
    flags[5] = sf::IntRect(477 + 36 + 36 + 36, 499, 20, 22); //spain - vega
    flags[6] = sf::IntRect(477 + 36, 499, 20, 22); //top right usa  - ken
    flags[7] = sf::IntRect(477 + 36, 499 + 31, 20, 22); //china - chunLi
    flags[8] = sf::IntRect(477 + 36 + 36, 499, 20, 22); //ussr - zangief
    flags[9] = sf::IntRect(477 + 36 + 36, 499 + 31, 20, 22); //india - dhalsim
    flags[10] = sf::IntRect(477 + 36 + 36 + 36, 499 + 31, 20, 22); //thailand - sagat
    flags[11] = sf::IntRect(0, 0, 0, 0); //M.Bison dont have a flag it seems Thailand

    int coordinates[12][2] = {
        {399,226}, //japan - bottom jap ryu
        {427,133}, //japan - uper jap e.Honda
        {567,282}, //brazil - blanka
        {609,191}, //bottom right usa  - guile
        {507,107}, //left usa  - balrog
        {94,79}, //spain - vega
        {599,79}, //top right usa  - ken
        {335,100}, //china - chunLi
        {210,107}, //ussr - zangief
        {223,205}, //india - dhalsim
        {317,268}, //thailand - sagat
        {317,268}, //thailand - M.Bison
    };
    vs.setTexture(txtr);
    vs.setTextureRect(sf::IntRect(0, 0, 0, 0));
    vs.setTextureRect(sf::IntRect(15, 509, 70, 50));
    vs.setScale(1.5, 1.5);
    vs.setPosition(345, 350);
    selectionName.setTexture(txtr);
    selectionName.setTextureRect(sf::IntRect(477, 499 - 26, 120, 25));
    selectionName.setScale(2.5, 2.5);
    selectionName.setPosition(255, 5);
    oneP.setTexture(txtr);
    oneP.setTextureRect(sf::IntRect(110, 470, 20, 15));
    oneP.setScale(2, 2);
    oneP.setPosition(40, 325);
    twoP.setTexture(txtr);
    twoP.setTextureRect(sf::IntRect(143, 470, 20, 15));
    twoP.setScale(2, 2);
    twoP.setPosition(650, 325);
    map.setTexture(txtr);
    map.setTextureRect(sf::IntRect(270,480, 190, 120));
    map.setScale(3.5, 3.5);
    map.setPosition(62.5, 30);
    characters.setTexture(txtr);
    characters.setTextureRect(sf::IntRect(110, 499, 121, 64));
    characters.setScale(2.5, 2.5);
    characters.setPosition(240, 420);
    playerHover.setTexture(txtr);
    playerHover.setTextureRect(sf::IntRect(17, 561, 21, 37));
    playerHover.setScale(2.5, 2.5);
    playerHover.setPosition(240, 410);
    enemyHover.setTexture(txtr);
    enemyHover.setTextureRect(sf::IntRect(48, 561, 21, 37));
    enemyHover.setScale(2.5, 2.5);
    enemyHover.setPosition(240, 410);
    playerName.setTexture(txtr);
    playerName.setTextureRect(characterNames[0]);
    playerName.setScale(2, 2);
    playerName.setPosition(40, 360);
    enemyName.setTexture(txtr);
    enemyName.setTextureRect(characterNames[0]);
    enemyName.setScale(2, 2);
    enemyName.setPosition(650, 360);
    playerPicture.setTexture(txtr);
    playerPicture.setTextureRect(characterImages[0]);
    playerPicture.setScale(2, 2);
    playerPicture.setPosition(25, 400);
    enemyPicture.setTexture(txtr);
    enemyPicture.setTextureRect(characterImages[0]);
    enemyPicture.setScale(-2, 2);
    enemyPicture.setPosition(770, 400);
    flag.setTexture(txtr);
    flag.setTextureRect(flags[0]);
    flag.setScale(3.5, 3.5);
    flag.setPosition(coordinates[0][0], coordinates[0][1]);
    enemyFlag.setTexture(txtr);
    enemyFlag.setTextureRect(flags[0]);
    enemyFlag.setScale(3.5, 3.5);
    enemyFlag.setPosition(0, 0);
    enemyFlag.setPosition(coordinates[0][0], coordinates[0][1]);
    window.clear(sf::Color(0,0,96,255));
    window.draw(map);
    window.draw(characters);
    window.draw(playerHover);
    window.draw(playerName);
    window.draw(playerPicture);
    window.draw(flag);
    window.draw(selectionName);
    window.draw(vs);
    window.draw(oneP);
    window.display();
    sf::Event e;
    bool end = false;
    bool second = false;
    choices[0] = choices[1] = 1;
    int indx = 0, selection = 0;
    while (!end)
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == sf::Keyboard::Enter)
                {
                    //lockIN.play();
                    if (second)
                    {
                        end = true;
                        #ifdef _WIN32
                            Sleep(1000);
                        #elif __linux__
                            sleep(1);
                        #endif
                    }
                    else 
                    {
                        second = true;
                        indx++;
                        selection = 0;
                        selectionName.setTextureRect(sf::IntRect(477, 570, 120, 20));
                        selectionName.setScale(3, 3);
                        window.clear(sf::Color(0, 0, 96, 255));
                        window.draw(map);
                        window.draw(characters);
                        window.draw(playerHover);
                        window.draw(enemyHover);
                        window.draw(enemyName);
                        window.draw(playerName);
                        window.draw(playerPicture);
                        window.draw(enemyPicture);
                        window.draw(flag);
                        window.draw(enemyFlag);
                        window.draw(vs);
                        window.draw(selectionName);
                        window.draw(oneP);
                        window.draw(twoP);
                        window.display();
                    }
                    break;
                }
                else if (e.key.code == sf::Keyboard::Right && ((choices[indx] < 6) || (choices[indx] > 6 && choices[indx] < 12)))
                {
                    /////selector.play();
                    if (second)
                    {
                        enemyHover.setPosition(enemyHover.getPosition().x + COL_WIDTH, enemyHover.getPosition().y);
                        choices[1]++;
                        enemyName.setTextureRect(characterNames[++selection]);
                        enemyPicture.setTextureRect(characterImages[selection]);
                        enemyFlag.setTextureRect(flags[selection]);
                        enemyFlag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }
                    else
                    {
                        playerHover.setPosition(playerHover.getPosition().x + COL_WIDTH, playerHover.getPosition().y);
                        choices[0]++;
                        playerName.setTextureRect(characterNames[++selection]);
                        playerPicture.setTextureRect(characterImages[selection]);
                        flag.setTextureRect(flags[selection]);
                        flag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }
                    
                }
                else if (e.key.code == sf::Keyboard::Left && ((choices[indx] > 1 && choices[indx] <= 6) || (choices[indx] > 7 && choices[indx] <= 12)))
                {
                    //selector.play();
                    if (second)
                    {
                        enemyHover.setPosition(enemyHover.getPosition().x - COL_WIDTH, enemyHover.getPosition().y);
                        choices[1]--;
                        enemyName.setTextureRect(characterNames[--selection]);
                        enemyPicture.setTextureRect(characterImages[selection]);
                        enemyFlag.setTextureRect(flags[selection]);
                        enemyFlag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }
                    else
                    {
                        playerHover.setPosition(playerHover.getPosition().x - COL_WIDTH, playerHover.getPosition().y);
                        choices[0]--;
                        playerName.setTextureRect(characterNames[--selection]);
                        playerPicture.setTextureRect(characterImages[selection]);
                        flag.setTextureRect(flags[selection]);
                        flag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }
                    
                }
                else if (e.key.code == sf::Keyboard::Down && choices[indx] < 7)
                {
                    //selector.play();
                    selection += 6;
                    if (second)
                    {
                        enemyHover.setPosition(enemyHover.getPosition().x, enemyHover.getPosition().y + ROW_HEIGHT);
                        choices[1] += 6;
                        enemyName.setTextureRect(characterNames[selection]);
                        enemyPicture.setTextureRect(characterImages[selection]);
                        enemyFlag.setTextureRect(flags[selection]);
                        enemyFlag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }
                    else
                    {
                        playerHover.setPosition(playerHover.getPosition().x, playerHover.getPosition().y + ROW_HEIGHT);
                        choices[0] += 6;
                        playerName.setTextureRect(characterNames[selection]);
                        playerPicture.setTextureRect(characterImages[selection]);
                        flag.setTextureRect(flags[selection]);
                        flag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }

                }
                else if (e.key.code == sf::Keyboard::Up && choices[indx] > 6)
                {
                    //selector.play();
                    selection -= 6;
                    if (second)
                    {
                        enemyHover.setPosition(enemyHover.getPosition().x, enemyHover.getPosition().y - ROW_HEIGHT);
                        choices[1] -= 6;
                        enemyName.setTextureRect(characterNames[selection]);
                        enemyPicture.setTextureRect(characterImages[selection]);
                        enemyFlag.setTextureRect(flags[selection]);
                        enemyFlag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }
                    else
                    {
                        playerHover.setPosition(playerHover.getPosition().x, playerHover.getPosition().y - ROW_HEIGHT);
                        choices[0] -= 6;
                        playerName.setTextureRect(characterNames[selection]);
                        playerPicture.setTextureRect(characterImages[selection]);
                        flag.setTextureRect(flags[selection]);
                        flag.setPosition(coordinates[selection][0], coordinates[selection][1]);
                    }
                }
                window.clear(sf::Color(0, 0, 96, 255));
                window.draw(map);
                window.draw(characters);
                window.draw(playerHover);
                window.draw(playerName);
                window.draw(playerPicture);
                window.draw(flag);
                window.draw(vs);
                window.draw(selectionName);
                window.draw(oneP);
                if (second)
                {
                    window.draw(enemyHover);
                    window.draw(enemyName);
                    window.draw(enemyPicture);
                    window.draw(enemyFlag);
                    window.draw(twoP);
                }
                window.display();
            }

        }
    }
    bgm.stop();
    return choices;
}

std::string Game::execCommand(const std::string& command)
{
  if (command == "exit" || command == "quit" || command == "yawr")
     return "exit";
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
  outputText.setString("Command output will appear here");
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
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace && command.length() >= 1)
        {
          command.pop_back();
          text.setString("shell> "+command);
          cursor.setPosition(cursor.getPosition().x-8,cursor.getPosition().y);
        }
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
            if (res == "exit")
                return;
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
void Game::showCredits() 
{
    sf::Font font;
    font.loadFromFile("assets/crunch_chips.otf");//for consistency
    backgroundTexture.loadFromFile("SF2.jpeg");
    background.setTexture(backgroundTexture);
    background.setScale(1.5, 1.1);
    Credits credits(window, font, background);
    credits.run();
}

int Game::showMenu()
{
  const char* entries[] = {"Play","Credits","Settings","Quit"};
  Menu m(entries,4);
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
  srand(time(0)); //use epoch time as seed 
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
    ////key was pressed, so we are back after playing intro
    //while (true) 
    //{
    //    int option = showMenu();
    //    //some option was selected from the menu
    //    if (option == 0) //option 0 is play
    //        break;
    //    else if (option == 1)
    //        showCredits();
    //    else if (option == 2)
    //        showTerminal();
    //    else if (option == 3)
    //        return;
    //}
    int* character = nullptr;
    //character = selectScreen();
    //setStage(character);
    int idek[2] = { 8, 9 }; //set character and enemy index from here for faster debugging/testing
    int* set = idek;
    setStage(set);
    sf::Music stageSet;
    stageSet.openFromFile("assets/SFX/VS.wav");
    //stageSet.play();
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
    delete[] character;
}

void Game::playMusic(const char* filename) 
{
    if (bgm.getStatus() == sf::Music::Playing)
        bgm.stop(); //if any music was playing before
    if (!(bgm.openFromFile(filename)))
        perror("Error loading assets\n");
    bgm.setVolume(10);
    bgm.setLoop(true); //infinitely play song on loop
    //bgm.play();
}

void Game::setStage(int* c)
{
    switch (c[0]) 
    {
        case 1:
            player = new Ryu();
            break;
        case 5:
            player = new Balrog();
            break;
        case 7:
            player = new Ken();
            break;
        case 8:
            player = new Chun_Li();
            break;
        case 9:
            player = new Zangief();
            break;
        case 10:
            player = new Dhalsim();
            break;
        case 11:
            player = new Sagat();
            break;
        default:
            player = new Ryu();
            break;
    }
    switch (c[1]) 
    {
        case 1:
            enemy = new Ryu();
            backgroundTexture.loadFromFile("assets/Ryu Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.4f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(150, 0, 600, 230));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
        case 5:
            enemy = new Balrog();
            backgroundTexture.loadFromFile("assets/Balrog Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(2.1f, 2.5f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(280, 0, 800, 400));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
        case 7:
            enemy = new Ken();
            backgroundTexture.loadFromFile("assets/Ken Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.4f, 3.0f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(100, 0, 800, 400));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
        case 8:
            enemy = new Chun_Li();
            backgroundTexture.loadFromFile("assets/ChunLi Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.2f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(65, 0, 800, 400));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
        case 9:
            enemy = new Zangief();
            backgroundTexture.loadFromFile("assets/Zangief Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.2f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(65, 0, 800, 400));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
        case 10:
            enemy = new Dhalsim();
            backgroundTexture.loadFromFile("assets/Dhalsim Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.2f, 2.5f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(50, 0, 800, 400));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
        case 11:
            enemy = new Sagat();
            backgroundTexture.loadFromFile("assets/Sagat Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.4f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(150, 0, 600, 230));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
        default:
            enemy = new Ryu();
            backgroundTexture.loadFromFile("assets/Ryu Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.4f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(150, 0, 600, 230));
            playMusic("assets/SFX/Theme_of_Ryu.ogg");
            break;
    }
    //was common in all
    enemy->flipX();
    player->setPosition(120, BOTTOMY - (player->getGlobalBounds().height) + 1);
    enemy->setPosition(650, BOTTOMY - (enemy->getGlobalBounds().height) + 1);
    
}
Game::~Game()
{
    if(player)
      delete player;
    if(enemy)
      delete enemy;
}

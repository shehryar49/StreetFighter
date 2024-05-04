 #include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
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
#include "utils.h"

#ifdef _WIN32
  #include <Windows.h>
#elif  __linux__
  #include <unistd.h>
#endif

using namespace std;

#define COL_WIDTH 50
#define ROW_HEIGHT 79


//public
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
  playerDamage.setSize(sf::Vector2f(0,25));
  playerDamage.setFillColor(sf::Color::Red);
  playerDamage.setPosition(0,0);

  enemyDamage.setSize(sf::Vector2f(0,25));
  enemyDamage.setFillColor(sf::Color::Red);
  enemyDamage.setPosition(500,0);
  
  //Load sounds
  intro_music = smg.load("assets/intro/intro.ogg");
  player_selected_music = smg.load("assets/SFX/CMN_HUD_0.wav");
  player_lockin_music =  smg.load("assets/SFX/CMN_HUD_1.wav");
  player_selectionbgm_music = smg.load("assets/SFX/Player Select.wav");
  vs_music = smg.load("assets/SFX/VS.wav");
  fight_bgm = -1;//smg.load("assets/SFX/Theme_of_Ryu.ogg");
  terminal_music = smg.load("assets/SFX/hackerman.wav");
  smg.setVolume(100); // change volume here or using terminal
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
                  if(player->jump())
                      smg.play(player_voice_lines[3]);
                  break;
                case sf::Keyboard::Down:
                  player->crouch();
                  break;
                case sf::Keyboard::Q:
                  if(player->specialMove1())
                      smg.play(player_voice_lines[4]);
                  break;
                case sf::Keyboard::W:
                  if(player->specialMove2())
                      smg.play(player_voice_lines[5]);
                  break;
                case sf::Keyboard::A:                  
                    if (player->punch1())
                        smg.play(player_voice_lines[0]);
                  break;
                case sf::Keyboard::S:
                  if(player->punch2())
                      smg.play(player_voice_lines[1]);
                  break;
                case sf::Keyboard::D:
                  if(player->punch3())
                      smg.play(player_voice_lines[2]);
                  break;
                case sf::Keyboard::Z:
                  if(player->kick1())
                      smg.play(player_voice_lines[0]);
                  break;
                case sf::Keyboard::X:
                  if(player->kick2())
                      smg.play(player_voice_lines[1]);
                  break;
                case sf::Keyboard::C:
                  if(player->kick3())
                      smg.play(player_voice_lines[2]);
                  break;
                case sf::Keyboard::LShift:
                  player->block();
                  break;
                case sf::Keyboard::B:
                  player->bodyHit();
                  break;
                case sf::Keyboard::J:
                  enemy->flippedMoveLeft(0);
                  break;
                case sf::Keyboard::K:
                 // player->knockout();
                  break;
                default:
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
    static float elapsed1 = 0;
    static float elapsed2 = 0;
    static float elapsed3 = 0;
    static int hits = 0;
    elapsed1 += dt;
    elapsed2 += dt;
    elapsed3 += dt;
    player->update(dt);
	//check projectile damage
	if(player->projectile_active && player->projectile.getGlobalBounds().intersects(enemy->getGlobalBounds()))
	{
		if(enemy->damage <= 95.0f)
			enemy->damage+=5.0f;
		enemyDamage.setSize(sf::Vector2f(enemy->damage*3,25)); 
        if(enemy->damage == 100.0f)
        {
          	enemy->knockout(&game_over);
          	await_game_over = true;
        }
      	else
        	enemy->bodyHit();  
		player->projectile_active = false;
	}
    //check if player hit enemy
    if(elapsed1>=0.4f && player->getGlobalBounds().intersects(enemy->getGlobalBounds()) && !enemy->isAttacking() && player->isAttacking() && !enemy->isSuffering())
    {
      //1.0f
        if(enemy->damage <= 95.0f)
          enemy->damage += 5.0f;
        enemyDamage.setSize(sf::Vector2f(enemy->damage*3,25)); 
      	if(enemy->damage == 100.0f)
      	{
			player->victory();
        	enemy->knockout(&game_over);
        	await_game_over = true;
      	}
      	else
        	enemy->bodyHit();     
      	elapsed1 = 0;
      	hits++;
    }
    enemy->update(dt);
    //give damage to player
    if(elapsed1!=0 && elapsed2>=0.4f && player->getGlobalBounds().intersects(enemy->getGlobalBounds()) && !player->isAttacking() && !player->isSuffering() && enemy->isAttacking() && !enemy->isSuffering())
    {
      if(player->damage <= 99.0f)
        player->damage += 1.0f;
      playerDamage.setSize(sf::Vector2f(player->damage*3,25));
      if(player->damage == 100.0f)
      {
        player->knockout(&game_over);
        await_game_over = true;
      }
      else
        player->bodyHit();
      elapsed2 = 0;
    }
    // set up things for next updation
    bool AIBOT = true && !await_game_over;
	
    if(elapsed3 >= 1.0f && AIBOT && enemy->isIdle())
    {
        float a  = enemy->getGlobalBounds().left - enemy->getGlobalBounds().width;
      	float b = player->getGlobalBounds().left + player->getGlobalBounds().width - 1;
      	if(hits >= 5 && a <= b-80)
        {
        	enemy->flippedMoveRight(WINDOW_WIDTH);
        	elapsed3 = 0;
        	hits = 0;
        	return;
        }
        else if(a > b - 80)
      	{
        	enemy->flippedMoveLeft(b);
        	elapsed3 = 0;
          	return;
      	}
      	int r = rand() % 6;
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
		else if(r == 5)
  			enemy->kick3();
        elapsed3 = 0;
    }

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
    // all frames loaded
    sf::Sprite s;
    s.setScale(1.7f, 1.7f);
    int i = 0;
    window.setFramerateLimit(30); //run at 30fps
    smg.play(intro_music);

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
                smg.stop(intro_music);
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
            smg.play(intro_music);//restart music
        }
    }
    window.setFramerateLimit(0);
    smg.stop(intro_music);
}
void Game::gameOver()
{
  sf::Font f;
  f.loadFromFile("assets/Hack-Regular.ttf");
  sf::Text t;
  t.setFont(f);
  t.setCharacterSize(28);
  t.setFillColor(sf::Color::White);
  t.setPosition(320,280);
  t.setString("Game Over");
  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
          if (event.type == sf::Event::KeyPressed)
          {
              return;
          }
      }
      window.clear();
      window.draw(t);
      window.display();
  }
  
}
int* Game::selectScreen()
{
    int* choices = new int[2];
    smg.play(player_selectionbgm_music,true);
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
    
    sf::IntRect characterNames[12] = {
      sf::IntRect(86, 93, 80, 15),
      sf::IntRect(354, 93, 80, 15),
      sf::IntRect(629, 93, 80, 15),
      sf::IntRect(903, 93, 80, 15),
      sf::IntRect(1166, 93, 80, 15),
      sf::IntRect(1451, 93, 80, 15),
      sf::IntRect(94, 315, 80, 15),
      sf::IntRect(349, 315, 80, 15),
      sf::IntRect(627, 312, 80, 15),
      sf::IntRect(895, 312, 80, 15),
      sf::IntRect(1169, 313, 80, 15),
      sf::IntRect(1441, 312, 80, 15)
    };
    sf::IntRect characterImages[12] = {
      sf::IntRect(6, 110, 100, 100),
      sf::IntRect(274, 110, 100, 100),
      sf::IntRect(555, 110, 100, 100),
      sf::IntRect(823, 113, 100, 100),
      sf::IntRect(1090, 115, 100, 100),
      sf::IntRect(1365, 115, 100, 100),
      sf::IntRect(6, 342, 100, 100),
      sf::IntRect(274, 342, 100, 100),
      sf::IntRect(555, 342, 100, 100),
      sf::IntRect(823, 343, 100, 100),
      sf::IntRect(1090, 343, 100, 100),
      sf::IntRect(1364, 343, 100, 100)
    };
    sf::IntRect flags[12] = {
      sf::IntRect(477, 499, 20, 22), //japan - bottom jap ryu
      sf::IntRect(477, 499, 20, 22), //japan - uper jap e.Honda
      sf::IntRect(477, 499 + 31, 20, 22), //brazil - blanka
      sf::IntRect(477 + 36, 499, 20, 22), //bottom right usa  - guile
      sf::IntRect(477 + 36, 499, 20, 22), //bottom left usa  - balrog
      sf::IntRect(477 + 36 + 36 + 36, 499, 20, 22), //spain - vega
      sf::IntRect(477 + 36, 499, 20, 22), //top right usa  - ken
      sf::IntRect(477 + 36, 499 + 31, 20, 22), //china - chunLi
      sf::IntRect(477 + 36 + 36, 499, 20, 22), //ussr - zangief
      sf::IntRect(477 + 36 + 36, 499 + 31, 20, 22), //india - dhalsim
      sf::IntRect(477 + 36 + 36 + 36, 499 + 31, 20, 22), //thailand - sagat
      sf::IntRect(0, 0, 0, 0) //M.Bison dont have a flag it seems Thailand
    };
    float coordinates[12][2] = {
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
    sf::Sprite* pointers[] = {
      &vs,
      &selectionName,
      &oneP,
      &twoP,
      &map,
      &characters,
      &playerHover,
      &enemyHover,
      &playerName,
      &enemyName,
      &playerPicture,
      &enemyPicture,
      &flag,
      &enemyFlag
    };
    sf::IntRect rects[] = {
      sf::IntRect(15, 509, 70, 50),
      sf::IntRect(477, 499 - 26, 120, 25),
      sf::IntRect(110, 470, 20, 15),
      sf::IntRect(143, 470, 20, 15),
      sf::IntRect(270,480, 190, 120),
      sf::IntRect(110, 499, 121, 64),
      sf::IntRect(17, 561, 21, 37),
      sf::IntRect(48, 561, 21, 37),
      characterNames[0],
      characterNames[0],
      characterImages[0],
      characterImages[0],
      flags[0],
      flags[0],
    };

    float scale_x[] = {1.5,2.5,2,2,3.5,2.5,2.5,2.5,2,2,2,-2,3.5,3.5};
    float scale_y[] = {1.5,2.5,2,2,3.5,2.5,2.5,2.5,2,2,2,2,3.5,3.5};
    float pos_x[] = {345,255,40,650,62.5,240,240,240,40,650,25,770,coordinates[0][0],coordinates[0][0]};
    float pos_y[] = {350,5,325,325,30,420,410,410,360,360,400,400,coordinates[0][1],coordinates[0][1]};

    for(int i = 0; i < sizeof(pointers)/sizeof(sf::Sprite*); i++)
    {
      sf::Sprite* curr = pointers[i];
      curr->setTexture(txtr);
      curr->setTextureRect(rects[i]);
      curr->setScale(scale_x[i],scale_y[i]);
      curr->setPosition(pos_x[i],pos_y[i]);
    }
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
                    smg.play(player_lockin_music);
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
                    smg.play(player_selected_music);
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
                    smg.play(player_selected_music);
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
                    smg.play(player_selected_music);
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
                    smg.play(player_selected_music);
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
    smg.stop(player_selectionbgm_music);
    return choices;
}

std::string Game::execCommand(const std::string& command)
{
  if (command == "exit" || command == "quit" || command == "yawr" || command == "")
    return "exit";

  vector<string> parts = split(command,' ');
  //remove extra space from each word
  for(size_t i=0;i<parts.size();i++)
    strip(parts[i]);

  //Execute da command
  if(parts[0] == "set")
  {
    if(parts.size() != 3)
      return "usage: set option value";
    if(parts[1] == "volume")
    {
      int vol = atoi(parts[2].c_str());
      if(vol < 0 || vol >= 100)
        return "Volume must be in range [0,100]";
      smg.setVolume(vol);
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
  outputText.setString("Your wish is my command, master.");
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
  smg.play(terminal_music);
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

void Game::run()
{
  playIntro();
  while(true)
  {
    int option = showMenu();
    if(option == 0)
      break;
    else if(option == 1)
      showCredits();
    else if(option == 2)
      showTerminal();
    else if(option == 3)
      return;
  }
  int* character = selectScreen();
  setStage(character);
  smg.play(vs_music);
  while (window.isOpen())
  {
    pollEvents();
    float dt = clock.restart().asSeconds();
    update(dt);
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(health1);
    window.draw(health2);
    window.draw(playerDamage);
    window.draw(enemyDamage);
    player->render(window);
    enemy->render(window);
    window.display();
  }
  delete[] character;
}
void Game::testRun()
{
    smg.setVolume(0);
    window.setFramerateLimit(0);
    int* character = nullptr;
    int idek[2] = { 8,8 }; //set character and enemy index from here for faster debugging/testing(no so fast when you have to look integers)
    // - remember em then - ok my fuhrer
    int* set = idek;
    setStage(set);
    smg.play(vs_music);
    while (!game_over && window.isOpen())
    {
        pollEvents();
        float dt = clock.restart().asSeconds();
        update(dt);
        window.clear(sf::Color::Black);
        window.draw(background);
        window.draw(health1);
        window.draw(health2);
        window.draw(playerDamage);
        window.draw(enemyDamage);
        player->render(window);
        enemy->render(window);
        window.display();
    }
    if(game_over && window.isOpen())
	{
	  #ifdef __linux
	  sleep(2);
	  #endif
      gameOver();
	}
    delete[] character;
}

void Game::setVoiceLines(int c, string path = "")
{
    switch (c)
    {
        case -2: //loading for player
            for (int i = 0; i < NO_OF_VOICE_LINES; i++)
                player_voice_lines[i] = smg.load(path + to_string(i) + ".wav");
            return;
        case -1: //loading for enemy diff to player
            for (int i = 0; i < NO_OF_VOICE_LINES; i++)
                enemy_voice_lines[i] = smg.load(path + to_string(i) + ".wav");
            return;
        default: //loading for enemy same as player
            for (int i = 0; i < NO_OF_VOICE_LINES; i++)
                enemy_voice_lines[i] = player_voice_lines[i];
            return;
    }
}

void Game::setStage(int* c)
{
    switch (c[0]) 
    {
        case 1:
            player = new Ryu();
            setVoiceLines(-2, "assets/PlayerVoiceLines/Ryu/");
            break;
        case 5:
            player = new Balrog();
            setVoiceLines(-2, "assets/PlayerVoiceLines/Balrog/");
            break;
        case 7:
            player = new Ken();
            setVoiceLines(-2, "assets/PlayerVoiceLines/Ken/");
            break;
        case 8:
            player = new Chun_Li();
            setVoiceLines(-2, "assets/PlayerVoiceLines/ChunLi/");
            break;
        case 9:
            player = new Zangief();
            setVoiceLines(-2,"assets/PlayerVoiceLines/Zangief/");
            break;
        case 10:
            player = new Dhalsim();
            setVoiceLines(-2, "assets/PlayerVoiceLines/Dhalsim/");
            break;
        case 11:
            player = new Sagat();
            break;
        default:
            player = new Ryu();
            setVoiceLines(-2, "assets/PlayerVoiceLines/Ryu/");
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
            if (c[0] == c[1])
                setVoiceLines(c[0]);
            else
                setVoiceLines(-1, "assets/PlayerVoiceLines/Ryu/");
            smg.play(fight_bgm);
            break;
        case 5:
            enemy = new Balrog();
            backgroundTexture.loadFromFile("assets/Balrog Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(2.1f, 2.5f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(280, 0, 800, 400));
            if (c[0] == c[1]) // reuse audio
                setVoiceLines(c[0]);
            else
                setVoiceLines(-1, "assets/PlayerVoiceLines/Zangief/");
            smg.play(fight_bgm);
            break;
        case 7:
            enemy = new Ken();
            backgroundTexture.loadFromFile("assets/Ken Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.4f, 3.0f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(100, 0, 800, 400));
            if (c[0] == c[1])
                setVoiceLines(c[0]);
            else
                setVoiceLines(-1, "assets/PlayerVoiceLines/Ken/");
            smg.play(fight_bgm);
            break;
        case 8:
            enemy = new Chun_Li();
            backgroundTexture.loadFromFile("assets/ChunLi Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.2f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(65, 0, 800, 400));
            if (c[0] == c[1])
                setVoiceLines(c[0]);
            else
                setVoiceLines(-1, "assets/PlayerVoiceLines/ChunLi/");
            smg.play(fight_bgm);
            break;
        case 9:
            enemy = new Zangief();
            backgroundTexture.loadFromFile("assets/Zangief Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.2f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(65, 0, 800, 400));
            if (c[0] == c[1])
                setVoiceLines(c[0]);
            else
                setVoiceLines(-1, "assets/PlayerVoiceLines/Zangief/");
            smg.play(fight_bgm);
            break;
        case 10:
            enemy = new Dhalsim();
            backgroundTexture.loadFromFile("assets/Dhalsim Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.2f, 2.5f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(50, 0, 800, 400));
            if (c[0] == c[1])
                setVoiceLines(c[0]);
            else
                setVoiceLines(-1, "assets/PlayerVoiceLines/Dhalsim/");
            smg.play(fight_bgm);
            break;
        case 11:
            enemy = new Sagat();
            backgroundTexture.loadFromFile("assets/Sagat Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.4f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(150, 0, 600, 230));
            smg.play(fight_bgm);
            break;
        default:
            enemy = new Ryu();
            backgroundTexture.loadFromFile("assets/Ryu Stage.png");
            background.setTexture(backgroundTexture);
            background.setScale(1.4f, 2.8f);
            background.setPosition(0, 0);
            background.setTextureRect(sf::IntRect(150, 0, 600, 230));
            setVoiceLines(-1, "assets/PlayerVoiceLines/Ryu/");
            smg.play(fight_bgm);
            smg.play(fight_bgm);
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

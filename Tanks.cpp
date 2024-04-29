//#define __CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW

#include <SFML/Graphics.hpp>
#include <iostream>
#include<windows.h>
#include<fstream>
#include "ClassTexture.h"
#include "ClassFloatRect.h"
#include "Items.h"
#include <SFML/Audio.hpp>
#include "Map.h"
#define KEY(x) Keyboard::isKeyPressed(Keyboard::x)



#define OBJECTS 20000






using namespace sf;
using namespace std;
using namespace Items;
using namespace Map;


#include "ClassObject.h"
#include "ClassBullet.h"
#include "ClassPlayer.h"
#include "ClassEnemy.h"
#include "ClassHeadquarters.h"
#include "ClassBrick.h"
#include "ClassMenu.h"
#include "ClassTnt.h"
#include "ClassExplosion.h"
#include "ClassConstructorLevel.h"



int main()
{
    srand(time(NULL));
 

    RenderWindow window(VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Tanks", sf::Style::Fullscreen);//sf::Style::Fullscreen

    window.setMouseCursorVisible(false);
    View view;
    view.reset(sf::FloatRect(0, 0, sizeScreenWidht, sizeScreenHeight+9));
    window.setView(view);

 


    writeMap();

    
    ClassObject* ListObjects[OBJECTS];

    for (int i = 0; i < OBJECTS; ++i) {
        ListObjects[i] = new ClassObject(-100.0f, -100.0f, ListObjects);
    }

    


    RenderTexture backTexture;
    
    backTexture.create((int)sizeScreenWidht, (int)sizeScreenHeight);

    //Music music;
    //music.openFromFile("music/music.ogg");
    //
    //Music musicMain;
    //musicMain.openFromFile("music/main.ogg");

    ClassMenu menu = ClassMenu();

    ConstructorLevel LevelConstructor;

    

    bool clockChangeLevelIgnore= true;

    int count_frame = 0;
    Clock clockFrame;
    Event key;
    Clock clock;
    Clock clockChangeLevel;
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    while (window.isOpen())

        {
        
        deltaShift = clock.restart().asSeconds();


        if (menu.menuIsOpen) {
            window.clear(Color(87, 90, 87, 255));
        }
        else {
            window.clear(Color(0, 0, 0, 255));
        }


        while (window.pollEvent(key))
        {
            if (key.type == Event::Closed) window.close();
        }

        if (KEY(Escape) && !menu.menuIsOpen) {
            menu.menuIsOpen = true;
        }


        if (!menu.menuIsOpen) {



            if (menu.makeLevel && (clockChangeLevelIgnore || clockChangeLevel.getElapsedTime().asSeconds() > 5.0f)) {
               
                LevelConstructor.makeLevel(ListObjects, menu.countPlayers, backTexture);
                //musicMain.play();
                menu.makeLevel = false;
                clockChangeLevelIgnore = false;
            }


            //count_frame += 1;
            //if (clockFrame.getElapsedTime().asSeconds() > 1.0f) {
            //    clockFrame.restart().asSeconds();
            //    cout << count_frame << endl;
            //    count_frame = 0;
            //}

            if (ListObjects[0]->typeObject == PLAYER) {
                ListObjects[0]->keys(KEY(S), KEY(A), KEY(D), KEY(W), KEY(E), backTexture);
            }
            if (ListObjects[1]->typeObject == PLAYER) {
                ListObjects[1]->keys(KEY(K), KEY(J), KEY(L), KEY(I), KEY(O), backTexture);
            }
           
            

            int countEnemy = 0;
            int countPlayers = 0;
            int countHeadquarter = 0;

            for (int i = 0; i < countObjects; ++i) {
                if (ListObjects[i]->typeObject == ENEMY) {
                    countEnemy += 1;
                }
                else if (ListObjects[i]->typeObject == PLAYER) {
                    countPlayers += 1;
                }
                else if (ListObjects[i]->typeObject == HEADQUARTERS) {
                    countHeadquarter += 1;
                }

                if (ListObjects[i]->armor > 0.0f) {
                    ListObjects[i]->update(backTexture);
                }
                else {

                    if (ListObjects[i]->typeObject == BRICK_LARGE || ListObjects[i]->typeObject == BRICK_LITTLE) {
                        backTexture.draw(ListObjects[i]->backSprite);
                    }

                    if (ListObjects[i]->typeObject == TNT || ListObjects[i]->typeObject == ENEMY || ListObjects[i]->typeObject == PLAYER) {
                        playerRewardPoints += ListObjects[i]->rewardPoint;
                        float x = ListObjects[i]->rect.centerX() - 12.0f;
                        float y = ListObjects[i]->rect.centerY() - 12.0f;
                        delete ListObjects[i];
                        ListObjects[i] = new Explosion(x, y, ListObjects);
                    }
                    else {
                        playerRewardPoints += ListObjects[i]->rewardPoint;
                        delete ListObjects[i];
                        ListObjects[i] = new ClassObject(-100.0f, -100.0f, ListObjects);
                    }

                }
            };

            if (countEnemy == 0 && !menu.makeLevel && countLevel< countlevels-1) {
                countLevel += 1;
       
                menu.makeLevel = true;
                clockChangeLevel.restart().asSeconds();
            }
            if ((countPlayers == 0 || countHeadquarter==0) && !menu.makeLevel) {

                if (countLevel > 0) {
                    countLevel -= 1;
                }

                menu.makeLevel = true;
                clockChangeLevel.restart().asSeconds();
            }

            //backTexture.display();

            //
            
            Sprite backSprite(backTexture.getTexture());

          

            window.draw(backSprite);
            for (int i = 0; i < countObjects; ++i) {
                if (ListObjects[i]->typeObject != EMPTY && ListObjects[i]->typeObject != BRICK_LARGE && ListObjects[i]->typeObject != BRICK_LITTLE) {
                    ListObjects[i]->sprite.setPosition(ListObjects[i]->rect.left, ListObjects[i]->rect.top);
                    window.draw(ListObjects[i]->sprite);
                    if (ListObjects[i]->isBurn) {
                        Textures.burnSprite.setTextureRect(IntRect(0, int(ListObjects[i] ->stepBurn) * 10, 10, 10));
                        Textures.burnSprite.setPosition(ListObjects[i]->rect.left, ListObjects[i]->rect.top);
                        window.draw(Textures.burnSprite);
                    };
                }
            };


            int copyRewardPoint = playerRewardPoints;
            if (copyRewardPoint > 0) {

                float positionNumber = 350;

                int number = 0;
                while (copyRewardPoint > 0) {
                    number = copyRewardPoint % 10;
                    positionNumber -= 4.0f;
                    Textures.numbersSprite.setTextureRect(IntRect(number * 4, 0, 4, 7));
                    Textures.numbersSprite.setPosition(positionNumber, 229.0f);
                    window.draw(Textures.numbersSprite);

                    copyRewardPoint = copyRewardPoint / 10;
                }

            }

            if (headquartersInTarget) {
                Textures.targetSprite.setPosition(1.0f, 229.0f);
                window.draw(Textures.targetSprite);
            }
        
       
            

        }
        else {
            menu.menuView(window);
        }
        
        window.display();
}

//_CrtDumpMemoryLeaks();
//return 0;
}


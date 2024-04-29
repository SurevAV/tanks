#pragma once

#define UP 0
#define RIGHT 1
#define LEFT 2
#define DOWN 3

#define EMPTY 0
#define PLAYER 1
#define ENEMY 2
#define BULLET 3

#define HEADQUARTERS 4

#define BRICK_LARGE 5
#define BRICK_LITTLE 6
#define BRICK_ROCK 7

#define TNT 8
#define EXPLOSION 9

#define BULLET_LITTLE 100
#define BULLET_LARGE 101

#define COLLISION listObjects[i]->typeObject != EMPTY && rect.intersects(listObjects[i]->rect) && listObjects[i]->typeObject != BULLET && listObjects[i] != this && listObjects[i]->typeObject != EXPLOSION 
#define TEXTURE_RECT sprite.setTextureRect(IntRect(int(stepAnimation)*10, direction * 10, 10, 10));
#define MOVE(_down, _left, _right, _up, _coordinate, _identificatorPusher)if (listObjects[i]->typeObject == TNT || listObjects[i]->typeObject == BRICK_ROCK) { listObjects[i]->move(_down, _left, _right, _up, _coordinate, _identificatorPusher); }

#define IDENTIFICATION identificator = countIdentification; countIdentification +=1;

#define RECOVERY_ENGINE_MULTIPLIER engineMultiplier += 0.2f * deltaShift; if (engineMultiplier > 1.5f) engineMultiplier = 1.5f;
#define REDUCE_ENGINE_MULTIPLIER engineMultiplier -= 0.4f * deltaShift; if (engineMultiplier < 1.0f) engineMultiplier =1.0f;

#define NOTPUSHER && listObjects[i]->identificator != identificatorPusher

#define RANDOM4 (rand() * (int)(4) / RAND_MAX) 
#define RANDOM2 (rand() * (int)(2) / RAND_MAX) 

class ClassObject
{

public:

    FloatRectItem rect;
    Sprite sprite;
    Sprite backSprite;
    float shift = 5.0f;
    ClassObject** listObjects;

    Clock clockBullet;

    Clock clockMarkTank;
    int typeObject = EMPTY;
    int direction = 0;
    float armor = 1.0f;
    float reboundProbability = 0.0f;

    float stepAnimation = 0.0f;
    int typeBullet = BULLET_LITTLE;

    int identificator = 0;
    float engineMultiplier = 1.5f;

    bool isBurn = false;
    float stepBurn = 0.0f;

    float surfaceMultiplier = 1.0f;

    int rewardPoint = 1;




    ClassObject(float _x, float _y, ClassObject** _listObjects) {
        rect = FloatRectItem(_x, _y);
        typeObject = EMPTY;
    }

    virtual ~ClassObject() {
    }

    virtual void update(RenderTexture& backTexture)
    {
        
    }

    virtual void makeBullet()
    {
    }

    virtual void checkBurn()
    {
        if (isBurn) {
            stepBurn += deltaShift * 2.0f;
            if (stepBurn >= 10.0f) {
                armor = -1.0f;
            }
        }
    }

    virtual void move(bool down, bool left, bool right, bool up, float coordinate, int identificatorPusher) {
        if (down) {

            rect.setTop(coordinate + 0.01f);

            for (int i = 0; i < countObjects; ++i) {
                if (COLLISION NOTPUSHER) rect.setTop(listObjects[i]->rect.top - rect.height);

            }
            if (rect.getDown() > sizeScreenHeight) {
                rect.setTop(sizeScreenHeight - rect.height);
            }
        }


        if (left) {
            rect.setLeft(coordinate - rect.width - 0.01f);
            for (int i = 0; i < countObjects; ++i) {
                if (COLLISION NOTPUSHER) rect.setLeft(listObjects[i]->rect.right);
            }
            if (rect.left < 0.0f) {
                rect.setLeft(0.0f);
            }
        }


        if (right) {
            rect.setLeft(coordinate + 0.01f);
            for (int i = 0; i < countObjects; ++i) {
                if (COLLISION NOTPUSHER) rect.setLeft(listObjects[i]->rect.left - rect.width);
            }

            if (rect.getRight() > sizeScreenWidht) {
                rect.setLeft(sizeScreenWidht - rect.width);
            }
        }


        if (up) {
            rect.setTop(coordinate - rect.height - 0.01f);
            for (int i = 0; i < countObjects; ++i) {
                if (COLLISION NOTPUSHER) rect.setTop(listObjects[i]->rect.down);
            }
            if (rect.top < 0.0f) {
                rect.setTop(0.0f);
            }
        }
    }

    virtual void keys(bool down, bool left, bool right, bool up, bool bullet, RenderTexture& backTexture)
    {

        if (bullet) {
            makeBullet();

        }


        if (down || left || right || up) {
            stepAnimation += deltaShift * 2.0f;
            if (stepAnimation >= 2.0f) {
                stepAnimation = 0.0f;
            }


            if (level[countLevel][(int)(rect.centerY()/12.0f)][(int)(rect.centerX() / 12.0f)] == _W) {
                surfaceMultiplier = 0.2f;
            }
            else {
                surfaceMultiplier = 1.0f;
                if (clockMarkTank.getElapsedTime().asSeconds() > 0.1f) {
                    if (down) {
                        Textures.markTankSpriteY.setPosition(rect.left, rect.centerY());
                        backTexture.draw(Textures.markTankSpriteY);
                        Textures.markTankSpriteY.setPosition(rect.left + 8.0f, rect.centerY());
                        backTexture.draw(Textures.markTankSpriteY);
                    }
                    else if (left) {
                        Textures.markTankSpriteX.setPosition(rect.centerX(), rect.top);
                        backTexture.draw(Textures.markTankSpriteX);
                        Textures.markTankSpriteX.setPosition(rect.centerX(), rect.top + 8.0f);
                        backTexture.draw(Textures.markTankSpriteX);
                    }
                    else if (right) {
                        Textures.markTankSpriteX.setPosition(rect.centerX(), rect.top);
                        backTexture.draw(Textures.markTankSpriteX);
                        Textures.markTankSpriteX.setPosition(rect.centerX(), rect.top + 8.0f);
                        backTexture.draw(Textures.markTankSpriteX);
                    }
                    else if (up) {
                        Textures.markTankSpriteY.setPosition(rect.left, rect.centerY());
                        backTexture.draw(Textures.markTankSpriteY);
                        Textures.markTankSpriteY.setPosition(rect.left + 8.0f, rect.centerY());
                        backTexture.draw(Textures.markTankSpriteY);
                    }
                    clockMarkTank.restart().asSeconds();
                }
            }
            
        }


        if (down) {
            REDUCE_ENGINE_MULTIPLIER
            direction = DOWN;
            rect.changeTop(shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.getDown() > sizeScreenHeight) {
                rect.setTop(sizeScreenHeight - rect.height);
            }

            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {
                    if (COLLISION) {
                        MOVE(true, false, false, false, rect.down, identificator)
                            rect.setTop(listObjects[i]->rect.top - rect.height-0.01f);
                    }
                }

        }

        else if (left) {
            REDUCE_ENGINE_MULTIPLIER
            direction = LEFT;
            rect.changeLeft(-shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.left < 0.0f) {
                rect.setLeft(0.0f);
            }

            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {
                    if (COLLISION) {
                        MOVE(false, true, false, false, rect.left, identificator)
                            rect.setLeft(listObjects[i]->rect.right + 0.01f);
                    }
                }
        }

        else if (right) {
            REDUCE_ENGINE_MULTIPLIER
            direction = RIGHT;
            rect.changeLeft(shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.getRight() > sizeScreenWidht) {
                rect.setLeft(sizeScreenWidht - rect.width);
            }


            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {
                    if (COLLISION) {
                        MOVE(false, false, true, false, rect.right, identificator)
                            rect.setLeft(listObjects[i]->rect.left - rect.width - 0.01f);
                    }
                }
        }

        else if (up) {
            REDUCE_ENGINE_MULTIPLIER
            direction = UP;
            rect.changeTop(-shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.top < 0.0f) {
                rect.setTop(0.0f);
            }

            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {
                    if (COLLISION) {
                        MOVE(false, false, false, true, rect.top, identificator)
                            rect.setTop(listObjects[i]->rect.down +0.01f);
                    }
                }
        }
    }

};









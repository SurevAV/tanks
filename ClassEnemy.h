#pragma once

class Enemy : public ClassObject
{
public:
    Clock clockMove;
    Clock clockMakeBullet;
    float cdChangeDirection = ((float)(rand() * (int)(500) / RAND_MAX) / 100.0f) + 2.0f;
    bool bullet = false;
    float cdMakeBullet = ((float)(rand() * (int)(200) / RAND_MAX) / 100.0f) + 2.0f;
    int stopProbability = 10;
    bool notMovement = false;


    Enemy(float _x, float _y, ClassObject** _listObjects, int _typeEnemy) : ClassObject(_x, _y, _listObjects) {
        direction = RANDOM4;

        rect = FloatRectItem(_x, _y);
        if (_typeEnemy == N1) {
            sprite.setTexture(Textures.Enemy);
            reboundProbability = 0.7f;
            typeBullet = BULLET_LARGE;

        }
        else if (_typeEnemy == N2) {
            sprite.setTexture(Textures.Enemy2);
            reboundProbability = 0.2f;
            shift = 15.0f;
            typeBullet = BULLET_LITTLE;
        }
        else if (_typeEnemy == N3) {
            sprite.setTexture(Textures.Enemy3);
            reboundProbability = 0.2f;
            shift = 15.0f;
            typeBullet = BULLET_LITTLE;
        }
        else if (_typeEnemy == N4) {
            sprite.setTexture(Textures.Enemy4);
            reboundProbability = 0.2f;
            shift = 15.0f;
            typeBullet = BULLET_LITTLE;
        }
        
        sprite.setTextureRect(IntRect(0, 0, 10, 10));
        listObjects = _listObjects;
        typeObject = ENEMY;
        
        IDENTIFICATION
        
    }

    void makeBullet() {

        if (clockBullet.getElapsedTime().asSeconds() > 2.0f) {
            clockBullet.restart().asSeconds();
            for (int i = 2; i < countObjects; ++i) {
                if (listObjects[i]->typeObject == EMPTY) {
                    delete listObjects[i];
                    listObjects[i] = new Bullet(0.0f, 0.0f, listObjects, direction, rect, typeObject, typeBullet, identificator);
                    break;
                }
            }

        }
    }

    void update(RenderTexture& backTexture)
    {
        checkBurn();
        RECOVERY_ENGINE_MULTIPLIER

        if (clockMove.getElapsedTime().asSeconds() > cdChangeDirection) {

            
            stopProbability = (rand() * (int)(10) / RAND_MAX);

            if (stopProbability > 4) {
                direction = RANDOM4;
                notMovement = false;
            }
            else
            {
                notMovement = true;
            }
            clockMove.restart().asSeconds();

        }

        if (clockMakeBullet.getElapsedTime().asSeconds() > cdMakeBullet) {
            clockMakeBullet.restart().asSeconds();
            bullet = true;
        
        }

        if (notMovement) {
            keys(false, false, false, false, bullet, backTexture);
        }
        else if (direction == DOWN) {
            keys(true, false, false, false, bullet, backTexture);
        }
        else if (direction == LEFT) {
            keys(false, true, false, false, bullet, backTexture);
        }
        else if (direction == RIGHT) {
            keys(false, false, true, false, bullet, backTexture);
        }
        else {
            keys(false, false, false, true, bullet, backTexture);
        }

        bullet = false;
    }
};

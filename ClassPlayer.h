#pragma once

class Player : public ClassObject
{
public:
    

    Player(float _x, float _y, ClassObject** _listObjects) : ClassObject(_x, _y, _listObjects) {
        shift = 15.0f;
        rect = FloatRectItem(_x, _y);
        sprite.setTexture(Textures.Player);
        sprite.setTextureRect(IntRect(0, UP, 10, 10));
        listObjects = _listObjects;

        typeObject = PLAYER;
        typeBullet = BULLET_LITTLE;

        reboundProbability = 0.5f;
        IDENTIFICATION

    }

    void update(RenderTexture& backTexture) {
        checkBurn();
        RECOVERY_ENGINE_MULTIPLIER

      
    }

    void makeBullet() {
        

        if (clockBullet.getElapsedTime().asSeconds() > 1.0f) {
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




};


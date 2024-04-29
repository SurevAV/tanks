#pragma once
//#define MOVE(_down, _left, _right, _up, _coordinate, _identificatorPusher)if (listObjects[i]->typeObject == TNT || listObjects[i]->typeObject == BRICK_ROCK) { listObjects[i]->move(_down, _left, _right, _up, _coordinate, _identificatorPusher); }


class Bullet : public ClassObject
{

public:
    bool notRebound = true;
    bool move = false;
    int typeOwner;
    int identificatorOwner = 0;

    Bullet(float _x, float _y, ClassObject** _listObjects, int _direction, FloatRectItem _rect, int _typeOwner, int _typeBullet, int _identificatorOwner) : ClassObject(_x, _y, _listObjects) {
        shift = 230.0f;
        identificatorOwner = _identificatorOwner;
        direction = _direction;

        sprite.setTexture(Textures.ListBullets[RANDOM2]);

        if (_typeBullet == BULLET_LITTLE) {
            armor = 0.95f;
        }
        else if (_typeBullet == BULLET_LARGE) {
            armor = 4.00f;
        }

        if (direction == DOWN) {
            rect = FloatRectItem(_rect.centerX() - 0.5f, _rect.getDown() + 0.2f, 1, 4);
            sprite.setTextureRect(IntRect(0, 6, 1, 4));
        }
        else if (direction == LEFT) {
            rect = FloatRectItem(_rect.left - 4.2f, _rect.centerY() - 0.5f, 4, 1);
            sprite.setTextureRect(IntRect(0, 4, 4, 1));
        }
        else if (direction == RIGHT) {
            rect = FloatRectItem(_rect.getRight() + 0.2f, _rect.centerY() - 0.5f, 4, 1);
            sprite.setTextureRect(IntRect(0, 5, 4, 1));
        }
        else {
            rect = FloatRectItem(_rect.centerX() - 0.5f, _rect.top - 4.2f, 1, 4);
            sprite.setTextureRect(IntRect(0, 0, 1, 4));
        }


        listObjects = _listObjects;
        typeObject = BULLET;
        typeOwner = _typeOwner;

        ListSound.ListBullets[RANDOM2].play();

        IDENTIFICATION
        collision();
    }

    void update(RenderTexture& backTexture)
    {
        if (move) {
            if (direction == DOWN) {
                rect.changeTop(shift * deltaShift);
                if (rect.getDown() > sizeScreenHeight) {
                    rect.setTop(sizeScreenHeight - rect.height);
                    armor = -1.0f;
                }

            }
            else if (direction == LEFT) {
                rect.changeLeft(-shift * deltaShift);
                if (rect.left < 0.0f) {
                    rect.setLeft(0.0f);
                    armor = -1.0f;
                }

            }
            else if (direction == RIGHT) {
                rect.changeLeft(shift * deltaShift);
                if (rect.getRight() > sizeScreenWidht) {
                    rect.setLeft(sizeScreenWidht - rect.width);
                    armor = -1.0f;
                }

            }
            else {
                rect.changeTop(-shift * deltaShift);
                if (rect.top < 0.0f) {
                    rect.setTop(0.0f);
                    armor = -1.0f;
                }
            }
        }
        armor -= deltaShift * 0.5f;
        move = true;
        collision();
        

    }

    void collision() {
        if (notRebound) {

            for (int i = 0; i < countObjects; ++i) {
                if (listObjects[i]->typeObject != EMPTY && listObjects[i] != this && rect.intersects(listObjects[i]->rect) && listObjects[i]->armor>0.0f && listObjects[i]->typeObject!=EXPLOSION && listObjects[i]->identificator != identificatorOwner) {

                    if (typeOwner != listObjects[i]->typeObject && (listObjects[i]->reboundProbability <= (float)(rand() * (int)(100) / RAND_MAX) / 100.0f
                        || listObjects[i]->typeObject == BRICK_LARGE 
                        || listObjects[i]->typeObject == BRICK_LITTLE
                        || listObjects[i]->typeObject == BRICK_ROCK)) {


                        if (RANDOM_TO(4) <= 1 && (listObjects[i]->typeObject == ENEMY || listObjects[i]->typeObject == PLAYER)) {
                            armor = -1.0f;
                            listObjects[i]->isBurn = true;

                        }
                        else {
                            //minus on minus
                            armor -= listObjects[i]->armor;
                            listObjects[i]->armor -= 100.0f;
                            //minus on minus
                        }

                    }
                    else {
                        armor = 0.5f;
                        shift *= -0.04f;
                        notRebound = false;
                        ListSound.Rebound.play();
                    }

                }
            }
        }
    }

};

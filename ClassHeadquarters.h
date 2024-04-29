#pragma once
             
class Headquarters : public ClassObject
{
public:
    Clock clockMove;
    float cdChangeDirection = ((float)(rand() * (int)(500) / RAND_MAX) / 100.0f) + 2.0f;

    Headquarters(float _x, float _y, ClassObject** _listObjects) : ClassObject(_x, _y, _listObjects) {
        armor = 0.2f;
        reboundProbability = 0.1f;
        typeObject = HEADQUARTERS;
        listObjects = _listObjects;


        sprite.setTexture(Textures.Headquarters);
        sprite.setTextureRect(IntRect(0, 0, 10, 10));
        rect = FloatRectItem(_x, _y, 10.0f, 10.0f);
        IDENTIFICATION

    }

    void update(RenderTexture& backTexture)
    {
        RECOVERY_ENGINE_MULTIPLIER

            
        headquartersInTarget = false;
        for (int i = 2; i < countObjects; ++i) {
            if(listObjects[i]->typeObject == ENEMY && ( 
                abs(rect.centerX()- listObjects[i]->rect.centerX()) < 5.0f || abs(rect.centerY() - listObjects[i]->rect.centerY()) < 5.0f)
                ) {
                headquartersInTarget = true;
            }
        }

        if (clockMove.getElapsedTime().asSeconds() > cdChangeDirection) {
            direction = RANDOM4;
            clockMove.restart().asSeconds();
        }

        stepAnimation += deltaShift * 2.0f;
        if (stepAnimation >= 2.0f) {
            stepAnimation = 0.0f;
        }


        if (level[countLevel][(int)(rect.centerY() / 12.0f)][(int)(rect.centerX() / 12.0f)] == _W) {
            surfaceMultiplier = 0.2f;
        }
        else {
            surfaceMultiplier = 1.0f;
        }


        if (direction == DOWN) {
            REDUCE_ENGINE_MULTIPLIER

            rect.changeTop(shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.getDown() > sizeScreenHeight) {
                rect.setTop(sizeScreenHeight - rect.height);
            }


            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {
                    if (COLLISION) {
                        MOVE(true, false, false, false, rect.down, identificator)
                            rect.setTop(listObjects[i]->rect.top - rect.height);
                    }
                }

        }

        else if (direction == LEFT) {
            REDUCE_ENGINE_MULTIPLIER

            rect.changeLeft(-shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.left < 0.0f) {
                rect.setLeft(0.0f);
            }

            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {
                    if (COLLISION) {
                        MOVE(false, true, false, false, rect.left, identificator)
                            rect.setLeft(listObjects[i]->rect.right);
                    }
                }
        }

        else if (direction == RIGHT) {
            REDUCE_ENGINE_MULTIPLIER

            rect.changeLeft(shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.getRight() > sizeScreenWidht) {
                rect.setLeft(sizeScreenWidht - rect.width);
            }


            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {
                    if (COLLISION) {
                        MOVE(false, false, true, false, rect.right, identificator)
                            rect.setLeft(listObjects[i]->rect.left - rect.width);
                    }
                }
        }

        else if (direction == UP) {
            REDUCE_ENGINE_MULTIPLIER

            rect.changeTop(-shift * deltaShift * engineMultiplier * surfaceMultiplier);

            if (rect.top < 0.0f) {
                rect.setTop(0.0f);
            }

            TEXTURE_RECT
                for (int i = 0; i < countObjects; ++i) {

                    if (COLLISION) {
                        MOVE(false, false, false, true, rect.top, identificator)
                            rect.setTop(listObjects[i]->rect.down);
                    }
                }
        }

    }

};

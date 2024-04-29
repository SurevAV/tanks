#pragma once

class Explosion : public ClassObject
{
public:
    Clock clock;
    bool destruction = false;

    Explosion(float _x, float _y, ClassObject** _listObjects) : ClassObject(_x, _y, _listObjects) {
        rect = FloatRectItem(_x, _y, 24, 24);
        typeObject = EXPLOSION;
        sprite.setTexture(Textures.Explosion);
        sprite.setTextureRect(IntRect(0, 0, 24, 24));
        listObjects = _listObjects;
        clock.restart().asSeconds();
        ListSound.ListExplosions[RANDOM2].play();
        IDENTIFICATION
    }


    void update(RenderTexture& backTexture) {
        if (!destruction) {
            float x = rect.centerX();
            float y = rect.centerY();
            for (int i = 0; i < countObjects; ++i) {
                if (listObjects[i] != nullptr && sqrt(pow(listObjects[i]->rect.centerX() - x,2) + pow(listObjects[i]->rect.centerY() - y, 2)) < 12.0f && listObjects[i]->typeObject != EXPLOSION){
                    listObjects[i]->armor = -1.0f;
                }
            }

            destruction = true;
            
        }

        if (clock.getElapsedTime().asSeconds()>0.1f) {
            if (level[countLevel][(int)(rect.centerY() / 12.0f)][(int)(rect.centerX() / 12.0f)] != _W) {
                Textures.markExplosionSprite.setPosition(rect.left, rect.top);
                backTexture.draw(Textures.markExplosionSprite);
            }
            armor = -1.0f;
            
        }
    }

};
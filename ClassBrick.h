#pragma once

class Brick : public ClassObject
{
public:
    
    Brick(float _x, float _y, ClassObject** _listObjects, int _typeBrick) : ClassObject(_x, _y, _listObjects) {
        armor = 10.0f;
        reboundProbability = 0.2f;
        typeObject = _typeBrick;
        listObjects = _listObjects;

        if (typeObject == BRICK_LARGE) {
            sprite.setTexture(Textures.BrickLarge);
            sprite.setTextureRect(IntRect(0, 0, 4, 2));
            rect = FloatRectItem(_x, _y, 4.0f, 2.0f);

            backSprite.setTexture(Textures.BrickLargeEmpty);
            backSprite.setTextureRect(IntRect(0, 0, 4, 2));
        }
        else if (typeObject == BRICK_LITTLE) {
            sprite.setTexture(Textures.BrickLittle);
            sprite.setTextureRect(IntRect(0, 0, 2, 2));
            rect = FloatRectItem(_x, _y, 2.0f, 2.0f);

            backSprite.setTexture(Textures.BrickLittleEmpty);
            backSprite.setTextureRect(IntRect(0, 0, 2, 2));
            
        }
        else if (typeObject == BRICK_ROCK) {
            sprite.setTexture(Textures.BrickRock);
            sprite.setTextureRect(IntRect(0, 0, 4, 4));
            rect = FloatRectItem(_x, _y, 4.0f, 4.0f);

           

            armor = 400.0f;

        }

        sprite.setPosition(_x, _y);
        backSprite.setPosition(_x, _y);

        IDENTIFICATION

    }

};

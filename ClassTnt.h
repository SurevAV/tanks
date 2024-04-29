#pragma once


class Tnt : public ClassObject
{
public:
    Tnt(float _x, float _y, ClassObject** _listObjects) : ClassObject(_x, _y, _listObjects) {
        rect = FloatRectItem(_x, _y, 5, 5);
        typeObject = TNT;
        sprite.setTexture(Textures.Tnt);
        sprite.setTextureRect(IntRect(0, 0, 5, 5));
        listObjects = _listObjects;
        IDENTIFICATION
    }


};
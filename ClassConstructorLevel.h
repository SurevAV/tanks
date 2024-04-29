#pragma once
#define SIDE_SIZE 12

//Delete before make objects
class ConstructorLevel {

public:


    int emptySlot(ClassObject** ListObjects) {
        for (int i = 2; i < OBJECTS; ++i) {
      
            if (ListObjects[i]->typeObject == EMPTY) {
                return i;
            }
        }
        return 0;
    }


    void makeWall2(float _x, float _y, ClassObject** ListObjects) {
        int ListObjectsI = emptySlot(ListObjects);


        delete ListObjects[ListObjectsI];
        ListObjects[ListObjectsI] = new Brick(_x, _y, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI+1];
        ListObjects[ListObjectsI + 1] = new Brick(_x + 4.0f, _y, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI+2];
        ListObjects[ListObjectsI + 2] = new Brick(_x + 8.0f, _y, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI+3];
        ListObjects[ListObjectsI + 3] = new Brick(_x, _y + 4.0f, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI+4];
        ListObjects[ListObjectsI + 4] = new Brick(_x + 4.0f, _y + 4.0f, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI+5];
        ListObjects[ListObjectsI + 5] = new Brick(_x + 8.0f, _y + 4.0f, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI+6];
        ListObjects[ListObjectsI + 6] = new Brick(_x , _y + 8.0f, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI+7];
        ListObjects[ListObjectsI + 7] = new Brick(_x +4.0f, _y + 8.0f, ListObjects, BRICK_ROCK);

        delete ListObjects[ListObjectsI + 8];
        ListObjects[ListObjectsI + 8] = new Brick(_x + 8.0f, _y + 8.0f, ListObjects, BRICK_ROCK);
      

    }

    void makeWallMidle(float _x, float _y, ClassObject** ListObjects) {

        int ListObjectsI = emptySlot(ListObjects);



        for (int i = 0; i <6; ++i) {
            float y = _y + (float)i * 2.0f;

            if (i % 2 == 0) {

                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI] = new Brick(_x, y, ListObjects, BRICK_LITTLE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 2.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 6.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 3];
                ListObjects[ListObjectsI + 3] = new Brick(_x + 10.0f, y, ListObjects, BRICK_LITTLE);

                ListObjectsI += 4;
            }
            else {
                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI] = new Brick(_x, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 4.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 8.0f, y, ListObjects, BRICK_LARGE);
                ListObjectsI += 3;
            }
        }

    }

    void makeWallLeftMidleRight(float _x, float _y, ClassObject** ListObjects) {

        int ListObjectsI = emptySlot(ListObjects);



        for (int i = 0; i < 6; ++i) {
            float y = _y + (float)i * 2.0f;

            if (i % 2 == 0) {
                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI ] = new Brick(_x + 2.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 6.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 10.0f, y, ListObjects, BRICK_LARGE);
                ListObjectsI += 3;
            }
            else {
                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI] = new Brick(_x, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 4.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 8.0f, y, ListObjects, BRICK_LARGE);
                ListObjectsI += 3;
            }
        }

    }

    void makeWallMidleRight(float _x, float _y, ClassObject** ListObjects) {

        int ListObjectsI = emptySlot(ListObjects);



        for (int i = 0; i < 6; ++i) {
            float y = _y + (float)i * 2.0f;

            if (i % 2 == 0) {
                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI] = new Brick(_x, y, ListObjects, BRICK_LITTLE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 2.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 6.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 3];
                ListObjects[ListObjectsI + 3] = new Brick(_x + 10.0f, y, ListObjects, BRICK_LARGE);
                ListObjectsI += 4;
            }
            else {
                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI] = new Brick(_x, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 4.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 8.0f, y, ListObjects, BRICK_LARGE);
                ListObjectsI += 3;
            }
        }

    }


    void makeWallLeftMidle(float _x, float _y, ClassObject** ListObjects) {

        int ListObjectsI = emptySlot(ListObjects);
      



        for (int i = 0; i < 6; ++i) {
            float y = _y + (float)i * 2.0f;

            if (i % 2 == 0) {
                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI ] = new Brick(_x + 2.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 6.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 10.0f, y, ListObjects, BRICK_LITTLE);

                ListObjectsI += 3;
            }
            else {

                delete ListObjects[ListObjectsI];
                ListObjects[ListObjectsI] = new Brick(_x, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 1];
                ListObjects[ListObjectsI + 1] = new Brick(_x + 4.0f, y, ListObjects, BRICK_LARGE);

                delete ListObjects[ListObjectsI + 2];
                ListObjects[ListObjectsI + 2] = new Brick(_x + 8.0f, y, ListObjects, BRICK_LARGE);

                ListObjectsI += 3;
            }
        }

    }



    void makeEnemy(float _x, float _y, ClassObject** ListObjects, int typeEnemy) {
        int slot = emptySlot(ListObjects);
        delete ListObjects[slot];
        ListObjects[slot] = new Enemy(_x, _y, ListObjects, typeEnemy);
    }





    void makeLevel(ClassObject** ListObjects, int countPlayers, RenderTexture& backTexture) {
        for (int i = 0; i < OBJECTS; ++i) {
            delete ListObjects[i];
            ListObjects[i] = new ClassObject(-100.0f, -100.0f, ListObjects);
        }

        backTexture.clear(Color(95, 92, 84, 255));
        countIdentification = 0;

        //player 1 2 in list
        for (int y = 0; y < level_height; ++y) {
            for (int x = 0; x < level_width; ++x) {
                int item = level[countLevel][y][x];
                if (item == P1) {
                    delete ListObjects[0];
                    ListObjects[0] = new Player((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                }
            }
        }

        for (int y = 0; y < level_height; ++y) {
            for (int x = 0; x < level_width; ++x) {
                int item = level[countLevel][y][x];
                if (item == P2 && countPlayers == 2) {

                    delete ListObjects[1];
                    ListObjects[1] = new Player((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                }
            }
        }
        //player 1 2 in list



        for (int y = 0; y < level_height; ++y) {
            for (int x = 0; x < level_width; ++x) {
                if (level[countLevel][y][x] == _W) {
                    Textures.WaterSprite.setPosition((float)x * SIDE_SIZE, (float)y * SIDE_SIZE);
                    backTexture.draw(Textures.WaterSprite);
                }
            }
        }


        for (int y = 0; y < level_height; ++y) {
            for (int x = 0; x < level_width; ++x) {
                if (level[countLevel][y][x] != _W) {
                    Textures.GroundSprite.setPosition(((float)x * SIDE_SIZE) - 1, ((float)y * SIDE_SIZE) - 1);
                    backTexture.draw(Textures.GroundSprite);
                }
            }
        }


        for (int y = 0; y < level_height; ++y) {
            for (int x = 0; x < level_width; ++x) {
                if (level[countLevel][y][x] == W1) {
                    Textures.GroundSprite2.setPosition(((float)x * SIDE_SIZE)-5, ((float)y * SIDE_SIZE)-5);
                    backTexture.draw(Textures.GroundSprite2);
                }
            }
        }



        for (int y = 0; y < level_height; ++y) {
            for (int x = 0; x < level_width; ++x) {

                int item = level[countLevel][y][x];

                if (item == W1) {


                    if (x > 0 && x < level_width - 1 && level[countLevel][y][x - 1] == W1 && level[countLevel][y][x + 1] == W1) {
                       
                        makeWallLeftMidleRight((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                    }
                    else if (x > 0 && level[countLevel][y][x - 1] == W1) {
                        
                        makeWallLeftMidle((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                    }
                    else if (x < level_width - 1 && level[countLevel][y][x + 1] == W1) {
               
                        makeWallMidleRight((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                    }
                    else {
                        
                        makeWallMidle((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                    }
                    


                }
                else if (item == W2) {
                    makeWall2((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                }
                else if (item == N1 || item == N2 || item == N3 || item == N4) {
                    makeEnemy((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects, item);
                }
                else if (item == T1) {
                    int slot = emptySlot(ListObjects);
                    delete ListObjects[slot];
                    ListObjects[slot] = new Tnt((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                }
                else if (item == H_) {
                    int slot = emptySlot(ListObjects);
                    delete ListObjects[slot];
                    ListObjects[slot] = new Headquarters((float)x * SIDE_SIZE, (float)y * SIDE_SIZE, ListObjects);
                }


            }
        }


        
        countObjects = emptySlot(ListObjects)+500;



        for (int i = 0; i < OBJECTS; ++i) {
            if ( ListObjects[i]->typeObject == BRICK_LARGE || ListObjects[i]->typeObject == BRICK_LITTLE) {
                backTexture.draw(ListObjects[i]->sprite);
            }
        };
        backTexture.display();
    }

};


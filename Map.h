#pragma once

#define RANDOM_TO(_number) (rand() * ((int)(_number)+1) / RAND_MAX) 

#define _E 400 //empty
#define W1 401 //wall
#define W2 402 //wall2
#define P1 403 //player
#define P2 404 //player

#define N1 405 //enemy
#define N2 406 //enemy2
#define N3 407 //enemy3
#define N4 408 //enemy4

#define T1 409 //tnt
#define H_ 410 //headquarters
#define _W 411 //water

namespace Map

{
	const int level_height = 19;
	const int level_width = 30;

	const int countlevels = 50;

	int level[countlevels][level_height][level_width]{

		{
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, W1, W1, _E, W1, _E, _E, W1, _E, W1, W1, _E, _E, W1, W1, W1, _E, W1, _E, W1, _E, _E, W1, _E, _E, W1, _E, W1, _E  },
	{ _E, W1, _E, _E, _E, W1, _E, _E, W1, _E, W1, _E, W1, _E, W1, _E, _E, _E, W1, _E, W1, _E, W1, _E, W1, _E, W1, _E, W1, _E  },
	{ _E, W1, _E, _E, _E, W1, _E, _E, W1, _E, W1, _E, W1, _E, W1, _E, _E, _E, W1, _E, W1, _E, W1, _E, W1, _E, W1, _E, W1, _E  },
	{ _E, _E, W1, _E, _E, W1, _E, _E, W1, _E, W1, W1, _E, _E, W1, W1, _E, _E, W1, _E, W1, _E, W1, W1, W1, _E, W1, _E, W1, _E  },
	{ _E, _E, _E, W1, _E, W1, _E, _E, W1, _E, W1, _E, W1, _E, W1, _E, _E, _E, W1, _E, W1, _E, W1, _E, W1, _E, W1, _E, W1, _E  },
	{ _E, _E, _E, W1, _E, W1, _E, _E, W1, _E, W1, _E, W1, _E, W1, _E, _E, _E, _E, W1, _E, _E, W1, _E, W1, _E, _E, W1, _E, _E  },
	{ _E, W1, W1, _E, _E, _E, W1, W1, _E, _E, W1, _E, W1, _E, W1, W1, W1, _E, _E, W1, _E, _E, W1, _E, W1, _E, _E, W1, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, P1, _E, _E, P2, _E, _E, H_, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  },
	{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E  }}
	};


    int limiter(int x) {
        if (x > 4) {
            return 4;
        }
        return x;
    }


    void writeMap() {
        //map--------------------------------------------------------------------


        for (int levelInMap = 1; levelInMap < countlevels; ++levelInMap) { //empty
            for (int y = 0; y < level_height; ++y) {
                for (int x = 0; x < level_width; ++x) {
                    level[levelInMap][y][x] = _E;
                }
            }



            //walls
            for (int y = 0; y < level_height; ++y) {

                for (int x = 0; x < level_width; ++x) {
                    if (RANDOM_TO(15) == 15) {
                        int direction = RANDOM_TO(1);

                        if (direction == 0) {
                            int length = RANDOM_TO(level_height - y);
                            int type_wall = W1 + RANDOM_TO(1);

                            for (int i = y; i < y + length; i++) {
                                level[levelInMap][i][x] = type_wall;
                            }

                        }
                        else {
                            int length = RANDOM_TO(level_width - x);
                            int type_wall = W1 + RANDOM_TO(1);

                            for (int i = x; i < x + length; i++) {
                                level[levelInMap][y][i] = type_wall;
                            }

                        }

                    }
                }
            }
            //water
            for (int y = 0; y < level_height; ++y) {
                for (int x = 0; x < level_width; ++x) {
                    if (RANDOM_TO(25) == 25) {
                        int length_y = RANDOM_TO(limiter(level_height - y));
                        int length_x = RANDOM_TO(limiter(level_width - x));

                        for (int i_y = y; i_y < y + length_y; ++i_y) {
                            for (int i_x = x; i_x < x + length_x; ++i_x) {
                                level[levelInMap][i_y][i_x] = _W;

                            }
                        }

                    }

                }
            }
            //enemy
            for (int y = 0; y < level_height; ++y) {
                for (int x = 0; x < level_width; ++x) {
                    if (RANDOM_TO(25) == 25) {
                        level[levelInMap][y][x] = N1 + RANDOM_TO(4);

                    }

                    if (RANDOM_TO(50) == 50) {
                        level[levelInMap][y][x] = T1;
                    }
                }
            }

            int y = RANDOM_TO(level_height - 1);
            int x = RANDOM_TO(level_width - 4);

            level[levelInMap][y][x] = H_;
            level[levelInMap][y][x + 1] = P1;
            level[levelInMap][y][x + 2] = P2;


        }

        //map--------------------------------------------------------------------

      

    }

}




	//int level[19][25]{
	//{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, W1, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ W1, W1, W1, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, _E, _E, W1, W1, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, W1, W2, _E, _E, W1, W1, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, W1, _E, _E, _E, _E, _E, _E, _E, W2, W2, W2, W2, W2, W2, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, W1, _E, _E, _E, _E, _E, _E, _E, _E, W2, W2, W2, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, W1, W1, W1, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, W1, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, W1, _E, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, W1, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, W1, _E, _E, _E, _E, _E, _E, W1, _E, _E, W1, _E, _E, _E, W1, W1, W1, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, W1, W1, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, W1, W1, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, W1, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E },
	//{ _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _P, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E, _E }, };
	


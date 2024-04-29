#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;


class ClassListTexture {
public:

	Texture Player;
	Texture Enemy;
	Texture Enemy2;
	Texture Enemy3;
	Texture Enemy4;


	Texture BrickLarge;
	Texture BrickLittle;
	Texture BrickRock;

	Texture BrickLargeEmpty;
	Texture BrickLittleEmpty;
	

	Texture Headquarters;


	Texture Tnt;
	Texture Explosion;


	Texture Ground;
	Sprite GroundSprite;

	Texture Ground2;
	Sprite GroundSprite2;

	Texture Water;
	Sprite WaterSprite;


	Texture markExplosion;
	Sprite markExplosionSprite;

	Texture markTankY;
	Sprite markTankSpriteY;
	Texture markTankX;
	Sprite markTankSpriteX;

	Texture burn;
	Sprite burnSprite;

	Texture menu;

	Texture numbers;
	Sprite numbersSprite;


	Texture target;
	Sprite targetSprite;

	Texture* ListBullets = new Texture[2];

	ClassListTexture() {
		Player.loadFromImage(openFile("images/player/player.png"));

		Enemy.loadFromImage(openFile("images/enemy/enemy.png"));
		Enemy2.loadFromImage(openFile("images/enemy/enemy2.png"));
		Enemy3.loadFromImage(openFile("images/enemy/enemy3.png"));
		Enemy4.loadFromImage(openFile("images/enemy/enemy4.png"));

		Headquarters.loadFromImage(openFile("images/headquarters/headquarters.png"));

		BrickLarge.loadFromImage(openFile("images/brick/brick.png"));
		BrickLittle.loadFromImage(openFile("images/brick/brick2.png"));
		BrickLargeEmpty.loadFromImage(openFile("images/brick/brickEmpty.png"));
		BrickLittleEmpty.loadFromImage(openFile("images/brick/brick2empty.png"));
		BrickRock.loadFromImage(openFile("images/brick/rock.png"));
	

		Tnt.loadFromImage(openFile("images/tnt/tnt.png"));
		Explosion.loadFromImage(openFile("images/explosion/explosion.png"));

		Ground.loadFromImage(openFile("images/ground/ground.png"));
		GroundSprite.setTexture(Ground);

		Ground2.loadFromImage(openFile("images/ground/ground2.png"));
		GroundSprite2.setTexture(Ground2);

		Water.loadFromImage(openFile("images/water/water.png"));
		WaterSprite.setTexture(Water);

		markExplosion.loadFromImage(openFile("images/marks/markExplosion.png"));
		markExplosionSprite.setTexture(markExplosion);

		markTankY.loadFromImage(openFile("images/marks/markTankY.png"));
		markTankSpriteY.setTexture(markTankY);

		markTankX.loadFromImage(openFile("images/marks/markTankX.png"));
		markTankSpriteX.setTexture(markTankX);


		burn.loadFromImage(openFile("images/burn/burn.png"));
		burnSprite.setTexture(burn);

		menu.loadFromImage(openFile("images/menu/menu.png"));

		numbers.loadFromImage(openFile("images/menu/numbers.png"));
		numbersSprite.setTexture(numbers);
		

		target.loadFromImage(openFile("images/menu/target.png"));
		targetSprite.setTexture(target);
		targetSprite.setTextureRect(IntRect(0, 0, 7, 7));
		

		ListBullets[0].loadFromImage(openFile("images/bullets/bullet.png"));
		ListBullets[1].loadFromImage(openFile("images/bullets/bullet2.png"));
			
	}

	Image openFile(string item) {
		Image image;
		image.loadFromFile(item);
		image.createMaskFromColor(Color(255, 255, 255));
	
		//ImageBackground.setPixel(10, 10, Color(0, 0, 0));
		return image;
	}

};




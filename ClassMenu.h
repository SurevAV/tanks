#pragma once

class ClassMenu {
public:
	Clock clockMenu;
	//Font font;
	//Text text;
	//string listMenu[4];
	int selected = 0;

	bool menuIsOpen = true;
	Sprite spriteTank;
	float topSprite = 75.0f;
	int countPlayers = 1;

	bool makeLevel = true;

	Sprite spriteMenu;

	ClassMenu() {
		//font.loadFromFile("Letters.ttf");
		//text.setFont(font);
		//text.setFillColor(Color(0, 0, 0));
		//text.setCharacterSize(15);

		//
		//listMenu[0] = "1 Player";
		//listMenu[1] = "2 Player";
		//listMenu[2] = "Exit";
		//listMenu[3] = "Continue";

		spriteTank.setTexture(Textures.Player);
		spriteTank.setTextureRect(IntRect(0, 10, 10, 10));
		spriteMenu.setTexture(Textures.menu);

		

	}


	void menuView(RenderWindow& window) {


		int rows = 4;
		
		spriteMenu.setTextureRect(IntRect(0, 0, 85, 46));
		if (makeLevel) {
			rows = 3;
			
			spriteMenu.setTextureRect(IntRect(0, 0, 85, 34));
		}

		spriteMenu.setPosition(150.0f, 75.0f);
		window.draw(spriteMenu);




		if (KEY(Up) && clockMenu.getElapsedTime().asSeconds() > 0.2 && selected>0) {
			
			clockMenu.restart().asSeconds();

			selected -= 1;
			topSprite -= 12.0f;

			

		}
		else if (KEY(Down) && clockMenu.getElapsedTime().asSeconds() > 0.2 && selected < rows-1) {

			clockMenu.restart().asSeconds();

			selected += 1;
			topSprite += 12.0f;

		}
		else if (KEY(Enter) && clockMenu.getElapsedTime().asSeconds() > 0.2) {

			clockMenu.restart().asSeconds();

			
			if (selected == 0) {
				countPlayers = 1;
				menuIsOpen = false;
				makeLevel = true;
				countLevel = 0;
				playerRewardPoints = 0;
			}
			else if (selected == 1) {
				countPlayers = 2;
				menuIsOpen = false;
				makeLevel = true;
				countLevel = 0;
				playerRewardPoints = 0;
			}
			else if (selected == 3) {
				menuIsOpen = false;
			}
			else if (selected == 2) {
				window.close();
			}
		

		}

		spriteTank.setPosition(135.0f, topSprite);
		window.draw(spriteTank);

	}
};

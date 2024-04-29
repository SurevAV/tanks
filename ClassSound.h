#pragma once
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;


class ClassListSound {
public:

	SoundBuffer sbBullet1;
	SoundBuffer sbBullet2;
	Sound* ListBullets = new Sound[2];

	SoundBuffer sbExplosion1;
	SoundBuffer sbExplosion2;
	Sound* ListExplosions = new Sound[2];

	SoundBuffer sbRebound;
	Sound Rebound;

	

	ClassListSound() {
		sbBullet1.loadFromFile("sound/bullet1.wav");
		ListBullets[0].setBuffer(sbBullet1);
		ListBullets[0].setVolume(20.f);
	
		sbBullet2.loadFromFile("sound/bullet2.wav");
		ListBullets[1].setBuffer(sbBullet2);
		ListBullets[1].setVolume(20.f);


		sbExplosion1.loadFromFile("sound/explosion1.wav");
		ListExplosions[0].setBuffer(sbExplosion1);
		ListExplosions[0].setVolume(20.f);

		sbExplosion2.loadFromFile("sound/explosion2.wav");
		ListExplosions[1].setBuffer(sbExplosion2);
		ListExplosions[1].setVolume(20.f);


		sbRebound.loadFromFile("sound/rebound.wav");
		Rebound.setBuffer(sbRebound);
		Rebound.setVolume(10.f);

		

	}
};


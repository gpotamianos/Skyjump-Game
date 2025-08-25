#pragma once
#include "platforms.h"
#include <string>
//Εδω δημιουργουνται τα σκαλοπατια του level 1 που πατα επανω ο παικτης 

class Rocks : public Platforms {

private:
	bool scpaceship_coll = false;
public:

	void draw();
	void init();
	void update();
	Rocks(const std::string& name = "Rocks") : Platforms(name) {};
	bool getSpaceshipCollision() { return scpaceship_coll; }
};

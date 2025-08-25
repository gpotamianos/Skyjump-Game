#pragma once
#include "platforms.h"
#include <string>
/*
εδω φτιαχνουμε τα σκαλοπατια του lvl 2 που ειναι μετεοριτες με βαση την κλαση platforms
*/
class Meteorites : public Platforms {
public:

	void draw();
	void init();
	void update();
	Meteorites(const std::string& name = "Meteorites") : Platforms(name) {};
public:
	bool moon_coll = false;
	bool getMoonCollision() { return moon_coll; }
};

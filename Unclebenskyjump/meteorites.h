#pragma once
#include "platforms.h"
#include <string>
/*
��� ���������� �� ���������� ��� lvl 2 ��� ����� ���������� �� ���� ��� ����� platforms
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

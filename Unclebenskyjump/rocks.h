#pragma once
#include "platforms.h"
#include <string>
//��� �������������� �� ���������� ��� level 1 ��� ���� ����� � ������� 

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

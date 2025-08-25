#pragma once
#include "enemy.h"
#include <string>
//��� �������������� �� ���������� ��� level 1 ��� ���� ����� � ������� 

class Badbirds : public Enemy {

private:
	bool badbird_coll = false;
public:

	void draw();
	void init();
	void update(float dt);
	Badbirds(const std::string& name = "Rocks") : Enemy(name) {};
	bool getBadbirdCollision() { return badbird_coll; }
};

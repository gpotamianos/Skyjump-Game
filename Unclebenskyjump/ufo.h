#pragma once
#include "enemy.h"
#include <string>
//��� �������������� �� ���������� ��� level 1 ��� ���� ����� � ������� 

class Ufo : public Enemy {

private:
	bool ufo_coll = false;
public:

	void draw();
	void init();
	void update(float dt);
	Ufo(const std::string& name = "Rocks") : Enemy(name) {};
	bool getUfoCollision() { return ufo_coll; }
};

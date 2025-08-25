#pragma once
#include "gameobject.h"
#include <string>
#include "box.h"
#include <sgg/graphics.h>
#include <vector>
#include "collisions.h"

//εδω φτιαχνουμε τους εχθρους
class Enemy : public GameObject, public Box {
private:
	
	
	const float velocity = 2.0f;
	float m_rock_direction = -1.0f;
	int dir = 0;
	float MAX_X_POSITION = -9.f;
	float MIN_X_POSITION = -21.f;
	bool enemy_collision = false;
	int direction=1; //εαν το direction ειναι μονοσ αριθμος πηγαινει ο εχθρος δεξια ενω αν ειναι ζυγος πηγαινει αριστερα
	
public:
	float m_vx = 0.0f;
	float m_vy = 0.0f;
	void update(float dt);
	void draw();
	void init();
	Enemy(std::string name) : GameObject(name) {}
	float getEnemyX() const { return m_pos_x; }
	float getEnemyY() const { return m_pos_y; }
	bool getEnemyCollision() { return enemy_collision; }
	

protected:
	Collisions* m_coll = new Collisions();
	void moveEnemy(float dt);
	std::vector<std::string> m_spritesright;
	std::vector<std::string> m_spritesleft;
	std::vector<Box> m_enemy;
	graphics::Brush m_brush_enemy;
	graphics::Brush m_brush_enemy_debug;
};

#include "enemy.h"
#include "util.h"
#include "box.h"

//εδω υλοποιουμε τις συναρτησεις της κλασης Enemy που θα χρησιμοποιηθουν στις κλασεις Badbirds και UFO

void Enemy::update(float dt)
{
	float delta_time = dt / 1000.0f;
	moveEnemy(dt);
	
	GameObject::update(dt);
}

void Enemy::draw()
{
	
	
	for (int i = 0; i < m_enemy.size(); i++)
	{
		Box& box1 = m_enemy[i];
		int spriteright = (int)fmod(100.0f - box1.m_pos_x * 9.0f, m_spritesright.size());
		int spriteleft = (int)fmod(100.0f - box1.m_pos_x * 9.0f, m_spritesleft.size());
		if (direction % 2 ==0) {
			m_brush_enemy.texture = m_spritesright[spriteright];
		}                                                            //Τοποθετηση καταλληλου sprite με βαση το direction
		else  {
			m_brush_enemy.texture = m_spritesleft[spriteleft];
		}
		float x1 = box1.m_pos_x + m_state->m_global_offset_x;
		float y1 = box1.m_pos_y + m_state->m_global_offset_y;

		graphics::drawRect(x1, y1, 1.0f, 1.0f, m_brush_enemy);

		if (m_state->m_debugging)                                       // DEBUG
			graphics::drawRect(x1, y1, 0.7f, 0.4f, m_brush_enemy_debug);
	}
}

void Enemy::init()
{

}


//moving the enemies
void Enemy::moveEnemy(float dt)
{
	float delta_time = dt / 1000.0f;
	for (auto& enemy : m_enemy)
	{
		
		float newPosX = enemy.m_pos_x + delta_time * velocity * m_rock_direction;


		if (newPosX >= MAX_X_POSITION || newPosX <= MIN_X_POSITION)
		{
			m_rock_direction *= -1.0f;
			direction += 1;
			
		}
		else
		{
			enemy.m_pos_x = newPosX;
		}
	}
}

#include "ufo.h"
#include "util.h"
//Υλοποιηση κλασησ Badbirds με βαση την κλαση Enemy
void Ufo::draw()
{
	Enemy::draw();
}

void Ufo::init()
{
	m_pos_x = -20.0f;
	m_pos_y = 1.0f;
	m_brush_enemy.fill_opacity = 1.0f;
	m_brush_enemy.outline_opacity = 0.0f;
	m_brush_enemy.texture = m_state->getFullAssetPath("ufo1.png");
	m_spritesright.push_back(m_state->getFullAssetPath("ufo1.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("ufo2.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("ufo3.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("ufo4.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("ufo5.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("ufo1.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("ufo2.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("ufo3.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("ufo4.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("ufo5.png"));
	
	float x_coor = m_pos_x;
	float y_coor = m_pos_y;

	for (int i = 0; i < 14; i++) {
		m_enemy.push_back(Box(x_coor, y_coor, 0.7f, 0.4f));
		y_coor -= 3.5f;
	}
	m_brush_enemy.outline_opacity = 0.0f;
	m_brush_enemy_debug.fill_opacity = 0.1f;
	SETCOLOR(m_brush_enemy_debug.fill_color, 0.1f, 1.0f, 0.1f);
	SETCOLOR(m_brush_enemy_debug.outline_color, 0.3f, 1.0f, 0.2f);
}

void Ufo::update(float dt)
{
	if (!m_enemy.empty()) {
		if (m_coll->checkEnemyCollision(m_enemy)) {
			ufo_coll = true;
		}
	}
	
	Enemy::update(dt);
}

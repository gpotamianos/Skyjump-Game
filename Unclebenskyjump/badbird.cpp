#include "badbird.h"
#include "util.h"
//Υλοποιηση κλασησ Badbirds με βαση την κλαση Enemy
void Badbirds::draw()
{
	Enemy::draw();
}

void Badbirds::init()
{
	m_pos_x = -20.0f;
	m_pos_y = 1.0f;
	m_brush_enemy.fill_opacity = 1.0f;
	m_brush_enemy.outline_opacity = 0.0f;
	m_brush_enemy.texture = m_state->getFullAssetPath("badbird1.png");
	m_spritesright.push_back(m_state->getFullAssetPath("badbird1.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("badbird2.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("badbird3.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("badbird4.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("badbird5.png"));
	m_spritesright.push_back(m_state->getFullAssetPath("badbird6.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("badbird11.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("badbird22.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("badbird33.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("badbird44.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("badbird55.png"));
	m_spritesleft.push_back(m_state->getFullAssetPath("badbird66.png"));
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

void Badbirds::update(float dt)
{
	if (m_coll->checkEnemyCollision(m_enemy)) {
		badbird_coll = true;
	}
	Enemy::update(dt);
}


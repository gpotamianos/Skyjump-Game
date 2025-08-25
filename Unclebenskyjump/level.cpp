#include "level.h"
#include <sgg/graphics.h>
#include "player.h"
#include "util.h"

//�������� �������� ��� ����������

void Level::update(float dt)
{
	if (m_name == "1.lvl") {
		
		if (m_state->getPlayer()->isActive())
			m_state->getPlayer()->update(dt);

		m_boundary->update();
		
	}
	else if (m_name == "2.lvl") 
	{
		
		if (m_state->getPlayer()->isActive())
			m_state->getPlayer()->update(dt);

		m_boundary->update();
		
	}
	
	GameObject::update(dt);
}

void Level::draw()
{
	
	// drawing lvl 1
	if (m_name == "1.lvl") {
		
		m_brush_background1.outline_opacity = 0.0f;
		m_brush_background1.texture = m_state->getFullAssetPath("back1.png");

		m_brush_background2.outline_opacity = 0.0f;
		m_brush_background2.texture = m_state->getFullAssetPath("back2.png");
	
		float w = m_state->getCanvasWidth();
		float h = m_state->getCanvasHeight();

		float offset_x = m_state->m_global_offset_x / 2.0f + w / 2.0f;
		float offset_y = m_state->m_global_offset_y / 2.0f + h / 2.0f;



		// ����������� ���������� ��� �� rectangle ��� background
		float rectWidth = 1.5f * w;
		float rectHeight = w / 1.2f;

		// �������� ������ background LEVEL1
		graphics::drawRect(offset_x - 10.0f, offset_y, rectWidth, rectHeight, m_brush_background1);
		// �������� ��� ���� background 

		graphics::drawRect(offset_x - 10.0f, offset_y - 8.0f, rectWidth, rectHeight, m_brush_background2);
		graphics::drawRect(offset_x - 10.0f, offset_y - 16.0f, rectWidth, rectHeight, m_brush_background2);
		graphics::drawRect(offset_x - 10.0f, offset_y - 24.0f, rectWidth, rectHeight, m_brush_background2);

		if (m_state->getPlayer()->isActive())
			m_state->getPlayer()->draw();
		m_boundary->draw();
		
		
	}
		
	//drawing lvl 2
	
	else if (m_name == "2.lvl") {
		m_brush_background3.outline_opacity = 0.0f;
		m_brush_background3.texture = m_state->getFullAssetPath("spacebackground.png");
		float w = m_state->getCanvasWidth();
		float h = m_state->getCanvasHeight();

		float offset_x = m_state->m_global_offset_x / 2.0f + w / 2.0f;
		float offset_y = m_state->m_global_offset_y / 2.0f + h / 2.0f;

		float rectWidth = 1.5f * w;
		float rectHeight = w / 1.2f;

		// �������� background LEVEL2
		graphics::drawRect(offset_x - 10.0f, offset_y, rectWidth, rectHeight, m_brush_background3);
		graphics::drawRect(offset_x - 10.0f, offset_y - 8.0f, rectWidth, rectHeight, m_brush_background3);
		graphics::drawRect(offset_x - 10.0f, offset_y - 16.0f, rectWidth, rectHeight, m_brush_background3);
		graphics::drawRect(offset_x - 10.0f, offset_y - 24.0f, rectWidth, rectHeight, m_brush_background3);
		if (m_state->getPlayer()->isActive())
			m_state->getPlayer()->draw();
		m_boundary->draw();
		
	}
	
}

void Level::init()
{
	if (m_name == "1.lvl") {
		
		m_boundary->init();
		
	}
	if (m_name == "2.lvl") {
	
		m_boundary->init();
	}
	
}

Level::Level(const std::string & name)
	: GameObject(name)
{
}

Level::~Level()
{	
	delete m_boundary;

}

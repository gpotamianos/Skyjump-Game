#pragma once

#include "gameobject.h"
#include <string>
#include <sgg/graphics.h>
#include "boundary.h"


class Level : public GameObject
{
	
public:
	void update(float dt) override;
	void draw() override;
	void init() override;

	Level(const std::string & name = "Level0");
	~Level() override;
	

private:
	graphics::Brush m_brush_background1;
	graphics::Brush m_brush_background2;
	graphics::Brush m_brush_background3;
	class Boundary* m_boundary = new Boundary();
	float m_backgroundLength=100;
	
};
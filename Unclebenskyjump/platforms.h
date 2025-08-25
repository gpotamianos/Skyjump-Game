// platform.h
#pragma once
#include "gameobject.h"
#include <vector>
#include <string>
#include <sgg/graphics.h>
#include "collisions.h"

/*
��� ���������� ��� ����� platforms ��� �� ����������� ��� �� ����������� ��� ����� ������ ���� � �������.
*/

class Platforms : public GameObject {

private:
    float m_rock_direction = 1.0f;
   
    
protected:
    std::vector<std::string> m_rocks_names;
    std::vector<Box> m_rocks;
    std::vector<Box> m_telos; //vector �� ����� �������� �� ������������� ��� �� ������� �� ��x
    const float m_rock_size = 1.5f;
    Collisions* m_collisions = new Collisions();
    graphics::Brush m_rock_brush;
    graphics::Brush m_rock_brush_debug;
public:
    Platforms(const std::string& name = "Platform");
    ~Platforms() {}
    void draw();
    void init();
    void update();
    
};

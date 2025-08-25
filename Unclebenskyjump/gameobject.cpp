#include "gameobject.h"

int GameObject::m_next_id = 1;



GameObject::GameObject(const std::string& name)
	: m_name(name), m_id(m_next_id++), m_state(GameState::getInstance())
{


}


float GameObject::getRandomNumber(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(min, max);
	return dis(gen);
	
}
// collisions.h
#pragma once
#include <vector>
#include "box.h"  
#include "gamestate.h" 
#include "gameobject.h"  
#include <string>
//Αρχειο δήλωσης συναρτήσεων της κλάσης Collsions  
class Collisions: public GameObject
{
public:
    Collisions(const std::string& name = "Colission");  
    void checkDownCollisions(const std::vector<Box>& objects);
    void checkSidewaysCollisions(const std::vector<Box>& objects);
    bool checkWinCollision(const Box& spaceship);
    bool checkEnemyCollision(const std::vector<Box>& objects);

};



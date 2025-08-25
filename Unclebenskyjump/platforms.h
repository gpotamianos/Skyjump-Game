// platform.h
#pragma once
#include "gameobject.h"
#include <vector>
#include <string>
#include <sgg/graphics.h>
#include "collisions.h"

/*
Εδω φτιαχνουμε μια κλαση platforms που θα κληρωνομουν ολα τα αντικειμενα στα οποια παταει πανω ο παικτης.
*/

class Platforms : public GameObject {

private:
    float m_rock_direction = 1.0f;
   
    
protected:
    std::vector<std::string> m_rocks_names;
    std::vector<Box> m_rocks;
    std::vector<Box> m_telos; //vector το οποιο περιέχει το διαστημοπλοιο και το φεγγαρι σε Βοx
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

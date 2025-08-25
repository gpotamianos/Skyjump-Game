#include "rocks.h"

//Εδω δημιουργουνται τα σκαλοπατια του level 1 που πατα επανω ο παικτης με βαση την κλαση PLatforms
void Rocks::draw()
{

    Platforms::draw(); 
    Box& box2 = m_telos[0];
    float x1 = box2.m_pos_x + m_state->m_global_offset_x;
    float y1 = box2.m_pos_y + m_state->m_global_offset_y;
    
    m_rock_brush.texture = m_state->getFullAssetPath("spaceship.png");// το τελευταιο rock ειναι spaceship και παει στο επομενο επιπεδο

    graphics::drawRect(x1, y1, m_rock_size, m_rock_size, m_rock_brush);

    if (m_state->m_debugging)
        graphics::drawRect(x1, y1, 0.8f, 0.6f, m_rock_brush_debug);// Κλήση της μεθόδου draw() της βάσης Platforms
}

void Rocks::init()
{
    for (int i = 0; i < 14; i++) {
        m_rocks_names.push_back("rock.png");  
    }
    
    Platforms::init();
}

void Rocks::update()
{
    if (!m_telos.empty()) {
        Platforms::update();
        if (m_collisions->checkWinCollision(m_telos[0])) {
            scpaceship_coll = true;

        }
    }
    
}

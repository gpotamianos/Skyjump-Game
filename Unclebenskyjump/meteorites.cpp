#include "meteorites.h"
/*
εδω φτιαχνουμε τα σκαλοπατια του lvl 2 που ειναι μετεοριτες με βαση την κλαση platforms
*/
void Meteorites::draw()
{
    Platforms::draw(); // Κλήση της μεθόδου draw() της βάσης Platforms
    Box& box2 = m_telos[0];
    float x1 = box2.m_pos_x + m_state->m_global_offset_x;
    float y1 = box2.m_pos_y + m_state->m_global_offset_y;

    m_rock_brush.texture = m_state->getFullAssetPath("moon.png"); // το τελευταιο σκαλοπατι ειναι το moon οπου τελειωνει το παιχνιδι μολις γινει intersect

    graphics::drawRect(x1, y1, m_rock_size, m_rock_size, m_rock_brush);

    if (m_state->m_debugging)
        graphics::drawRect(x1, y1, 0.8f, 0.6f, m_rock_brush_debug);
}

void Meteorites::init()
{
    for (int i = 0; i < 14; i++) {
        m_rocks_names.push_back("meteorite2.png");
    }
    Platforms::init();
}

void Meteorites::update()
{
    if (!m_rocks.empty()) {
        Platforms::update();
        if (m_collisions->checkWinCollision(m_telos[1])) {
            moon_coll = true;

        }
    }

}

#pragma once

#include <string>
#include <sgg/graphics.h>


class GameState
{
public:
  
    enum game_state_t { START, LOADING, PLAYLEVEL1, SPACESHIP_COLLISION, PLAYLEVEL2, WIN, LOSE };

protected:
    game_state_t state = START; //initialize the state
private:
    static GameState* m_unique_instance;

    const std::string m_asset_path = "assets\\";

    const float m_canvas_width = 10.0f;
    const float m_canvas_height = 8.0f;

    class Level* m_current_level = nullptr;
    class Player* m_player = nullptr;
    class Rocks* m_rocks = nullptr;
    class Meteorites* m_meteorites = nullptr;
    class Badbirds* m_badbirds = nullptr;
    class Ufo* m_ufo = nullptr;
    int level = 1;
    graphics::Brush m_text;
    graphics::Brush br4;
    graphics::Brush br5;
    float loadingElapsedTime = 0.0f;

    GameState();
    

public:
    float m_global_offset_x = 0.0f;
    float m_global_offset_y = 0.0f;

    bool m_debugging = false;
public:
    ~GameState();
    static GameState* getInstance();

    void init();
    void draw();
    void update(float dt);

    std::string getFullAssetPath(const std::string& asset);
    std::string getAssetDir();

    float getCanvasWidth() { return m_canvas_width; }
    float getCanvasHeight() { return m_canvas_height; }

    class Player* getPlayer() { return m_player; }

};

#include "gamestate.h"
#include "level.h"
#include "util.h"
#include "player.h"
#include "rocks.h"
#include "meteorites.h"
#include "badbird.h"
#include "ufo.h"
#include <thread>
#include <chrono>


using namespace std::chrono_literals;

GameState::GameState()
{
}

GameState::~GameState()
{
	if (m_current_level)
		delete m_current_level;
	if (m_player)
		delete m_player;
	if (m_rocks)
		delete m_rocks;
	if (m_meteorites)
		delete m_meteorites;
	if (m_badbirds)
		delete m_badbirds;
	if (m_ufo)
		delete m_ufo;
}

GameState* GameState::getInstance()
{
	if (!m_unique_instance)
	{
		m_unique_instance = new GameState();
	}
	return m_unique_instance;
}


/// ////////////////////////имит////////////////////////////


void GameState::init()
{
	graphics::preloadBitmaps(getAssetDir());
	graphics::setFont(m_asset_path + "OpenSans-Regular.ttf");
	
	if (level == 1) {   //setting lvl 1

		m_current_level = new Level("1.lvl");
		m_current_level->init();

		m_player = new Player("Player1");
		m_player->init();

		m_rocks = new Rocks();
		m_rocks->init();
		
		m_badbirds = new Badbirds("Badbird");
		m_badbirds->init();
	}
	
	else if (level == 2) {   //setting lvl 2
		m_current_level = new Level("2.lvl");
		m_current_level->init();

		m_player = new Player("Player2");
		m_player->init();
		
		m_meteorites = new Meteorites();
		m_meteorites->init();

		m_ufo = new Ufo("Ufo");
		m_ufo->init();

	}
}




/////////////////////////////////////DRAW/////////////////////////////////

void GameState::draw()
{
	//the states of our game
	if (state == START)
	{
		graphics::Brush br;
		br.texture = string(AP) + "back2.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(m_canvas_width / 2, m_canvas_height / 2, m_canvas_width, m_canvas_height, br);
		
		if (graphics::getKeyState(graphics::SCANCODE_SPACE))
		{
			state = PLAYLEVEL1;
			
		}

	}

	else if (state == PLAYLEVEL1)
	{
		m_current_level->draw();
		m_rocks->draw();
		m_badbirds->draw();
		
	}
	else if (state == SPACESHIP_COLLISION) {
		//state = PLAYLEVEL2;
		return;
	}
	else if (state == PLAYLEVEL2) {
		m_current_level->draw();
		m_meteorites->draw();
		m_ufo->draw();
		return;
	}
	else if (state == WIN && level == 2) {
		br4.texture = string(AP) + "win.png";
		br4.outline_opacity = 0.0f;
		graphics::drawRect(m_canvas_width / 2, m_canvas_height / 2, m_canvas_width, m_canvas_height, br4);
		
	}
	else if (state == LOSE ) {
		br5.texture = string(AP) + "youlost.png";
		br5.outline_opacity = 0.0f;
		graphics::drawRect(m_canvas_width / 2, m_canvas_height / 2, m_canvas_width, m_canvas_height, br5);
		
	}

	
}





////////////////////////////////UPDATE///////////////////////////////////////




void GameState::update(float dt)
{
	m_debugging = graphics::getKeyState(graphics::SCANCODE_0);
	// Skip an update if a long delay is detected 
	// to avoid messing up the collision simulation
	if (dt > 500) // ms
		return;

	// Avoid too quick updates
	float sleep_time = std::max(17.0f - dt, 0.0f);
	if (sleep_time > 0.0f)
	{
		std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(sleep_time));

	}
	//game rules
	if (graphics::getKeyState(graphics::SCANCODE_R))
	{
		graphics::drawText(m_canvas_width / 2 - 1.8, m_canvas_height / 2 - 2.0 , 0.2f, "Use A,W,D,S to navigate", m_text);
		graphics::drawText(m_canvas_width / 2 - 1.8, m_canvas_height / 2 - 1.75 , 0.2f, "Reach the top to win", m_text);              //GAME RULES AND INSTRUCTIONS
		graphics::drawText(m_canvas_width / 2 - 1.8, m_canvas_height / 2 - 1.5 , 0.2f, "Press M to stop Music", m_text);
		graphics::drawText(m_canvas_width / 2 - 1.8, m_canvas_height / 2 - 1.25 , 0.2f, "Press P to restart Music", m_text);
		graphics::drawText(m_canvas_width / 2 - 1.8, m_canvas_height / 2 - 1.0 , 0.2f, "If you touch the deadly birds and UFOS you die!", m_text);
	}
	//music
	if (getKeyState(graphics::SCANCODE_M))
	{
		graphics::stopMusic();
	}
	
	if (getKeyState(graphics::SCANCODE_P))
	{
		graphics::playMusic(string(AP) + "everybody.mp3", 0.6f, true, 0);
	}

	//The states of our game
	if (state == START)
	{
		graphics::drawText(m_canvas_width / 2 - 2.2f, m_canvas_height / 2 + 2.5, 0.5f, "Press 'SPACE' to start", m_text);
		graphics::drawText(m_canvas_width / 2 - 2.f, m_canvas_height / 2 +3.0, 0.4f, "Press 'R' for game rules", m_text);   
		graphics::drawText(m_canvas_width / 2 - 2.60f, m_canvas_height / 2 - 3.0, 0.6f, "UNCLE BEN SKYJUMP", m_text);

		return;
	}
	else if (state == LOADING)
	{
		init();
		state = PLAYLEVEL1;
		return;
	}
	else if (state == PLAYLEVEL1)
	{
		
		if (!m_current_level)
			return;
		m_current_level->update(dt);
		m_rocks->update();
		m_badbirds->update(dt);
		
		if (m_badbirds->getBadbirdCollision()) {
			state = LOSE;
			sleep(1000);
			
			return;
		}
		if (m_rocks->getSpaceshipCollision()&&level==1) {
			
			level = 2;
			init();
			state = SPACESHIP_COLLISION;
			return;
		}
	}
	else if (state == SPACESHIP_COLLISION) {
		
		state = PLAYLEVEL2;
		return;
		
	}
	else if (state == PLAYLEVEL2) {
		
		m_current_level->update(dt);
		m_meteorites->update();
		m_ufo->update(dt);
		if (m_ufo->getUfoCollision()) {
			sleep(1000);
			state = LOSE;
			
			return;
		}
		if (m_meteorites->getMoonCollision() && level == 2) {
			state = WIN;
			return;
		}
		return;
	}

	else if (state == WIN)
	{
		graphics::drawText(m_canvas_width / 2 - 1.5f, m_canvas_height / 2 + 3.5, 0.3f, "Press 'Q' to EXIT the Game", m_text);
		if (graphics::getKeyState(graphics::SCANCODE_Q))
		{
			graphics::stopMessageLoop();

		}
		return;
		
	}
	else if (state == LOSE)
	{
		graphics::drawText(m_canvas_width / 2 - 1.5f, m_canvas_height / 2 + 3.5, 0.3f, "Press 'Q' to EXIT the Game", m_text);
		if (graphics::getKeyState(graphics::SCANCODE_Q))
		{
			graphics::stopMessageLoop();

		}
		return;

	}
	
}
	

std::string GameState::getFullAssetPath(const std::string& asset)
{
	return m_asset_path + asset;
}

std::string GameState::getAssetDir()
{
	return m_asset_path;
}

GameState* GameState::m_unique_instance = nullptr;
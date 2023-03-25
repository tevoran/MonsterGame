#include "main.hpp"
#include "world.hpp"
#include "character.hpp"

mg::game::game()
{
	tt_init("Awesome MonsterGame", 1920, 1080, false, 16, NULL);
	tt_new_frame(); //init keyboard state

	//prepare camera
	tt_input_mouse_set_relative_mode(true);

	//load stuff
	m_world = new world;
	m_player = new character(true, {0.0, 0.0, 0.0});
}

mg::game::~game()
{
	delete m_world;
	delete m_player;
}

void mg::game::update()
{
	while(!tt_input_keyboard_key_press(TT_KEY_ESC))
	{
		m_player->update();
		m_world->update();
		tt_new_frame();
	}
}

int main(int argc, char *argv[])
{
	mg::game game;
	game.update();

	return 0;
}
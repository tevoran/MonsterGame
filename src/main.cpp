#include "main.hpp"

mg::game::game()
{
	tt_init("Awesome MonsterGame", 1920, 1080, false, 16, NULL);

	//load stuff
	m_world = new world;
}

mg::game::~game()
{
	delete m_world;
}

int main(int argc, char *argv[])
{
	mg::game game;

    tt_vec3 light_col={0.5f, 0.3f, 0.03f};
    tt_vec3 light_pos={-20.0f, 10.0f, -50.0f};
    tt_point_light light=tt_point_light_new();
    tt_point_light_set_color(light, &light_col);
    tt_point_light_set_position(light, &light_pos);
    tt_point_light_set_strength(light, 2500.0f);

	tt_3d_texture *obj_tex=tt_3d_texture_new("assets/ship.bmp", true);

	while(!tt_input_keyboard_key_press(TT_KEY_ESC))
	{
		tt_new_frame();
	}

	return 0;
}
#include "world.hpp"

mg::world::world()
{
	m_ground = tt_3d_object_new();
	m_ground_mesh = tt_3d_custom_model_load_file("assets/ground.obj");
	m_ground_tex = tt_3d_texture_new("assets/ground.png", true);

	tt_vec3 pos = {0.0, -2.0, 15.0};
	tt_vec3 scale = {30.0, 1.0, 30.0};
	tt_3d_object_set_position(m_ground, &pos);
	tt_3d_object_scale(m_ground, &scale);
	tt_3d_object_use_custom_model(m_ground, m_ground_mesh);
	tt_3d_object_use_texture(m_ground, m_ground_tex);
}

mg::world::~world()
{
	tt_3d_object_delete(&m_ground);
	tt_3d_custom_model_delete(&m_ground_mesh);
}

void mg::world::update()
{

}
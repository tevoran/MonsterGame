#include "world.hpp"

mg::world::world()
{
    //sround
	m_ground = tt_3d_object_new();
	m_ground_mesh = tt_3d_custom_model_load_file("assets/ground.obj");
	m_ground_tex = tt_3d_texture_new("assets/ground.png", true);

    //skybox
    m_skybox = tt_3d_object_new();
    m_skybox_tex = tt_3d_texture_new("assets/Paprika_Kanoniermond.png", true);

    //gravestones
	m_gravestone_0 = tt_3d_object_new();
    m_gravestone_0_tex = tt_3d_texture_new("assets/Grabstein_0.png", true);

	m_gravestone_1 = tt_3d_object_new();
    m_gravestone_1_tex = tt_3d_texture_new("assets/Grabstein_1.png", true);            

    //ground
	tt_vec3 pos = {0.0, -2.0, 15.0};
	tt_vec3 scale = {30.0, 1.0, 30.0};
	tt_3d_object_set_position(m_ground, &pos);
	tt_3d_object_scale(m_ground, &scale);
	tt_3d_object_use_custom_model(m_ground, m_ground_mesh);
	tt_3d_object_use_texture(m_ground, m_ground_tex);
	tt_3d_object_light_affected(m_ground, false);


	//gravestone_0
    tt_vec3 pos_gravestone_0 = {0.0, -1.0, 10.0};
	tt_vec3 scale_gravestone_0 = {3.0, 6.0, 1.5};
    tt_3d_object_set_position(m_gravestone_0, &pos_gravestone_0);
    tt_3d_object_scale(m_gravestone_0,&scale_gravestone_0);
    tt_3d_object_make_cube(m_gravestone_0);
    tt_3d_object_use_texture(m_gravestone_0, m_gravestone_0_tex);
    tt_3d_object_light_affected(m_gravestone_0, true);
    tt_3d_object_back_face_culling(m_gravestone_0, false);

	//gravestone_1
	tt_vec3 pos_gravestone_1 = {10.0, -1.0, 10.0};
	tt_vec3 scale_gravestone_1 = {1.0, 2.0, 0.5};
    tt_3d_object_set_position(m_gravestone_1, &pos_gravestone_1);
    tt_3d_object_scale(m_gravestone_1,&scale_gravestone_1);
    tt_3d_object_make_cube(m_gravestone_1);
    tt_3d_object_use_texture(m_gravestone_1, m_gravestone_1_tex);
    tt_3d_object_light_affected(m_gravestone_1, true);
    tt_3d_object_back_face_culling(m_gravestone_1, false);

    //point light
// 	tt_vec3 lightswitch_col={1.0f, 1.0f, 1.0f};
//     tt_vec3 lightswitch_pos={0.0f, 0.0f, -7.0f};
//     tt_point_light m_lightswitch=tt_directional_light_new();
//     tt_point_light_set_color(m_lightswitch, &lightswitch_col);
//     tt_point_light_set_position(m_lightswitch, &lightswitch_pos);
//     tt_point_light_set_strength(m_lightswitch, 01.0f);
// 	tt_3d_object_add_point_light(m_ground, m_lightswitch);

    //directional light
    tt_vec3 dirlight1_col={0.0f, 0.0f, 1.0f};
    tt_vec3 dirlight1_dir={15.0f, 2.0f,15.0f};
    tt_dir_light m_dirlight1=tt_directional_light_new();
    tt_directional_light_set_color(m_dirlight1, &dirlight1_col);
    tt_directional_light_set_strength(m_dirlight1, 02.0f);
    tt_directional_light_set_direction(m_dirlight1, &dirlight1_dir);
    
    //skybox
    tt_vec3 pos_skybox = {0.0, 0.0, 0.0};
	tt_vec3 scale_skybox = {200.0, 200.0, 200.0};
    tt_3d_object_set_position(m_skybox, &pos_skybox);
    tt_3d_object_scale(m_skybox,&scale_skybox);
    tt_3d_object_make_cube(m_skybox);
    tt_3d_object_use_texture(m_skybox, m_skybox_tex);
    tt_3d_object_light_affected(m_skybox, false);
    tt_3d_object_back_face_culling(m_skybox, false);

}

mg::world::~world()
{
	//ground
	tt_3d_object_delete(&m_ground);
	tt_3d_custom_model_delete(&m_ground_mesh);
	tt_3d_texture_delete(&m_ground_tex);
	//gravestones
	tt_3d_object_delete(&m_gravestone_1);
	tt_3d_texture_delete(&m_gravestone_1_tex);
	tt_3d_object_delete(&m_gravestone_0);
	tt_3d_texture_delete(&m_gravestone_0_tex);
	//skybox
	tt_3d_object_delete(&m_skybox);
	tt_3d_texture_delete(&m_skybox_tex);
	//lights
	//tt_point_light_delete(m_lightswitch);
    tt_directional_light_delete(m_dirlight1);
}

void mg::world::update()
{

}

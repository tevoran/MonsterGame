#include "world.hpp"

mg::world::world()
{
    //Ground
	m_ground_mesh = tt_3d_custom_model_load_file("assets/ground.obj");
	m_ground_tex = tt_3d_texture_new("assets/ground.png", true);
    m_ground_batch = tt_3d_object_new();
    for (int i = 0; i < MG_WORLD_SIZE_X; i++)
    {
    	for (int j = 0; j < MG_WORLD_SIZE_Y; j++)
    	{
    		m_ground[i][j] = tt_3d_object_new();
			tt_vec3 pos = {
				0.0f + i * MG_WORLD_TILE_SIZE,
				-2.0f,
				0.0f + j * MG_WORLD_TILE_SIZE};
			tt_vec3 scale = {MG_WORLD_TILE_SIZE * 0.5f, 1.0, MG_WORLD_TILE_SIZE * 0.5f};
			tt_3d_object_use_custom_model(m_ground[i][j], m_ground_mesh);
			tt_3d_object_set_position(m_ground[i][j], &pos);
			tt_3d_object_scale(m_ground[i][j], &scale);
			tt_3d_object_use_texture(m_ground[i][j], m_ground_tex);
			tt_3d_object_back_face_culling(m_ground[i][j], false);
			tt_3d_object_light_affected(m_ground[i][j], false);
			tt_3d_object_make_invisible(m_ground[i][j], true);
    	}
    }
	m_ground_batch_obj=tt_3d_batch_object_new();
	tt_3d_batch_object_batch_custom_model_objects(
		m_ground_batch_obj,
		m_ground_mesh, 
		MG_WORLD_SIZE_X * MG_WORLD_SIZE_Y,
		&m_ground[0][0]);
	tt_3d_object_use_batch_object(m_ground_batch, m_ground_batch_obj);
	tt_3d_object_use_texture(m_ground_batch, m_ground_tex);
	tt_3d_object_light_affected(m_ground_batch, false);

// 	tt_vec3 lightswitch_col={1.0f, 1.0f, 1.0f};
//     tt_vec3 lightswitch_pos={0.0f, 0.0f, -7.0f};
//     tt_point_light m_lightswitch=tt_directional_light_new();
//     tt_point_light_set_color(m_lightswitch, &lightswitch_col);
//     tt_point_light_set_position(m_lightswitch, &lightswitch_pos);
//     tt_point_light_set_strength(m_lightswitch, 01.0f);
// 	tt_3d_object_add_point_light(m_ground, m_lightswitch);
    
    tt_vec3 dirlight1_col={0.0f, 0.0f, 1.0f};
    tt_vec3 dirlight1_dir={15.0f, 2.0f,15.0f};
    tt_dir_light m_dirlight1=tt_directional_light_new();
    tt_directional_light_set_color(m_dirlight1, &dirlight1_col);
    tt_directional_light_set_strength(m_dirlight1, 02.0f);
    tt_directional_light_set_direction(m_dirlight1, &dirlight1_dir);
    
    //Skybox
    m_skybox = tt_3d_object_new();
    m_skybox_tex = tt_3d_texture_new("assets/Paprika_Kanoniermond.png", true);
	tt_vec3 scale_skybox = {250.0, 250.0, 250.0};
    tt_3d_object_scale(m_skybox,&scale_skybox);
    tt_3d_object_make_cube(m_skybox);
    tt_3d_object_use_texture(m_skybox, m_skybox_tex);
    tt_3d_object_light_affected(m_skybox, false);
    tt_3d_object_back_face_culling(m_skybox, false);
}

mg::world::~world()
{
    for (int i = 0; i < MG_WORLD_SIZE_X; i++)
    {
    	for (int j = 0; j < MG_WORLD_SIZE_Y; j++)
    	{
    		tt_3d_object_delete(&m_ground[i][j]);
    	}
    }
    tt_3d_object_delete(&m_ground_batch);
	tt_3d_object_delete(&m_skybox);
	//tt_point_light_delete(m_lightswitch);
    tt_directional_light_delete(m_dirlight1);
	tt_3d_custom_model_delete(&m_ground_mesh);
}

void mg::world::update(const tt_vec3 *player_pos)
{
	tt_3d_object_set_position(m_skybox, (tt_vec3*)player_pos);
}

#include "character.hpp"
#include "settings.hpp"

mg::character::character(bool is_player, tt_vec3 pos)
{
	m_is_player = is_player;
	m_pos = pos;
}

mg::character::~character()
{
	
}

void mg::character::update()
{
	m_acc.x = 0.0f;
	m_acc.y = 0.0f;
	m_acc.z = 0.0f;

	//player update
	if(m_is_player)
	{
		//camera
		static float yaw_radians = 0.0f;
		static float pitch_radians = 0.0f;
		int dx, dy;
		float time=tt_time_current_frame_s();
		tt_input_mouse_relative_motion(&dx, &dy);
		pitch_radians += (float)dy * time * MG_MOUSE_SENSITIVITY;
		if(pitch_radians > 0.5f * tt_PI)
		{
			pitch_radians = 0.5f * tt_PI;
		}
		if(pitch_radians < -0.5f * tt_PI)
		{
			pitch_radians = -0.5f * tt_PI;
		}
		yaw_radians -= (float)dx * time * MG_MOUSE_SENSITIVITY;
		tt_camera_fps(pitch_radians, yaw_radians);
		m_dir = tt_camera_view_direction();
		m_dir.y = 0.0f;
		m_dir = tt_math_vec3_normalize(&m_dir);

		//forward movement
		if(tt_input_keyboard_key_down(TT_KEY_W))
		{
			m_acc = tt_math_vec3_mul_float(&m_dir, MG_CHAR_ACC);
		}

	}
	//npc update
	else
	{

	}

	//position update
	float t = tt_time_current_frame_s();
	tt_vec3 delta_v = tt_math_vec3_mul_float(&m_acc, t);
	m_vel = tt_math_vec3_add(&m_vel, &delta_v);
	tt_vec3 delta_pos = tt_math_vec3_mul_float(&m_vel, t);
	m_pos = tt_math_vec3_add(&m_pos, &delta_pos);

	printf("%f\n", m_pos.z);

	//player camera
	if(m_is_player)
	{
		tt_camera_set_position(&m_pos);		
	}

}
#pragma once

#include <tt.h>

namespace mg
{
	class character
	{
		public:
			character(bool is_player, tt_vec3 pos);
			~character();
			void update();
			const tt_vec3 *get_pos() {return &m_pos;};
		private:
			bool m_is_player = false;

			//movement
			tt_vec3 m_pos = { 0.0, 0.0, 0.0};
			tt_vec3 m_vel = { 0.0, 0.0, 0.0};
			tt_vec3 m_acc = { 0.0, 0.0, 0.0};
			tt_vec3 m_dir = { 0.0, 0.0, -1.0}; //viewing direction
			float m_acc_t_forward = 0.0f; //acceleration time
			float m_acc_t_side = 0.0f; //acceleration time
	};
}
#pragma once
#include <tt.h>
#include "settings.hpp"

namespace mg
{
	class world
	{
		public:
			world();
			~world();
			void update(const tt_vec3 *player_pos);
		private:
			//ground
			tt_3d_batch_object *m_ground_batch_obj = nullptr;
			tt_3d_object *m_ground_batch = nullptr;
			tt_3d_object *m_ground[MG_WORLD_SIZE_X][MG_WORLD_SIZE_Y];
			tt_3d_custom_model *m_ground_mesh = nullptr;
			tt_3d_texture *m_ground_tex = nullptr;
			
			//skybox
			tt_3d_texture *m_skybox_tex = nullptr;
			tt_3d_object *m_skybox = nullptr;

			//light
			//tt_point_light m_lightswitch;
            tt_dir_light m_dirlight1;
	};
}

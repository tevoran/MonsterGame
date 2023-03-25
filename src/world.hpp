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
			void update();
		private:
			//ground
			tt_3d_object *m_ground = nullptr;
			tt_3d_custom_model *m_ground_mesh = nullptr;
			tt_3d_texture *m_ground_tex = nullptr;

			//light
			//tt_point_light m_lightswitch;
            tt_dir_light m_dirlight1;
	};
}

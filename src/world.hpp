#pragma once
#include <tt.h>

namespace mg
{
	class world
	{
		public:
			world();
			~world();
		private:
			//ground
			tt_3d_object *m_ground = nullptr;
			tt_3d_custom_model *m_ground_mesh = nullptr;
			tt_3d_texture *m_ground_tex = nullptr;
	};
}
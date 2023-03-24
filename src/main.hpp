#pragma once

#include <tt.h>
#include "world.hpp"

namespace mg
{
	class game
	{
		public:
			game();
			~game();
		private:
			//objects
			world *m_world = nullptr;
	};
}
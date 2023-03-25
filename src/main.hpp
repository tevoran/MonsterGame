#pragma once

#include <tt.h>
#include "world.hpp"
#include "character.hpp"


namespace mg
{
	class game
	{
		public:
			game();
			~game();
			void update();
		private:
			//objects
			character *m_player = nullptr;
			world *m_world = nullptr;
	};
}

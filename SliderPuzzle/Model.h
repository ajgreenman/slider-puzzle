#ifndef __SLIDER_MODEL_H
#define __SLIDER_MODEL_H

#include <algorithm>
#include <time.h>
#include <vector>

namespace Slider
{
	class Model
	{
	public:
		Model();
		std::vector<std::vector<int>> get_board();
		bool game_won();
		int get_board_length();
		void move_left();
		void move_right();
		void move_up();
		void move_down();
	private:
		std::vector<std::vector<int>> board;
		void randomize_board_values();
	};
}

#endif
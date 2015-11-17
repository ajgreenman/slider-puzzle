#ifndef __SLIDER_MODEL_H
#define __SLIDER_MODEL_H

#include <vector>

namespace Slider
{
	class Model
	{
	public:
		Model(void);
		std::vector<std::vector<int>> get_board();
	private:
		std::vector<std::vector<int>> board;
	};
}

#endif
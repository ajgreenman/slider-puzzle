#include "Model.h"

using Slider::Model;

Model::Model(void)
{
	std::vector<std::vector<int>> b(4, std::vector<int>(4));
	board = b;
}

std::vector<std::vector<int>> Model::get_board()
{
	return board;
}
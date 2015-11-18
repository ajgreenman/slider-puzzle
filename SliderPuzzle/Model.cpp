#include "Model.h"

using Slider::Model;

const int board_size = 4;

Model::Model(void) : board(board_size, std::vector<int>(board_size))
{
	randomize_board_values();
}

std::vector<std::vector<int>> Model::get_board()
{
	return board;
}

void Model::randomize_board_values()
{
	int r, length = board_size * board_size;
	srand(time(NULL));
	std::vector<int> placeholder(length);
	for(int i = 1; i < length; ++i)
	{
		do {
			r = rand() % length;
		} while(placeholder[r] != 0);

		placeholder[r] = i;
	}

	for(int i = 0; i < length; ++i)
	{
		int row = i / board_size;
		int col = i % board_size;

		board[row][col] = placeholder[i];
	}
}
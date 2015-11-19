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

bool Model::game_won()
{
	return false;
}

void Model::move_left()
{
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[i].size(); ++j)
		{
			if(board[i][j] == 0)
			{
				if(j != board_size - 1) {
					board[i][j] = board[i][j + 1];
					board[i][j + 1] = 0;
				}
				return;
			}
		}
	}
}

void Model::move_right()
{
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[i].size(); ++j)
		{
			if(board[i][j] == 0)
			{
				if(j != 0) {
					board[i][j] = board[i][j - 1];
					board[i][j - 1] = 0;
				}
				return;
			}
		}
	}
}

void Model::move_up()
{
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[i].size(); ++j)
		{
			if(board[j][i] == 0)
			{
				if(j != board_size - 1) {
					board[j][i] = board[j + 1][i];
					board[j + 1][i] = 0;
				}
				return;
			}
		}
	}
}

void Model::move_down()
{
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[i].size(); ++j)
		{
			if(board[j][i] == 0)
			{
				if(j != 0) {
					board[j][i] = board[j - 1][i];
					board[j - 1][i] = 0;
				}
				return;
			}
		}
	}
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
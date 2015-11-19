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
				std::vector<int> row = board[i];
				board[i].clear();
				row.erase(std::remove(row.begin(), row.end(), 0), row.end());
				board[i].insert(board[i].end(), row.begin(), row.end());
				board[i].push_back(0);
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
				std::vector<int> row = board[i];
				row.erase(std::remove(row.begin(), row.end(), 0), row.end());
				board[i].erase(board[i].begin() + 1, board[i].end());
				board[i][0] = 0;
				board[i].insert(board[i].end(), row.begin(), row.end());
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
				std::vector<int> col;
				for(int k = 0; k < board_size; ++k)
				{
					col.push_back(board[k][i]);
				}
				col.erase(std::remove(col.begin(), col.end(), 0), col.end());
				for(int l = 0; l < board_size - 1; ++l)
				{
					board[l][i] = col[l];
				}
				board[board_size - 1][i] = 0;
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
				std::vector<int> col;
				for(int k = 0; k < board_size; ++k)
				{
					col.push_back(board[k][i]);
				}
				col.erase(std::remove(col.begin(), col.end(), 0), col.end());
				for(int l = 1; l < board_size; ++l)
				{
					board[l][i] = col[l - 1];
				}
				board[0][i] = 0;
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
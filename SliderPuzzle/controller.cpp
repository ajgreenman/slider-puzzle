#include <conio.h>
#include <iostream>
#include <string>

#include "Model.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Q 113

void print_board(std::vector<std::vector<int>>);

int main()
{
	std::cout << "Welcome! Press the arrow keys to move the board around. Press (q) to quit." << std::endl;

	Slider::Model model = Slider::Model();
	print_board(model.get_board());
		
	int input = 0;
	bool playing = true, won = false;
	while(playing && !won)
	{
		input = 0;

		switch(input = _getch()) {
		case KEY_UP:
			model.move_up();
			print_board(model.get_board());
			won = model.game_won();
			break;
		case KEY_DOWN:
			model.move_down();
			print_board(model.get_board());
			won = model.game_won();
			break;
		case KEY_LEFT:
			model.move_left();
			print_board(model.get_board());
			won = model.game_won();
			break;
		case KEY_RIGHT:
			model.move_right();
			print_board(model.get_board());
			won = model.game_won();
			break;
		case KEY_Q:
			playing = false;
			break;
		}
	}

	if(won)
	{
		std::cout << std::endl << "Awesome job! You won!" << std::endl << std::endl << "Press any key to exit...";
		input = _getch();
	}

	return 0;
}

void print_board(std::vector<std::vector<int>> board)
{
	std::cout << std::endl << "---------------------" << std::endl;
	for(auto &row : board)
	{
		std::cout << "|";
		for(auto &value : row)
		{
			if(value == 0)
			{
				std::cout << "    |";
			}
			else if(value > 9)
			{
				std::cout << " " << value << " |";
			}
			else
			{
				std::cout << " 0" << value << " |";
			}
		}
		std::cout << std::endl << "---------------------" << std::endl;
	}
}
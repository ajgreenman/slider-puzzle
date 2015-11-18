#include <iostream>
#include <string>

#include "Model.h"

void print_board(std::vector<std::vector<int>>);

int main()
{
	std::string input;
	std::cout << "Welcome. Press (q) to quit or any other key to play." << std::endl;
	std::cin >> input;

	while(input != "q")
	{
		Slider::Model model = Slider::Model();
		print_board(model.get_board());

		std::cout << "Press (q) to quit or any other key to play again." << std::endl;
		std::cin >> input;
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
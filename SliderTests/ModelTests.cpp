#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\SliderPuzzle\Model.h"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SliderTests
{		
	TEST_CLASS(ModelTests)
	{
	public:
		TEST_METHOD(InitializationTests)
		{
			Assert::IsTrue(array_initialized(), (const wchar_t *) "The board does not contain numbers 0-15");
		}

	private:
		bool array_initialized()
		{	
			Slider::Model model = Slider::Model();
			auto board = model.get_board();
			std::vector<int> numbers;
		
			for(int i = 0; i < model.get_board_length(); ++i)
			{
				for(int j = 0; j < model.get_board_length(); ++j)
				{
					numbers.push_back(board[i][j]);
				}
			}

			for(int i = 0; i < model.get_board_length() * model.get_board_length(); ++i)
			{
				if(std::find(numbers.begin(), numbers.end(), i) == numbers.end())
				{
					return false;
				}
			}

			return true;
		}
	};
}
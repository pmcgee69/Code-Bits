#pragma hdrstop
#pragma argsused

#include <iostream>
#include <array>
#include <vector>
#include "nanorange/nanorange.hpp"
//#include "nanorange/ranges.hpp"
//#include "nanorange/views.hpp"


int main()
{
	std::array<int, 10> ArrX{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4};
	std::vector<int> ArrY;

	for (auto myNumber : ArrX
			 | nano::views::filter(
					[](auto i) { return (0 == i % 2) && (i > 0); }
			 )
		 )
		 ArrY.push_back(myNumber);

	std::cout << "Original array: ";
	for(auto number : ArrX)           std::cout << number << " ";
	std::cout << "\nAfter PositiveEvens: ";
	for(auto number : ArrY)           std::cout << number << " ";
	std::cout << "\n";

	getchar();
}



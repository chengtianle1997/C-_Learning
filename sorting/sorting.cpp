#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> values = { 3, 5, 1, 4, 2 };
	// <functional>
	// std::sort(values.begin(), values.end(), std::greater<int>());
	// lambda function
	std::sort(values.begin(), values.end(), [](int a, int b)
	{
		// if we return true here, a will be listed before b,
		// if we return false, a will be listed behind b.

		// for example, in ascending order:
		// return a < b;

		// in desending order:
		// return a > b;

		// list element in ascending order and put '1' to the end:
		if (a == 1)
			return false;
		if (b == 1)
			return true;
		return a < b;
	});
	for (int value : values)
	{
		std::cout << value << std::endl;
	}
}
#include "Header.h"
bool testPoint_length()
{
	Point corner1{ 0.0,0.0,0.0 };
	Point corner2{ 1.0,1.0,1.0 };
	double x = corner1.length();
	double y = corner2.length();
	if (x == 0 && y == std::sqrt(corner2.x * corner2.x + corner2.y * corner2.y + corner2.z * corner2.z))
	{
		return true;
	}
	return false;
}

bool testPoint_minus_operator()
{
	Point corner1{ 0.0,0.0,0.0 };
	Point corner2{ 1.0,1.0,1.0 };

	Point res = corner2 - corner1;
	if(res == Point {1.0,1.0,1.0})
	{
		return true;
	}
	return false;
}

bool testPoint_plus_operator()
{
	Point corner1{ 0.0,0.0,0.0 };
	Point corner2{ 1.0,1.0,1.0 };

	Point res = corner2 + corner1;
	if (res == Point{ 1.0,1.0,1.0 })
	{
		return true;
	}
	return false;
}

bool testPoint_det_operator()
{
	Point corner1{ 2.0,2.0,2.0 };
	double val = 2;

	Point res = corner1 / val;
	if (res == Point{ 1.0,1.0,1.0 })
	{
		return true;
	}
	return false;
}

bool testPoint_multiply_operator()
{
	Point corner1{ 2.0,2.0,2.0 };
	double val = 2;

	Point res = corner1 * val;
	if (res == Point{ 4.0,4.0,4.0 })
	{
		return true;
	}
	return false;
}

bool testPoint_equal_operator()
{
	Point corner1{ 2.0,2.0,2.0 };
	Point corner2{ 2.0,2.0,2.0 };

	bool res = corner1 == corner2;
	return res;
}

void test_point()
{
	bool result = testPoint_length();
	std::cout << "Результат теста метода length(): " << result << '\n';

	result = testPoint_minus_operator();
	std::cout << "Результат теста оператора минус: " << result << '\n';

	result = testPoint_plus_operator();
	std::cout << "Результат теста оператора плюс: " << result << '\n';

	result = testPoint_det_operator();
	std::cout << "Результат теста оператора делить на число: " << result << '\n';

	result = testPoint_multiply_operator();
	std::cout << "Результат теста оператора умножить на число: " << result << '\n';

	result = testPoint_equal_operator();
	std::cout << "Результат теста оператора равенства: " << result << '\n';
}

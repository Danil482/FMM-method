#include "Header.h"
bool testPoint_length()
{
	Point corner1{ 0.0,0.0};
	Point corner2{ 1.0,1.0};
	double x = corner1.length();
	double y = corner2.length();
	if (x == 0 && y == std::sqrt(corner2.x * corner2.x + corner2.y * corner2.y))
	{
		return true;
	}
	return false;
}

bool testPoint_minus_operator()
{
	Point corner1{ 0.0,0.0 };
	Point corner2{ 1.0,1.0};

	Point res = corner2 - corner1;
	if(res == Point {1.0,1.0})
	{
		return true;
	}
	return false;
}

bool testPoint_plus_operator()
{
	Point corner1{ 0.0,0.0 };
	Point corner2{ 1.0,1.0 };

	Point res = corner2 + corner1;
	if (res == Point{ 1.0,1.0 })
	{
		return true;
	}
	return false;
}

bool testPoint_det_operator()
{
	Point corner1{ 2.0,2.0};
	double val = 2;

	Point res = corner1 / val;
	if (res == Point{ 1.0,1.0})
	{
		return true;
	}
	return false;
}

bool testPoint_multiply_operator()
{
	Point corner1{ 2.0,2.0};
	double val = 2;

	Point res = corner1 * val;
	if (res == Point{ 4.0,4.0})
	{
		return true;
	}
	return false;
}

bool testPoint_equal_operator()
{
	Point corner1{ 2.0,2.0};
	Point corner2{ 2.0,2.0 };

	bool res = corner1 == corner2;
	return res;
}

bool test_distance_between()
{
	Point corner1{ 2.0,2.0};
	Point corner2{ 4.0,4.0};
	if(distanceBetween(corner1,corner2) == std::sqrt(8))
	{
		return true;
	}
	return false;
}
void test_point()
{
	bool result = testPoint_length();
	std::cout << "��������� ����� ������ length(): " << result << '\n';

	result = testPoint_minus_operator();
	std::cout << "��������� ����� ��������� �����: " << result << '\n';

	result = testPoint_plus_operator();
	std::cout << "��������� ����� ��������� ����: " << result << '\n';

	result = testPoint_det_operator();
	std::cout << "��������� ����� ��������� ������ �� �����: " << result << '\n';

	result = testPoint_multiply_operator();
	std::cout << "��������� ����� ��������� �������� �� �����: " << result << '\n';

	result = testPoint_equal_operator();
	std::cout << "��������� ����� ��������� ���������: " << result << '\n';

	result = test_distance_between();
	std::cout << "��������� ����� distance_between: " << result << '\n';
}

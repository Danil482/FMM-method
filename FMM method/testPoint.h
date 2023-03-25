#pragma once
#include "Point.h"
bool testPoint_length()
{
	Point corner1{ 0.0,0.0,0.0 };
	Point corner2{ 1.0,1.0,1.0 };
	double x = corner1.length();
	double y = corner2.length();
	if (x == 0 && y == 1)
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
#include"Header.h"
bool test_charge_det_operator()
{
	Point p1{ 1.0,1.0,1.0 };
	Charge charge{ p1,10 };
	charge = charge / 10;
	if(charge.location == Point {0.1,0.1,0.1} && charge.value == 1)
	{
		return true;
	}
	return false;
}

bool test_empty()
{
	Charge charge{};
	if(charge.empty())
	{
		return true;
	}
	return false;
}

void test_charge()
{
	bool res = test_charge_det_operator();
	std::cout << "Результат теста оператора / для заряда и числа: " << res << '\n';

	res = test_empty();
	std::cout << "Результат теста метода empty : " << res << '\n';
}
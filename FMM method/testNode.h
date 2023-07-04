#include"Header.h"
bool test_is_Leaf()
{
	Node node{};
	if(node.isLeaf())
	{
		return true;
	}
	return false;
}

bool test_get_total_charge()
{
	Node node { 0,0,Point{1.0,1.0},Point{2.0,2.0} };
	std::vector<std::shared_ptr<Charge>> charges;
	charges.push_back(std::make_shared<Charge>(Point(0.9, 0.9), 10));
	charges.push_back(std::make_shared<Charge>(Point(0.8, 0.8), 12));
	node.charges = charges;
	if(node.getTotalCharge() == 22)
	{
		return true;
	}
	return false;
}

bool test_update_Center_of_Mass()
{
	Node node{ 0,0,Point{1.0,1.0},Point{2.0,2.0} };
	/*std::vector<std::shared_ptr<Charge>> charges;
	charges.push_back(std::make_shared<Charge>(Point(1.0, 1.0, 1.0), 10));
	charges.push_back(std::make_shared<Charge>(Point(2.0, 2.0, 2.0), 12));
	node.charges = charges;
	node.updateCenterOfMass();*/
	if (node.centerOfMass == Point{0.5,0.5})
	{
		return true;
	}
	return false;
}

void test_node()
{
	bool res = test_is_Leaf();
	std::cout << "Результат теста is_Leaf: " << res << '\n';

	res = test_get_total_charge();
	std::cout << "Результат теста get_total_charge: " << res << '\n';

	res = test_update_Center_of_Mass();
	std::cout << "Результат теста test_update_Center_of_Mass: " << res << '\n';
}

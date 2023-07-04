#include"Header.h"
std::vector<std::shared_ptr<Charge>> charges;
std::vector<Node> tree;

std::vector<std::shared_ptr<Charge>> generateCharges(Point p1, Point p2, Point q, int count = 100)
{
	// Create a random number generator using the current time as a seed
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

	// Create a uniform distribution for generating random double values in [-5.0, 5.0]
	std::uniform_real_distribution<double> distribution1(p1.x, p1.y);
	std::uniform_real_distribution<double> distribution2(p2.x, p2.y);
	std::uniform_real_distribution<double> distribution3(q.x, q.y);

	// Fill the charges vector with count random charges
	std::vector<std::shared_ptr<Charge>> charges;
	for (int i = 0; i < count; ++i)
	{
		Point position(distribution1(generator), distribution2(generator));
		double charge = distribution3(generator);
		charges.push_back(std::make_shared<Charge>(position, charge));
	}
	/*std::uniform_real_distribution<double> distribution4(p1.x + 3.0, p1.y + 3.0);
	std::uniform_real_distribution<double> distribution5(p2.x + 3.0, p2.y + 3.0);
	for (int i = 0; i < count / 3; ++i)
	{
		Point position(distribution4(generator), distribution5(generator));
		double charge = distribution3(generator);
		charges.push_back(std::make_shared<Charge>(position, charge));
	}
	std::uniform_real_distribution<double> distribution6(p1.x, p1.y + 3.0);
	std::uniform_real_distribution<double> distribution7(p2.x, p2.y + 3.0);
	for (int i = 0; i < count / 3; ++i)
	{
		Point position(distribution6(generator), distribution7(generator));
		double charge = distribution3(generator);
		charges.push_back(std::make_shared<Charge>(position, charge));*/
	//}
	

	
	return charges;
}

void outputDataToFile(int i)
{
	ofstream fout("outputChargeLocation.txt");
	for (auto charge : charges)
	{
		fout << charge->location.x << " " << charge->location.y << std::endl;
	}
	ofstream fout3("outputTreeLocation" + to_string(i) + ".txt");
	for (auto item : tree)
	{
		fout3 << item.corner1.x << " " << item.corner1.y << " " << item.corner2.x << " " << item.corner2.y
			<< std::endl;
	}
}
void inputDataFromFile(string s1 = "outputChargeLocation.txt", string s2 = "outputChargeValue.txt")
{
	std::ifstream locationFile(s1);
	std::ifstream valueFile(s2);

	// Read the data from the files and add it to the charges vector
	std::string locationLine, valueLine;
	while (std::getline(locationFile, locationLine) && std::getline(valueFile, valueLine)) {
		std::istringstream locationStream(locationLine);
		std::istringstream valueStream(valueLine);
		double x, y, value;
		locationStream >> x >> y;
		valueStream >> value;
		charges.push_back(std::make_shared<Charge>(Point(x, y), value));
	}
}
void casualProblem()
{
	charges = generateCharges(Point(-2.0, 2.0), Point(-2.0, 2.0), Point(-1.0, 1.0),250);
	ofstream fout("outputChargeLocation2.txt");
	for (auto charge : charges)
	{
		fout << charge->location.x << " " << charge->location.y << std::endl;
	}
}
void casualSubProblem()
{
	charges = generateCharges(Point(1.0, 1.5), Point(1.5, 2.0), Point(-1.0, 1.0), 100);
	ofstream fout("outputChargeLocation4.txt");
	for (auto charge : charges)
	{
		fout << charge->location.x << " " << charge->location.y << std::endl;
	}
}
void moveTargetPointPoint()
{
	Charge charge(Point(-0.5, 0.0), 0.0);
	Node root(0, 0, Point(-1.0, -1.0), Point(0.0, 1.0));
	root.charges.push_back(std::make_shared<Charge>(charge));
	Point target(0.0, 0.0);
	Point h(0.01, 0.0);
	vector<double> potentials;
	for (int k = 8; k < 15; k++)
	{
		root.charges[0]->value += 0.2;
		target = Point(0.0, 0.0);
		for (int i = 0; i < 1000; ++i)
		{
			potentials.push_back(calculatePotentialDirect(root, target));
			target = target + h;
		}
		ofstream fout("outputPotentials" + to_string(k) + ".txt");
		for (auto p : potentials)
		{
			fout << p << std::endl;
		}
		potentials.clear();
	}
}
void moveTargetPointCloud()
{
	//charges = generateCharges(Point(-1.0, 0.0), Point(-1.0, 1.0), Point(-1.0,1.0), 100);
	inputDataFromFile("outputChargeLocation1.txt", "outputChargeValue1.txt");
	Node root(0, 0, Point(-1.0, -1.0), Point(0.0, 1.0));
	root.charges = charges;
	std::cout <<"Total charge: "<< root.getTotalCharge() << std::endl;
	Point target(0.0, 0.0);
	Point h(0.01, 0.0);
	vector<double> potentials;
	for(int k = 2; k < 8; k++)
	{
		root.charges[0]->value += 0.2;
		target = Point(0.0, 0.0);
		for(int i = 0; i < 1000; ++i)
		{
			potentials.push_back(calculatePotentialDirect(root, target));
			target = target + h;
		}
		ofstream fout("outputPotentials" + to_string(k) + ".txt");
		for (auto p : potentials)
		{
			fout << p << std::endl;
		}
		potentials.clear();
	}
	//ofstream fout1("outputChargeLocation1.txt");
	//for (auto charge : charges)
	//{
	//	fout1 << charge->location.x << " " << charge->location.y << std::endl;
	//}
	//ofstream fout2("outputChargeValue1.txt");
	//for (auto charge : charges)
	//{
	//	fout2 << charge->value << std::endl;
	//}
}
void outputdata()
{
	//// Create a random number generator using the current time as a seed
	//std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

	//// Create a uniform distribution for generating random double values in [-5.0, 5.0]
	//std::uniform_real_distribution<double> distribution1(-2.0, 0.0);
	//std::uniform_real_distribution<double> distribution2(-2.0, 2.0);
	//std::uniform_real_distribution<double> distribution3(-1.0, 1.0);

	//// Fill the charges vector with 100 random charges
	//std::vector<std::shared_ptr<Charge>> charges;
	//for (int i = 0; i < 100; ++i) {
	//	Point position(distribution1(generator), distribution2(generator));
	//	double charge = distribution3(generator);
	//	charges.push_back(std::make_shared<Charge>(position, charge));
	//}
	// Open the files
	std::ifstream locationFile("outputChargeLocation.txt");
	std::ifstream valueFile("outputChargeValue.txt");

	// Create a vector of charges
	std::vector<std::shared_ptr<Charge>> charges;

	// Read the data from the files and add it to the charges vector
	std::string locationLine, valueLine;
	while (std::getline(locationFile, locationLine) && std::getline(valueFile, valueLine)) {
		std::istringstream locationStream(locationLine);
		std::istringstream valueStream(valueLine);
		double x, y, value;
		locationStream >> x >> y;
		valueStream >> value;
		charges.push_back(std::make_shared<Charge>(Point(x, y), value));
	}
	//charges.push_back(std::make_shared<Charge>(Point(-1.0, 0.0), 11.4709));

	// Close the files
	//locationFile.close();
	//valueFile.close();

	// Create a root node
	Node root(0, 0, Point(-2.0, -2.0), Point(101.0, 101.0));
	root.charges = charges;
	//std::cout<<"Полный заряд: " << root.getTotalCharge() << std::endl; // -2.55351e-15
	// Build the tree
	std::vector<Node> tree;
	buildTree(root, tree, 1, 5.0);

	//printTree(tree);
	//Create a target point
	vector<double> ps;
	Point target = Point( 1.0,0.0 ); //Потенциал в точке: (1,0) = -6.17206
	Point h = Point(1, 0.0);
	for(int i = 0; i < 100; ++i)
	{
		double p = calculatePotentialDirect(tree[0], target);
		ps.push_back(p);
		std::cout << "Потенциал в точке: ("<< target.x<<"," << target.y<< ") = " << p << std::endl;
		target = target + h;
	}
	/*double p = calculatePotentialDirect(tree[0], target);
	ps.push_back(p);
	std::cout << "Потенциал в точке: (" << target.x << "," << target.y << ") = " << p << std::endl;*/
	/*ofstream fout("outputChargeLocation.txt");
	for(auto charge : charges)
	{
		fout << charge->location.x << " " << charge->location.y << std::endl;
	}
	ofstream fout2("outputChargeValue.txt");
	for (auto charge : charges)
	{
		fout2 << charge->value << std::endl;
	}
	ofstream fout3("outputTreeLocation.txt");
	for(auto item : tree)
	{
		fout3 << item.corner1.x << " " << item.corner1.y << " " << item.corner2.x << " " << item.corner2.y 
			<< std::endl;
	}*/
	ofstream fout("outputPotentials0.txt");
	for (auto p : ps)
	{
		fout << p << std::endl;
	}

}
void newBuildTreeTest()
{
	//charges = generateCharges(Point(-2.0, 0.0), Point(-2.0, 2.0), Point(-1.0, 1.0),500);
	inputDataFromFile();
	Node root(0, 0, Point(-2.0, -2.0), Point(2.0, 2.0));
	root.charges = charges;
	//std::cout<<"Полный заряд: " << root.getTotalCharge() << std::endl; // -2.55351e-15
	// Build the tree
	buildTree(root, tree);

	//printTree(tree);
	//Create a target point
	vector<double> ps;
	Point target = Point(-0.4, -0.4);

	double p = calculatePotentialDirect(tree[0], target);

	std::cout << "Потенциал в точке: (" << target.x << "," << target.y << ") = " << p << std::endl;

	outputDataToFile(0);
}

void getAlgoSteps()
{
	//charges = generateCharges(Point(-2.0, -1.0), Point(-2.0, -1.0), Point(-1.0, 1.0),250);
	inputDataFromFile();
	Node root(0, 0, Point(-2.0, -2.0), Point(2.0, 2.0));
	root.charges = charges;
	//std::cout<<"Полный заряд: " << root.getTotalCharge() << std::endl; // -2.55351e-15
	// Build the tree
	for (int i = 1; i <= 5; ++i)
	{	
		buildTree(root, tree, i, 2);

		//printTree(tree);
		//Create a target point
		vector<double> ps;
		Point target = Point(0.4, 0.4);

		double p = calculatePotentialDirect(tree[0], target);

		std::cout << "Потенциал в точке: (" << target.x << "," << target.y << ") = " << p << std::endl;

		outputDataToFile(i);
	}
}
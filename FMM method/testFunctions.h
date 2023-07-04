#include"Header.h"
bool test_chargesInNode()
{
	Node node{ 0,0,Point{1.0,1.0},Point{20.0,20.0} };
	std::vector<std::shared_ptr<Charge>> charges;
	charges.push_back(std::make_shared<Charge>(Point(1.0, 1.0), 10));
	charges.push_back(std::make_shared<Charge>(Point(2.0, 2.0), 12));
	size_t count = chargesInNode(node, charges);
	if(count == 1)
	{
		return true;
	}
	return false;
}

bool test_getSubCorner()
{
	Point p1{ 1.0,1.0 };
	Point p2{ 2.0,2.0};
	Point res = getSubCorner(p1, p2, 0);
	if(res == Point {1.0,1.0})
	{
		return true;
	}
	return false;
}

void test_and()
{
	std::cout << '\n';
	for(int i = 0; i < 4; i++)
	{
		std::cout << (i & 1) << "\t";
		
	}
	std::cout << '\n';
	for (int i = 0; i < 4; i++)
	{
		std::cout << (i & 2) << "\t";

	}
	std::cout << '\n';
	for (int i = 0; i < 4; i++)
	{
		std::cout << (i & 4) << "\t";

	}
	std::cout << '\n';
}

void test_SplitNode() {
    // Create a node and add some charges
    Point corner1(0, 0);
    Point corner2(1, 1);
    Node node(0, 0, corner1, corner2);
    std::vector<std::shared_ptr<Charge>> charges = {
        std::make_shared<Charge>(Point(0.25, 0.25), 1.0),
        std::make_shared<Charge>(Point(0.75, 0.75), -1.0),
    };
    node.charges = charges;

    // Split the node
    std::vector<Node> tree;
	tree.push_back(node);
    splitNode(node, tree);

    // Check the results
	assert(tree.size() == 3);
    assert(node.children[0]->charges.size() == 1);
    assert(node.children[0]->charges[0]->location == Point(0.25, 0.25));
	assert(node.children[3]->charges.size() == 1);
    assert(node.children[3]->charges[0]->location == Point(0.75, 0.75));
}

void test_BuildTree() {
    // Create a vector of charges
    std::vector<std::shared_ptr<Charge>> charges = {
        std::make_shared<Charge>(Point(1.0, 1.0), 1.0),
        std::make_shared<Charge>(Point(2.0, 2.0), -2.0),
        std::make_shared<Charge>(Point(3.0, 3.0), 3.0),
        std::make_shared<Charge>(Point(4.0, 4.0), -4.0),
        std::make_shared<Charge>(Point(-1.0, -1.0), 1.0),
        std::make_shared<Charge>(Point(-2.0, -2.0), -2.0),
        std::make_shared<Charge>(Point(-3.0, -3.0), 3.0),
        std::make_shared<Charge>(Point(-4.0, -4.0), -4.0)
    };

    // Create a root node
    Node root(0, 0, Point(-5.0, -5.0), Point(5.0, 5.0));
    root.charges = charges;
    // Build the tree
	std::vector<Node> tree;
    buildTree(root,tree, 2, 1.0);

	printTree(tree);

    // Test the size of the tree
    assert(tree.size() == 7);
	// Test the root node
	assert(tree[0].corner1 == Point(-5.0, -5.0));
	assert(tree[0].corner2 == Point(5.0, 5.0));
	assert(tree[0].depth == 0);
	assert(tree[0].charges.size() == charges.size());

	// Test the charges in the child nodes
	assert(tree[1].charges.size() == 4);
	assert(tree[2].charges.size() == 4);
	assert(tree[3].charges.size() == 2);
	assert(tree[4].charges.size() == 2);
	assert(tree[5].charges.size() == 2);
	assert(tree[6].charges.size() == 2);

	// Test the depth of the child nodes
	assert(tree[1].depth == 1);
	assert(tree[2].depth == 1);
	assert(tree[3].depth == 2);
	assert(tree[4].depth == 2);
	assert(tree[5].depth == 2);
	assert(tree[6].depth == 2);

	//Test the children in the parents node
	assert(tree[0].children[0]->index == 1); 
	assert(tree[0].children[0]->depth == 1);
	assert(tree[0].children[0]->corner1 == Point( - 5.0, -5.0));
	assert(tree[0].children[0]->corner2 == Point( 0.0,0.0));
	// std::make_shared<Node>)(1, 1, Point{ -5.0,-5.0,-5.0 }, Point{ 0.0,0.0,0.0 })
}

void test_CalculatePotentioal()
{
	// Create a vector of charges
	std::vector<std::shared_ptr<Charge>> charges = {
		std::make_shared<Charge>(Point(1.0, 0.0), 1.0),
		//std::make_shared<Charge>(Point(2.0, 2.0, 2.0), -2.0),
		//std::make_shared<Charge>(Point(3.0, 3.0, 3.0), 3.0),
		//std::make_shared<Charge>(Point(4.0, 4.0, 4.0), -4.0),
		std::make_shared<Charge>(Point(-1.0, 0.0), -2.0)
		//std::make_shared<Charge>(Point(-2.0, -2.0, -2.0), -2.0),
		//std::make_shared<Charge>(Point(-3.0, -3.0, -3.0), 3.0),
		//std::make_shared<Charge>(Point(-4.0, -4.0, -4.0), -4.0)
	};

	// Create a root node
	Node root(0, 0, Point(-5.0, -5.0), Point(5.0, 5.0));
	root.charges = charges;
	// Build the tree
	std::vector<Node> tree;
	buildTree(root, tree, 2, 1.0);

	//printTree(tree);

	double p = calculatePotential(tree[0], Point{-1.0/3.0,100.0});
	std::cout << "Потенциал в точке: " << p << std::endl;
}


void test_Functions()
{/*
	bool res = test_chargesInNode();
	std::cout << "Результат теста chargesInNode: " << res << '\n';

	res = test_getSubCorner();
	std::cout << "Результат теста getSubCorner: " << res << '\n';*/

	//test_and();
	//test_SplitNode();
    //test_BuildTree();
	test_CalculatePotentioal();

}
#include "Header.h"
struct Node  {
    size_t index; // The index of the node
    double size;  // The size of the node
    std::vector<std::shared_ptr<Charge>> charges; // A shared pointer to the charge contained in the node (if any)
    std::vector<std::shared_ptr<Node>> children; // A vector of shared pointers to the children nodes
    size_t depth; // The depth of the node in the tree
    Point corner1, corner2; // The corners of the node's bounding box
    Point centerOfMass; // The center of mass of the node

    // Default constructor
    Node() {}

    // Constructor that takes index, depth, corner1 and corner2
    Node(int index, int depth, Point corner1, Point corner2) :
        index(index), depth(depth), corner1(corner1), corner2(corner2), size((corner2 - corner1).length()), centerOfMass((corner2 - corner1) / 2)
    {
        children.resize(4);
    }
    // Function that returns whether the node is a leaf node or not
    bool isLeaf() const {
        bool res = true;
        // Check if any of the children nodes are not null pointers
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i] != nullptr)
            {
                res = false;
            }
        }
        return res;
    }

    // Function that returns the total charge of the node and all its children
    double getTotalCharge() const {
        double totalCharge = 0.0;
        for(auto charge:charges)
        {
            totalCharge += charge->value;
        }
        return totalCharge;
    }
    double getTotalChargeAbs() const {
        double totalCharge = 0.0;
        for (auto charge : charges)
        {
            totalCharge += abs(charge->value);
        }
        return totalCharge;
    }
};
#include"Header.h"
// This function counts the number of charges that are inside a given 3D box defined by two corners.
size_t chargesInNode(const Node& node, const std::vector<std::shared_ptr<Charge>>& charges) {
        // Initialize a counter to keep track of the number of charges in the cell
        size_t count = 0;
        // Iterate over each charge in the input vector of charges
        for (const auto& charge : charges) {
            // Check if the location of the charge is inside the box defined by the two corners
            if (charge->location.x > node.corner1.x && charge->location.x < node.corner2.x &&
                charge->location.y > node.corner1.y && charge->location.y < node.corner2.y &&
                charge->location.z > node.corner1.z && charge->location.z < node.corner2.z) {
                // If the charge is inside the box, increment the counter
                count++;
            }
        }
        // Return the number of charges found inside the box
        return count;
    }

    // This function returns the corner point of a subcell in a octree cell
Point getSubCorner(const Point& corner1, const Point& corner2, int index) {
    // given the two corners of the parent cell and the index of the subcell.
    // The index is a 3-bit integer (0 to 7), with each bit corresponding to
    // whether the subcell is in the "lower" or "upper" half of the parent cell
    // along each of the three dimensions.
    double x1 = corner1.x, y1 = corner1.y;
    double x2 = corner2.x, y2 = corner2.y;

        double x = (index & 1) ? x1 + (x2 - x1) / 2.0 : x1;
        double y = (index & 2) ? y1 + (y2 - y1) / 2.0 : y1;

        return Point(x, y);
    }

void splitNode(Node& node, std::vector<Node>& tree) {
    std::vector<std::vector<std::shared_ptr<Charge>>> subCharges(8);
    for (const std::shared_ptr<Charge> charge : node.charges) {
        for (int i = 0; i < 4; i++) {
            Point subCorner1 = getSubCorner(node.corner1, node.corner2, i);
            Point subCorner2 = subCorner1 + (node.corner2 - node.corner1) / 2;
            if (charge->location.inCorner(subCorner1) && subCorner2.inCorner(charge->location)) {
                subCharges[i].push_back((charge));
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!subCharges[i].empty()) {
            if (node.children[i] == nullptr) {
                Point subCorner1 = getSubCorner(node.corner1, node.corner2, i);
                Point subCorner2 = subCorner1 + (node.corner2 - node.corner1) / 2;
                node.children[i] = std::make_shared<Node>(tree.size(), node.depth + 1, subCorner1, subCorner2);
                node.children[i]->charges = subCharges[i];
                for(int j = 0 ; j < tree.size(); j++)
                {
                    if(node.children[i]->depth - tree[j].depth == 1 &&
                        node.children[i]->corner1.inCorner(tree[j].corner1) && 
                        tree[j].corner2.inCorner(node.children[i]->corner2))
                    {
                        tree[j].children[i] = node.children[i];
                    }
                }
                tree.push_back(*node.children[i]);
            }
        }
    }
}

void buildTree(Node& root,std::vector<Node>& tree, int maxDepth = 5, 
    int maxCountOfChargesInCell = 10) 
{
    tree.push_back(root);

    std::vector<Node> queue;
    queue.push_back(tree[0]);

    while (!queue.empty()) {
        Node node = queue.back();
        queue.pop_back();

        if (node.depth == maxDepth || 
            node.charges.size() <= maxCountOfChargesInCell) {
            continue;
        }
        splitNode(node, tree);

        for (int i = 0; i < 4; i++) {
            if (node.children[i] != nullptr) {
                queue.push_back(*node.children[i]);
            }
        }
    }
    //return tree;
}


void printTree(const std::vector<Node>& tree) {
    for(auto item: tree)
    {
    std::cout << "Node " << item.index << " at depth " << item.depth << ": "
        << "corner 1 = (" << item.corner1.x << ", " << item.corner1.y << "), "
        << "corner 2 = (" << item.corner2.x << ", " << item.corner2.y << "), "
        << "size: " << item.size << ", " << "number of charges: "<< item.charges.size() << std::endl;
    }
}

double calculatePotential(Node& node, const Point& point) {
    // Calculate distance between charge and center of mass of node
    
    double distance = distanceBetween(node.centerOfMass, point);
    // Check if the point is inside the current node
    if (point.inCorner(node.corner1) && node.corner2.inCorner(point)) { // If the point is sufficiently far from the center of mass
        if (node.isLeaf()) { // If the node has no children, consider the potentials as summation
            double potential = 0.0;
            for (const auto& c : node.charges) {
                double distance = distanceBetween(c->location, point);
                potential += c->value / distance;
            }
            return potential;
        }
        else { // If the node has children, call recursively for each child
            double potential = 0.0;
            for (const auto& child : node.children) {
                if (child != nullptr) {
                    potential += calculatePotential(*child, point);
                }
            }
            return potential;
        }
    }
    else { // If the point is not inside the current node, approximate as 1 charge and add to potential
        double distance = distanceBetween(node.centerOfMass, point);
        return node.getTotalCharge() * log(distance);
    }
}

double calculatePotentialDirect(Node& node, const Point& point) 
{
    double potential = 0.0;
    for (const auto& c : node.charges) {
        double distance = distanceBetween(c->location, point);
        potential += c->value * log(distance);
    }
    return potential;
}






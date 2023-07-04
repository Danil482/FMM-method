#include"Header.h"
// Define a struct for a 3D point with x, y, and z coordinates
struct Point {
    double x, y, z; // coordinates of the charge

    // Default constructor
    Point() {}

    // Constructor that initializes the coordinates
    Point(double _x, double _y)
        : x(_x), y(_y) {}

    // Calculate the length of the point vector
    double length() const {
        return std::sqrt(x * x + y * y);
    }
    // Check if the point is within a given corner (bounding box)
    bool inCorner(const Point& corner1) const {
        return (x >= corner1.x) &&
            (y >= corner1.y);
    }
};
// Overloaded subtraction operator for Point objects
Point operator-(const Point& p1, const Point& p2)
{
    return { p1.x - p2.x,p1.y - p2.y };
}
// Overloaded division operator for Point objects with a scalar value
Point operator/(const Point& p1, const double value)
{
    return { p1.x / value,p1.y / value};
}
// Overloaded division operator for Point objects with a scalar value
Point operator*(const Point& p1, double value)
{
    return{ p1.x * value,p1.y * value };
}
// Overloaded addition operator for Point objects
Point operator+(const Point& p1, const Point& p2)
{
    return { p1.x + p2.x,p1.y + p2.y };
}
// Overloaded equality operator for Point objects
bool operator==(const Point& p1, const Point& p2)
{
    if (p1.x == p2.x && p1.y == p2.y) // Check if x, y, and z coordinates of the two points are equal
    {
        return true;
    }
    return false;
}
double distanceBetween(const Point& p1, const Point& p2) {
            return (p2 - p1).length();
        }
// Define a struct for representing an electric charge
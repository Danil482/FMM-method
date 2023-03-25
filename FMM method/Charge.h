#include"Header.h"
struct Charge {
    Point location;  // The location of the charge in 3D space
    double value;    // The value of the charge
    Charge(){}
    // Constructor to initialize the charge with a location and a value
    Charge(Point _location, double _value) : location{ _location }, value{ _value } {}

    // Overload the division operator to allow division by a scalar
    Charge operator/(double divisor) const {
        return Charge(location / divisor, value / divisor);
    }
    // Check if the charge is empty
    bool empty()
    {   // Return true if the location is (0,0,0) and the value is NULL
        if (this->location == Point())
        {
            return true;
        }
        return false;
    }
};
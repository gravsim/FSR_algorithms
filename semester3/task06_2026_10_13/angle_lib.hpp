#include <iostream>


class Angle
{
private:
    double degree;
    double radians;

public:
    Angle(double degree);
    Angle();
    const double get_degree();
    const double get_radians();
    void set_degree(double deg);
    void set_radians(double rad);

    Angle operator+(Angle angle);
    Angle operator-(Angle angle);
    Angle operator*(double coefficient);
    Angle operator/(double coefficient);
    Angle operator+=(Angle angle);
    Angle operator-=(Angle angle);
    Angle operator*=(double coefficient);
    Angle operator/=(double coefficient);
    Angle operator++();
    Angle operator--();

};

std::ostream& operator<<(std::ostream& out, Angle angle);
std::istream& operator>>(std::istream& in, Angle angle);


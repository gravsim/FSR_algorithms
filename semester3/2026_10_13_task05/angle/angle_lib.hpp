#include <iostream>


class Angle
{
private:
    double degree;
    double radians;

public:
    Angle();
    Angle(double degree);
    double get_degree() const;
    double get_radians() const;
    void set_degree(double deg);
    void set_radians(double rad);

    Angle operator=(double degree);
    Angle operator+(Angle angle) const;
    Angle operator-(Angle angle) const;
    Angle operator*(double coefficient) const;
    Angle operator/(double coefficient) const;
    const Angle operator+=(Angle angle);
    const Angle operator-=(Angle angle);
    const Angle operator*=(double coefficient);
    const Angle operator/=(double coefficient);
    bool operator==(Angle angle) const;
    bool operator<=(Angle angle) const;
    bool operator>=(Angle angle) const;
    bool operator<(Angle angle) const;
    bool operator>(Angle angle) const;
    const Angle operator++();
    const Angle operator++(int);
    const Angle operator--();
    const Angle operator--(int);
    friend std::ostream& operator<<(std::ostream& out, Angle& angle);
    friend std::istream& operator>>(std::istream& in, Angle& angle);

    operator double() const;
    operator int() const;
};


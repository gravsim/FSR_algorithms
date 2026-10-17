
#ifndef ANGLE
#define ANGLE
#include <iostream>


class Vec2;


class Angle
{
private:
    double degree;
    double radians;

public:
    Angle();
    Angle(double degree);
    Angle(double value, int type);
    Angle(Vec2& vec);
    double get_degree() const;
    double get_radians() const;
    void set_degree(double deg);
    void set_radians(double rad);
    Vec2 to_vec2() const;

    double get_cos() const;
    double get_sin() const;

    Angle operator=(double degree);
    Angle operator+(Angle& angle) const;
    Angle operator-(Angle& angle) const;
    Angle operator*(double coefficient) const;
    Angle operator/(double coefficient) const;
    const Angle operator+=(Angle& angle);
    const Angle operator-=(Angle& angle);
    const Angle operator*=(double coefficient);
    const Angle operator/=(double coefficient);
    bool operator==(Angle& angle) const;
    bool operator<=(Angle& angle) const;
    bool operator>=(Angle& angle) const;
    bool operator<(Angle& angle) const;
    bool operator>(Angle& angle) const;
    const Angle operator++();
    const Angle operator++(int);
    const Angle operator--();
    const Angle operator--(int);
    friend std::ostream& operator<<(std::ostream& out, Angle& angle);
    friend std::istream& operator>>(std::istream& in, Angle& angle);

    operator double() const;
    operator int() const;
    operator Vec2() const;
};

#endif

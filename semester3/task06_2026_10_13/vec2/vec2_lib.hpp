#include <iostream>


class Vec2
{
private:
    double x;
    double y;

public:
    Vec2();
    Vec2(double x, double y);
    const double get_x();
    const double get_y();
    const double get_norm();
    void set_x(double x0);
    void set_y(double y0);

    Vec2& operator=(Vec2 vec);
    Vec2 operator+(Vec2 vec);
    Vec2 operator-(Vec2 vec);
    Vec2 operator-();
    Vec2 operator*(double coefficient);
    Vec2 operator/(double coefficient);


    Vec2 operator+=(Vec2 vec);
    Vec2 operator-=(Vec2 vec);
    Vec2 operator*=(double coefficient);
    Vec2 operator/=(double coefficient);
    Vec2 operator++();
    Vec2 operator--();
    bool operator==(Vec2 vec);
    bool operator<=(Vec2 vec);
    bool operator>=(Vec2 vec);
    friend std::ostream& operator<<(std::ostream& out, Vec2& vec);
    friend std::istream& operator>>(std::istream& in, Vec2& vec);

    operator double();
    operator int();
};


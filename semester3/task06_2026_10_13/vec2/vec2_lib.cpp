#include "vec2_lib.hpp"
#define PI 3.1415926535897932
#define PRECISION 1e-10
#include <math.h>


Vec2::Vec2() {
    this->x = 0;
    this->y = 0;
}


Vec2::Vec2(double x, double y) {
    this->x = x;
    this->y = y;
}


const double Vec2::get_x() {
    return x;
}


const double Vec2::get_y() {
    return y;
}


const double Vec2::get_norm() {
    return sqrt(x * x + y * y);
}


void Vec2::set_x(double x0) {
    this->x = x0;

}


void Vec2::set_y(double y0) {
    this->y = y0;
}


Vec2& Vec2::operator=(Vec2 vec) {
    x = vec.x;
    y = vec.y;
    return *this;
}


Vec2 Vec2::operator+(Vec2 vec) {
    return Vec2(x + vec.x, y + vec.y);
}


Vec2 Vec2::operator-(Vec2 vec) {
    return Vec2(x - vec.x, y - vec.y);
}


Vec2 Vec2::operator-() {
    return Vec2(-x, -y);
}


Vec2 Vec2::operator*(double coefficient) {
    return Vec2(x * coefficient, y * coefficient);
}


Vec2 Vec2::operator/(double coefficient) {
    return Vec2(x / coefficient, y / coefficient);
}


Vec2 Vec2::operator+=(Vec2 vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}


Vec2 Vec2::operator-=(Vec2 vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}


Vec2 Vec2::operator*=(double coefficient) {
    x *= coefficient;
    y *= coefficient;
    return *this;
}


Vec2 Vec2::operator/=(double coefficient) {
    x /= coefficient;
    y /= coefficient;
    return *this;
}


Vec2 Vec2::operator++() {
    x++;
    y++;
    return *this;
}


Vec2 Vec2::operator--() {
    x--;
    y--;
    return *this;
}


bool Vec2::operator==(Vec2 vec) {
    return fabs(x - vec.x) < PRECISION && fabs(y - vec.y) < PRECISION;
}


bool Vec2::operator<=(Vec2 vec) {
    if (x != vec.x) {
        return x < vec.x;
    }
    if (y != vec.y) {
        return y < vec.y;
    }
    return false;
}


bool Vec2::operator>=(Vec2 vec) {
    if (x != vec.x) {
        return x > vec.x;
    }
    if (y != vec.y) {
        return y > vec.y;
    }
    return false;
}


Vec2::operator double() {
    return get_norm();
}


Vec2::operator int() {
    return (int)get_norm();
}


std::ostream& operator<<(std::ostream& out, Vec2& vec) {
    out << "Vec2: (" << vec.x << ", " << vec.y << ")\n";
    return out;
}


std::istream& operator>>(std::istream& in, Vec2& vec) {
    return in >> vec.x >> vec.y;
}

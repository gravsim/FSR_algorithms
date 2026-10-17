#include "vec2.hpp"
#include "angle.hpp"
#include <cmath>
#define PI 3.1415926535897932
#define PRECISION 1e-15


// const fun() {}
// means that the return parameter is const,
// use if you return a reference or a pointer
//
// fun() const {}
// means that the function is part of a class and
// cant change any members of that class


bool double_equal(double a, double b) {
    return fabs(a - b) <= PRECISION;
}


int int_sign(double a) {
    if (a < -PRECISION) {
        return -1;
    }
    if (a > PRECISION) {
        return 1;
    }
    return 0;
}


Vec2::Vec2() {
    this->x = 0;
    this->y = 0;
}


Vec2::Vec2(double x, double y) {
    this->x = x;
    this->y = y;
}


Vec2::Vec2(Angle& angle) {
    this->x = angle.get_cos();
    this->y = angle.get_sin();
}


Vec2::Vec2(double length, Angle& angle) {
    this->x = length * angle.get_cos();
    this->y = length * angle.get_sin();
}


double Vec2::get_x() const {
    return x;
}


double Vec2::get_y() const {
    return y;
}


double Vec2::get_norm() const {
    return sqrt(x * x + y * y);
}


void Vec2::set_x(double x0) {
    this->x = x0;
}


void Vec2::set_y(double y0) {
    this->y = y0;
}


Vec2& Vec2::operator=(const Vec2& vec) {
    x = vec.x;
    y = vec.y;
    return *this;
}


Vec2 Vec2::operator+(const Vec2& vec) const {
    return Vec2(x + vec.x, y + vec.y);
}


Vec2 Vec2::operator+(const Angle& angle) const {
    double new_x = x * angle.get_cos() - y * angle.get_sin();
    double new_y = x * angle.get_sin() + y * angle.get_cos();
    return Vec2(new_x, new_y);
}


Vec2 Vec2::operator-(const Vec2& vec) const {
    return Vec2(x - vec.x, y - vec.y);
}


Vec2 Vec2::operator-(const Angle& angle) const {
    double new_x = x * angle.get_cos() + y * angle.get_sin();
    double new_y = -x * angle.get_sin() + y * angle.get_cos();
    return Vec2(new_x, new_y);
}


Vec2 Vec2::operator-() const {
    return Vec2(-x, -y);
}


Vec2 Vec2::operator*(double& coefficient) const {
    return Vec2(x * coefficient, y * coefficient);
}


Vec2 Vec2::operator/(double& coefficient) const {
    return Vec2(x / coefficient, y / coefficient);
}


Vec2 Vec2::operator+=(const Vec2& vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}


Vec2 Vec2::operator+=(const Angle& angle) {
    double new_x = x * angle.get_cos() - y * angle.get_sin();
    double new_y = x * angle.get_sin() + y * angle.get_cos();
    x = new_x;
    y = new_y;
    return *this;
}


Vec2 Vec2::operator-=(const Vec2& vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}


Vec2 Vec2::operator-=(const Angle& angle) {
    double new_x = x * angle.get_cos() + y * angle.get_sin();
    double new_y = -x * angle.get_sin() + y * angle.get_cos();
    x = new_x;
    y = new_y;
    return *this;
}


Vec2 Vec2::operator*=(double& coefficient) {
    x *= coefficient;
    y *= coefficient;
    return *this;
}


Vec2 Vec2::operator/=(double& coefficient) {
    x /= coefficient;
    y /= coefficient;
    return *this;
}


Vec2 Vec2::operator++() {
    x++;
    y++;
    return *this;
}


Vec2 Vec2::operator++(int) {
    x++;
    y++;
    return *this;
}


Vec2 Vec2::operator--() {
    x--;
    y--;
    return *this;
}


Vec2 Vec2::operator--(int) {
    x--;
    y--;
    return *this;
}


bool Vec2::operator==(const Vec2& vec) const {
    return double_equal(x, vec.x) && double_equal(y, vec.y);
}


bool Vec2::operator<=(const Vec2& vec) const {
    if (!double_equal(x, vec.x)) {
        return x <= vec.x;
    }
    if (!double_equal(y, vec.y)) {
        return y <= vec.y;
    }
    return false;
}


bool Vec2::operator>=(const Vec2& vec) const {
    if (!double_equal(x, vec.x)) {
        return x >= vec.x;
    }
    if (!double_equal(y, vec.y)) {
        return y >= vec.y;
    }
    return false;
}


bool Vec2::operator<(const Vec2& vec) const {
    if (!double_equal(x, vec.x)) {
        return x < vec.x;
    }
    if (!double_equal(y, vec.y)) {
        return y < vec.y;
    }
    return false;
}


bool Vec2::operator>(const Vec2& vec) const {
    if (!double_equal(x, vec.x)) {
        return x > vec.x;
    }
    if (!double_equal(y, vec.y)) {
        return y > vec.y;
    }
    return false;
}


Vec2::operator double() const {
    return get_norm();
}


Vec2::operator int() const {
    return (int)get_norm();
}


Vec2::operator Angle() const {
    return to_angle();
}


std::ostream& operator<<(std::ostream& out, const Vec2& vec) {
    out << "(" << vec.x << ", " << vec.y << ") ";
    return out;
}


std::istream& operator>>(std::istream& in, Vec2& vec) {
    return in >> vec.x >> vec.y;
}


Vec2 Vec2::normalized() const {
    return Vec2(x / this->get_norm(), y / this->get_norm());
}

Angle Vec2::to_angle() const {
    double radians = acos(get_x() / sqrt(get_x() * get_x() + get_y() * get_y()));
    return Angle(radians, 1);
}


double distance(Vec2& a, Vec2& b) {
    return (a - b).get_norm();
}


double cross2(const Vec2& a, const Vec2& b) {
    return a.x * b.y - a.y * b.x;
}


double dot(const Vec2& a, const Vec2& b) {
    return a.x * b.x + a.y * b.y;
}


int vectors_sign(const Vec2& point, const Vec2& start, const Vec2& end) {
    Vec2 edge = end - start;
    Vec2 diff = point - start;
    int result = int_sign(cross2(edge, diff));
    return result;
}


double cos_between(const Vec2& a, const Vec2& b) {
    return dot(a.normalized(), b.normalized());
}


Angle angle_between(const Vec2& a, const Vec2& b) {
    return Angle(acos(cos_between(a, b)), 1);
}

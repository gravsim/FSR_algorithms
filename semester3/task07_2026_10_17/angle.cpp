#include "vec2.hpp"
#include "angle.hpp"
#include <cmath>
# define PI 3.1415926535897932
#define PRECISION 1e-15


Angle::Angle() {
    this->degree = 0;
    this->radians = 0;
}


Angle::Angle(double degree) {
    this->degree = degree;
    this->radians = degree / 180 * PI;
}


Angle::Angle(double value, int type) {
    switch (type) {
        case 1:
            this->degree = value / PI * 180;
            this->radians = value;
            break;
        default:
            this->degree = value;
            this->radians = value / 180 * PI;
            break;
    }
}


Angle::Angle(Vec2& vec) {
    this->radians = acos(vec.get_x() / sqrt(vec.get_x() * vec.get_x() + vec.get_y() * vec.get_y()));
    this->degree = this->radians / PI * 180;
}


double Angle::get_degree() const{
    return degree;
}


double Angle::get_radians() const{
    return radians;
}


double Angle::get_cos() const {
    return cos(radians);
}


double Angle::get_sin() const {
    return sin(radians);
}


void Angle::set_degree(double deg) {
    this->degree = deg;
    this->radians = deg / 180 * PI;
}


void Angle::set_radians(double rad) {
    this->degree = rad / PI * 180;
    this->radians = rad;
}


Vec2 Angle::to_vec2() const {
    return Vec2(get_cos(), get_sin());
}



Angle Angle::operator=(double deg) {
    this->degree = deg;
    this->radians = deg / 180 * PI;
    return *this;
}


Angle Angle::operator+(Angle& angle) const {
    return Angle(degree + angle.degree);
}


Angle Angle::operator-(Angle& angle) const {
    return Angle(degree - angle.degree);
}


Angle Angle::operator*(double coefficient) const {
    return Angle(degree * coefficient);
}


Angle Angle::operator/(double coefficient) const {
    return Angle(degree / coefficient);
}


const Angle Angle::operator+=(Angle& angle) {
    degree += angle.degree;
    radians += angle.radians;
    return *this;
}


const Angle Angle::operator-=(Angle& angle) {
    degree -= angle.degree;
    radians -= angle.radians;
    return *this;
}


const Angle Angle::operator*=(double coefficient) {
    degree *= coefficient;
    radians *= coefficient;
    return *this;
}


const Angle Angle::operator/=(double coefficient) {
    degree /= coefficient;
    radians /= coefficient;
    return *this;
}


bool Angle::operator==(Angle& angle) const {
    return double_equal(degree, angle.degree);
}


bool Angle::operator<=(Angle& angle) const {
    return degree <= angle.degree - PRECISION;
}


bool Angle::operator>=(Angle& angle) const {
    return degree >= angle.degree + PRECISION;
}


bool Angle::operator<(Angle& angle) const {
    return degree < angle.degree - PRECISION;
}


bool Angle::operator>(Angle& angle) const {
    return degree > angle.degree + PRECISION;
}


const Angle Angle::operator++() {
    degree++;
    radians += PI / 180;
    return *this;
}


const Angle Angle::operator++(int) {
    degree++;
    radians += PI / 180;
    return *this;
}


const Angle Angle::operator--() {
    degree--;
    radians -= PI / 180;
    return *this;
}


const Angle Angle::operator--(int) {
    degree--;
    radians -= PI / 180;
    return *this;
}


Angle::operator double() const {
    return degree;
}


Angle::operator int() const {
    return (int)degree;
}


Angle::operator Vec2() const {
    return to_vec2();
}


std::ostream& operator<<(std::ostream& out, Angle& angle) {
    out << "Degree: " << angle.degree << " Radians: " << angle.radians << "\n";
    return out;
}


std::istream& operator>>(std::istream& in, Angle& angle) {
    double deg;
    in >> deg;
    angle.set_degree(deg);
    return in;
}

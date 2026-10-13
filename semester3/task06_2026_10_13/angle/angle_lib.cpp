#include "angle_lib.hpp"
# define PI 3.1415926535897932


Angle::Angle() {
    this->degree = 0;
    this->radians = 0;
}


Angle::Angle(double degree) {
    this->degree = degree;
    this->radians = degree / 180 * PI;
}


const double Angle::get_degree() {
    return degree;
}


const double Angle::get_radians() {
    return radians;
}


void Angle::set_degree(double deg) {
    this->degree = deg;
    this->radians = deg / 180 * PI;
}


void Angle::set_radians(double rad) {
    this->degree = rad / PI * 180;
    this->radians = rad;
}


Angle Angle::operator+(Angle angle) {
    return Angle(degree + angle.degree);
}


Angle Angle::operator-(Angle angle) {
    return Angle(degree - angle.degree);
}


Angle Angle::operator*(double coefficient) {
    return Angle(degree * coefficient);
}


Angle Angle::operator/(double coefficient) {
    return Angle(degree / coefficient);
}


Angle Angle::operator+=(Angle angle) {
    degree += angle.degree;
    radians += angle.radians;
    return *this;
}


Angle Angle::operator-=(Angle angle) {
    degree -= angle.degree;
    radians -= angle.radians;
    return *this;
}


Angle Angle::operator*=(double coefficient) {
    degree *= coefficient;
    radians *= coefficient;
    return *this;
}


Angle Angle::operator/=(double coefficient) {
    degree /= coefficient;
    radians /= coefficient;
    return *this;
}


Angle Angle::operator++() {
    degree++;
    radians += PI / 180;
    return *this;
}


Angle Angle::operator--() {
    degree--;
    radians -= PI / 180;
    return *this;
}


Angle::operator double() {
    return degree;
}


Angle::operator int() {
    return (int)degree;
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

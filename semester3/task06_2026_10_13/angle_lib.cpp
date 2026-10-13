#include "angle_lib.hpp"
# define PI 3.1415926535897932


Angle::Angle(double degree) {
    this->degree = degree;
    this->radians = degree / 180 * PI;
}


Angle::Angle() {
    this->degree = 0;
    this->radians = 0;
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

std::ostream& operator<<(std::ostream& out, Angle angle) {
    std::cout << "Degree: "<< angle.get_degree() << "\n";
}
std::istream& operator>>(std::istream& in, Angle angle) {
    std::cout << "Degree: "<< angle.get_degree() << "\n";
}

#include "angle_lib.hpp"
#include <cmath>
# define PI 3.1415926535897932
#define PRECISION 1e-15


bool double_equal(double a, double b) {
    return fabs(a - b) <= PRECISION;
}


Angle::Angle() {
    this->degree = 0;
    this->radians = 0;
}


Angle::Angle(double degree) {
    this->degree = degree;
    this->radians = degree / 180 * PI;
}


double Angle::get_degree() const{
    return degree;
}


double Angle::get_radians() const{
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


Angle Angle::operator+(Angle angle) const{
    return Angle(degree + angle.degree);
}


Angle Angle::operator-(Angle angle) const {
    return Angle(degree - angle.degree);
}


Angle Angle::operator*(double coefficient) const {
    return Angle(degree * coefficient);
}


Angle Angle::operator/(double coefficient) const {
    return Angle(degree / coefficient);
}


const Angle Angle::operator+=(Angle angle) {
    degree += angle.degree;
    radians += angle.radians;
    return *this;
}


const Angle Angle::operator-=(Angle angle) {
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


bool Angle::operator==(Angle angle) const {
    return double_equal(degree, angle.degree);
}


bool Angle::operator<=(Angle angle) const {
    return degree <= angle.degree - PRECISION;
}


bool Angle::operator>=(Angle angle) const {
    return degree >= angle.degree + PRECISION;
}


bool Angle::operator<(Angle angle) const {
    return degree < angle.degree - PRECISION;
}


bool Angle::operator>(Angle angle) const {
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

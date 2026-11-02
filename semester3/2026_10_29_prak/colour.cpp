#include <iostream>
#include "cmath"
#define TOLERANCE 1e-16

class Colour {
protected:
    double* data;
public:
    Colour();
    Colour(double a, double b, double c, double d);
    virtual ~Colour();
    virtual bool is_black();
    void get_data(double* res_data);
    Colour operator+(const Colour& col) const;
    friend std::ostream& operator<<(std::ostream& out, const Colour& col);
};


std::ostream& operator<<(std::ostream& out, const Colour& col) {
    out << "(" << col.data[0] << ", " << col.data[1] << ", " << col.data[2] << ", " << col.data[3] << ") ";
    return out;
}


Colour::Colour(){
    data = new double[4];
    data[0] = 0.0;
    data[1] = 0.0;
    data[2] = 0.0;
    data[3] = 0.0;
}


Colour::Colour(double a, double b, double c, double d){
    data = new double[4];
    data[0] = a;
    data[1] = b;
    data[2] = c;
    data[3] = d;
}


Colour::~Colour(){
    delete data;
}

void Colour::get_data(double* res_data) {
    res_data[0] = data[0];
    res_data[1] = data[1];
    res_data[2] = data[2];
    res_data[3] = data[3];
}


double cut(double number) {
    if (number > 1) {
        return number - 1;
    }
    return number;
}


Colour Colour::operator+(const Colour& col) const {
    return Colour(cut(data[0] + col.data[0]),
    cut(data[1] + col.data[1]),
    cut(data[2] + col.data[2]),
    cut(data[3] + col.data[3]));
}


class RGBa:Colour{
public:
    RGBa(double r, double g, double b, double a);
    virtual bool is_black();
    double* get_data();

    double get_red() {return data[0];};
    double get_green() {return data[1];};
    double get_blue() {return data[2];};
    double get_alpha() {return data[3];};

    void set_red(double red) {data[0] = red;};
    void set_green(double green) {data[1] = green;};
    void set_blue(double blue) {data[2] = blue;};
    void set_alpha(double alpha) {data[3] = alpha;};
};


RGBa::RGBa(double r, double g, double b, double a) {
    data[0] = r;
    data[1] = g;
    data[2] = b;
    data[3] = a;
}


bool RGBa::is_black() {
    return (fabs(data[0]) + fabs(data[1]) + fabs(data[2])) < TOLERANCE && data[3] >= 1 - TOLERANCE;
}


class SMYK: public Colour{
public:
    virtual bool is_black();

    double get_cyan() {return data[0];};
    double get_magenta() {return data[1];};
    double get_yellow() {return data[2];};
    double get_black() {return data[3];};

    void set_cyan(double cyan) {data[0] = cyan;};
    void set_magenta(double magenta) {data[0] = magenta;};
    void set_yellow(double yellow) {data[0] = yellow;};
    void set_black(double black) {data[0] = black;};

    virtual bool is_clear();
};


bool SMYK::is_black() {
    return data[3] >= 1 - TOLERANCE;
}



bool non_zero(double a, double b, double c) {
    return a > 0 && b < TOLERANCE && c < TOLERANCE;
}


bool equal(double a, double b, double c) {
    return fabs(a - b) < TOLERANCE && c < TOLERANCE;
}


bool SMYK::is_clear() {
    return
    non_zero(data[0], data[1], data[2])
    || non_zero(data[0], data[2], data[1])
    || non_zero(data[1], data[0], data[2])
    || non_zero(data[1], data[2], data[0])
    || non_zero(data[2], data[0], data[1])
    || non_zero(data[2], data[1], data[0])

    || equal(data[0], data[1], data[2])
    || equal(data[0], data[2], data[1])
    || equal(data[1], data[0], data[2])
    || equal(data[1], data[2], data[0])
    || equal(data[2], data[0], data[1])
    || equal(data[2], data[1], data[0]);
}


class Warm_SMYK: public SMYK{
public:
    virtual bool is_black();

    double get_cyan() {return data[0];};
    double get_magenta() {return data[1];};
    double get_yellow() {return data[2];};
    double get_black() {return data[3];};

    void set_cyan(double cyan) {data[0] = cyan;};
    void set_magenta(double magenta) {data[0] = magenta;};
    void set_yellow(double yellow) {data[0] = yellow;};
    void set_black(double black) {data[0] = black;};

    virtual bool is_clear();
};


bool Warm_SMYK::is_black() {
    return data[3] >= 1 - TOLERANCE;
}


bool Warm_SMYK::is_clear() {
    return
    non_zero(data[0], data[1], data[2])
    || non_zero(data[0], data[2], data[1])
    || non_zero(data[1], data[0], data[2])
    || non_zero(data[1], data[2], data[0])
    || non_zero(data[2], data[0], data[1])
    || non_zero(data[2], data[1], data[0])

    || equal(data[0], data[1], data[2])
    || equal(data[0], data[2], data[1])
    || equal(data[1], data[0], data[2])
    || equal(data[1], data[2], data[0])
    || equal(data[2], data[0], data[1])
    || equal(data[2], data[1], data[0]);
}


int main() {
    Colour col1 = Colour(1, 0.5, 1, 1);
    std::cout << col1 << "\n";
}

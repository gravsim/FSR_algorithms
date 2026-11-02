#include <iostream>
#include "cmath"
#define TOLERANCE 1e-12


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
    delete[] data;
}


bool Colour::is_black() {
    return fabs(data[0]) + fabs(data[1]) + fabs(data[2]) + fabs(data[3]) < TOLERANCE;
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


class RGBa: public Colour{
public:
    using Colour::Colour;
    bool is_black() override;

    double get_red() {return data[0];};
    double get_green() {return data[1];};
    double get_blue() {return data[2];};
    double get_alpha() {return data[3];};

    void set_red(double red) {data[0] = red;};
    void set_green(double green) {data[1] = green;};
    void set_blue(double blue) {data[2] = blue;};
    void set_alpha(double alpha) {data[3] = alpha;};
    friend std::ostream& operator<<(std::ostream& out, const RGBa& col);
};


std::ostream& operator<<(std::ostream& out, const RGBa& col) {
    out << "(" << col.data[0] << ", " << col.data[1] << ", " << col.data[2] << ", " << col.data[3] << ") ";
    return out;
}


bool RGBa::is_black() {
    return fabs(data[0]) + fabs(data[1]) + fabs(data[2]) < TOLERANCE && data[3] >= 1 - TOLERANCE;
}


class CMYK: public Colour{
public:
    using Colour::Colour;
    bool is_black() override;

    double get_cyan() {return data[0];};
    double get_magenta() {return data[1];};
    double get_yellow() {return data[2];};
    double get_black() {return data[3];};

    void set_cyan(double cyan) {data[0] = cyan;};
    void set_magenta(double magenta) {data[1] = magenta;};
    void set_yellow(double yellow) {data[2] = yellow;};
    void set_black(double black) {data[3] = black;};

    virtual bool is_clear();
    friend std::ostream& operator<<(std::ostream& out, const CMYK& col);
};


std::ostream& operator<<(std::ostream& out, const CMYK& col) {
    out << "(" << col.data[0] << ", " << col.data[1] << ", " << col.data[2] << ", " << col.data[3] << ") ";
    return out;
}


bool CMYK::is_black() {
    return data[3] >= 1 - TOLERANCE;
}



bool non_zero(double a, double b, double c) {
    return a > 0 && b < TOLERANCE && c < TOLERANCE;
}


bool equal(double a, double b, double c) {
    return fabs(a - b) < TOLERANCE && c < TOLERANCE;
}


bool CMYK::is_clear() {
    return false;
}


class Warm_CMYK: public CMYK{
public:
    using CMYK::CMYK;
    bool is_black() override;

    bool is_clear() override;
    friend std::ostream& operator<<(std::ostream& out, const Warm_CMYK& col);
};


std::ostream& operator<<(std::ostream& out, const Warm_CMYK& col) {
    out << "(" << col.data[0] << ", " << col.data[1] << ", " << col.data[2] << ", " << col.data[3] << ") ";
    return out;
}


bool Warm_CMYK::is_black() {
    return data[3] >= 1 - TOLERANCE;
}


bool Warm_CMYK::is_clear() {
    return non_zero(data[0], data[1], data[2])
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
    Colour col = Colour(0, 0, 0, 1);
    std::cout << col << "\n";
    std::cout << "is_black col: " << col.is_black() << "\n";

    RGBa col1 = RGBa(0, 0, 0, 1);
    std::cout<< col1 << "\n";


    Colour* col1_p = &col1;
    std::cout << "is_black Virtual col1: " << col1_p->is_black() << "\n";

    CMYK cmyk = CMYK(1, 0, 0, 0);
    std::cout << cmyk << "\n";
    std::cout << "is_clear cmyk: " << cmyk.is_clear() << "\n";

    Warm_CMYK warm_cmyk = Warm_CMYK(1, 1, 0, 0);
    std::cout << warm_cmyk << "\n";
    CMYK* warm_cmyk_p = &warm_cmyk;

    std::cout << "is_clear Virtual warm_cmyk: " << warm_cmyk_p->is_clear() << "\n";
}

#include <iostream>
#include <iomanip>
#include <fstream>


class Legendre_exception: public std::exception {
protected:
    const char* message;
public:
    Legendre_exception();
    const char* what() const noexcept override;
};


Legendre_exception::Legendre_exception(): message("Error") {
}


const char *Legendre_exception::what() const noexcept {
    return message;
}


class n_exception: public Legendre_exception {
protected:
    double n;
public:
    n_exception(double n);
    double get_n() const;
};


n_exception::n_exception(double n) {
    this->n = n;
}


double n_exception::get_n() const {
    return n;
}


class Negative_n_exception: public n_exception {
public:
    Negative_n_exception(double n);
    const char* what() const noexcept override;
};


Negative_n_exception::Negative_n_exception(double n): n_exception(n) {
    this->n = n;
    message = "n must be an positive or 0";
}


const char *Negative_n_exception::what() const noexcept {
    return message;
}


class Non_int_n_exception: public n_exception {
public:
    Non_int_n_exception(double n);
    const char* what() const noexcept override;
};


Non_int_n_exception::Non_int_n_exception(double n): n_exception(n) {
    this->n = n;
    message = "n must be an integer";
}


const char *Non_int_n_exception::what() const noexcept {
    return message;
}


double Legendre(double x, double n) {
    if (n < 0) {
        throw Negative_n_exception(n);
    }
    if (static_cast<double>(static_cast<int>(n)) != n) {
        throw Non_int_n_exception(n);
    }
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    if (n > 1) {
        double Pn0 = 1;
        double Pn1 = x;
        double Pn2 = Pn1;
        int deg = static_cast<int>(n);
        for (int i = 2; i <= deg; i++) {
            Pn2 = 1.0 / i  * ((2 * i - 1) * x * Pn1 - (i - 1) * Pn0);
            Pn0 = Pn1;
            Pn1 = Pn2;
        }
        return Pn2;
    }
    return 0;
}


int main() {
    double n;
    double x;
    std::ifstream input("input.txt");
    input >> x >> n;
    std::ofstream output;
    output.open("output.txt", std::ios_base::out);
    try {
        output << "Legendre(x=" << x << ", n=" << n << ") = " << Legendre(x, n);
    }
    catch (const Negative_n_exception& err) {
        std::cout << "Exception: " << err.what() << "\n";
    }
    catch (const Non_int_n_exception& err) {
        std::cout << "Exception: " << err.what() << "\n";
    }
    std::cout << "Program finished.";
    return 0;
}

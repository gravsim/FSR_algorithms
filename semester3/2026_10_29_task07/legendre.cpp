#include <iostream>
#include <iomanip>
#include <fstream>

double Legendre(double x, int n) {
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
        for (int i = 2; i <= n; i++) {
            Pn2 = 1.0 / i  * ((2 * i - 1) * x * Pn1 - (i - 1) * Pn0);
            Pn0 = Pn1;
            Pn1 = Pn2;
        }
        return Pn2;
    }
    if (n < 1) {
        return -1;
    }
    return -1;
}


int main() {
    int n;
    double x;
    std::ifstream input("input.txt");
    input >> x >> n;
    std::ofstream output;
    output.open("output.txt", std::ios_base::out);
    output << "Legendre(x=" << x << ", n=" << n << ") = " << Legendre(x, n);
    std::cout << "Program finished.";
    return 0;
}


#include <iostream>
#include <vector>
#include <cmath> // Added for std::fabs

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator for subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload >> operator for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << std::fabs(c.imag) << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";


    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Example of managing a collection of complex numbers
    vector<Complex> complexList = {c1, c2, sum, diff};
    cout << "\nCollection of complex numbers:\n";
    for (const auto& c : complexList) {
        cout << c << endl;
    }
    cout<<endl<<"Yug Shah\n24CE114";
    return 0;
}

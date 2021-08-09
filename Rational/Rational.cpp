#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int NOD(int a, int b) {
    while(a != 0 and b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
        }
    return a+b;
}

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        num = abs(numerator);
        denom = abs(denominator);
        if (denom == 0) 
            throw invalid_argument("Invalid argument");
        if (num == 0) {
            denom = 1;
            return;
        }
        int nod = NOD(num, denom);
        if (num%nod == 0 && denom%nod == 0) {
            num /= nod;
            denom /= nod;
        }
        if (denominator < 0 || numerator < 0) {
            num = (-1) * num;
        }
        if (numerator < 0 && denominator < 0) {
            num = abs(num);
            denom = abs(denom);
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

private:
    int num;
    int denom;
};

Rational operator+(const Rational& lh, const Rational& rh) {
        int first_part = lh.Numerator()*rh.Denominator() + rh.Numerator()*lh.Denominator();
        int second_part = rh.Denominator()*lh.Denominator();
        return Rational(first_part, second_part);
    }

Rational operator-(const Rational& lh, const Rational& rh) {
        int first_part = lh.Numerator()*rh.Denominator() - rh.Numerator()*lh.Denominator();
        int second_part = rh.Denominator()*lh.Denominator();
        return Rational(first_part, second_part);
}

Rational operator*(const Rational& lh, const Rational& rh) {
        int first_part = lh.Numerator()*rh.Numerator();
        int second_part = rh.Denominator()*lh.Denominator();
        return Rational(first_part, second_part);
    }

Rational operator/(const Rational& lh, const Rational& rh) {
        int first_part = lh.Numerator()*rh.Denominator();
        int second_part = lh.Denominator()*rh.Numerator();
        if (second_part == 0) 
            throw domain_error("Division by zero");
        return Rational(first_part, second_part);
    }

bool operator<(const Rational& lh, const Rational& rh) {
        int first_el = lh.Numerator()*rh.Denominator();
        int secon_el = rh.Numerator()*lh.Denominator();
        return first_el < secon_el;
    }
 
bool operator==(const Rational& lh, const Rational& rh) {
    if (lh.Numerator() == rh.Numerator() && lh.Denominator() == rh.Denominator()) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& stream, const Rational& rh) {
    stream << rh.Numerator();
    stream << "/";
    stream << rh.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rh) {
    int nm;
    stream >> nm;
    if (stream.fail())
    {   
        rh = Rational(rh.Numerator(), rh.Denominator());
        return stream;
    }
    char ch;
    stream >> ch;
    if (ch != '/') {
        rh = Rational();
        return stream;
    }
    int dn;
    stream >> dn;
    if (stream.fail())
    {
        rh = Rational();
        return stream;
    }
    rh = Rational(nm, dn);
    return stream;
}

int main() {

    Rational r1, r2;
    char operation;
    try {
        cin >> r1 >> operation >> r2;
        if (operation == '+') {
            cout << r1 + r2 << endl;
        } else if (operation == '-') {
            cout << r1 - r2 << endl;
        } else if (operation == '*') {
            cout << r1 * r2 << endl;
        } else if (operation == '/') {
            try {
                cout << r1 / r2 << endl;
            } catch (domain_error& de) {
                cout << de.what();
            }
        }
    } catch (invalid_argument& ia) {
        cout << ia.what();
    }

    return 0;
}
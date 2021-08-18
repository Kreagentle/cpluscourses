#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

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

void TestCreator() {
    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestNOD() {
    Rational r(3, 4);
    AssertEqual(r.Numerator(), 3);
    AssertEqual(r.Denominator(), 4);

    Rational s(4, 8);
    AssertEqual(s.Numerator(), 1);
    AssertEqual(s.Denominator(), 2);
}

void TestMinus() {
    Rational r(-1, 2);
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 2);

    Rational m(1, -2);
    AssertEqual(m.Numerator(), -1);
    AssertEqual(m.Denominator(), 2);

    Rational s(-4, 8);
    AssertEqual(s.Numerator(), -1);
    AssertEqual(s.Denominator(), 2);

    Rational z(4, -8);
    AssertEqual(z.Numerator(), -1);
    AssertEqual(z.Denominator(), 2);
}

void TestPlus() {
    Rational r(1, 3);
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 3);

    Rational s(-1, -3);
    AssertEqual(s.Numerator(), 1);
    AssertEqual(s.Denominator(), 3);
}

void TestZero() {
    Rational r(0, 8);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

int main() {
  TestRunner runner;
  runner.RunTest(TestCreator, "TestCreator");
  runner.RunTest(TestNOD, "TestNOD");
  runner.RunTest(TestMinus, "TestMinus");
  runner.RunTest(TestPlus, "TestPlus"); 
  runner.RunTest(TestZero, "TestZero");
  return 0;
}
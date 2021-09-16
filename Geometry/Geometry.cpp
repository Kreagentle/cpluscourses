#include <iostream>
#include <iomanip>
#include <math.h>
#include <memory>
#include <sstream>
#include <vector>

using namespace std;

class Figure {
    public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Triangle : public Figure {
    public:
    Triangle(int fir, int sec, int thi) : a(fir), b(sec), c(thi) {
        a = fir;
        b = sec;
        c = thi;
    };
    string Name() override {
        return "TRIANGLE";
    };
    double Perimeter() override {
        return a+b+c;
    };
    double Area() override {
        double p = Perimeter()/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    };
    private:
    int a, b, c;
}; 

class Rect : public Figure {
    public:
    Rect(int fir, int sec) : width(fir), height(sec) {};
    string Name() override {
        return "RECT";
    };
    double Perimeter() override {
        return 2*(width + height);
    };
    double Area() override {
        return width*height;
    };
    private:
    int width, height;
};

class Circle : public Figure {
    public:
    Circle(int fir) : r(fir) {};
    string Name() override {
        return "CIRCLE";
    };
    double Perimeter() override {
        return 2*3.14*r;
    };
    double Area() override {
        return 3.14*r*r;
    };
    private:
    int r;
};

shared_ptr<Figure> CreateFigure(istringstream& s) {
    string nm;
    s >> nm;
    if (nm == "RECT") {
        int wid, he;
        s >> wid >> he;
        return make_shared <Rect>(wid, he);
    } else if (nm == "TRIANGLE") {
         int a, b, c;
         s >> a >> b >> c;
         return make_shared <Triangle>(a, b, c);
    } else if (nm == "CIRCLE") {
         int r;
         s >> r;
         return make_shared <Circle>(r);
    }
    return 0;
}; 

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
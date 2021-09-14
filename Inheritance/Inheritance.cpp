#include <iostream>

using namespace std;

class Animal {
public:
    Animal(string n) : Name(n){
    }
    const string Name;
};


class Dog : public Animal {
public:
    Dog(string s) : Animal(s) {
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
    Dog dog("s");
    dog.Bark();
    return 0;
}
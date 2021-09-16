#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
    public:
    Person(const string& n, const string& occ): name(n), occupation(occ) {};

    virtual void Walk(const string& destination) const {
        cout << occupation << ": " << name << " walks to: " << destination << endl;
    };

    string GetName() const {
        return name;
    };

    string GetOccupation() const {
        return occupation;
    };

    private:
    string name, occupation;
};

class Student : public Person {
public:

    Student(const string n, const string favouriteSong) : Person(n, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << GetOccupation() << ": " << GetName() << " learns" << endl;
    }

    void Walk(string& destination) const {
        cout << GetOccupation() << ": " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << GetOccupation() << ": " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& n, const string& subject) : Person(n, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << GetOccupation() << ": " << GetName() << " teaches: " << Subject << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& n) : Person(n, "Policeman") {}

    void Check(const Person& p) const {
        cout << GetOccupation() << ": " << GetName() << " checks " << p.GetOccupation() << ". " << p.GetOccupation() << "'s name is: " << GetName() << endl;
    }
};

void VisitPlaces(const Person& t, const vector<string>& places) {
    for (const auto& p : places) {
        t.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
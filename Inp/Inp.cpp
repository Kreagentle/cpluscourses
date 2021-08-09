#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
 
using namespace std;

struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main()
{   
    int n, r;
    string hl;
    cin >> n;
    vector<Student> st(n);
    for (int i=0; i<n; i++) {
        cin >> st[i].name;
        cin >> st[i].surname;
        cin >> st[i].day;
        cin >> st[i].month;
        cin >> st[i].year;
    }
    cin >> r;
    for (int i=0; i<r; i++) {
        int k = 0;
        cin >> hl;
        if (hl == "name") {
            cin >> k;
            if (k > n || k<=0) {
                cout << "bad request" << endl;
            }
            for (int j=0; j<n;j++) {
                if (j == k-1)
                cout << st[j].name << " " << st[j].surname << endl;
            }
        } else if(hl == "date") {
            cin >> k;
            if (k > n || k<=0) {
                cout << "bad request" << endl;
            }
            for (int j=0; j<n;j++) {
                if (j == k-1)
                cout << st[j].day << "." << st[j].month << "." << st[j].year << endl;
            }
        } else {
            cin >> k;
            cout << "bad request" << endl;
        }
    }
    // system("pause");
    return 0;
}
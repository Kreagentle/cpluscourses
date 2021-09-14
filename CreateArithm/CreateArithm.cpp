#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, kolvo;
    cin >> n;
    cin >> kolvo;
    deque <string> deq;
    deq.push_back(to_string(n));
    for (int i = 0; i < kolvo; i++) {
        deq.push_front("(");
        deq.push_back(") ");
        char oper;
        cin >> oper;
        int num;
        cin >> num;
        deq.push_back(string(1, oper));
        deq.push_back(" ");
        deq.push_back(to_string(num));
    }
    for (string &s : deq) {
        cout << s;
    }
    return 0;
}
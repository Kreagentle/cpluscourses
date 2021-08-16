#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Предварительное объявление шаблонных функций
template<typename T> T Sqr(T x);
template <typename First , typename Second>
pair <First , Second > operator*(pair <First , Second >& p1 ,
            pair <First , Second >& p2);
template <typename T> // для vector
vector<T> operator * (vector <T>& vi, vector <T>& v);
template <typename Key , typename Value > // для map
map<Key , Value > operator * (map<Key , Value >& vi, map<Key , Value >& v);


// Объявляем шаблонные функции
template <typename First , typename Second>
pair <First , Second > operator*(pair <First , Second >& p1 ,
            pair <First , Second >& p2) {
                First f = p1.first * p2.first;
                Second s = p1.second * p2.second;
            return {f, s};
            }

template <typename T> // для vector
vector<T> operator * (vector <T>& vi, vector <T>& v) {
    vector <T> res;
    for (auto& i : vi) {
        res.push_back(i*i);
    }   
    return res;
}

template <typename Key , typename Value > // для map
map<Key , Value > operator * (map<Key , Value >& vi, map<Key , Value >& v) {
    for (auto& [key, value] : vi) {
        v[key] = value * v.at(key);
    }
    return vi;
}

template <typename T>
T Sqr(T x) { 
    return x*x;
}

int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
}
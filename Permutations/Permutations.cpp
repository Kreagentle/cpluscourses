#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int fact(int N)
{
    if (N == 0) 
        return 1;
    else 
        return N * fact(N - 1);
}

int main() {
  int n;
  vector<int> vec;
  cin >> n;
  for (int i = n; i >= 1; i--) {
      vec.push_back(i);
  }
  for (auto Iter1 = vec.begin(); Iter1 != vec.end(); Iter1++) {
        cout << *Iter1 << " ";
  }
  cout << endl;
  int iii = 1;
    while (iii < fact(n)) {
        prev_permutation (vec.begin( ), vec.end( ));
        for (auto Iter1 = vec.begin(); Iter1 != vec.end(); Iter1 ++ )
            cout << *Iter1 << " ";
        cout << endl;
        iii++;
    }
  return 0;
}
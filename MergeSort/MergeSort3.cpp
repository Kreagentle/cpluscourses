#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    vector<typename RandomIt::value_type> temp;
    auto it1 = begin(elements) + elements.size() / 3;
    auto it2 = begin(elements) + 2 * elements.size() / 3;
    MergeSort(begin(elements), it1);
    MergeSort(it1, it2);
    MergeSort(it2, end(elements));
    merge(begin(elements), it1, it1, it2, back_inserter(temp));
    merge(begin(temp), end(temp), it2, end(elements), range_begin);
};

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
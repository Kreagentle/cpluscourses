#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
        if (numbers.lower_bound(border) == numbers.begin()) {
            return numbers.lower_bound(border);
        }
        for (auto it = begin(numbers); it != end(numbers); it++) {
            if ((*it > border && it == begin(numbers)) || *it == border) {
                return it;
            } else if (*it > border && it != begin(numbers)) {
                int el1 = *it - border;
                int el2 = border - *prev(it);
                if (el2 > el1) {
                    return it;
                } else {
                    return prev(it);
                }
            } else if (border > *prev(end(numbers))) {
                return prev(end(numbers));
            }
            }
        return end(numbers);
    };

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> vec;
    auto temp = begin(s);
    auto it = begin(s);
    while (it != end(s)) {
        it = find(temp, end(s), ' ');
        vec.push_back({temp, it});
        temp = it;
        temp++;
    }
    return vec;
};

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
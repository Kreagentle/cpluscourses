#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

auto Comparison (const string& std_name, const string& parent_std_name, const map<Lang, string>& names, const int64_t& population) {
    return tie(std_name, parent_std_name, names, population);
};

bool operator<(const Region r1, const Region r2) {
    return Comparison(r1.std_name, r1.parent_std_name, r1.names, r1.population)<Comparison(r2.std_name, r2.parent_std_name, r2.names, r2.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int sum = 0, temp; 
    set<Region> setreg{};
    for (auto s:regions) {
        setreg.insert(s);
    }
    for (auto s:setreg) {
        temp = 0;
        for (size_t i = 0; i < regions.size(); i++) {
            if (Comparison(regions[i].std_name, regions[i].parent_std_name, regions[i].names, regions[i].population) == Comparison(s.std_name, s.parent_std_name, s.names, s.population)) {
                temp++;
            }
         }
         if (temp > sum) {
            sum = temp;
         }
    }
    return sum;
};

int main() {
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;
  
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;
  
  return 0;
}
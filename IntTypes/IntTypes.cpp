#include <iostream>
#include <vector>
 
using namespace std;


int main()
{   
    unsigned int n;
    int64_t sum = 0;
    cin >> n;
    vector<int64_t> vec (n);
    vector<int64_t> vec1;
    for (size_t i = 0; i < vec.size(); i++) {
        cin >> vec[i];
        sum += vec[i];
    }
    int aver = sum/static_cast<int>(n);
    for (size_t i = 0; i < n; i++) {
        if (vec[i] > aver) {
            vec1.push_back(i);
        }
    }
    cout << vec1.size() << endl;
    for (size_t i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " "; 
    }
    return 0;
}
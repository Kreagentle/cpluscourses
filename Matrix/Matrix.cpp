#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Matrix {
    private:    
    int num_rows, num_cols;
    vector<vector<int>> mat;

    public: 
    Matrix() {
        num_rows = 0, num_cols = 0;
    }

    Matrix(int nr, int nc) {
        Reset(nr, nc);
    }

    void Reset(int nr, int nc) {
        if (nr < 0) {
            throw out_of_range("Change number of rows");
        }
        if (nc < 0) {
            throw out_of_range("Change number of columns");
        }
        if (nr == 0 || nc == 0) {
            nr = nc = 0;
        }
        num_rows = nr, num_cols = nc;
        mat.assign(num_rows, vector<int>(num_cols));
    }

    int& At(int nr, int nc) {
        return mat.at(nr).at(nc);
    }

    int At(int nr, int nc) const {
        return mat.at(nr).at(nc);
    }

    int GetNumRows() const {
        return num_rows;
    }

    int GetNumColumns() const {
        return num_cols;
    }
};   

bool operator==(Matrix mt, Matrix mt1) {
        if (mt.GetNumRows() != mt1.GetNumRows() || mt.GetNumColumns() != mt1.GetNumColumns()) {
            return false;
        }
        for (int i = 0; i < mt.GetNumRows(); i++) {
            for (int j = 0; j < mt.GetNumColumns(); j++) {
                if (mt.At(i, j) != mt1.At(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

Matrix operator+(Matrix mt, Matrix mt1) {
        if (mt.GetNumRows() != mt1.GetNumRows()) {
            throw invalid_argument("Mismatched number of rows");
        }
        if (mt.GetNumColumns() != mt1.GetNumColumns()) {
            throw invalid_argument("Mismatched number of columns");
        }
        int n = mt.GetNumRows(), m = mt.GetNumColumns();
        Matrix ts(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ts.At(i, j) = mt.At(i, j) + mt1.At(i, j);
            }
        }
        return ts;
    }

istream& operator>>(istream& stream, Matrix &mat) {
        int n, m;
        stream >> n >> m;
        mat.Reset(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { 
                stream >> mat.At(i, j);
            }
        }
        return stream;
}

ostream& operator<<(ostream& stream, Matrix mat) {
    int n = mat.GetNumRows();
    int m = mat.GetNumColumns();
    stream << n << ' ' << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                stream << mat.At(i, j) << ' ';
        }
        stream << endl;
    }
    return stream;
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
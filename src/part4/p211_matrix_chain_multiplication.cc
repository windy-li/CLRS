#include "p211_matrix_chain_multiplication.h"

void TestMatrixMultiply() {
  Solution s;
  vector<vector<int>> a = {{1, 2, 3, 4},
                           {5, 6, 7, 8},
                           {9, 1, 2, 3}};
  vector<vector<int>> b = {{1, 2},
                           {3, 4},
                           {5, 6},
                           {7, 8}};
  int a_row = a.size();
  int b_col = b[0].size();
  vector<vector<int>> c = s.MatrixMultiply(a, b);
  for (int i = 0; i < a_row; i++) {
    for (int j = 0; j < b_col; j++) {
      cout << c[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  TestMatrixMultiply();
}

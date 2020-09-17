#include "p211_matrix_chain_multiplication.h"

void TestMatrixMultiply() {
  std::vector<std::vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}};
  std::vector<std::vector<int>> b = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  int a_row = a.size();
  int b_col = b[0].size();
  Solution s;
  std::vector<std::vector<int>> c = s.MatrixMultiply(a, b);
  for (int i = 0; i < a_row; i++) {
    for (int j = 0; j < b_col; j++) {
      std::cout << c[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() { TestMatrixMultiply(); }

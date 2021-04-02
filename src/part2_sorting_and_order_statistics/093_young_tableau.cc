#include "clrs.h"

class YoungTableau {
 public:
  YoungTableau(int m, int n) : m_(m), n_(n), matrix_(std::vector(m, std::vector(n, INT_MAX))) {}

  int ExtractMin() {
    if (Empty()) {
      throw std::underflow_error("Young tableau underflow");
    }
    int ret = matrix_[0][0];
    matrix_[0][0] = INT_MAX;
    Youngify(0, 0);
    return ret;
  }

  bool Empty() { return matrix_[0][0] == INT_MAX; }

  bool Full() { return matrix_[m_ - 1][n_ - 1] < INT_MAX; }

  void Insert(int key) {
    if (Full()) {
      throw std::overflow_error("young tableau overflow");
    }
    DecreaseKey(m_ - 1, n_ - 1, key);
  }

  void DecreaseKey(int i, int j, int key) {
    if (key > matrix_[i][j]) {
      std::cerr << "new key cannot be greater than current key" << std::endl;
    }
    int top_key = (i > 0) ? matrix_[i - 1][j] : INT_MIN;
    int left_key = (j > 0) ? matrix_[i][j - 1] : INT_MIN;
    if (key >= top_key && key >= left_key) {
      matrix_[i][j] = key;
      return;
    }
    if (top_key > left_key) {
      matrix_[i][j] = top_key;
      matrix_[i - 1][j] = key;
      DecreaseKey(i - 1, j, key);
    } else {
      matrix_[i][j] = left_key;
      matrix_[i][j - 1] = key;
      DecreaseKey(i, j - 1, key);
    }
  }

  bool Contains(int key) {
    int row = 0;
    int col = n_ - 1;
    while (col >= 0 && row <= n_ - 1) {
      int val = matrix_[row][col];
      if (key == val) {
        return true;
      } else if (key < val) {
        col--;
      } else {
        row++;
      }
    }
    return false;
  }

 private:
  int m_;
  int n_;
  std::vector<std::vector<int>> matrix_;

  void Youngify(int i, int j) {
    int down_key = (i < n_ - 1) ? matrix_[i + 1][j] : INT_MAX;
    int right_key = (j < m_ - 1) ? matrix_[i][j + 1] : INT_MAX;
    if (down_key == INT_MAX && right_key == INT_MAX) {
      return;
    }
    if (down_key < right_key) {
      matrix_[i][j] = down_key;
      matrix_[i + 1][j] = INT_MAX;
      Youngify(i + 1, j);
    } else {
      matrix_[i][j] = right_key;
      matrix_[i][j + 1] = INT_MAX;
      Youngify(i, j + 1);
    }
  }
};

void TestYoungTableau() {
  int keys[] = {9, 16, 3, 2, 4, 8, 5, 14, 12};
  int m = 4;
  int n = 4;
  YoungTableau t(m, n);
  for (int key : keys) {
    t.Insert(key);
  }
  std::cout << t.Contains(8) << std::endl;
  std::cout << t.Contains(7) << std::endl;
  while (!t.Empty()) {
    std::cout << t.ExtractMin() << " ";
  }
}

int main() { TestYoungTableau(); }

/*
 * 1
 * 0
 * 2 3 4 5 8 9 12 14 16
 */

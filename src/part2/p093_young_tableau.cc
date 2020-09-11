#include "clrs.h"

class YoungTableau {
public:
  int m;
  int n;
  int **mat;

  YoungTableau(int m, int n) {
    this->m = m;
    this->n = n;
    mat = new int *[m];
    for (int i = 0; i < m; i++) {
      mat[i] = new int[n];
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[i][j] = INT_MAX;
      }
    }
  }

  YoungTableau(int m, int n, int **mat) {
    this->m = m;
    this->n = n;
    this->mat = mat;
  }

  int extractMin() {
    if (isEmpty()) {
      throw std::underflow_error("Young tableau underflow");
    }
    int ret = mat[0][0];
    mat[0][0] = INT_MAX;
    youngify(0, 0);
    return ret;
  }

  bool isEmpty() {
    return mat[0][0] == INT_MAX;
  }

  bool isFull() {
    return mat[m - 1][n - 1] < INT_MAX;
  }

  void insert(int key) {
    if (isFull()) {
      throw std::overflow_error("Young tableau overflow");
    }
    decreaseKey(m - 1, n - 1, key);
  }

  void decreaseKey(int i, int j, int key) {
    if (key > mat[i][j]) {
      std::cerr << "New key is greater than current key" << std::endl;
    }
    int topKey = (i > 0) ? mat[i - 1][j] : INT_MIN;
    int leftKey = (j > 0) ? mat[i][j - 1] : INT_MIN;
    if (key >= topKey && key >= leftKey) {
      mat[i][j] = key;
      return;
    }
    if (topKey > leftKey) {
      mat[i][j] = topKey;
      mat[i - 1][j] = key;
      decreaseKey(i - 1, j, key);
    } else {
      mat[i][j] = leftKey;
      mat[i][j - 1] = key;
      decreaseKey(i, j - 1, key);
    }
  }

  bool contains(int key) {
    int row = 0;
    int col = n - 1;
    while (col >= 0 && row <= n - 1) {
      int val = mat[row][col];
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

  void youngify(int i, int j) {
    int downKey = (i < n - 1) ? mat[i + 1][j] : INT_MAX;
    int rightKey = (j < m - 1) ? mat[i][j + 1] : INT_MAX;
    if (downKey == INT_MAX && rightKey == INT_MAX) {
      return;
    }
    if (downKey < rightKey) {
      mat[i][j] = downKey;
      mat[i + 1][j] = INT_MAX;
      youngify(i + 1, j);
    } else {
      mat[i][j] = rightKey;
      mat[i][j + 1] = INT_MAX;
      youngify(i, j + 1);
    }
  }
};

int main() {
  int keys[] = {9, 16, 3, 2, 4, 8, 5, 14, 12};
  int m = 4;
  int n = 4;
  auto *self = new YoungTableau(m, n);
  for (int key : keys) {
    self->insert(key);
  }
  std::cout << self->contains(8) << std::endl;
  std::cout << self->contains(7) << std::endl;
  while (!self->isEmpty()) {
    std::cout << self->extractMin() << " ";
  }
}

/*
 * 1
 * 0
 * 2 3 4 5 8 9 12 14 16
 */

#include <algorithm>
#include <climits>
#include <iostream>

enum Direction {
    LEFT, TOP, TURN
};

class Solution {
public:
    static int recursive(char *x, char *y, int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        } else if (x[m - 1] == y[n - 1]) {
            return recursive(x, y, m - 1, n - 1) + 1;
        } else {
            return std::max(recursive(x, y, m - 1, n), recursive(x, y, m, n - 1));
        }
    }

    static int memorized(char *x, int xLen, char *y, int yLen) {
        int c[xLen + 1][yLen + 1];
        for (int i = 0; i <= xLen; i++) {
            for (int j = 0; j <= yLen; j++) {
                if (i == 0 || j == 0) {
                    c[i][j] = 0;
                } else {
                    c[i][j] = INT_MIN;
                }
            }
        }
        return memorizedAux(x, y, (int *) c, yLen + 1, xLen, yLen);
    }

    static int bottomUp(char *x, int xLen, char *y, int yLen) {
        int c[xLen + 1][yLen + 1];
        for (int i = 0; i <= xLen; i++) {
            c[i][0] = 0;
        }
        for (int j = 0; j <= yLen; j++) {
            c[0][j] = 0;
        }
        for (int i = 1; i <= xLen; i++) {
            for (int j = 1; j <= yLen; j++) {
                if (x[i - 1] == y[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else {
                    c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
                }
            }
        }
        return c[xLen][yLen];
    }

    static void extendedBottomUp(char *x, int xLen, char *y, int yLen, int &result, int *b, int bCol) {
        int c[xLen + 1][yLen + 1];
        for (int i = 0; i <= xLen; i++) {
            c[i][0] = 0;
        }
        for (int j = 0; j <= yLen; j++) {
            c[0][j] = 0;
        }
        for (int i = 1; i <= xLen; i++) {
            for (int j = 1; j <= yLen; j++) {
                if (x[i - 1] == y[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    *((b + i * bCol) + j) = TURN;
                } else {
                    if (c[i - 1][j] >= c[i][j - 1]) {
                        c[i][j] = c[i - 1][j];
                        *((b + i * bCol) + j) = TOP;
                    } else {
                        c[i][j] = c[i][j - 1];
                        *((b + i * bCol) + j) = LEFT;
                    }
                }
            }
        }
        result = c[xLen][yLen];
    }

    static void constructSolution(int *b, int bCol, char *x, int i, int j) {
        if (i == 0 || j == 0) {
            return;
        }
        if (*((b + i * bCol) + j) == TURN) {
            constructSolution(b, bCol, x, i - 1, j - 1);
            std::cout << x[i - 1];
        } else {
            if (*((b + i * bCol) + j) == TOP) {
                constructSolution(b, bCol, x, i - 1, j);
            } else {
                constructSolution(b, bCol, x, i, j - 1);
            }
        }
    }

private:
    static int memorizedAux(char *x, char *y, int *c, int cCol, int i, int j) {
        if (*((c + i * cCol) + j) >= 0) {
            return *((c + i * cCol) + j);
        }
        if (x[i - 1] == y[j - 1]) {
            *((c + i * cCol) + j) = memorizedAux(x, y, c, cCol, i - 1, j - 1) + 1;
        } else {
            *((c + i * cCol) + j) = std::max(memorizedAux(x, y, c, cCol, i - 1, j), memorizedAux(x, y, c, cCol, i, j - 1));
        }
        return *((c + i * cCol) + j);
    }
};

int main() {
    char x[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char y[] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int xSize = 7;
    int ySize = 6;
    std::cout << Solution::recursive(x, y, xSize, ySize) << std::endl;
    std::cout << Solution::memorized(x, xSize, y, ySize) << std::endl;
    std::cout << Solution::bottomUp(x, xSize, y, ySize) << std::endl;
    int result = 0;
    int b[xSize + 1][ySize + 1];
    Solution::extendedBottomUp(x, xSize, y, ySize, result, (int *) b, ySize + 1);
    std::cout << result << std::endl;
    Solution::constructSolution((int *) b, ySize + 1, x, xSize, ySize);
    return 0;
}

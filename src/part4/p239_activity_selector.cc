#include <iostream>

class Solution {
public:
    static int recursive(int *s, int *f, int k, int n, int a) {
        int m = k + 1;
        while (m <= n && s[m] < f[k]) {
            m++;
        }
        if (m <= n) {
            a++;
            return recursive(s, f, m, n, a);
        } else {
            return a;
        }
    }

    static int greedy(int *s, int sLen, int *f) {
        int i = 0;
        int c = 0;
        for (int j = 1; j < sLen; ++j) {
            if (s[j] >= f[i]) {
                i = j;
                c++;
            }
        }
        return c;
    }

    static void constructSolution(int *s, int sLen, int *f) {
        int i = 1;
        std::cout << i << " ";
        for (int j = 1; j < sLen; ++j) {
            if (s[j] >= f[i]) {
                std::cout << j << " ";
                i = j;
            }
        }
    }
};

int main() {
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int f[] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int sLen = 12;
    int n = sLen - 1;
    std::cout << Solution::recursive(s, f, 0, n, 0) << std::endl;
    std::cout << Solution::greedy(s, sLen, f) << std::endl;
    Solution::constructSolution(s, sLen, f);
    return 0;
}

/*
 * 4
 * 4
 * 1 4 8 11
 */

#include <climits>
#include <iostream>
#include <algorithm>

class Solution {
public:
    static int recursive(int *p, int n) {
        if (n == 0) {
            return 0;
        }
        int max = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            max = std::max(max, p[i - 1] + recursive(p, n - i));
        }
        return max;
    }

    static int Memorized(int *p, int len) {
        int r[len + 1];
        r[0] = 0;
        for (int i = 1; i <= len; ++i) {
            r[i] = INT_MIN;
        }
        return memorizedAux(p, len, r);
    }

    static int BottomUp(int *p, int len) {
        int r[len + 1];
        r[0] = 0;
        for (int j = 1; j <= len; ++j) {
            int max = INT_MIN;
            for (int i = 1; i <= j; ++i) {
                max = std::max(max, p[i - 1] + r[j - i]);
            }
            r[j] = max;
        }
        return r[len];
    }

    static void extendedBottomUp(int *p, int len, int &result, int *s) {
        int r[len + 1];
        r[0] = 0;
        for (int j = 1; j <= len; ++j) {
            int max = INT_MIN;
            for (int i = 1; i <= j; ++i) {
                if (max < p[i - 1] + r[j - i]) {
                    max = p[i - 1] + r[j - i];
                    s[j] = i;
                }
            }
            r[j] = max;
        }
        result = r[len];
    }

    static void constructSolution(int *s, int n) {
        while (n > 0) {
            std::cout << s[n] << " " << std::endl;
            n -= s[n];
        }
    }

private:
    static int memorizedAux(int *p, int len, int *r) {
        if (r[len] >= 0) {
            return r[len];
        }
        int max = INT_MIN;
        for (int i = 1; i <= len; i++) {
            max = std::max(max, p[i - 1] + memorizedAux(p, len - i, r));
        }
        r[len] = max;
        return max;
    }
};

int main() {
    int p[] = {1, 5, 8, 9, 10, 17, 17};
    int len = 7;
    std::cout << Solution::recursive(p, len) << std::endl;
    std::cout << Solution::Memorized(p, len) << std::endl;
    std::cout << Solution::BottomUp(p, len) << std::endl;
    int result = 0;
    int s[len + 1];
    Solution::extendedBottomUp(p, len, result, s);
    std::cout << result << std::endl;
    Solution::constructSolution(s, len);
    return 0;
}

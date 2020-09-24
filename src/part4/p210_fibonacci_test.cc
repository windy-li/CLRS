#include <climits>
#include <iostream>

class Solution {
public:
    static int recursive(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        return recursive(n - 2) + recursive(n - 1);
    }

    static int tailRecursive(int n, int a, int b) {
        if (n == 1) {
            return a;
        }
        return tailRecursive(n - 1, b, a + b);
    }

    static int memorized(int n) {
        int d[n + 1];
        d[1] = 1;
        d[2] = 1;
        for (int i = 3; i <= n; ++i) {
            d[i] = INT_MIN;
        }
        return memorizedAux(n, d);
    }

    static void bottomUp(int n, int *d) {
        d[1] = 1;
        d[2] = 1;
        for (int i = 3; i <= n; ++i) {
            d[i] = d[i - 1] + d[i - 2];
        }
    }

private:
    static int memorizedAux(int i, int *d) {
        if (d[i] >= 0) {
            return d[i];
        }
        d[i] = memorizedAux(i - 1, d) + memorizedAux(i - 2, d);
        return d[i];
    }
};

int main() {
    int n = 7;
    std::cout << Solution::recursive(n) << std::endl;
    std::cout << Solution::tailRecursive(n, 1, 1) << std::endl;
    std::cout << Solution::memorized(n) << std::endl;
    int d[n + 1];
    Solution::bottomUp(n, d);
    for (int i = 1; i <= n; ++i) {
        std::cout << d[i] << " " << std::endl;
    }
    return 0;
}

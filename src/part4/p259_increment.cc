class Solution {
public:
    void Increment(int *arr, int len) {
        int i = 0;
        while (i < len - 1 && arr[len - 1 - i] == 1) {
            arr[len - 1 - i] = 0;
            i++;
        }
        if (i < len) {
            arr[len - 1 - i] = 1;
        }
    }
};

int main() {
    int arr[8];
    Solution s;
    for (int i = 1; i <= 16; i++) {
        s.Increment(arr, 8);
    }
}

#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;

        long int low = 1, high = x / 2, res = 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            int tmp = middle * middle;

            // 判断乘法是否溢出
            if (tmp / middle != middle) {
                high = middle - 1;
                continue;
            }

            if (tmp == x)
                return middle;
            else if (tmp < x) {
                low = middle + 1;
                res = middle;
            }
            else if (tmp > x)
                high = middle - 1;
        }
        return res;
    }

    int mySqrt2(int x) {
        // 位操作
        long long ans = 0;
        long bit = 1L << 16;
        while (bit > 0) {
            ans |= bit;
            if (ans * ans > x)
                ans ^= bit;
            bit >>= 1;
        }
        return int(ans);
    }
};


int main()
{
    Solution ans;
    for (int i = 0; i < 20; ++i)
        cout << ans.mySqrt2(i) << endl;
    cout << ans.mySqrt2(2147395599) << endl;
    return 0;
}

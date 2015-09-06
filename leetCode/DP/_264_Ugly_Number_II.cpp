/*
 * 264 Ugly Number II
 * https://leetcode.com/problems/ugly-number-ii/
 * ½£Ö¸offer p182.
 */


#include <iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;

        int *uglyNums = new int[n];
        uglyNums[0] = 1;
        int nextUglyIndex = 1;
        int uglyNum = 1;

        int *t2 = uglyNums, *t3 = uglyNums, *t5 = uglyNums;
        while (nextUglyIndex < n) {
            uglyNum = myMin(*t2 << 1, *t3 * 3, *t5 * 5);
            uglyNums[nextUglyIndex++] = uglyNum;
            while (*t2 << 1 <= uglyNum)
                ++t2;
            while (*t3 * 3 <= uglyNum)
                ++t3;
            while (*t5 * 5 <= uglyNum)
                ++t5;
        }

        delete[] uglyNums;
        return uglyNum;
    }
private:
    int myMin(int a, int b, int c) {
        if (a < b)
            return a < c ? a : c;
        return b < c ? b : c;
    }
};

int main()
{
    Solution ans;
    cout << ans.nthUglyNumber(10) << endl;
    return 0;
}

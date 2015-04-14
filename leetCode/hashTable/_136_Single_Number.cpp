/**
 * LeetCode 136 Single Number.
 * https://leetcode.com/problems/single-number/
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res ^= A[i];
        return res;
    }
};

int main()
{
    int A[] = {5, 5, 1, 4, 3, 3, 4};
    Solution ans;
    cout << ans.singleNumber(A, 7) << endl;

    return 0;
}

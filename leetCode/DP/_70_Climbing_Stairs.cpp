/*
 * 70 Climbing Stairs.
 * https://leetcode.com/problems/climbing-stairs/
 */

class Solution {
public:
    int climbStairs(int n) {
        // fibonacci.
        if (n == 1) return n;

        int a = 1, b = 1, res;
        for (int i = 1; i < n; ++i) {
            res = a + b;
            a = b;
            b = res;
        }

        return res;
    }
};

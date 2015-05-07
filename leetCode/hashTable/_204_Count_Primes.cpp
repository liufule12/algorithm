/**
 * LeetCode 204 Count Primes.
 * https://leetcode.com/problems/count-primes/
 */

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        int sum = 1;
        int upper = int(sqrt(n));
        bool *flag = new bool[n];
        for (int i = 3; i < n; i += 2) {
            if (!flag[i]) {
                ++sum;
                if (i > upper)
                    continue;
                for (int j = i * i; j < n; j += i) {
                    flag[j] = true;
                }
            }
        }

        delete flag;
        return sum;
    }
};

int main()
{
    Solution ans;
    cout << endl << ans.countPrimes(10000) << endl;

    return 0;
}

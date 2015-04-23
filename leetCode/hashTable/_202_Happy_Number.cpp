/**
 * LeetCode 202 Happy Number.
 * https://leetcode.com/problems/happy-number/
 * For small space, array will be faster than unorder_set.
 */

#include <iostream>
#include <string.h>
#include <limits.h>
#include <unordered_map>
#include <math.h>
using namespace std;



class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        unordered_map<int, bool> used;
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                // This statement will get different result.
                // sum += int(pow(n%10, 2));
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
            if (used.find(n) != used.end())
                return false;
            used[n] = true;
        }

        return true;
    }
};

int main()
{
    cout << "start!" << endl;
    int n;

    Solution ans;
    //for (int n = 0; n < 100; ++n) {
        if (true == ans.isHappy(2)) {
            cout << n << " " << "True!" << endl;
            //if (n % 10000 == 0)
             //   cout << n << " " << "True" << endl;
        } else
            cout << n << " " << "False!" << endl;
    //}

    return 0;
}

/*
class Solution {
public:
    bool isHappy(int n) {
        // 6ms
        if (n <= 0)
            return false;
        bool used[1000];
        memset(used, false, sizeof(used));
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
            if (true == used[n])
                return false;
            used[n] = true;
        }

        return true;
    }
};
*/

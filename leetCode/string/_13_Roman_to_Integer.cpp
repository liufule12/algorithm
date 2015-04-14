/**
 * LeetCode 13 Roman to Integer.
 * https://leetcode.com/problems/roman-to-integer/
 */

#include <iostream>
#include <string.h>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            switch (s[i]) {
            case 'I':
                res += (res >= 5 ? -1 : 1);
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                res += (res >= 50 ? -10 : 10);
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                res += (res >= 500 ? -100 : 100);
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
            }
        }
        return res;
    }
};


int main()
{
    Solution ans;
    cout << ans.romanToInt("MCDLXXIV") << endl;

    return 0;
}

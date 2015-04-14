/**
 * LeetCode 12 Integer to Roman.
 * https://leetcode.com/problems/integer-to-roman/
 */

#include <iostream>
#include <string.h>
using namespace std;

// 61ms
class Solution {
public:
    string intToRoman(int num) {
        string roman[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                          "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                          "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                          "","M","MM","MMM","MMMM"};

        return roman[num/1000 + 30] + roman[(num%1000) / 100 + 20] + roman[(num%100) / 10 + 10] + roman[num % 10];
    }
};


int main()
{
    Solution ans;
    cout << ans.intToRoman(1) << endl;

    return 0;
}

/* 49ms
class Solution {
public:
    string intToRoman(int num) {
        string res;

        int quotients = num / 1000;
        if (0 != quotients) {
            for (; quotients > 0 ; --quotients)
                res += "M";
        }

        quotients = (num % 1000) / 100;
        if (0 != quotients) {
            if (9 == quotients) {
                res += "CM";
            } else if (quotients >= 5) {
                res += "D";
                for (quotients -= 5; quotients > 0; --quotients)
                    res += "C";
            } else if (4 == quotients) {
                res += "CD";
            } else {
                for (; quotients > 0; --quotients)
                res += "C";
            }
        }

        quotients = (num % 100) / 10;
        if (0 != quotients) {
            if (9 == quotients) {
                res += "XC";
            } else if (quotients >= 5) {
                res += "L";
                for (quotients -= 5; quotients > 0; --quotients)
                    res += "X";
            } else if (4 == quotients) {
                res += "XL";
            } else {
                for (; quotients > 0; --quotients)
                res += "X";
            }
        }

        quotients = num % 10;
        if (0 != quotients) {
            if (9 == quotients) {
                res += "IX";
            } else if (quotients >= 5) {
                res += "V";
                for (quotients -= 5; quotients > 0; --quotients)
                    res += "I";
            } else if (4 == quotients) {
                res += "IV";
            } else {
                for (; quotients > 0; --quotients)
                res += "I";
            }
        }

        return res;
    }
};*/

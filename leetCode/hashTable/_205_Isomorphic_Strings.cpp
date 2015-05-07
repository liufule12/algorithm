/**
 * LeetCode 205 Isomorphic Strings.
 * https://leetcode.com/problems/isomorphic-strings/
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        int length = s.size();
        int alphabetS[500] = {0}, alphabetT[500] = {0};

        for (int i = 0; i < length; ++i) {
            if (alphabetS[int(s[i])] != alphabetT[int(t[i])])
                return false;
            alphabetS[int(s[i])] = i + 1;
            alphabetT[int(t[i])] = i + 1;
        }

        return true;
    }
};


int main()
{
    string s = "egg", t = "add";

    Solution ans;
    cout << ans.isIsomorphic(s, t) << endl;

    return 0;
}

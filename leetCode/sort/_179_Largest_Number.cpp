/**
 * LeetCode 179 Largest Number.
 * https://leetcode.com/problems/largest-number/
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution {
public:
    static string to_string(int val) {
        ostringstream stm;
        stm << val;
        return stm.str();
    }

    static bool cmp(int val1, int val2){
        string s1 = to_string(val1) + to_string(val2);
        string s2 = to_string(val2) + to_string(val1);
        return s1.compare(s2) > 0;
    }

    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);

        string res = "";
        for (vector<int>::iterator it = num.begin(); it != num.end(); ++it)
            res.append(to_string(*it));
        if ('0' == res[0])
            return "0";
        return res;
    }
};


int main()
{
    vector<int> num;
    const int N = 5;
    int A[N] = {3, 30, 34, 5, 9};
    for (int i = 0; i < N; ++i)
        num.push_back(A[i]);

    Solution ans;
    cout << ans.largestNumber(num) << endl;

    return 0;
}

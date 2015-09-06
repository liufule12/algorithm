/*
 * 198 Hourse Robber.
 * https://leetcode.com/problems/house-robber/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // Time O(1), space O(n).
        // Total[n] = max{Total[n-2], Total[n-3]} + nums[n]
        if (nums.size() == 0) return 0;

        int res = 0;
        vector<int> total;
        for (int i = 0; i < nums.size(); ++i) {
            int total1 = 0, total2 = 0;
            if (i - 2 >= 0)
                total1 = total[i-2];
            else
                total1 = 0;
            if (i - 3 >= 0)
                total2 = total[i-3];
            else
                total2 = 0;

            int tmp = max(total1, total2) + nums[i];
            total.push_back(tmp);
            if (res < tmp)
                res = tmp;
        }

        return res;
    }

    int rob2(vector<int>& nums) {
        // Time O(1), space O(1).
        // Total = max{Total[n-2] + nums[n], Total[n-1]}
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = tmp;
        }

        return cur;
    }
};

int main()
{
    vector<int> vec;
    int a[] = {10, 2, 4, 1, 3, 5, 7, 1, 2, 4};
    for (int i = 0; i < 10; ++i)
        vec.push_back(a[i]);

    Solution ans;
    cout << ans.rob2(vec) << endl;
    return 0;
}

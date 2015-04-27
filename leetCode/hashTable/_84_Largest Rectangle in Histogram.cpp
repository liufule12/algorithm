/**
 * LeetCode 84 Largest Rectangle in Histogram.
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 * Reference: http://blog.csdn.net/doc_sgl/article/details/11805519
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        stack<int> indices;
        int largestArea = 0, i = 0, lenHeight = height.size();

        while (i < lenHeight) {
            if (indices.empty() || height[i] >= height[indices.top()])
                indices.push(i++);
            else {
                int index = indices.top();
                indices.pop();
                int area = height[index] * (indices.empty() ? i : i - indices.top() - 1);
                if (largestArea < area)
                    largestArea = area;
            }
        }

        return largestArea;
    }
};


int main()
{
    cout << "start!" << endl;

    int a[6] = {2, 1, 5, 6, 2, 3};
    vector<int> height;
    for (int i = 0; i < 6; ++i) {
        height.push_back(a[i]);
    }

    Solution ans;
    cout << ans.largestRectangleArea(height) << endl;

    return 0;
}
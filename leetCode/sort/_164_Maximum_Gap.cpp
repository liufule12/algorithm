/**
 * LeetCode 164 Maximum Gap.
 * https://leetcode.com/problems/maximum-gap/
 *
 * Solution:
 * Suppose there are N elements and they range from A to B.
 * Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)].
 * Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket.
 * For any number K in the array, we can easily find out which bucket it belongs by calculating loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.
 * Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets.
 * For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max could be the potential answer to the question. Return the maximum of all those values.
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maximumGap(vector<int> &num) {
        // 先排序，再遍历比较，O(NlogN)。
        if (num.size() < 2)
            return 0;

        int maxGap = 0;
        sort(num.begin(), num.end());

        vector<int>::iterator itPre = num.begin();
        for (vector<int>::iterator it = num.begin()+1; it != num.end(); ++it, ++itPre){
            if (*it - *itPre > maxGap)
                maxGap = *it - *itPre;
        }

        return maxGap;
    }

    int maximumGap2(vector<int> &num) {
        // 桶排序，O(N)。
        int length = num.size();
        if (length < 2)
            return 0;

        int MIN = INT_MAX, MAX = INT_MIN;
        for (vector<int>::iterator it = num.begin(); it != num.end(); ++it){
            if (*it < MIN)
                MIN = *it;
            if (*it > MAX)
                MAX = *it;
        }

        int bucketLen = max(1, (MAX - MIN) / (length - 1));
        int bucketNum = (MAX - MIN) / bucketLen + 1;
        vector<int> bucketMin(bucketNum, INT_MAX);
        vector<int> bucketMax(bucketNum, INT_MIN);

        for (vector<int>::iterator it = num.begin(); it != num.end(); ++it){
            int loc = (*it-MIN)/bucketLen;
            if (INT_MAX == bucketMin[loc]){
                bucketMin[loc] = *it;
                bucketMax[loc] = *it;
            }else{
                if (*it < bucketMin[loc])
                    bucketMin[loc] = *it;
                if (*it > bucketMax[loc])
                    bucketMax[loc] = *it;
            }
        }

        int maxGap = 0;
        int preMax = MIN;
        for (int i = 0; i < bucketNum; ++i){
            if (INT_MAX != bucketMin[i]){
                if (maxGap < bucketMin[i] - preMax){
                    maxGap = bucketMin[i] - preMax;
                }
                preMax = bucketMax[i];
            }
        }

        return maxGap;
    }
};


int main()
{
    const int N = 6;
    int A[N] = {7, 9, 5, 1, 4, 20};
    vector <int> num;
    for (int i = 0; i < N; ++i)
        num.push_back(A[i]);

    Solution ans;
    cout << "maxGap: " << ans.maximumGap2(num) << endl;

    return 0;
}

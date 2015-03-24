/**
 * LeetCode 56 Merge Intervals.
 * https://leetcode.com/problems/merge-intervals/
 */


#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    static bool cmp(Interval a, Interval b) {
        if (a.start != b.start)
            return a.start < b.start;
        return a.end > b.end;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        // 先排序，再合并。
        const int length = intervals.size();
        int flag[length];
        memset(flag, 0, length*sizeof(int));

        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < length; ++i){
            if (flag[i] == 1)
                continue;

            for (int j = i + 1; j < length && intervals[j].start <= intervals[i].end; ++j){
                if (flag[j] == 0 && intervals[i].end >= intervals[j].start){
                    //cout << intervals[i].start << " " << intervals[i].end << " " << intervals[j].start << " " << intervals[j].end << endl;
                    flag[j] = 1;
                    if (intervals[j].end > intervals[i].end)
                        intervals[i].end = intervals[j].end;
                }
            }
        }

        vector<Interval> res;
        for (int i = 0; i < length; ++i){
            if (flag[i] == 0)
                res.push_back(intervals[i]);
        }

        return res;
    }
};


int main()
{
    const int N = 4;
    int A[N] = {0, 1, 1, 2};
    vector<Interval> intervals;
    for (int i = 0; i < N; i += 2)
        intervals.push_back(Interval(A[i], A[i+1]));

    Solution ans;
    vector<Interval> res = ans.merge(intervals);

    for (vector<Interval>::iterator it = res.begin(); it != res.end(); ++it)
        cout << (*it).start << " " << (*it).end << endl;

    return 0;
}

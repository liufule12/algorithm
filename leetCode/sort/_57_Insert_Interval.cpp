/**
 * LeetCode 57 Merge Intervals.
 * https://leetcode.com/problems/insert-interval/
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Insert, sort and merge.
        // Insert in ascending order.
        intervals.push_back(newInterval);
        int length = intervals.size();
        for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ++it){
            if ((*it).start > newInterval.start){
                intervals.insert(it, newInterval);
                intervals.pop_back();
                break;
            }
        }

        // Merge is equal to expand the end by overlapping interval.
        int flag[length];
        memset(flag, 0, length*sizeof(int));
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

        // Return the new intervals.
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
    const int N = 2;
    int A[N] = {1, 5};
    vector<Interval> intervals;
    for (int i = 0; i < N; i += 2)
        intervals.push_back(Interval(A[i], A[i+1]));
    Interval newInterval(2, 7);

    Solution ans;
    vector<Interval> res = ans.insert(intervals, newInterval);

    for (vector<Interval>::iterator it = res.begin(); it != res.end(); ++it)
        cout << (*it).start << " " << (*it).end << endl;

    return 0;
}

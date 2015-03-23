/**
 * LeetCode 75 Sort Colors.
 * https://leetcode.com/problems/sort-colors/
 */

#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    void sortColors(int A[], int n) {
        // 设头尾指针，遍历指针。
        // 若遍历元素为0则和头指针交换，头指针向后走一步。若交换后当前元素仍然为0，则遍历指针向前后一步。
        // 若遍历元素为2则和尾指针交换，尾指针向前走一步。

        int cur = 0, head = 0, tail = n - 1;
        while(cur <= tail && head <= tail){
            //cout << A[cur] << " " << cur << " " << head << " " << tail << endl;
            if (0 == A[cur]){
                swap(A[head], A[cur]);
                if (A[cur] == 0)
                    ++cur;
                ++head;
            }
            else if (1 == A[cur])
                ++cur;
            else if (2 == A[cur]){
                swap(A[cur], A[tail]);
                --tail;
            }
            else
                return ;
        }

        //for (int i = 0; i < n; ++i)
        //    cout << A[i] << endl;
    }

};


int main()
{
    //const int N = 13;
    //int A[N] = {0, 2, 1, 0, 1, 2, 0, 0, 2, 2, 2, 1, 0};
    const int N = 5;
    //int A[N] = {2, 2, 2, 2, 2};
    //int A[N] = {0, 0, 0, 0, 0};
    //int A[N] = {1, 1, 1, 1, 1};
    int A[N] = {0, 2, 0, 0, 1};
    Solution ans;
    ans.sortColors(A, N);

    return 0;
}

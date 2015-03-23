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
        // ��ͷβָ�룬����ָ�롣
        // ������Ԫ��Ϊ0���ͷָ�뽻����ͷָ�������һ������������ǰԪ����ȻΪ0�������ָ����ǰ��һ����
        // ������Ԫ��Ϊ2���βָ�뽻����βָ����ǰ��һ����

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

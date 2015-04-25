/**
 * LeetCode 49 Anagrams.
 * https://leetcode.com/problems/anagrams/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, pair<bool, string> > hashMap;
        vector<string> vec;

        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            string order_s = (*it);
            sort((order_s).begin(), (order_s).end());
            if (hashMap.find(order_s) != hashMap.end()) {
                if (false == hashMap[order_s].first) {
                    hashMap[order_s].first = true;
                    vec.push_back(hashMap[order_s].second);
                }
                vec.push_back((*it));
            }
            else
                hashMap.insert({order_s, {false, *it}});
        }

        return vec;
    }
};


int main()
{
    cout << "start!" << endl;
    string anagrams[10] = {"cat", "rye", "aye", "dog", "god", "cud", "cat", "old", "fop", "bra"};
    vector<string> strs;
    for (int i = 0; i < 10; ++i)
        strs.push_back(anagrams[i]);

    Solution ans;
    vector<string> vec = ans.anagrams(strs);
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << (*it) << " ";

    return 0;
}


/**
 * LeetCode 94 Binary Tree Inorder Traversal.
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 * Method 1: use stack, time complexity O(n), space complexity O(n).
 * Method 2: Morris Traversal, use the right point point to subsequent, time complexity O(n), space complexity O(1).
 * http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
 */

#include "treeNode.h"
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Morris Traversal. 5ms.
        vector<int> res;
        TreeNode *cur = root, *pre;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                //cout << cur->val << endl;
                cur = cur->right;
            }
            else {
                // Find the predecessor.
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (pre->right == cur) {
                    res.push_back(cur->val);
                    //cout << cur->val << endl;
                    pre->right = NULL;
                    cur = cur->right;
                } else {
                    pre->right = cur;
                    cur = cur->left;
                }
            }
        }
        return res;
    }
};

int main()
{
    TreeNode *T = NULL;
    createBinaryTree(&T);

    cout << "preOder:" << endl;
    preOrder(T);
    cout << endl;

    Solution ans;
    vector<int> vec = ans.inorderTraversal(T);

    return 0;
}

/* 4ms, stack, space O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> myStack;
        TreeNode *p = root;
        while (p) {
            myStack.push(p);
            p = p->left;
        }

        while (!myStack.empty()) {
            p = myStack.top();
            res.push_back(p->val);
            myStack.pop();

            if (p->right) {
                p = p->right;
                myStack.push(p);
                while (p->left) {
                    p = p->left;
                    myStack.push(p);
                }
            }
        }
        return res;
    }
};*/

#include <iostream>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        // 非递归方法，116ms.
        // 比较左右节点的树高，如果左树高，则结果加上右树的节点，指针进入左孩子；
        // 如果左右树高相同，则结果加上左树的节点，指针进入由孩子。
        int res = 0;
        while (root) {
            int leftHigh = high(root->left);
            int rightHigh = high(root->right);
            if (leftHigh > rightHigh) {
                if (rightHigh != 0)
                    res += (1 << rightHigh);
                else
                    return res + 2;
                root = root->left;
            } else if (leftHigh == rightHigh) {
                if (leftHigh != 0)
                    res += (1 << leftHigh);
                else
                    return res + 1;
                root = root->right;
            }
        }

        return res;
    }

    // 递归方法，320ms, https://leetcode.com/discuss/38899/easy-short-c-recursive-solution
    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

private:
    int high(TreeNode* root) {
        int h = 0;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }
};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution ans;
    cout << ans.countNodes(root) << endl;

    return 0;
}

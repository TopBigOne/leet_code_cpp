#include <iostream>

struct TreeNode {
    int      val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
        // dfs 的后序遍历
        TreeNode *left  = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // case 1:
        if (left == nullptr) {
            return right;
        }
        // case 2:
        if (right == nullptr) {
            return left;
        }
        // case 3；
        return root;
    }
};


int main() {

    return 0;
}

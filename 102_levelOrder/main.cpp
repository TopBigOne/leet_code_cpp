#include <iostream>

#include <queue>

using namespace std;

struct TreeNode {
    int      val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            vector<int> temp;
            size_t      size = queue.size();
            for (int    i    = 0; i < size; ++i) {
                TreeNode *node = queue.front();
                if (node == nullptr) {
                    continue;
                }
                temp.push_back(node->val);
                queue.pop();
                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }

    vector<vector<int>> levelOrder2(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            vector<int> temp;
            size_t      size = queue.size();
            for (int    i    = 0; i < size; i++) {
                TreeNode *p = queue.front();
                temp.push_back(p->val);
                queue.pop();
                if (p->left) queue.push(p->left);
                if (p->right) queue.push(p->right);
            }
            res.push_back(temp);
        }
        return res;
    }

    vector<vector<int>> levelOrder3(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            size_t      size = queue.size();
            vector<int> temp;
            for (int    i    = 0; i < size; i++) {
                TreeNode *node = queue.front();
                temp.push_back(node->val);
                queue.pop();
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                     queue.push(node->right);
                }

            }
            result.push_back(temp);
        }

        return result;
    }
};

int main() {


    return 0;
}

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
};

TreeNode* buildExampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    TreeNode* root = buildExampleTree();
    Solution sol;

    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << lca->val << endl;

    p = root->left;
    q = root->left->right->right;
    lca = sol.lowestCommonAncestor(root, p, q);
    cout << lca->val << endl;

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    p = root2;
    q = root2->left;
    lca = sol.lowestCommonAncestor(root2, p, q);
    cout << lca->val << endl;

    return 0;
}

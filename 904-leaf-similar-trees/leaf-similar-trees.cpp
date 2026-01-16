class Solution {
public:
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;

        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
            return;
        }

        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;

        getLeaves(root1, leaf1);
        getLeaves(root2, leaf2);

        return leaf1 == leaf2;
    }
};

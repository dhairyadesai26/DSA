/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans=0;
public:
    void solve(TreeNode* root,int left,int right){
        if(root==NULL){
            return;
        }
        ans=max(ans,max(left,right));
        solve(root->left,0,left+1);
        solve(root->right,right+1,0);





    }
    int longestZigZag(TreeNode* root) {
        solve(root,0,0);
        return ans;

        
    }
};
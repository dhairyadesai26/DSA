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
public:
    void inorder(TreeNode* root,vector<int>& result){
        if(root==nullptr){
            return;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
        
    }
    int getMinimumDifference(TreeNode* root) {
        // we will find bst inorder and then 
        vector<int> result;
        int mini=INT_MAX;
        inorder(root,result);
        for(int i=1;i<result.size();i++){
            mini=min(mini,abs(result[i]-result[i-1]));
        }
        return mini;            
        
    }
};
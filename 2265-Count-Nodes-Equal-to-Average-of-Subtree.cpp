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
    int solve(TreeNode* root,int& count,int& sum){
        if(root==nullptr){
            count=0;
            sum=0;
            return 0;
        } 
        int leftSum,leftCount;
        int rightSum,rightCount;
        int ans=0;
        ans+=solve(root->left,leftCount,leftSum);
        ans+=solve(root->right,rightCount,rightSum);
        sum=leftSum+rightSum+root->val;
        count=leftCount+rightCount+1;
        if(root->val==sum/count){
            ans++;
        }
        return ans;



    }
    int averageOfSubtree(TreeNode* root) {   
         int sum=0;
         int count=0;     
         return solve(root,count,sum);

        
    }
};
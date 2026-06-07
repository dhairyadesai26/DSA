1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
15      unordered_map<int, TreeNode*> mp;
16      unordered_set<int> childs;
17      for(auto &d :descriptions){
18        int parent =d[0];
19        int child=d[1];
20        int isLeft=d[2];
21        if(mp.find(parent)==mp.end()){
22            mp[parent]=new TreeNode(parent);
23        }
24        if(mp.find(child)==mp.end()){
25            mp[child]=new TreeNode(child);
26        }
27        if(isLeft){
28            mp[parent]->left=mp[child];
29        }
30        else{
31             mp[parent]->right=mp[child];
32        }
33        childs.insert(child);
34      }
35      for(auto &d:descriptions){
36        if(childs.find(d[0])==childs.end()){
37            return mp[d[0]];
38        }
39      }
40      return NULL;
41    }
42};
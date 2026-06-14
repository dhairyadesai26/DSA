1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    int pairSum(ListNode* head) {
14    ListNode* curr=head;
15    unordered_map<int,int> mp;
16    int i=0;
17    int maxi=INT_MIN;
18    while(curr!=nullptr){
19         mp[i++]=curr->val;
20        curr=curr->next;
21        
22    }
23    int n=i;
24    for(int i=0;i<n/2;i++){
25     maxi=max(maxi,mp[i]+mp[n-i-1]);
26
27    }
28    return maxi;
29    }
30};
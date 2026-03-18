/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
    ListNode* curr=head;
    unordered_map<int,int> mp;
    int i=0;
    int maxi=INT_MIN;
    while(curr!=nullptr){
         mp[i++]=curr->val;
        curr=curr->next;
        
    }
    int n=i;
    for(int i=0;i<n/2;i++){
     maxi=max(maxi,mp[i]+mp[n-i-1]);

    }
    return maxi;
    }
};
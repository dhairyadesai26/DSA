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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr=head->next;
        ListNode* prev=head;
        int count=0;
        vector<int> criticalPoint;
        while(curr!=nullptr && curr->next!=nullptr){
            ListNode* next=curr->next;
            count++;
            if((curr->val >prev->val) && (curr->val >next->val) || (curr->val <prev->val) && (curr->val < next->val) ){   
            criticalPoint.push_back(count);                              

            }
            prev=curr;
            curr=curr->next;
        }
        int m=criticalPoint.size();
        if(m<2) return {-1,-1};
        int mini=INT_MAX;
        for(int i=1;i<m;i++){
            mini=min(mini,criticalPoint[i]-criticalPoint[i-1]);
        }
        int maxi=criticalPoint[m-1]-criticalPoint[0];
        return {mini,maxi};

       


        
    }
};
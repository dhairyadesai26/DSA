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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right) return head;
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forward=nullptr;
        ListNode* leftprev=nullptr;
        ListNode* currLeft=nullptr;
        ListNode* rightnext=nullptr;
        long long count=1;
        while(curr!=nullptr){
            if(count==left){
                leftprev=prev;
                currLeft=curr;
                }
            if(count>=left && count<=right){
                if(count==right){
                rightnext=curr->next;
                }
                forward=curr->next;

                curr->next=prev;
                prev=curr;
                curr=forward;
            }


                 
            
            else{
                prev=curr;
                curr=curr->next;
            }
            if(count==right) break;
            count++;
            }
            if(leftprev!=nullptr){
                leftprev->next=prev;
            }
            else{
                head=prev;
            }

        currLeft->next=rightnext;
        return head;

        
    }
};
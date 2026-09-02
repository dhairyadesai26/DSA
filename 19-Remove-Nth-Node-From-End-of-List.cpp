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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        int count=0;
        int size = 0;

        while(curr != nullptr) {
          size++;
          curr = curr->next;
        }
        curr=head;
        while(curr!=nullptr){
            count++;
            if(count==size-n+1){
                if(prev==nullptr) head=curr->next;
                else{
                    prev->next=curr->next;
                }
                delete curr;
                break;

            }
            prev=curr;

            curr=curr->next;
        }



        return head;

        
    }
};
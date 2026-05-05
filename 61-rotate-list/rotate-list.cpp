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
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head || !head->next || k==0) return head;
      ListNode* curr=head;
      int n=1;
      while(curr->next){
        curr=curr->next;
        n++;
      }
      curr->next=head;
      k=k%n;
      int steps=n-k;
      for(int i=0;i<steps;i++){
        curr=curr->next;
      }
      ListNode* newHead=curr->next;
      curr->next=NULL;
        
      return newHead;

    }
};
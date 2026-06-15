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
13    ListNode* deleteMiddle(ListNode* head) {
14          if(head==nullptr || head->next==nullptr)
15        return nullptr;
16        ListNode* slow=head;
17        ListNode* fast=head;
18        ListNode* prev = nullptr;
19        while(fast!= NULL && fast->next!=NULL){
20            prev=slow;
21            slow=slow->next;
22            fast=fast->next->next;
23        }
24        prev->next=slow->next;
25  return head;
26    }
27};
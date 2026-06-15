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
    ListNode * mid(ListNode* head, ListNode* prev){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL) return NULL;
        ListNode* prev;
        ListNode* middle=mid(head,prev);
        if(middle->next->next!=NULL)
            middle->next=middle->next->next;
        else middle->next=NULL;
        return head;

    }
};
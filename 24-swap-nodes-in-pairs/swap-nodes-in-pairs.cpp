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
    ListNode* swapPairs(ListNode* head) {

        // using recursion
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head->next;
        head->next=swapPairs(temp->next);
        temp->next=head;
        return temp;


        // by iterrative method
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(prev->next and prev->next->next){
            ListNode* first=prev->next;
            ListNode* second=first->next;

            first->next=second->next;
            second->next=first;
            prev->next=second;
            prev=first;
        }
        return dummy->next;
    }
};
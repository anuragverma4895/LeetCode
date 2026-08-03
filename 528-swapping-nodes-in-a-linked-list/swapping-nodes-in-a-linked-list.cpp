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
    ListNode * findlastNode(ListNode* head, ListNode* temp){
        ListNode* prev=head;
        while(temp->next){
            temp=temp->next;
            prev=prev->next;

        }
        return prev;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        while(k>1){
            temp=temp->next;
            k--;
        }
        ListNode* prev2=findlastNode(head,temp);
        swap(temp->val,prev2->val);
        return head;
    }
};